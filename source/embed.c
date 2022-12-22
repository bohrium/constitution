/* author: samtenka
 * change: 2022-12-22
 * create:
 *
 * descrp: Analyze federal appeals judge voting patterns to identify whether
 *         "moderate" judges exist in great number!  Address related questions
 *         such as whether it tends to be the immoderate judges who are
 *         elevated to SCOTUS; whether appointments have become more partisan
 *         over time; and whether many judges become more moderate over time.
 *
 * method: Use approximate sampling-based inference on a hierarchical Bayesian
 *         model, conditioned on data in `*_data.c` assumed to have been
 *         correctly prepared from us judiciary websites.
 *
 * to use: Run `gcc embed.c -lm -o embed.o` and then run `./embed.o`.  Wait
 *         for histograms to be drawn.  Interpret histograms.
 */

/* ========================================================================= */
/* =  OVERVIEW  ============================================================ */
/* ========================================================================= */

/*  _DRAMATIS_PERSONAE_

    judges      `j` in J
    cases       `c` in C
    terms       `t` in T = { 1924, 1928, ..., 2020 }
    appointers  `pres.t` in {dem, rep} = {-1, +1}
    appt terms  `term.j` in T
    case terms  `date.c` in T
    votes       `vote.j.c` in {yea, nay} = {-1,+1}

    The judges include justices.  The appointers are entirely observed.  The
    votes are mostly unobserved: usually only 3 observations for each case
    unless except when a case is held-en-banc or is appealed-to-SCOTUS.

    We measure time `t` in presidential terms.  Conveniently, JFK and LBJ were
    shared a party, as did RMN and GRF; so we may stick to associating to each
    term one "president".

    The key concept in our model is `lean.j.t`, which says whether judge `j` in
    term `t` is red or blue, and by how much (red is +1; blue, -1).  In our
    model, `lean.j.t` engages in a random walk over time, starting from a value
    `core.j` at `j`'s appointment that relates to the (party of) the president
    who appointed `j`.  Controlling this walk's initialization and dynamics are
    3 high-level global model variables:

        `part` -- how intensely president affects judge
        `tite` -- how certainly president affects judge
        `walk` -- how much a judge drifts from term to term

    Finally, `lean.j.t` grounds out in observations (of `vote.j.c`) by
    participating in a kind of low-rank factorization of `vote.j.c`.  Each case
    has a `sens.c` that says whether positive or negative leaning judges are
    more likely to vote YEA.  (Each case also has a `lean`-unrelated `bias.c`).
    So the YEA : NAY log odds ratio NAY is `sens.c * lean.j + bias.c`
*/
/*  _GENERATIVE_MODEL_

        _historical_background_
        `pres.t`  ~ bernoulli { prob 1/2 }
        `term.j`  ~ uniform { 1924, 1928, ..., 2020 }
        `date.c`  ~ uniform { 1924, 1928, ..., 2020 }

        _meta_
        `part`    ~ exponentl {                                 mean 1       }
        `tite`    ~ exponentl {                                 mean 1       }
        `walk`    ~ exponentl {                                 mean 1       }

        _helpers_
        `bias.c`  ~ laplacian { mean 0                          vari 1       }
        `sens.c`  ~ laplacian { mean 0                          vari 1       }
        `core.j`  ~ laplacian { mean `pres.(term.j)`*`part`     vari `tite`  }

        _key_inferandum_
        `lean.j.t`~ laplacian { mean (if t==`term.j` then `core.j`
                                                     else `lean.j.(pred(t))`)
                                vari `walk`                                  }

        _key_observand_
        `vote.j.c`~ bernoulli { prob sigma(`sens.c`*`lean.j.(date.c)` +
                                           `bias.c`                    )     }

    We model the _historical_background_ variables so that later we might
    explore historical contrafactuals.  The function sigma is the logistic
    sigmoid; the function pred gives the term preceding its input.  Note that
    `part`, `tite`, `walk` are non-negative.
*/
/*  _QUALITATIVE_ASPECTS_

    We want to recognize moderate judges by estimating `lean.j.t`.

    Sometimes `bias` dominates `sens`; so some cases are intrinsically less
    partisan than others in a way we do not directly observe.  Therefore,
    inference about `lean.j` focuses on cases with split votes.  So the model
    won't suggest a judge is(n't) moderate just because they happen to
    participate in certain non-partisan cases.

    The role of `part` is this: as a very global variable, it will probably
    have large magnitude; then `lean.j.t` will have high-magnitude mean
    parameter so that much evidence is needed to establish `lean.j.t` is
    actually moderate.  So the model won't suggest a judge is moderate just
    because there is little data for that judge.

    TODO : Q : is `core` too weak a tether?  (unless (`tite` and) `walk` are
                much smaller than their prior scale of 1?)
*/

