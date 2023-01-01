''' author: samtenka
    change: 2022-01-01
    create: 2022-11-18
    descrp:
    to use:

        Download from the links described in `data-sources` to:
            `../data/decisions.fed-circuit.csv`
            `../data/appointers.csv`
        Run `python3 ../source/parse_fed.py` to generate
            `../source/federal_data.c`, which is then used by
            `../source/embed.c`.
'''

def term_from_date(ss):
    yr = int(ss[:4])
    return (yr-1) - (yr-1)%4 + 1


ONLY_SPLIT_VOTES = True
#ONLY_SPLIT_VOTES = False

import re
import random
import tqdm

NUM  = r'[0-9]+'
DATE = r'"([-0-9]+)"'
STR  = r'"[^"]*"'
GRP  = r'"([^"]*)"'

ROW = '^'+','.join((NUM,DATE,STR,
                    STR,STR,STR,
                    GRP,GRP,GRP,GRP,GRP,GRP,GRP,GRP,GRP,
                    STR                                 ))

ROW_APPT = '^'+','.join((  ','.join(STR for _ in range(2)),
                         GRP,
                           ','.join(STR for _ in range(16)),
                         GRP,
                           ','.join(STR for _ in range(2)),
                         GRP,
                           ','.join(STR for _ in range(13)),
                         GRP,
                         ))
'''
    "nid","jid",
"Last Name",
    "First Name","Middle Name","Suffix","Birth Month","Birth Day","Birth Year",
    "Birth City","Birth State","Death Month","Death Day","Death Year","Death City",
    "Death State","Gender","Race or Ethnicity","Court Type (1)",
"Court Name (1)",
    "Appointment Title (1)","Appointing President (1)",
"Party of Appointing President (1)",
    "Reappointing President (1)","Party of Reappointing President (1)",
    "ABA Rating (1)","Seat ID (1)","Statute Authorizing New Seat (1)",
    "Recess Appointment Date (1)","Nomination Date (1)",
    "Committee Referral Date (1)","Hearing Date (1)",
    "Judiciary Committee Action (1)","Committee Action Date (1)",
    "Senate Vote Type (1)","Ayes/Nays (1)",
"Confirmation Date (1)",
    "Commission Date (1)","Service as Chief Judge, Begin (1)",
    "Service as Chief Judge, End (1)","2nd Service as Chief Judge, Begin (1)",
    "2nd Service as Chief Judge, End (1)","Senior Status Date (1)",
    "Termination (1)","Termination Date (1)",
'''

def parse(ln, judges):
    gs = re.match(ROW, ln)

    gs = list(gs.groups())
    date, gs = gs[0], gs[1:]
    j = gs[:3]
    o = gs[3::2]
    a = gs[4::2]

    if o[0] not in {'Unanimous', 'Majority'}: return
    if ('' in j) or len(j)!=3: return # e.g. for some Per Curiam cases

    minority = set(aa for oo,aa in zip(o,a) if oo=='Dissenting')
    majority = set(j).difference(minority)

    if len(minority)+len(majority) != 3: return # e.g. for some en banc cases

    #judges.update(j)
    for j_nm in j:
        jj = j_nm[:7] # TODO: stop doing this
        judges.add(jj)

    return (term_from_date(date), tuple(majority), tuple(minority))

def votes_from_lns(lns):
    judges = set()
    parses = list(filter(None, [parse(ln, judges) for ln in lns if ln]))
    votes = [_[1:] for _ in parses]
    dates = [_[0]  for _ in parses]
    print(len(dates), len(votes))
    return dates, votes, judges

#def vote_row(maj,min, ids_by_nm):
def vote_row(maj,min, ids_by_nm, parties):
    row = ['_' for _ in range(len(ids_by_nm))]
    for j in maj: row[ids_by_nm[j]] = 'Y'#random.choice(('Y', 'N'))#'Y' if parties[j]=='Democratic' else 'N'
    for j in min: row[ids_by_nm[j]] = 'N'#random.choice(('Y', 'N'))#'Y' if parties[j]=='Democratic' else 'N'
    return ','.join(row)

TEMPLATE = '''
#define nb_judgs <<NB_JUDGES>>
#define nb_cases  <<NB_CASES>>
#define nb_terms  25
#define nm_length 32

party_t pres[nb_judgs] = <<PRES>>;
votes_t vote[nb_cases][nb_judgs] = <<VOTE>>;

char    name[nb_judgs][nm_length] = <<NAME>>;
char    year[nb_terms] = <<NAME>>;

int     term[nb_judgs] = <<TERM>>;
int     date[nb_cases] = <<DATE>>;
'''

termidx_from_year = lambda y : int((y-1931)/4)
year_from_termidx = lambda t : 1931 + 4*t

