# Toward a More Perfect US Supreme Court

## Summary

### What's the proposal?

I'd like your critical feedback on the following proposed amendment to the US
Constitution.  It's about how we appoint judges to the Supreme Court.  I'm very
proud of it.  Here's the key extract (lightly edited):

    -- SUPREME COURT AMENDMENT --

    The Supreme Court of the United States shall have 10 seats.  A strict
    majority of votes shall determine the outcome of a case; but the most
    junior Justice may not vote except to break ties.

    On May 1st of each odd year, the most senior Justice shall retire.  These
    and other vacancies shall be filled within T=60 days as follows.
     (A) From among the judges of the Appellate Courts shall be identified the
         K=30 judges of most median seniority.  The Senate may interview them.
     (B) The Senate shall select from those K judges k=2 finalists as follows.
         (B.a) Randomly sequence the Senators (and announce this sequence).
         (B.b) Each Senator in sequence shall mark one of the K judges (and
               shall announce this choice to the Senators who follow).
         (B.c) The finalists shall be the k judges with the *fewest* marks.
     (C) The Senate shall privately interview those k finalists.
     (D) Each Senator shall vote for any subset of the k finalists.  The
         finalist with the most votes shall become the newest Justice.

Scroll way down for the full text.

### Why might one support the proposal?

Here are three quick highlights:

    ANTIPARTISAN --- A Senate with 61 Republicans will select a Justice who is
        ~61st percentile, not 99th percentile, on the "Democrat-Republican"
        axis.  The process favors the broadly inoffensive over
        popular-but-polarizing --- a boon to the Court's legitimacy.

    DECISIVE --- Vacancies will be filled without delay.  Indeed, the process
        forces the Senate to choose from a fixed list of candidates rather than
        to confirm individual nominees.  So the Senate has no option to
        continually reject nominees.

    REGULAR --- New justices periodically replace old justices, leading in
        effect to 20-year term limits.  Due to the most junior Justice, these
        transitions do not threaten to evenly divide and thus impair the Court.

### What's the rest of this document?

This post is primarily an advertisement for an amendment to the US
Constitution.  It may be a good time to discussion such amendments: the Supreme
Court's rulings this past decade have enraged both social conservatives and
social liberals, amplifying concerns about the reach of the courts and the
prospect of partisan court packing.  For the first time since the second World
War, members of recent US Congresses (116th, 117th) have formally introduced
Supreme Court amendments.

In its second role, this post is a diary of ideas for the design of
preference-aggregating procedures.  A democracy works (I hope!) when we
exchange ideas and learn from each other.  So here is my contribution.  Though
in my excitement I write as an advocate, I do try to note the gaps and main
uncertainties in my thought.  I'd be pleased to read your thoughts, including
questioning of my premises or value judgements and including insights from
those of you residing outside the US.

##### _TABLE OF CONTENTS_

    Summary
        What's the proposal?
        Why might one support the proposal?
        What's the rest of this document?
        What might I count as a "fix"?
    Toward Decisive Designs
        Stalling
        Decisive procedures; application to the Supreme Court
        Bonus thought on filibusters
        Bonus thought on budgeting
    Toward Antipartisan Designs
        Gerrymandering
        Tension and balance
        Hot potatoes
        Bonus thought on House elections
    Toward Regular Designs
        Term limits and backups
        Presidential influence
        Transient stage
        Parameter tuning
    Appendices
        Related ideas
        Agreeing on randomness
        Analysis of judge data
        Full text

##### _...AREN'T YOU FORGETTING XYZ?  OR, THIS SOUNDS LIKE ABC..._

I probably am / it probably does.  Please comment to teach me!

Note that I list this proposal's full text and discuss related ideas below
(scroll way down).  The full text explains what "most median seniority" means,
that the Vice President breaks ties, how Congress may alter the mentioned
numeric parameters, how the judiciary shall gradually transition upon the
amendment's ratification, and more.

### Would this proposal "fix" the judiciary?

I don't know.

That's why I used the weasel word "toward" in the title.

I devised this amendment mostly on aesthetic grounds; I have no firm argument
that this system "is better for democracy" or "leads to wiser rulings" or
"threatens fewer constitutional crises" than the current system.

