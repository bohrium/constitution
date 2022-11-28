''' author: samtenka
    change: 2022-11-18
    create: 2022-11-18
    descrp:
    to use:

        Download from the links described in `data-sources` to:
            `../data/decisions.fed-circuit.csv`
            `../data/appointers.csv`
        Run `python3 ../source/parse_decisions.py` to generate
            `../source/federal_data.c`, which is then used by
            `../source/embed.c`.
'''

ONLY_SPLIT_VOTES = True
#ONLY_SPLIT_VOTES = False

import re
import random
import tqdm

NUM  = r'[0-9]+'
DATE = r'"[-0-9]+"'
STR  = r'"[^"]*"'
GRP  = r'"([^"]*)"'

ROW = '^'+','.join((NUM,DATE,STR,
                    STR,STR,STR,
                    GRP,GRP,GRP,GRP,GRP,GRP,GRP,GRP,GRP,
                    STR                                 ))

ROW_APPT = '^'+','.join((STR,STR,GRP,STR,STR,STR,STR,STR,STR,STR,STR,STR,STR,STR,STR,STR,STR,STR,STR,GRP,STR,STR,GRP))
#"nid"%"jid"%"Last Name"%"First Name"%"Middle Name"%"Suffix"%"Birth Month"%"Birth Day"%"Birth Year"%"Birth City"%"Birth State"%"Death Month"%"Death Day"%"Death Year"%"Death City"%"Death State"%"Gender"%"Race or Ethnicity"%"Court Type (1)"%"Court Name (1)"%"Appointment Title (1)"%"Appointing President (1)"%"Party of Appointing President (1)"%

def parse(ln, judges):
    gs = re.match(ROW, ln)

    gs = list(gs.groups())
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

    return (tuple(majority), tuple(minority))

def votes_from_lns(lns):
    judges = set()
    votes = [_ for _ in [parse(ln, judges) for ln in lns if ln] if _]
    return votes, judges

#def vote_row(maj,min, ids_by_nm):
def vote_row(maj,min, ids_by_nm, parties):
    row = ['_' for _ in range(len(ids_by_nm))]
    for j in maj: row[ids_by_nm[j]] = 'Y'#random.choice(('Y', 'N'))#'Y' if parties[j]=='Democratic' else 'N'
    for j in min: row[ids_by_nm[j]] = 'N'#random.choice(('Y', 'N'))#'Y' if parties[j]=='Democratic' else 'N'
    return ','.join(row)

TEMPLATE = '''
#define nb_judges <<NB_JUDGES>>
#define nb_cases  <<NB_CASES>>

party_t pres[nb_judges] = <<PRES>>;
votes_t vote[nb_cases][nb_judges] = <<VOTE>>;
char    name[nb_judges][32] = <<NAME>>;
'''

def tabulate(votes, judges, parties):
    ids_by_nm = {nm:i for i,nm in enumerate(sorted(judges))}
    for n,i in ids_by_nm.items():
        print(i, n)
    vote_table = (
        '{' +
        #','.join('\n    {'+vote_row(maj,min,ids_by_nm)+'}' for maj,min in votes)+
        ','.join('\n    {'+vote_row(maj,min,ids_by_nm, parties)+'}' for maj,min in votes)+
        '\n}'
        )
    pres_table = '{'+','.join(('DEM' if parties[j]=='Democratic' else 'REP') for j in sorted(judges))+'}'
    #return (TEMPLATE
    #        .replace('<<NB_JUDGES>>',   str(len(judges)))
    #        .replace('<<NB_CASES>>' ,   str(len(votes )))
    #        .replace('<<PRES>>'     ,   pres_table      )
    #        .replace('<<VOTE>>'     ,   vote_table      )
    #        )
    name_table = '{'+','.join('"'+j+'"' for j in sorted(judges))+'}'
    return (TEMPLATE
            .replace('<<NB_JUDGES>>',   str(len(judges)))
            .replace('<<NB_CASES>>' ,   str(len(votes )))
            .replace('<<PRES>>'     ,   pres_table      )
            .replace('<<VOTE>>'     ,   vote_table      )
            .replace('<<NAME>>'     ,   name_table      )
            )

court_nm = 'U.S. Court of Appeals for the Federal Circuit'
if __name__=='__main__':
    parties = {}
    with open('./data/appointers.csv') as f:
        lns = f.read().split('\n')[1:]
    for ln in lns:
        if court_nm not in ln: continue
        nm, fst_court, pres = re.match(ROW_APPT, ln).groups()
        # NOTE: we DON'T do `if court != court_nm: continue` since judges can be /re/appointed to Federal Circuit from a different court
        # NOTE: `...Federal Circuit` may appear under clerkships, so we get superset
        # NOTE: there are duplicate last names... hope this is alright!
        print('{:15s}{:10s} --- {}'.format(nm,pres,fst_court))
        parties[nm] = pres

    with open('../data/decisions.fed-circuit.csv') as f:
        lns = f.read().split('\n')[1:]

    votes, judges = votes_from_lns(lns)

    judges = judges.intersection(parties.keys())
    votes = [(maj,min) for maj,min in votes if judges.issuperset(set(maj).union(set(min)))]
    split = [(maj,min) for maj,min in votes if min]

    if ONLY_SPLIT_VOTES:
        tt = tabulate(split, judges, parties)
    else:
        tt = tabulate(votes, judges, parties)
    #with open('../federal_data.rand.c', 'w') as f:
    with open('./federal_data.c', 'w') as f:
        f.write(tt)

    print('found {} split decisions among {} decisions total'.format(
            len(split), len(votes)
         ))
    print('found {} judges'.format(
            len(judges)
         ))


