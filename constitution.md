# Toward a More Perfect US Supreme Court

## Summary

### What's the proposal?

I'd like your critical feedback on the following proposed amendment to the US
Constitution.  It's about the structure of and appointment process for the
Supreme Court.  I'm very proud of it.  Here's the key extract (lightly edited):

    -- SUPREME COURT AMENDMENT --

    The Supreme Court of the United States shall have 10 seats.  A strict
    majority of votes shall determine the outcome of a case; but the most
    junior Justice may not vote except to break ties.

    On May 1st of each odd year, the most senior Justice shall retire.  These
    and other vacancies shall be filled within T=60 days as follows.
     (A) From among the judges of the Appellate Courts shall be identified the
         K=30 judges of most median seniority.  The Senate may interview them.
     (B) The Senate shall select from those K judges k=2 finalists as follows.
         (B.a) Randomly sequence the Senators and announce this sequence.
         (B.b) Each Senator in sequence shall mark one of the K judges (and
               shall announce this choice to the Senators who follow).
         (B.c) The finalists shall be the k judges with the *fewest* marks.
     (C) The Senate shall privately interview those k finalists.
     (D) Each Senator shall vote for any subset of the k finalists.  The
         finalist with the most votes shall become the newest Justice.

Scroll way down for the full text.

### Why might I support the proposal?

Here are three quick highlights:

    ANTIPARTISAN --- A Senate with 61 Republicans will lead to a Justice who is
        ~61st percentile on the "Democrat-Republican" axis.  The process favors
        the broadly inoffensive over the popular-but-polarizing --- a boon for
        the Court's legitimacy.

    DECISIVE --- Vacancies will be filled without delay.  Indeed, the process
        forces the Senate to choose from a fixed list of candidates rather than
        to confirm individual nominees.  So the Senate has no option to
        continually reject nominees.

    REGULAR --- New justices periodically replace old justices, leading in
        effect to 20-year term limits.  Due to the most junior Justice, these
        transitions do not threaten to evenly divide and thus impair the Court.

### ...aren't you forgetting XYZ?  Or, this sounds like ABC...

I probably am / it probably does.  Please comment to teach me!

Note that I list this proposal's full text and discuss related ideas below
(scroll way down).  The full text explains what "most median seniority"
means, that the Vice President breaks ties, how Congress may alter the
mentioned numeric parameters, how the judiciary shall gradually transition upon
the amendment's ratification, and more.

### Would this proposal "fix" the judiciary?

I don't know.

That's why I used the weasel word "toward" in the title.

I devised this amendment mostly on aesthetic grounds; I have no firm argument
that this system "is better for democracy" or "leads to wiser rulings" or
"threatens fewer constitutional crises" than the current system.

### What might I count as a "fix"?

That said, my aesthetic sense is one disturbed by two specific problems I
perceive in the current appointment process:
    (A) unpredictable, election-dominating political hurricanes whenever a
        Justice dies; and
    (B) (apparent) partisanship and, with it, the Court's eroding legitimacy.
A more stable, more obviously nonpartisan system would strike me as more
beautiful.  Within simplified models of voting behavior that I describe below,
the new way mitigates some perverse incentives that I believe comprise some of
the root causes of those two problems.  IF those "problems" are actually so AND
I correctly identified some of their root causes AND the mentioned models are
adequately robust THEN the amendment is a promising step toward my desired,
more beautiful judiciary.

Note that, due to a quirk of my personality, I regard "bipartisan" as far from
"nonpartisan", especially when the "bi" refers to a specific party system such
as the US's current one.  Parties are extra-constitutional organizations that,
though regulated, are in essence private.  So I find any canonization of
parties in law quite ugly.  Imagine if we amended Congress's enumerated power
to establish post offices to explicitly mention Fedex and Amazon!

I thus dislike ideas such as that popularized by Buttigieg (to mandate 5
"republican" and 5 "democratic" justices on a reformed Supreme Court).  This
preference of mine might be a key way that what you and what I count as "fixes"
diverge; in any case, it guides the design considerations below.

 TODO: aesthetic sense about "dry, hard wall of consttitution" 


## Design Considerations: Decisive Designs

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
ratification procedure, we need only impose a time limit.

