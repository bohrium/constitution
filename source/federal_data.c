#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "math.h"


#define PF printf


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

#include "federal_data.c"
//#include "example_data.c"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~  Math Helpers  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

float rand_unif() { return rand() / (float)RAND_MAX; }
float rand_cent(float diam) { return (rand_unif() - .5)*diam; }

float laplace_loss(float loc, float scale, float x)
{   /*  density at x is exp(-|x-loc|/scale)/(2 scale) */
    return fabs(x-loc)/scale + log(2*scale);
}

float sigmoid_loss(float z, bool x)
{   /*  density at x is ( x ? p : q ) where p+q=1, p=1/(1+exp(-z))*/
    float soft_plus = z<-30 ? z : -log(1+exp(-z));
    return ( x ? 0 : z ) - soft_plus;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~  Histograms  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#define nb_bins 40

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

void print_histo(histogram_t h, float v_scale, int nb_rows)
{
    float probs[nb_bins];
    for (int b=0; b!=nb_bins; ++b) { probs[b] = h.counts[b]/(float)h.total; }
    for (int r=0; r!=nb_rows; ++r) {
        for (int b=0; b!=nb_bins; ++b) {
            bool filled = (nb_rows <= probs[b]*v_scale + r);
            printf("%c", filled ? ( r?'|':'+' ):(r+1==nb_rows?'_':' ') ) ;
        }
        printf("\n");
    }

    for (int b=0; b+2<=nb_bins; b+=6) {
        printf("  ^   ");
    }
    printf("\n");
    for (int b=0; b+2<=nb_bins; b+=6) {
        printf("%+-6.1f", ((b+2)/(float)nb_bins)*(h.hi-h.lo) + h.lo);
    }
    //printf("\n");

    printf("[ %+6.2f (%+6.2f) %+6.2f ]\n",
            quantile(&h, .1),
            quantile(&h, .5),
            quantile(&h, .9)
            );
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~  Model  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef struct {
    float part;
    float lean[nb_judges];
    float sens[nb_cases];
    float bias[nb_cases];
} state_t ;

float part_loss(float part)
{
    return laplace_loss(10., .1, part);
    //return laplace_loss(1., .1, part);
}

float indiv_sens_loss(float const* sens, int c)
{
    return laplace_loss(0., 1., sens[c]);
}

float indiv_bias_loss(float const* bias, int c)
{
    return laplace_loss(0., 1., bias[c]);
}

float sens_loss(float const* sens)
{
    float acc = 0.;
    for (int c=0; c!=nb_cases; ++c) { acc += indiv_sens_loss(sens, c); }
    return acc;
}

float bias_loss(float const* bias)
{
    float acc = 0.;
    for (int c=0; c!=nb_cases; ++c) { acc += indiv_sens_loss(bias, c); }
    return acc;
}

float indiv_lean_loss(float part, float const* lean, int j)
{
    //return laplace_loss(pres[j] * part, 1., lean[j]);
    return laplace_loss(pres[j] * part, .1, lean[j]);
    //return laplace_loss(0., .1, lean[j]);
}

float lean_loss(float part, float const* lean)
{
    float acc = 0.;
    for (int j=0; j!=nb_judges; ++j) { acc += indiv_lean_loss(part, lean, j); }
    return acc;
}

float indiv_vote_loss(float const* lean, float const* sens, float const* bias, int c, int j)
{ /* !assumes that vote[c][j] != ___ */
    //if ( vote[c][j] == ___ ) { return 0.; }
    float z = sens[c] * lean[j] + bias[c];
    return sigmoid_loss(z, vote[c][j]==YEA);
}

float vote_loss(float const* lean, float const* sens, float const* bias)
{
    float acc = 0.;
    for (int c=0; c!=nb_cases; ++c) {
        for (int j=0; j!=nb_judges; ++j) {
            if ( vote[c][j] == ___ ) { continue; }
            acc += indiv_vote_loss(lean, sens, bias, c, j);
        }
    }
    return acc;
}

float loss_on(state_t s)
{
    float acc = 0.;
    acc += part_loss(s.part);
    acc += sens_loss(s.sens);
    acc += bias_loss(s.bias);
    acc += lean_loss(s.part, s.lean);
    acc += vote_loss(s.lean, s.sens, s.bias);
    return acc;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~  Inference  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void init_state(state_t* next)
{
    next->part =  1.;//rand_cent(1.);
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

    PF("|  sens  ");  for (int c=0; c!= 2; ++c) { PF("%+5.2f  ", s->sens[c]); }
    PF("|  bias  ");  for (int c=0; c!= 2; ++c) { PF("%+5.2f  ", s->bias[c]); }
    PF("|  lean  ");  for (int j=0; j!=15; ++j) { PF("%+5.2f  ", s->lean[j]); }
    PF("\n");
}

float perturb(state_t* next)
{
    float noise_scale = 1.;//pow(.1, rand()%1);

    float loss_a, loss_b;
    int j,c;

    if (rand_unif() < 0.05) {
        loss_a = part_loss(next->part) +
                 lean_loss(next->part, next->lean);
        next->part += rand_cent( 1. * noise_scale );
        loss_b = part_loss(next->part) +
                 lean_loss(next->part, next->lean);
    } else if (rand_unif() < 0.4) {
        j = rand()%nb_judges;
        loss_a = indiv_lean_loss(next->part, next->lean, j);
        for (c=0; c!=nb_cases; ++c) {
            if ( vote[c][j] == ___ ) { continue; }
            loss_a += indiv_vote_loss(next->lean, next->sens, next->bias, c, j);
        }
        next->lean[j] += rand_cent( 1. * noise_scale );
        loss_b = indiv_lean_loss(next->part, next->lean, j);
        for (c=0; c!=nb_cases; ++c) {
            if ( vote[c][j] == ___ ) { continue; }
            loss_b += indiv_vote_loss(next->lean, next->sens, next->bias, c, j);
        }
    } else if (rand_unif() < 0.99) {
        c = rand()%nb_cases;
        loss_a = indiv_sens_loss(next->sens, c) +
                 indiv_bias_loss(next->bias, c)  ;
        for (j=0; j!=nb_judges; ++j) {
            if ( vote[c][j] == ___ ) { continue; }
            loss_a += indiv_vote_loss(next->lean, next->sens, next->bias, c, j);
        }
        next->sens[c] += rand_cent( 1. * noise_scale );
        next->bias[c] += rand_cent( 1. * noise_scale );
        loss_b = indiv_sens_loss(next->sens, c) +
                 indiv_bias_loss(next->bias, c)  ;
        for (j=0; j!=nb_judges; ++j) {
            if ( vote[c][j] == ___ ) { continue; }
            loss_b += indiv_vote_loss(next->lean, next->sens, next->bias, c, j);
        }
    } else {
        loss_a = loss_on(*next);
        next->part += rand_cent( .01 * noise_scale  );
        for (j=0; j!=nb_judges; ++j) {
            next->lean[j] += rand_cent( .1 * noise_scale );
        }
        for (c=0; c!=nb_cases; ++c) {
            next->sens[c] += rand_cent( .1 * noise_scale );
            next->bias[c] += rand_cent( .1 * noise_scale );
        }
        loss_b = loss_on(*next);
    }

    next->part = fabs(next->part);
    return loss_b-loss_a;
}

float propose_from(state_t const* s, state_t* next)
{
    copy_state(s, next);
    return perturb(next);
}

void mh_step(state_t* s)
{
    state_t next;
    float loss_diff = propose_from(s, &next);
    //float loss_diff = loss_on(next) - loss_on(*s);
    if ( loss_diff < -log(rand_unif()) ) {
        copy_state(&next, s);
        // TODO : obviate need for this double copy by pulling reversal code
        // into the proposal logic
    }
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~  Main Loop  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int main(int argc, char *argv[])
{
    int const E = 100000;
    int const T = 10*E;

    histogram_t h[nb_judges];
    float WIDTH = 1.5;
    for (int j=0; j!=nb_judges; ++j) { init_histo(&h[j], -WIDTH, +WIDTH); }

    histogram_t bb;
    init_histo(&bb, -3. , +3. );

    state_t s;
    init_state(&s);
    for (int t=0; t!=T; ++t) {
        if ( t%E == 0 ) { print_state(&s); }
        mh_step(&s);
        if ( t%10 ) { continue; }
        for (int j=0; j!=nb_judges; ++j) { update_histo(&h[j], s.lean[j]); }
        for (int c=0; c!=nb_cases ; ++c) { update_histo(&bb  , s.bias[c]); }
    }

    //print_histo(bb, 2.*nb_bins, 6.0*2.);
    //for (int j=0; j!=nb_judges; ++j) {
    for (int j=0; j!=15+0*nb_judges; ++j) {
        printf("%d\n",j);
        print_histo(h[j], 2.*nb_bins, 6.0*2.);
    }
    return 0;
}