##### _WHAT MIGHT I COUNT AS A "FIX"?_

That said, my aesthetic sense is one disturbed by two specific problems I
perceive in the current appointment process:
    (A) unpredictable, election-dominating political hurricanes whenever a
        Justice dies; and
    (B) (apparent) partisanship and thus an erosion of the Court's legitimacy.
A more stable, more obviously nonpartisan system would strike me as more
beautiful.  I believe certain perverse incentives contribute as root causes to
these two problems.  Within simplified models of voting behavior that I
describe below, the new way materially weakens these incentives.  IF those
"problems" are actually so AND I correctly identified some of their root causes
AND the mentioned models are adequately robust THEN the amendment is a
promising step toward my desired, more beautiful judiciary.

Note this personality quirk of mine: I regard "bipartisan" as far from
"nonpartisan", especially when the "bi" refers to a specific party system such
as the US's current one.  Parties are extra-constitutional organizations that,
though regulated, are in essence private.  So I find any canonization of
parties in law quite ugly.  Imagine if we amended Congress's enumerated
power-to-establish-post-offices by explicitly mentioning Fedex and Amazon!

I thus dislike ideas such as that popularized by Buttigieg (to mandate 5
"Republican" and 5 "Democratic" justices on a reformed Supreme Court).  This
might be a key way that your and my notions of "fix" diverge.

 TODO: aesthetic sense about "dry, hard wall of consttitution"

These thoughts guide the design considerations we discuss in the next three
sections.

## Toward Decisive Designs

### Stalling

Legislators "stall" in many ways.  For example, Senators (perhaps in
anticipation of an upcoming presidential election) may reject a technically
excellent Supreme Court nominee, causing a long vacancy in that Court.  Members
of either Chamber may engage in partisan deadlock, stranding federal
bureaucracies without a clear budget.  State legislators (perhaps to avoid the
acute unpopularity of a "no" vote) may fail ever to schedule a vote on a
proposed amendment, leaving the latter's ratification open for decades.

Such stalling leads to:

    (A) more time to deliberate towards a wise choice
    (B) irregular disruptions to regular governance
    (C) vast power for those who control procedure

### Decisive procedures; application to the Supreme Court

To prevent stalling, we ought to adopt decision making procedures that
necessarily terminate with a reasonable decision, i.e., with an answer to the
fundamental question we intend the procedure to address.  Call such procedures
*decisive*.

For ratification of amendments, the question is *should this amendment become
supreme law?* and the possible answers are `yes` or `no`; to get a decisive
ratification procedure, we may simply impose a time limit.

For appointment of Justices, the question might seem to be *should this
particular nominee join the Court?* --- but I regard that as an
implementation-specific sub-question of this more fundamental question: *who
should join the Court?*.  Majority voting to confirm a particular nominee, even
with a time limit, fails to be a decisive procedure, since the Senate might
keep rejecting nominees as its members play a game of chicken, each Senator
unwilling to budge in the face of the time limit.

I propose instead to revise the Court-filling procedure into something like an
election so that certainly *someone* will win:

    WHITTLING PROCEDURE.

        This procedure narrows a list of K candidates to size k.  To make it
        work, we require Senators to outnumber candidates.  (A minor variant,
        where we allow each Senator multiple marks, allows candidates to
        outnumber Senators).

    (A) Randomly sequence the Senators.  Publicly announce this sequence.
    (B) According to that sequence: each Senator in turn marks one candidate.
    (C) Select the k candidates with the *fewest* marks, letting VP break ties.

For example, letting `K=179` count the seats of the United States Appellate
Courts, we could use Whittling to select `k=1` finalist as our new Justice.
But, for practicality and other reasons discussed in subsequent sections, we
prefer `K=30` and `k=2`.

Is `K=30` impractically many candidates to consider?  I find it orienting to
recall that Senators in principle read thousands of pages per year in close
detail --- but that in practice their aids and their party leadership share
this burden.  I think that compiling and contemplating dossiers on the
characters, experiences, and jurisprudential philosophies of each of `K=30`
judges is a much lesser burden.