For appointment of Justices, the question might seem to be *should this
particular nominee join the Court?* --- but I regard that as an
implementation-specific sub-question of this more fundamental question: *who
should join the Court?*.  Now majority voting to confirm a particular nominee,
even with a time limit, is not a procedure, since the Senate might keep
rejecting nominees as its members play a game of chicken, each Senator
unwilling to budge in the face of the time limit.  Instead, I propose to revise
the Court-filling procedure into something of an election so that certainly
*someone* will win:

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
But, for interviewing practicality and for other reasons discussed in sections
below, we prefer `K=30` and `k=2`.

For a sense of scale, recall that Senators in principle read thousands of pages
per year in close detail --- but that in practice their aids and the organs of
their party leadership share this burden.  I think that compiling and
contemplating dossiers on the characters, experiences, and jurisprudential
philosophies of each of `K=30` judges is a much lesser burden.

Setting `k=2` allows the Senate to closely interview and decide between
multiple finalists, thus allowing recovery even if one totally unqualified
candidate slips through.  It could be that *multiple* finalists are totally
unqualified; but if these finalists --- the least objectionable `7%`(=2/30) of
a representative sample of the highest ranking `21%`(=179/861) of the country's
non-Justice judges --- harbor multiple incompetent judges, then we have bigger
problems to worry about.

We implement the preceding three paragraphs like this:

    WHITTLE-THEN-APPROVE PROCEDURE.

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

### Bonus application to filibusters

What do filibusters do?  They attempt to answer the question, *is opposition to
this bill so intense as to merit overriding a thin majority of yeas?*.
However, the implementation does this only for apparent intensity.  Our
challenge is to elicit truthful, calibrated estimates of earnestly felt
intensity.  In the same spirit as the shift-in-view we applied to Supreme Court
appointments, we might revise the implementation question to *out of this
palette of bills, which few have opposition so intense as to merit overriding a
thin majority of yeas?* This suggests a system that allots to each Senator a
limited budget of "filibuster tokens"; the Senator must choose wisely which
votes to use them on: once used, a token disappears.  In this way we *allow
but penalize* extremism.

It makes sense as a practical matter to let each token amplify a vote --- say,
from counting as one "yea" or "nay" to two --- rather than obstruct a majority
entirely.  Gangs of Senators would have to spend multiple tokens to obstruct a
thin-but-not-razor-thin majority.

More importantly, we should consider what new behaviors this "token system"
incentivizes.  For example, what if a thin majority rudely introduces replicas
of an obstructed bill, depleting the opposition's tokens until they can no
longer afford to obstruct?  The *threatened* passage of a thin-majority bills
is itself an action that ought to be done sparingly.  So let's make that cost
tokens, too.

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



    SENATE VOTING PROCEDURE

        This procedure decides on a bill.  No bill shall pass to the
        President's desk without having been passed by the House and
        *afterward* by this procedure.  But this procedure does not apply to
        the Senate's extraordinary activities such as advice-and-consent,
        impeachment trials, veto overrides, constitutional amendments,
        admission of States to the Union, etc.

    (A) The Senators vote with simple yeas and nays.  Should nays outnumber
        yeas, the bill fails.  The Vice President breaks ties.
    (B) Should the bill pass step (A), any f=(2/5)ths may, by spending tokens,
        initiate a "neofilibuster".  Here's what happens:
        (B.a) The objectors initiate by spending O=2(**) tokens in sum.
        (B.b) The supporters may choose to spend S=3(**) tokens in sum;
              if they do not, the bill fails.
        (B.c) After d=7(**) days of deliberation, there shall promptly follow...
        (B.d) ...the Weighted Vote Procedure to determine passage of the bill.
    (C) Otherwise, the bill passes.

    The Congress may by a 3/5s unweighted majority in each Chamber, subject to
    the ordinary veto and veto-override procedures, alter the parameters O,S,d
    marked above by (**).

    Note the relation S/(O+S) = 3/5.

The Weighted Voting Procedure is a simplified or "truncated" form of "quadratic
voting".  In certain extreme cases (if there is a large, fixed menu of bills
and if each senator is very uncertain about the other senators' preferences on
other bills, and if that uncertainty is symmetrical with respect both to bills
and senators and also statistically independent), quadratic voting maximizes
utility while our truncated version doesn't.  But those extreme cases do not
plausibly model the Senate.

### Bonus application to budgeting

Likewise, one decisive procedure for crafting a budget is to ask not *is this
 proposed budget acceptable?* but instead *is the current allocation for this