def make_array(iter, per_row=12, indent='    '):
    return ('{'+ ','.join((('' if i%per_row else ('\n'+indent))+str(x))
                          for i,x in enumerate(iter)) + '\n}')
def tabulate(votes, judges, parties, terms, dates):
    ids_by_nm = {nm:i for i,nm in enumerate(sorted(judges))}
    for n,i in ids_by_nm.items():
        print(i, n)
    vote_table = (
        '{' +
        #','.join('\n    {'+vote_row(maj,min,ids_by_nm)+'}' for maj,min in votes)+
        ','.join('\n    {'+vote_row(maj,min,ids_by_nm, parties)+'}' for maj,min in votes)+
        '\n}'
        )
    pres_table = make_array((('DEM' if parties[j]=='Democratic' else 'REP') for j in sorted(judges)))
    #'{'+','.join((('' if i%10 else '\n')+('DEM' if parties[j]=='Democratic' else 'REP')) for i,j in enumerate(sorted(judges)))+'}'
    term_table = make_array(map(termidx_from_year, (terms[j] for j in sorted(judges))))
    #'{'+','.join((('' if i%10 else '\n')+str(terms[j])) for i,j in enumerate(sorted(judges)))+'}'
    date_table = make_array(map(termidx_from_year, dates))
    #'{'+','.join((('' if i%10 else '\n')+str(d)) for i,d in enumerate(dates))+'}'
    name_table = make_array((('"'+j+'"') for j in sorted(judges)))
    #'{'+','.join('"'+j+'"' for j in sorted(judges))+'}'
    return (TEMPLATE
            .replace('<<NB_JUDGES>>',   str(len(judges)))
            .replace('<<NB_CASES>>' ,   str(len(votes )))
            .replace('<<PRES>>'     ,   pres_table      )
            .replace('<<VOTE>>'     ,   vote_table      )
            .replace('<<NAME>>'     ,   name_table      )
            .replace('<<TERM>>'     ,   term_table      )
            .replace('<<DATE>>'     ,   date_table      )
            )

court_nm = 'U.S. Court of Appeals for the Federal Circuit'
if __name__=='__main__':
    parties = {}
    terms   = {}
    with open('../data/appointers.csv') as f:
        lns = f.read().split('\n')[1:]
    for ln in lns:
        if court_nm not in ln: continue
        nm, fst_court, pres, date = re.match(ROW_APPT, ln).groups()
        date = term_from_date(date)
        # NOTE: we DON'T do `if court != court_nm: continue` since judges can be /re/appointed to Federal Circuit from a different court
        # NOTE: `...Federal Circuit` may appear under clerkships, so we get superset
        # NOTE: there are duplicate last names... hope this is alright!
        print('{:15s}{:10s} --- {:4d} --- {}'.format(nm,pres,date,fst_court))
        parties[nm] = pres
        terms  [nm] = date

    input()

    with open('../data/decisions.fed-circuit.csv') as f:
        lns = f.read().split('\n')[1:]

    dates, votes, judges = votes_from_lns(lns)

    judges = judges.intersection(parties.keys())

    if ONLY_SPLIT_VOTES:
        dates = [d for d,(maj,min) in zip(dates,votes) if (judges.issuperset(set(maj).union(set(min)))
                                                       and min)]
        votes = [(maj,min) for maj,min in votes if judges.issuperset(set(maj).union(set(min)))]
        split = [(maj,min) for maj,min in votes if min]
        tt = tabulate(split, judges, parties, terms, dates)
    else:
        dates = [d for d,(maj,min) in zip(dates,votes) if judges.issuperset(set(maj).union(set(min)))]
        votes = [(maj,min) for maj,min in votes if judges.issuperset(set(maj).union(set(min)))]
        tt = tabulate(votes, judges, parties, terms, dates)
    #with open('../federal_data.rand.c', 'w') as f:
    with open('./federal_data_.c', 'w') as f:
        f.write(tt)

    print('found {} split decisions among {} decisions total'.format(
            len(split), len(votes)
         ))
    print('found {} judges'.format(
            len(judges)
         ))