With `k=2`, the Senate may closely interview and decide between multiple
finalists, thus allowing recovery even if a totally unqualified candidate slips
through.  It could be that *multiple* finalists are totally unqualified; but if
these finalists --- in a sense the least objectionable `7%`(=2/30) of a
representative sample of the highest ranking `21%`(=179/861) of the country's
non-Justice judges --- harbor multiple incompetent judges, then we have bigger
problems to worry about.

We implement the preceding three paragraphs like this:

    APPROVE-AFTER-WHITTLING PROCEDURE.

        This procedure fills a vacancy on the Supreme Court.  It shall conclude
        at most T=60 days after a vacancy arises.

    (A) Select from the judges on the Appellate courts those K=30 judges of the
        most median seniority, not counting those who opt out.
    (B) Narrow that list to k=2 finalists via the Whittling Procedure.
    (C) Senators thoroughly interview those k=2 finalists.
    (D) Each Senator votes for any subset of the k=2 finalists.  The finalist
        with the most votes becomes the newest Justice.

    Note: for step (A), we count vacant seats as most junior when ranking by
    seniority.  Otherwise, the President or setters of the Senate's schedule
    might influence the result by choosing how many judges to confirm shortly
    before step (A) begins.  Likewise, whether or not a judge opts out shall
    not change the numeric ranks given to the other judges.

In step (D) we use "approval voting" instead of "plurality voting" so as to
avoid third-candidate spoiler effects.  This consideration is relevant only
when `k>=3`.

### Bonus thought on filibusters

Above, we shifted our view about the fundamental question a SCOTUS appointment
procedure ought to answer.  This shift helped us craft a decisive procedure.
We now treat filibusters in the same spirit.

What do filibusters do?  They attempt to answer the question, *is opposition to
this bill so intense as to merit overriding a thin majority of yeas?*.
However, the actual filibuster process weighs merely *apparent* intensity.  We
want inistead to elicit truthful, calibrated estimates of earnestly felt
intensity.  So let's revise the implementation question to *among this palette
of bills, which few bills have opposition so intense as to merit overriding a
thin majority of yeas?*  This suggests a system that allots to each Senator a
limited budget of "filibuster tokens"; the Senator must choose wisely which
votes to use them on: once used, a token disappears.  In this way we *allow but
penalize* extremism.

As a matter of calibration, we let each token amplify a vote --- say, from
counting as one "yea" or "nay" to two --- rather than obstruct a majority
entirely.  Gangs of Senators would have to spend multiple tokens to obstruct
anything but a nearly-tied majority.

    WEIGHTED VOTE PROCEDURE

    (A) Each elected Senator receives T=2 tokens at the start of their 6-year
        term.  This does not apply to Senators appointed to fill a vacancy.  A
        Senator's tokens expire at the end of their 6-year term.

    (B) A "weighted vote" occurs as follows.  Each Senator who holds at least
        one token may choose to "amplify their vote".  Doing so decreases the
        number of tokens they hold by one; it also promotes their vote to count
        as w=2 votes.  The outcome is determined by whether weighted yeas
        outnumber weighted nays.  The Vice President breaks ties.

    Tokens spent on vetoed legislation are not returned.

Now, what new behaviors might this "token system" incentivize?  For example,
what if a thin majority rudely introduces replicas of an obstructed bill,
depleting the opposition's tokens until they can no longer afford to obstruct?
The *threatened* passage of a thin-majority bills is itself something to do
only sparingly.  So let's make that cost tokens, too:

    SENATE VOTING PROCEDURE

        This procedure decides on a bill.  No bill shall pass to the
        President's desk without having been passed by the House and
        *afterward* by this procedure.  This procedure does not apply to the
        Senate's extraordinary activities such as advice-and-consent,
        impeachment trials, veto overrides, constitutional amendments,
        admission of States to the Union, etc.

    (A) The Senators vote with simple yeas and nays.  Should nays outnumber
        yeas, the bill fails.  The Vice President breaks ties.
    (B) Should the bill pass step (A), any f=(2/5)ths of Senators may, by
        spending tokens, initiate a "neofilibuster".  Here's what happens:
        (B.a) The objectors initiate by spending O=2(**) tokens in sum.
        (B.b) The supporters may choose to spend S=3(**) tokens in sum;
              unless they do so, the bill fails.
        (B.c) After d=7(**) days of deliberation shall promptly follow...
        (B.d) ...the Weighted Vote Procedure to determine passage of the bill.
    (C) If no "neofilibuster" occurs, the bill passes.

    The Congress may by a 3/5s unweighted majority in each Chamber, subject to
    the ordinary veto and veto-override procedures, alter the parameters O,S,d
    marked above by (**).

    Note the relation S/(O+S) = 3/5.