budget item too low or too high?*.  Here's a sketch of such a procedure (we
focus on the House since that chamber constitutionally originates revenue bills
and by convention originates appropriations bills):

    (sketch of) BINARY BUDGETING PROCEDURE

        This procedure results in a budget, that is, a list of items to fund,
        each annotated with the dollar amount allotted and with rules for how
        the funding may be spent.  It is intended to augment House Rules, not
        the US Constitution.

    (A) The House decides on a coarse-grained menu of, say, 1000 items to fund.
        Items might be executive departments, tax cuts, specific programs, etc.
    (B) Determine for each item a ceiling $X for that item's allocation:
        (B.a) Tentatively set the item's ceiling X to 1 (meaning one dollar).
        (B.b) Each Representative specifies whether the item's current ceiling
              is high enough.
        (B.c) If (3/5)ths of (B.b)'s votes are yeas, conclude.  Otherwise,
              multiply X by 10 and repeat (B.b) and (B.c).
    (C) The House REPEATEDLY refines each item's allocation intervals like so:
        (C.a) Each item begins with a tentative allocation interval [$0, $X].
        (C.b) Each Representative specifies for each item whether the current
              allocation interval leans high or leans low.
        (C.c) According to the which of those three choices has a plurality,
              the interval [L, H] becomes either [L, H-S/2] or [L+S/2, H];
              here, S=H-L is the interval width.
        (C.d) Repeat (C.b, C.c) until they have been done, say, 20 times total.
        (C.e) Allocate to each item with interval [L,H] the mean (L+H)/2.
    (D) Within a 60 day timeframe, representatives may propose revisions to the
        allocations, revisions that must be promptly voted on.  Revisions that
        modify the coarse-grained menu, the allocations to its items, or
        constraints between its items are accepted when a (3/5)ths majority
        concurs.  Revisions that merely specify fine-grained constraints within
        a menu item are accepted when a simple majority concurs.

One may adapt the above into a decisive procedure involving both Chambers.



## Design Considerations: Antipartisan Designs

### Tension and balance

### Hot potatoes

CONTINUITY (vs "gerrymander")


This sensitivity to sequencing could be partially mitigated by scheduling
multiple passes through the sequence of Senators so that each Senator ends up
marking, say, thrice.  I did not include this in the Amendment text since it
seems complicated and I have not convinced myself of its substantive value.


### Bias-variance "gerrymandering"

We can see a weakness of this method when we consider a (not implausibly)
partisan political atmosphere whose every appointee to the Appellate Courts
is "very red" or "very blue".  FILLIN TODO

### Randomness

We saw in "Hot Potatos" that the sequencing of Senators subtly affects the
Supreme Court appointment process.  It is thus important to ensure fair random
selection of that sequence.  The process should be not only fair but
*verifiably* fair.

Here's an elegant way to meet these goals.  This method relies on three
trust-enhancing tools: a "hash function", a clear plastic box, and trusted live
television.  We rely on these properties of "hashing":

    -- Each seq S has exactly one hash H=h(S).
    -- H is easy to compute from S.
    -- It is intractably hard to find given H a seq whose hash equals H.
       For instance, S is intractably hard to compute from H.



    RANDOMNESS GENERATION PROCEDURE

        This procedure generates a seq, to be regarded as a completely random
        seq, by aggregating seqs from concerned parties (say, Senators) at
        least one of whom would benefit from that seq being completely random.
        Our word "seq" is shorthand for "a sequence of 1000 binary digits."
        For a sense of scale, a seq may be represented as an 8-by-8 grid of
        glyphs, each one of "0123456789abcdef".

    (A) Each Senator k:
        (A.a) privately chooses a "private seq" (call it s(k))
        (A.b) computes their "public seq" h(s(k))
        (A.c) publicizes a value y(k), which they swear to be their public seq
    (B) The Senators assemble and commit their seqs, all on live television:
        (B.a) Each brings a piece of paper, folded so as to hide its contents,
              on which is drawn their name and a seq p(k) that they swear to be
              their private sequence.
        (B.b) The Senators commit their piece of paper to a clear plastic box.
        (B.c) Each paper is taken out, unfolded, and its contents televised.
    (C) Each Senator's p(k) is verified to obey the relation h(p(k)) = y(k).
        Senators for whom this relation fails are reprimanded.
    (D) Sum all the verified p(k)'s to get the overall "random" seq.