/* ========================================================================= */
/* =  BASICS  ============================================================== */
/* ========================================================================= */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define PF printf
#define fsgn(X) (copysign(1., (X)))

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~  Data  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef enum { DEM = -1, REP = +1           } party_t ;
#if 0
  typedef enum { NAY = -1, YEA = +1, ___ = 0  } votes_t ;
#else
  typedef enum { N = -1, Y = +1, _ = 0  } votes_t ;
  int YEA = Y;
  int ___ = _;
#endif

  /* TODO: `extern` used arrays etc for self-contained readability  */
//#include "federal_data.part.c"
//#include "federal_data.rand.c"
#include "federal_data.c"
//#include "scotus_data.c"
//#include "example_data.c"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~  Math Helpers  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

float rand_unif() { return rand() / (float)RAND_MAX; }
float rand_cent(float diam) { return (rand_unif() - .5)*diam; }

float lap(float loc, float scale, float x)
{   /*  LAPLACE : density at x is exp(-|x-loc|/scale)/(2 scale) */
    return fabs(x-loc)/scale + log(2*scale);
}

float sig(float z, bool x)
{   /*  SIGMOID : density at x is ( x ? p : q ) where p+q=1, p=1/(1+exp(-z)) */
    float soft_plus = z<-30 ? z : -log(1+exp(-z));
    return ( x ? 0 : z ) - soft_plus;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~  Fancy Printing  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define WHITE   "\033[37m"
#define YELLOW  "\033[33m"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~  Histograms  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#define nb_bins 77//40

typedef struct {
    float lo, hi;
    int counts[nb_bins];
    int too_lo, too_hi;
    int total;
} histogram_t ;

float quantile(histogram_t const* h, float q)
{
    float thresh = h->total * q - h->too_lo;
    int b=0;
    while (b!=nb_bins && thresh>=0) { thresh-=h->counts[b]; ++b; };
    return (b/(float)nb_bins) * (h->hi - h->lo) + h->lo;
}

void init_histo(histogram_t* h, float lo, float hi)
{
    h->lo = lo;
    h->hi = hi;
    for (int b=0; b!=nb_bins; ++b) { h->counts[b] = 0; }
    h->too_lo = 0;
    h->too_hi = 0;
    h->total = 0;
}

void update_histo(histogram_t* h, float x)
{
    h->total += 1;
    if (x <  h->lo) { h->too_lo += 1; return; }
    if (x >= h->hi) { h->too_hi += 1; return; }
    float b = nb_bins * (x - h->lo)/(h->hi - h->lo);
    h->counts[(int)b] += 1;
}

typedef struct { char const* color; char c; } CC;
void print_histo(histogram_t h, float norm, int nb_rows, char const* label)
{
    float deciles[10];
    int decile_cols[10];
    for (int k = 0; k != 10; ++k) {
        deciles[k] = quantile(&h, k/10.);
        decile_cols[k] = (int)(nb_bins*(deciles[k]-h.lo)/(h.hi-h.lo));
    }

    float v_scale = norm*nb_bins;

    int ll = strlen(label);

    float probs[nb_bins];
    for (int b=0; b!=nb_bins; ++b) { probs[b] = h.counts[b]/(float)h.total; }

    for (int r=0; r!=nb_rows; ++r) {
        for (int b=0; b!=nb_bins; ++b) {
            if (r==1 && b<ll) { printf(GREEN "%c" CYAN, label[b]); continue; }
            if (r==1 && b+18==nb_bins) {
                printf("[" "%s%+4.1f%s " "(%s%+4.1f%s)" " %s%+4.1f%s" "]",
                    YELLOW, deciles[1], CYAN,
                    GREEN , deciles[5], CYAN,
                    YELLOW, deciles[9], CYAN
                );
                b=nb_bins-1;
                continue;
            }

            bool filled  = (nb_rows <= probs[b]*v_scale + r);
            bool hfilled = (nb_rows <= probs[b]*v_scale + r+.5);

            CC cc = (
                filled  ? ( r ? (CC){CYAN, '|'} : (CC){MAGENTA,'+'} ) :
                hfilled ? (CC){CYAN, ','} :
                          (CC){BLUE, '_'}
                //hfilled ? ( r+1==nb_rows ? (CC){CYAN, ','} : (CC){BLUE, '_'}) :
            );
            if (cc.c!='+' && cc.c!='_' && b==decile_cols[1]) { cc.color = YELLOW; /*cc.c = '(';*/ }
            if (cc.c!='+' && cc.c!='_' && b==decile_cols[9]) { cc.color = YELLOW; /*cc.c = ')';*/ }
            if (cc.c!='+' && cc.c!='_' && b==decile_cols[5]) { cc.color = GREEN ; cc.c = '#'; }

            printf("%s%c" CYAN, cc.color, cc.c);
        }
        printf("\n");
    }

    for (int b=0; b!=nb_bins; ++b) {
        CC cc = ( b%6==2 ? (CC){BLUE, '^'} : (CC){CYAN, ' '} );
        if (b==decile_cols[1]) { cc.color = YELLOW; cc.c = 'A'; }
        if (b==decile_cols[9]) { cc.color = YELLOW; cc.c = 'A'; }
        if (b==decile_cols[5]) { cc.color = GREEN ; cc.c = 'A'; }
        printf("%s%c" CYAN, cc.color, cc.c);
    }

    printf("\n");
    for (int b=0; b+2<=nb_bins; b+=12) {
        printf("%+-12.1f", ((b+2)/(float)nb_bins)*(h.hi-h.lo) + h.lo);
    }

}

/* ========================================================================= */
/* =  MODEL  =============================================================== */
/* ========================================================================= */

typedef struct {
    float part, tite;
    float lean[nb_judges];
    float sens[nb_cases];
    float bias[nb_cases];
} state_t ;

float part_loss(float part) { return lap(1., .1, part); }

float tite_loss(float tite) { return lap(0., .01, tite); }

float sens_loss(float const* sens, int c) { return lap(0., 1., sens[c]); }

float bias_loss(float const* bias, int c) { return lap(0., 1., bias[c]); }

float lean_loss(float part, float tite, float const* lean, int j)
{
    // NOTE --- we do not use `tite`
    //return lap(pres[j] * part, fabs(tite), lean[j]);
    return lap(pres[j] * part, .1 , lean[j]);
}

float vote_loss(float const* lean, float const* sens, float const* bias,
                int c, int j                                            )
{ /* !assumes that vote[c][j] != ___ */
    //if ( vote[c][j] == ___ ) { return 0.; }
    float z = sens[c] * lean[j] + bias[c];
    return sig(z, vote[c][j]==YEA);
}

float sens_c_loss(float const* sens)
{
    float acc = 0.;
    for (int c=0; c!=nb_cases; ++c) { acc += sens_loss(sens, c); }
    return acc;
}

float bias_c_loss(float const* bias)
{
    float acc = 0.;
    for (int c=0; c!=nb_cases; ++c) { acc += bias_loss(bias, c); }
    return acc;
}

float lean_j_loss(float part, float tite, float const* lean)
{
    float acc = 0.;
    for (int j=0; j!=nb_judges; ++j) { acc += lean_loss(part, tite, lean, j); }
    return acc;
}

float vote_cj_loss(float const* lean, float const* sens, float const* bias)
{
    float acc = 0.;
    for (int c=0; c!=nb_cases; ++c) {
        for (int j=0; j!=nb_judges; ++j) {
            if ( vote[c][j] == ___ ) { continue; }
            acc += vote_loss(lean, sens, bias, c, j);
        }
    }
    return acc;
}

float loss_on(state_t s)
{
    float acc = 0.;
    acc += part_loss(s.part);
    acc += tite_loss(s.tite);
    acc += sens_c_loss(s.sens);
    acc += bias_c_loss(s.bias);
    acc += lean_j_loss(s.part, s.tite, s.lean);
    acc += vote_cj_loss(s.lean, s.sens, s.bias);
    return acc;
}

/* ========================================================================= */
/* =  INFERENCE  =========================================================== */
/* ========================================================================= */

void init_state(state_t* next)
{
    next->part = 1.;//rand_cent(1.);
    next->tite = .5;//rand_cent(1.);
    for (int c=0; c!=nb_cases; ++c) {
        next->sens[c] = rand_cent(1.);
        next->bias[c] = rand_cent(1.);
    }
    for (int j=0; j!=nb_judges; ++j) {
        next->lean[j] = rand_cent(1.);
    }
}

void copy_state(state_t const* s, state_t* next)
{
    next->part = s->part;
    next->tite = s->tite;
    for (int c=0; c!=nb_cases; ++c) {
        next->sens[c] = s->sens[c];
        next->bias[c] = s->bias[c];
    }
    for (int j=0; j!=nb_judges; ++j) {
        next->lean[j] = s->lean[j];
    }
}

void print_state(state_t const* s)
{
    PF("part  ");  PF("%5.2f  ", s->part);
    //PF("|  tite  ");  PF("%5.2f  ", s->tite);

    PF("|  sens  ");  for (int c=0; c!= 2; ++c) { PF("%+5.2f  ", s->sens[c]); }
    PF("|  bias  ");  for (int c=0; c!= 2; ++c) { PF("%+5.2f  ", s->bias[c]); }
    PF("|  lean  ");  for (int j=0; j!= 6; ++j) { PF("%+5.2f  ", s->lean[j]); }
    PF("\n");
}

typedef struct {
    enum { PART, LEAN, CASE } kind;
    float dp,dt,dl,ds,db;
    int j,c;
} pert_t ;

/* TODO : to cater to time-evolving leans, allow perturbations to `lean.j.t`
 *          of two kinds : sparse (at one `t`) and co-sparse (shift everything
 *          before `t_` by some amount and after `t_` by some other amount, for
 *          some threshold `t_`).
 */

pert_t sample_pert()
{
    pert_t p;

    float u = rand_unif();
    p.kind = (  u<0.05 ? PART :
                u<0.5  ? LEAN :
                         CASE   );

    float noise_scale = 1.;//pow(.1, rand()%2);
    switch (p.kind) {
    break; case PART: p.dp = rand_cent( 1. * noise_scale );
                      p.dt = rand_cent( 1. * noise_scale );
    break; case LEAN: p.j = rand()%nb_judges;
                        p.dl = rand_cent( 1. * noise_scale );
    break; case CASE: p.c = rand()%nb_cases;
                        p.ds = rand_cent( 1. * noise_scale );
                        p.db = rand_cent( 1. * noise_scale );
    }

    return p;
}

void apply_pert(state_t* s, pert_t p, int sign)
{
    switch (p.kind) {
    break; case PART:   s->part      += sign * p.dp;  s->part = fabs(s->part);
                        s->tite      += sign * p.dt;  s->tite = fabs(s->tite);
    break; case LEAN:   s->lean[p.j] += sign * p.dl;
    break; case CASE:   s->sens[p.c] += sign * p.ds;
                        s->bias[p.c] += sign * p.db;
    }
}

float loss_rel(state_t* s, pert_t p)
{
    float l = 0.;

    switch (p.kind) {
    break; case PART:
        l += part_loss(s->part);
        l += tite_loss(s->tite);
        l += lean_j_loss(s->part, s->tite, s->lean);
    break; case LEAN:
        l += lean_loss(s->part, s->tite, s->lean, p.j);
        for (int c=0; c!=nb_cases; ++c) {
            if ( vote[c][p.j] == ___ ) { continue; }
            l += vote_loss(s->lean, s->sens, s->bias, c, p.j);
        }
    break; case CASE:
        l += sens_loss(s->sens, p.c);
        l += bias_loss(s->bias, p.c);
        for (int j=0; j!=nb_judges; ++j) {
            if ( vote[p.c][j] == ___ ) { continue; }
            l += vote_loss(s->lean, s->sens, s->bias, p.c, j);
        }
    }
    return l;
}

void mh_step(state_t* s)
{
    float dloss=0;

    pert_t pert = sample_pert();
    dloss -= loss_rel(s, pert);
    apply_pert(s, pert, +1);
    dloss += loss_rel(s, pert);
    if ( dloss < -log(rand_unif()) ) { return; }    // <- accept
    apply_pert(s, pert, -1);                        // <- reject
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~  Hamiltonian  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void step_p(state_t* p, state_t const* q, float dt)
{
    /* FILLIN TODO */
}

void step_q(state_t const* p, state_t* q, float dt)
{
    q->part += dt * p->part;
    q->tite += dt * p->tite;
    for (int c=0; c!=nb_cases; ++c) {
        q->sens[c] += dt * p->sens[c];
        q->bias[c] += dt * p->bias[c];
    }
    for (int j=0; j!=nb_judges; ++j) {
        q->lean[j] += dt * p->lean[j];
    }
}

void evolve(state_t* p, state_t* q, float dt, int its)
{   /* leapfrog verlet with synchronized boundary times */
    if ( ! its ) { return; }
    step_p(p, q, dt/2.);
    for (int i = 0; i < its-1; ++i) {
        step_q(p, q, dt);
        step_p(p, q, dt);
    }
    step_q(p, q, dt);
    step_p(p, q, dt/2.);
}

/* ========================================================================= */
/* =  MAIN LOOP  =========================================================== */
/* ========================================================================= */

int main(int argc, char *argv[])
{
    int const T    = 1100000;
    int const DISP =  100000;
    int const BURN =  100000;
    int const SKIP =      10;

    histogram_t h[nb_judges];
    float WIDTH = 3.2;//3.3;
    for (int j=0; j!=nb_judges; ++j) { init_histo(&h[j], -WIDTH, +WIDTH); }

    histogram_t bb, ll;
    init_histo(&bb, -2. , +2. );
    //init_histo(&ll, -.1 , +1.1);
    init_histo(&ll, -.1 , +2.1);

    printf("%ssampling %d k times... (%d k steps)%s\n",
           BLUE, ((T-BURN)/SKIP)/1000, T/1000, CYAN     );

//#define CAP(Y) (1.<fabs(Y) ? 1. : fabs(Y))
#define CAP(Y) (2.<fabs(Y) ? 2. : fabs(Y))
    state_t s;
    init_state(&s);
    for (int t=0; t!=T; ++t) {
        if ( t%DISP == 0 ) { print_state(&s); }
        mh_step(&s);
        if ( t%SKIP || t<BURN ) { continue; }
        for (int j=0; j!=nb_judges; ++j) { update_histo(&h[j], s.lean[j]); }
        for (int c=0; c!=nb_cases ; ++c) { update_histo(&bb  , s.bias[c]); }
        for (int j=0; j!=nb_judges; ++j) { update_histo(&ll  , CAP(s.lean[j])); }
    }

    print_histo(bb, 2., 6, "bias");             printf("\n\n");
    print_histo(ll, 3., 6, "leans (capped)");   printf("\n\n");

    char label[] = "judge   ";
    //for (int j=0; j!=6+0*nb_judges; ++j) {
    for (int j=0; j!=nb_judges; ++j) {
        //label[7] = '0' + (j%10);
        //label[6] = '0' + ((j/10)%10);
        //print_histo(h[j], .8, 6, label);        printf("\n\n");
        print_histo(h[j], .3, 6, name[j]);        printf("\n\n");
    }
    return 0;
}