The Weighted Voting Procedure is a simplified or "truncated" form of "quadratic
voting".  In certain extreme cases (if there is a large, fixed menu of bills
and if each Senator is substantively uncertain about the other Senators'
preferences, and if these uncertainties are uncorrelated and symmetric with
respect to both bills and Senators), quadratic voting maximizes utility while
our truncated version doesn't.  But those extreme cases do not plausibly model
the Senate.

### Bonus thought on budgeting

Likewise, one decisive procedure for crafting a budget is to ask not *is this
 proposed budget acceptable?* but instead *is the current allocation for this
budget item too low or too high?*.  Here's a sketch of such a procedure (we
focus on the House since that chamber originates revenue bills and by
convention also appropriations bills):

    (sketch of) BINARY BUDGETING PROCEDURE

        This procedure results in a budget, that is, a list of items to fund,
        each annotated with the dollar amount allotted and with rules for how
        the funds may be spent.  I imagine it as augmenting House Rules, not
        the US Constitution.

    (A) The House decides on a coarse-grained menu of, say, 1000 items to fund.
        Items might be executive departments, tax cuts, specific programs, etc.
    (B) Determine for each item a ceiling $X for that item's allocation:
        (B.a) Tentatively set each item's ceiling to 1 dollar.
        (B.b) Each Representative specifies for each item whether that item's
              current ceiling is high enough.
        (B.c) For each item: unless 3/5ths of (B.b)'s votes are yeas, multiply
              X by 10.  If any item's ceiling increased: repeat (B.b), (B.c).
    (C) The House REPEATEDLY refines each item's allocation intervals like so:
        (C.a) Each item begins with a tentative allocation interval [$0, $X].
        (C.b) Each Representative specifies for each item whether the current
              allocation interval leans high or leans low.
        (C.c) Accordingly refine the interval [L,H] to [L,H-S] or [L+S,H].
              here, S=(H-L) is the interval half-width.
        (C.d) Repeat (C.b, C.c), say, 30 times total.
        (C.e) Allocate to each item with interval [L,H] the midpoint (L+H)/2.
    (D) Representatives may propose revisions to the allocations, revisions
        that must be promptly voted on.  Revisions that merely specify
        fine-grained constraints within a menu item are accepted when a simple
        majority concurs.  Other revisions require a (3/5)ths majority.  At the
        end of 60 days, the allocation passes the House.

One may adapt the above into a decisive procedure involving both Chambers.

     - - - - - - - - - - - - - - - - - - - -

## Toward Antipartisan Designs

### Gerrymandering

I understand **gerrymandering** as the failure of (linearity and hence)
associativity of the "majority operation".  To say that "most rows of a
chessboard each have most of their cells occupied" is quite different from
saying that "most of the board's cells are occupied".  Just imagine a 5-by-5
region!  Gerrymandering appears in government when decisions are made by
majorities of majorities.(\*\*)  For example, it is a majority of Electors that
chooses the President; each Elector follows their state's popular majority.
Or, to swap time for space: it is a majority of Justices that decides a case
before the Supreme Court; each Justice (usually) aligns with their appointing
President and thus with a majority of some past Electoral College.
Gerrymandering can feel especially obnoxious when the "parentheses" around the
inner majorities are set politically --- thus it was the strategic shaping of
House districts that gave us the word `gerrymander`.

##### _WHEN DO WE WANT GERRYMANDERING?_

Here are two examples where such a winner-takes-all intermediate step may make
sense: we do not give a greater vote to those people with more brain cells.
Nor does the UN give a greater vote to more populous member states.  These
examples take as their atomic units of experience (to which they give equal
weight) the person or the state rather than the neuron or the person.  On the
other hand, one may dismiss those two examples: the first, as treating systems
(brains) radically more coordinated than human populations; the second, as an
artifact of compromise rather than a long-term optimum.