Steps (A,C,D) alone form a randomness generation procedure.  More precisely, we
might replace step (B) by:
    (B') Each Senator in sequence publicly announces their p(k), sworn to be
         their private sequence (called s(k))
However, this gives undue power to the last Senator in the sequence, since they
may choose whether or not to truthfully reveal s(k) based on their knowledge of
the previous Senators' announcements and thus how either choice would determine
the resulting "random" seq.  The point of (B) is to force all choices of
whether to be truthful to come *before* the private seqs s(k) are announced.

Steps (B,D) alone form a randomness generation procedure.  More precisely, we
might replace steps (A,C) by:
    (A') Each Senator k: privately chooses a "private seq"
    (C') do nothing
However, this procedure is more difficult to verify because it would offer no
evidence to counter a Senator's false claim (perhaps asserted due to an
unfavorable result) that the step (B) videostream had been corrupted.  By
contrast, the full procedure (A,B,C,D) publicly broadcasts the pairs
(y(k),p(k)) for each Senator, pairs that may be checked by folks at home.

Overall, this procedure relies on some respect for procedure but not much ---
perhaps as much as occurs in the Senate during the pro forma tallying of
presidential electoral votes.  In particular, there is no space for acting
"softly" in bad faith.

In practice, the computations involved are done easily by a computer and it
would suffice for each Senator to delegate their role to trusted clerks.


 TODO : talk about robustness to CONSPIRACY


### Bonus application to House Elections

Randomness helps against such gerrymandering

 FILLIN TODO --- randomized house idea



## Design Considerations: Regular Designs and Other Details

Is the 10th Justice packing?

### Term limits and backups

    REVOLVING DOOR PROCEDURE.

        This procedure maintains a queue of 10 Supreme Court Justices.  The
        most junior Justice hears cases, deliberates, and may write opinions;
        but they may not vote except to break ties.  The most junior Justice
        thus votes only in the event of a vacancy or recusal.

    (A) On May 1 of each odd year, the most senior Justice retires.
    (B) Whenever a vacancy arises, including by step (A), fill that vacancy via
        the Whittle-then-Approve Procedure.

### Presidential influence

The amendment strips the President of immediate influence over Supreme Court
appointments.  However, the President strongly affects future Supreme Court
appointments through their appointments to the Appellate Courts.  This counters
the risk that the Supreme Court gets packed with Justices whose rulings favor
an expansively powerful Senate and a limited, vestigial Presidency.

To give a sense of scale, it seems that typical presidents each year rotate
about `4%` to `8%` of the Appellate Courts' seats.  Here are the postwar
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

To change parameters (such as the number of seats on the Appellate Courts) lies
somewhere between a Constitutional Amendment and ordinary law.  We might then
set an intermediate criterion for passage:

    The Congress may by a 3/5s unweighted majority in each Chamber, subject to
    the ordinary veto and veto-override procedures, alter the following numeric
    parameters: T, K, k, N, ...

Using 1/2 instead of 3/5 could tempt a thin majority to expand and "pack" the
Appellate Courts, thus shifting future Supreme Court appointments.  To further
counter this temptation, we may add a time delay:

    For the purpose of appointing Justices to the Supreme Court: each
    additional seat on the Appellate Courts shall, 12 years after its addition
    and no earlier, be considered in the computations of seniority and be
    eligible for inclusion in lists of candidates.

This allows expansions to immediately relieve ever-growing case burdens.



## Appendices

Note: we refer below to some recent congressional activity.  For this purpose,
`X.Y.N` stands for "item number `N` of kind `Y` in the `X`th congress" found at
`www.congress.gov/bill/Xth-congress/Y/N`.  For example, `116.house-bill.8424`
stands for "item number `8424` of kind `house-bill` in the `116`th congress"
found at `www.congress.gov/bill/116th-congress/house-bill/8424`

### Related Ideas: Term Limits, Scheduled Appointments, Seniority Queues

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

### Related Ideas : Structure of Foreign Courts of Last Resort

 TODO: comment on how they do it in Taiwan, Uruguay, India, Mauritius, Norway.

### Full Text

    I.  The Supreme Court
    ---------------------

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


    II.  The Appellate Courts
    -------------------------

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



    III.  Transition and Tuning
    ---------------------------

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