'''
"nid","jid","Last Name","First Name","Middle Name","Suffix","Birth
Month","Birth Day","Birth Year","Birth City","Birth State","Death Month","Death
Day","Death Year","Death City","Death State","Gender","Race or
Ethnicity","Court Type (1)","Court Name (1)","Appointment Title
(1)","Appointing President (1)","Party of Appointing President
(1)","Reappointing President (1)","Party of Reappointing President (1)","ABA
Rating (1)","Seat ID (1)","Statute Authorizing New Seat (1)","Recess
Appointment Date (1)","Nomination Date (1)","Committee Referral Date
(1)","Hearing Date (1)","Judiciary Committee Action (1)","Committee Action Date
(1)","Senate Vote Type (1)","Ayes/Nays (1)","Confirmation Date (1)","Commission
Date (1)","Service as Chief Judge, Begin (1)","Service as Chief Judge, End
(1)","2nd Service as Chief Judge, Begin (1)","2nd Service as Chief Judge, End
(1)","Senior Status Date (1)","Termination (1)","Termination Date (1)","Court
Type (2)","Court Name (2)","Appointment Title (2)","Appointing President
(2)","Party of Appointing President (2)","Reappointing President (2)","Party of
Reappointing President (2)","ABA Rating (2)","Seat ID (2)","Statute Authorizing
New Seat (2)","Recess Appointment Date (2)","Nomination Date (2)","Committee
Referral Date (2)","Hearing Date (2)","Judiciary Committee Action
(2)","Committee Action Date (2)","Senate Vote Type (2)","Ayes/Nays
(2)","Confirmation Date (2)","Commission Date (2)","Service as Chief Judge,
Begin (2)","Service as Chief Judge, End (2)","2nd Service as Chief Judge, Begin
(2)","2nd Service as Chief Judge, End (2)","Senior Status Date
(2)","Termination (2)","Termination Date (2)","Court Type (3)","Court Name
(3)","Appointment Title (3)","Appointing President (3)","Party of Appointing
President (3)","Reappointing President (3)","Party of Reappointing President
(3)","ABA Rating (3)","Seat ID (3)","Statute Authorizing New Seat (3)","Recess
Appointment Date (3)","Nomination Date (3)","Committee Referral Date
(3)","Hearing Date (3)","Judiciary Committee Action (3)","Committee Action Date
(3)","Senate Vote Type (3)","Ayes/Nays (3)","Confirmation Date (3)","Commission
Date (3)","Service as Chief Judge, Begin (3)","Service as Chief Judge, End
(3)","2nd Service as Chief Judge, Begin (3)","2nd Service as Chief Judge, End
(3)","Senior Status Date (3)","Termination (3)","Termination Date (3)","Court
Type (4)","Court Name (4)","Appointment Title (4)","Appointing President
(4)","Party of Appointing President (4)","Reappointing President (4)","Party of
Reappointing President (4)","ABA Rating (4)","Seat ID (4)","Statute Authorizing
New Seat (4)","Recess Appointment Date (4)","Nomination Date (4)","Committee
Referral Date (4)","Hearing Date (4)","Judiciary Committee Action
(4)","Committee Action Date (4)","Senate Vote Type (4)","Ayes/Nays
(4)","Confirmation Date (4)","Commission Date (4)","Service as Chief Judge,
Begin (4)","Service as Chief Judge, End (4)","2nd Service as Chief Judge, Begin
(4)","2nd Service as Chief Judge, End (4)","Senior Status Date
(4)","Termination (4)","Termination Date (4)","Court Type (5)","Court Name
(5)","Appointment Title (5)","Appointing President (5)","Party of Appointing
President (5)","Reappointing President (5)","Party of Reappointing President
(5)","ABA Rating (5)","Seat ID (5)","Statute Authorizing New Seat (5)","Recess
Appointment Date (5)","Nomination Date (5)","Committee Referral Date
(5)","Hearing Date (5)","Judiciary Committee Action (5)","Committee Action Date
(5)","Senate Vote Type (5)","Ayes/Nays (5)","Confirmation Date (5)","Commission
Date (5)","Service as Chief Judge, Begin (5)","Service as Chief Judge, End
(5)","2nd Service as Chief Judge, Begin (5)","2nd Service as Chief Judge, End
(5)","Senior Status Date (5)","Termination (5)","Termination Date (5)","Court
Type (6)","Court Name (6)","Appointment Title (6)","Appointing President
(6)","Party of Appointing President (6)","Reappointing President (6)","Party of
Reappointing President (6)","ABA Rating (6)","Seat ID (6)","Statute Authorizing
New Seat (6)","Recess Appointment Date (6)","Nomination Date (6)","Committee
Referral Date (6)","Hearing Date (6)","Judiciary Committee Action
(6)","Committee Action Date (6)","Senate Vote Type (6)","Ayes/Nays
(6)","Confirmation Date (6)","Commission Date (6)","Service as Chief Judge,
Begin (6)","Service as Chief Judge, End (6)","2nd Service as Chief Judge, Begin
(6)","2nd Service as Chief Judge, End (6)","Senior Status Date
(6)","Termination (6)","Termination Date (6)","Other Federal Judicial Service
(1)","Other Federal Judicial Service (2)","Other Federal Judicial Service
(3)","Other Federal Judicial Service (4)","School (1)","Degree (1)","Degree
Year (1)","School (2)","Degree (2)","Degree Year (2)","School (3)","Degree
(3)","Degree Year (3)","School (4)","Degree (4)","Degree Year (4)","School
(5)","Degree (5)","Degree Year (5)","Professional Career","Other
Nominations/Recess Appointments"
'''