When we vote in order to aggregate *beliefs* and when each larger unit
agglomerates *correlated* smaller units, then we may aggregate more accurately
by weighing larger units equally.  But when we vote in order to aggregate
*preferences* then it may be more natural to give equal weight to whichever
unit we regard as experiencing utility (usually, the person).(\*\*\*\*)

(\*\*) compare with median-of-medians selection.

(\*\*\*\*) I'd need to stretch in this latter case to justify giving equal
weights instead to groups of people --- perhaps having one's preference
violated feels less bad if most of one's neighbors hold opposing preferences
(bounded-radius empathy); or perhaps there is less risk of violent rebellion or
unchecked resentment when a policy's supporters spread evenly throughout all
regions rather than concentrating in some far-away "capital of empire".

### Tension and balance

To reduce gerrymandering, we want to look beyond majority operations.  I think
of this as *keeping the tension* so that the choices of an individual in a
minority counts despite a clear majority.

### Hot potatoes

CONTINUITY (vs "gerrymander")


We may partially mitigate this sensitivity to sequencing by scheduling multiple
passes through the sequence of Senators so that each Senator ends up marking,
say, thrice.  I did not include this in the proposal's text since it seems
complicated and I have not convinced myself of its substantive value.

##### _BIAS-VARIANCE "GERRYMANDERING"_

Here's a weakness of the proposal.  Consider a (not implausibly) partisan
political atmosphere whose every appointee to the Appellate Courts is "very
red" or "very blue".  FILLIN TODO

### Bonus thought on House Elections

Randomness helps against such gerrymandering

 FILLIN TODO --- randomized house idea

## Toward Regular Designs

Is the 10th Justice packing?

### Term limits and backups

    REVOLVING DOOR PROCEDURE.

        This procedure maintains a queue of 10 Supreme Court Justices.  The
        most junior Justice hears cases, deliberates, and may write opinions;
        but they may not vote except to break ties.  The most junior Justice
        thus votes only in the event of a vacancy or recusal.

    (A) On May 1 of each odd year, the most senior Justice retires.
    (B) Whenever a vacancy arises, including by step (A), fill that vacancy via
        the Approve-after-Whittling Procedure.

### Presidential influence

The amendment strips the President of immediate influence over Supreme Court
appointments.  However, each President strongly affects future Supreme Court
appointments through their appointments to the Appellate Courts.  This counters
the risk that the Supreme Court gets packed with Justices whose rulings favor
an expansively powerful Senate and a limited, vestigial Presidency.

Here are statistics to refine our sense of scale.  Typical presidents each year
rotate about `4%` to `8%` of the Appellate Courts' seats.  Here are the postwar
presidents together with their number of appointments to the appeals courts.

    ~~~ TABLE ~~~

                ~years  appointees :    chance/yr   rotations :    chance/yr
                office  number seats    seat reset  number seats   rotate
    Truman        8       27: 65           5%         24: 65          5%
    Eisenhower    8       45: 68           8%         44: 68          8%
    Kennedy       3       20: 78           9%         20: 78          9%
    Johnson       5       41: 97           9%         32: 97          7%
    Nixon         6       45: 97           8%         45: 97          8%
    Ford          2       12: 97           6%         12: 97          6%
    Carter        4       56:132 (*)      11%         39:132          7%
    Reagan        8       83:168           6%         65:168          5%
    Bush Sr.      4       42:179           6%         37:179          5%
    Clinton       8       66:179           5%         66:179          5%
    Bush Jr.      8       63:179           4%         63:179          4%
    Obama         8       55:179           4%         55:179          4%
    Trump         4       54:179           8%         54:179          8%
    Biden         2       11:179           3%         11:179          3%

    (*) I think it was this expansion of the courts, undiluted by a double
        term, that allowed Carter to reset so many seats per year of his term.

    Note: by the number of `rotations` we mean the number of appointees minus
          *half* of the seat expansion during the term.  This helps us discount
          for the effect of court expansion.

    Note: we sum 12 regional appeals courts with the federal appeals court;
          and to count seats we use the president's end of term.  There may
          be off-by-one errors in this end-of-term seat-number timing.

    Note: presidents may fill the same seat multiple times.  TODO!

[history of seat number](https://www.uscourts.gov/file/19476/download)
[presidential appointments](https://www.uscourts.gov/file/21619/download)

(TODO : consider practical allowances for appeals courts expansion?)

Thus, we might expect presidents to rotate between 16% and 64% of the seats.
All listed presidents (except Biden) have appointed between 12% and 64%.

Does this give some one former President too much lasting power?  If they
happen to have been the appointer of almost all the K=30 median seniority
judges?

Vacant seats count as most junior.  Judges may opt out, in which case their
seats still count according to their seniority.

### Transient stage

### Parameter tuning

Congress may expand the courts (to relieve ever-growing case burdens).  Such
changes of parameters lie somewhere between a Constitutional Amendment and
ordinary law.  So let's use an intermediate criterion for passage:

    The Congress may by a 3/5ths unweighted majority in each Chamber, subject
    to the ordinary veto and veto-override procedures, alter the following
    numeric parameters: T, K, k, N, ...

We use `3/5` instead of `1/2` so as not to tempt a thin majority toward packing
the Appellate Courts and thus toward shifting future Supreme Court
appointments.  We further counter this temptation by adding a time delay:

    When appointing Justices to the Supreme Court: each additional seat on the
    Appellate Courts shall, 12 years after its addition and no earlier, be
    considered in seniority computations and be eligible for inclusion in lists
    of candidates.

## Appendices

### Related ideas

Note: we refer below to some recent congressional activity.  For this purpose,
`X.Y.N` stands for "item number `N` of kind `Y` in the `X`th congress" found at
`www.congress.gov/bill/Xth-congress/Y/N`.  For example, `116.house-bill.8424`
stands for "item number `8424` of kind `house-bill` in the `116`th congress"
found at `www.congress.gov/bill/116th-congress/house-bill/8424`

##### _TERM LIMITS, SCHEDULED APPOINTMENTS, SENIORITY QUEUES_

 TODO: comment on supreme court regularity act

**To establish 18 year term limits and a seniority-based queue**:
[116.house-bill.8424 ](www.congress.gov/bill/116th-congress/house-bill/8424 );
[117.house-bill.5140 ](www.congress.gov/bill/117th-congress/house-bill/5140 );
[117.house-bill.8500 ](www.congress.gov/bill/117th-congress/house-bill/8500 );
[117.senate-bill.4706](www.congress.gov/bill/117th-congress/senate-bill/4706);

 TODO: comment on

harvardlawreview.org/2021/05/the-future-of-supreme-court-reform
fixthecourt.com/fix/term-limits
fixthecourt.com/2020/09/tl-statute
fixthecourt.com/wp-content/uploads/2022/07/FTCA-7.5.22.pdf
americanprogress.org/article/need-supreme-court-term-limits
nytimes.com/2018/09/18/opinion/columnists/brett-kavanaugh-supreme-court-term-limits
scotustermlimits.org/

### Related Ideas : For and Against Expanding the Court

Is the 10th Justice packing?

**To expand the Supreme Court to 13 seats**
[117.house-bill.2584 ](www.congress.gov/bill/117th-congress/house-bill/2584 );
[117.senate-bill.1141](www.congress.gov/bill/117th-congress/senate-bill/1141);

**To fix the Supreme Court to 9 seats**
[117.house-joint-resolution.11](www.congress.gov/bill/117th-congress/house-joint-resolution/11);
[117.house-joint-resolution.39](www.congress.gov/bill/117th-congress/house-joint-resolution/39);
[117.house-joint-resolution.40](www.congress.gov/bill/117th-congress/house-joint-resolution/40);
[117.house-resolution.351     ](www.congress.gov/bill/117th-congress/house-resolution/351     );
[117.senate-bill.461          ](www.congress.gov/bill/117th-congress/senate-bill/461          );
[117.senate-joint-resolution.4](www.congress.gov/bill/117th-congress/senate-joint-resolution/4);
[117.senate-joint-resolution.9](www.congress.gov/bill/117th-congress/senate-joint-resolution/9);

 TODO: comment on buttigieg court packing
theatlantic.com/ideas/archive/2019/06/buttigiegs-supreme-court-plan-and-democratic-party/590905
yalelawjournal.org/feature/how-to-save-the-supreme-court

##### _STRUCTURE OF FOREIGN COURTS OF LAST RESORT_

 TODO: comment on how they do it in Taiwan, Uruguay, India, Mauritius, Norway.

### Agreeing on Randomness

##### _A RANDOMNESS GENERATION PROCEDURE_

We saw in "Hot potatoes" that Supreme Court appointment outcomes depend subtly
on how we sequence Senators.  So we want to sequence Senators in a fair, random
manner.  Mere coin tosses won't do, since they'd require us to trust blindly
that the tosser didn't use a trick coin or sleight-of-hand.  The process should
be not only fair but *verifiably* so.

Here's an elegant way to meet these goals.  This method relies on three
trust-enhancing tools: a "hash function", a clear plastic box, and trusted live
television.  The method results in a "heads" or "tails" that all involved
parties have compelling reason to regard as random.

Actually, let's simulate 1000 coin tosses, not just 1.  That's enough to inform
random choices such as a sequencing of Senators.  We write **seq** as shorthand
for *a sequence of 1000 binary digits*.  Seqs are small enough for us humans to
manipulate them manually --- we may represent a seq as a 15-by-15 grid of
letters A-Z --- yet long enough to stand secure against quantum Grover attacks.

    HOW TO FLIP A COIN FAIRLY
    "The many-handed coin flip"

        This procedure generates a seq, to be regarded as a completely random
        seq, by aggregating seqs from concerned parties (say, Senators).

    (A) Each Senator k:
        (A.a) privately chooses a "private seq" (call it s(k))
        (A.b) computes their "public seq" h(s(k))
        (A.c) publicizes a value y(k), which they swear to be their public seq
    (B) The Senators assemble to reveal their seqs on live television:
        (B.a) Each brings a piece of paper, folded so as to hide its contents,
              on which is drawn their name k and a seq p(k) that they swear to
              match their private sequence.
        (B.b) The Senators commit their piece of paper to a clear plastic box.
        (B.c) Each paper is taken out, unfolded, and its contents televised.
    (C) Each Senator's p(k) is verified to obey the relation h(p(k)) = y(k).
        Senators for whom this relation fails are reprimanded.
    (D) Sum all the verified p(k)'s to get the overall "random" seq.

##### _WHY NOT A SIMPLER PROCEDURE?_

Steps (A,C,D) alone form a randomness generation procedure.  More precisely, we
might replace step (B) by:
    (B') Each Senator in sequence publicly announces some seq p(k).  They swear
         that p(k) matches their private seq s(k)
However, this gives undue power to the last Senator in the sequence, since they
may choose whether or not to truthfully reveal s(k) based on their knowledge of
the previous Senators' announcements and thus how either choice would determine
the resulting "random" seq.  The point of (B) is to force all choices of
whether to be truthful to come *before* the private seqs s(k) are announced.

Steps (B,D) alone form a randomness generation procedure.  More precisely, we
might replace steps (A,C) respectively by:
    (A') Each Senator k: privately chooses a "private seq"
    (C') do nothing
However, this variant procedure is harder to verify because it can offer no
evidence to counter a Senator's false post-hoc claim (perhaps asserted in light
of an unfavorable result) that the step (B) videostream had been corrupted.  By
contrast, the full procedure (A,B,C,D) publicly broadcasts pairs (y(k),p(k))
whose first elements y(k) each Senator individually controls and against which
folks at home may check the second elements p(k).

Overall, this method for generating randomness relies on some-but-not-much
respect for procedure.  Perhaps as much respect as Senators must have during
the pro forma tallying of presidential electoral votes.  There is no space for
"softly" bad faith actions (e.g. for strategic interpretations of procedure).

Computers can easily do all computations involved.  So in practice each Senator
may delegate their role to trusted computer-savvy clerks.

##### _ASSUMPTIONS AND GUARANTEES_

Our procedure is "fair" unless all senators "conspire".  Here's what I mean
precisely.  Let's adopt some fixed Senator k's point of view.  During the
QUASI-COIN procedure they choose values for s(k),p(k),y(k).  Each choice may
depend on publically announced knowledge, their private knowledge (of their own
previous choices), and potentially some private knowledge of other Senators
with which they conspire.  Each Senator

 FILLIN

is: IF at least one Senator would benefit from the resulting seq being
completely random rather than whatever it would be were the other Senators to
have their way, then the resulting seq will indeed be completely random.

We rely on these properties of "hashing":

    -- Each seq S has exactly one hash H=h(S).
    -- H is easy to compute from S.
    -- It is intractably hard to construct given H a seq whose hash equals H.
       For instance, S is intractably hard to compute from H.

 FILLIN

##### _ROBUSTNESS TO CONSPIRACY_

(These reasons stem from a careful pitting of privacy against transparency.  I
think of a tensegrity sculpture.)

 FILLIN
 TODO : sketch proof

### Analysis of judge data

##### _BAYESIAN MODEL OF JUDGE ALIGNMENT_
##### _INFERENCE METHODS_
##### _SOURCES AND PREPARATION OF DATA_

##### _SIMULATING THE WHITTLING METHOD_

### Full text

##### _I.  THE SUPREME COURT_

    I.i

    The Supreme Court of the United States shall have 10 Justices.  A strict
    majority of votes shall determine the outcome of a case; but the most
    junior Justice may not vote except to break ties.

    I.ii

    On May 1st of each odd year, the most senior Justice shall retire.

    I.iii

    Those and other vacancies shall be filled within D=60(**) days as follows:

    (A) The K=30(**) judges of most median seniority, shall, by the following
        methods, be identified from among the judges of the Appellate Courts:
        (A.a) Each judge shall be allowed to opt out.
        (A.b) Seniorities shall be computed as follows.  A judge has seniority
              s when that judge has not opted out AND there are s many judges,
              including those who opted out, whose date of confirmation
              coincides with or precedes that of the judge in question.
        (A.c) The K candidates shall be the judges who have seniority closest
              to N/2.  Here, N counts the Appellate Courts' seats.
    (B) From those K candidates shall be selected k=2(**) finalists as follows:
        (B.a) The Senate may interview these candidates.
        (B.b) The Senate shall, in uniformly random manner, sequence its
              Senators and shall make this sequence known to all Senators.
        (B.c) Each Senator in sequence shall mark one of the K candidates
              and shall make their choice known to the Senators who follow.
        (B.d) The finalists shall be the k candidates with the fewest marks.
    (C) The Senate shall privately interview those k finalists.
    (D) Each Senator shall vote for any subset of the k finalists.  The
        finalist with the most votes shall become the newest Justice.

    At each applicable step (A.c, B.d, D), the Vice President shall break ties.

    Should fewer than K judges remain after step (A.a), then in place of steps
    (A.b, A.c), the President shall nominate additional qualified persons so as
    to yield K candidates total.

    Should a judge have been confirmed multiple times to the Appellate Courts,
    the date of confirmation used in (A.b) shall be the most recent one.

##### _II.  THE APPELLATE COURTS_

    II.i

    The Appellate Courts of the United States shall have N=179(**) seats.
    Congress may expand these Courts as described below; each additional seat
    shall count toward I.iii's procedure W=12(**) years after its addition and
    no earlier.  And seats resolved by Congress to be removed shall be removed
    no earlier than W years after Congress so resolves.

    Judges of the Appellate Courts shall be appointed by the President, with
    the consent of a simple unweighted majority of the Senate, to fill
    vacancies as they arise.  The Senate shall vote on one nominee at a time.

    II.ii

    No one shall serve more than T=20(**) years as a judge of the Appellate
    Courts.

##### _III.  TRANSITION AND TUNING_

    III.i

    Upon Ratification of this Amendment, sections I.i, II, and III shall take
    immediate effect.  However, section I.ii shall take effect 8 years after
    Ratification and no earlier.  And section I.iii shall take effect
    12 years after Ratification and no earlier.

    Moreover, II.ii shall be understood not to count years served before
    Ratification of this Amendment.

    III.ii

    The Congress may by a 3/5s unweighted majority in each Chamber, subject to
    the ordinary veto and veto-override procedures, alter the parameters D, K,
    k, N, W, T marked above by (**).
