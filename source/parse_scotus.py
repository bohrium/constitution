''' author: samtenka
    change: 2022-11-19
    create: 2022-11-19
    descrp:
    to use:

        Download from the link described in `data-sources` to:
            `../data/SCDB_2022_01_justiceCentered_Citation.csv`
        Run `python3 ../source/parse_scotus.py` to generate
            `../source/scotus_data.c`, which is then used by
            `../source/embed.c`.

'''

ONLY_SPLIT_VOTES = True
#ONLY_SPLIT_VOTES = False

import re
import random
import tqdm

NUM  = r'[0-9]*'
DATE = r'"[-0-9]+"'
STR  = r'"[^"]*"'
GRP  = r'"([^"]*)"'
GRPNUM  = r'([0-9]+)'
ANY  = r'[^,]*'

ROW = '^'+','.join([GRP]+[ANY]*3+[ANY]+[ANY]*9+[GRP]+[ANY]*39+[GRP]+[GRPNUM,GRPNUM,GRPNUM,GRPNUM])
#"caseId",
#"docketId","caseIssuesId","voteId",
#"dateDecision",
#"decisionType","usCite","sctCite","ledCite","lexisCite","term","naturalCourt","chief","docket",
#"caseName",
#"dateArgument","dateRearg","petitioner","petitionerState","respondent","respondentState","jurisdiction","adminAction","adminActionState","threeJudgeFdc","caseOrigin","caseOriginState","caseSource","caseSourceState","lcDisagreement","certReason","lcDisposition","lcDispositionDirection","declarationUncon","caseDisposition","caseDispositionUnusual","partyWinning","precedentAlteration","voteUnclear","issue","issueArea","decisionDirection","decisionDirectionDissent","authorityDecision1","authorityDecision2","lawType","lawSupp","lawMinor","majOpinWriter","majOpinAssigner","splitVote","majVotes","minVotes","justice",
#"justiceName","vote","opinion","direction","majority",
#"firstAgreement","secondAgreement"

rules = {}
dates = {}
judges = set()

def parse(ln):
    gs = re.match(ROW, ln)
    if gs is None: return
    (case_id, case_nm, just_nm,
            vote, opin, dire, is_majo) = list(gs.groups())

    just_nm = just_nm[:7] # TODO: stop doing this
    judges.add(just_nm)

    if case_id not in rules: rules[case_id] = {}
    rules[case_id][just_nm] = 1 if is_majo=='2' else 0

TEMPLATE = '''
#define nb_judges <<NB_JUDGES>>
#define nb_cases  <<NB_CASES>>

party_t pres[nb_judges] = <<PRES>>;
votes_t vote[nb_cases][nb_judges] = <<VOTE>>;
char    name[nb_judges][32] = <<NAME>>;
'''
#def vote_row(maj,min, ids_by_nm, parties):
def vote_row(maj,min, ids_by_nm):
    row = ['_' for _ in range(len(ids_by_nm))]
    for j in maj: row[ids_by_nm[j]] = 'Y'
    for j in min: row[ids_by_nm[j]] = 'N'
    return ','.join(row)


parties = {
    'ACBarre':'R', # trump
    'AFortas':'D', # lbj        (liberal?) -- scandalous
    'AMKenne':'R', # ford       (swing)
    'AScalia':'R', # reagan     (conservative)
    'BMKavan':'R', # trump
    'BRWhite':'D', # kennedy    (swing??)
    'CThomas':'R', # hw bush    (conservative)
    'DHSoute':'R', # hw bush    (liberal!!)
    'EKagan' :'D', # obama      (liberal)
    'EWarren':'R', # eisenhower (liberal??)
    'HABlack':'R', # nixon      (liberal!!)
    'HLBlack':'D', # fdr        (liberal??)
    'JGRober':'R', # w bush     (swing)
    'JHarlan':'R', # hayes      (conservative??)
    'JPSteve':'R', # ford       (liberal!!)
    'LFPowel':'R', # nixon      (conservative)
    'NMGorsu':'R', # trump
    'PStewar':'R', # eisenhower (swing)
    'RBGinsb':'D', # clinton    (liberal)
    'SAAlito':'R', # w bush     (conservative)
    'SDOConn':'R', # reagan     (swing)
    'SGBreye':'D', # clinton    (liberal)
    'SSotoma':'D', # obama      (liberal)
    'TMarsha':'D', # lbj        (liberal)
    'WEBurge':'R', # nixon      (conservative?)
    'WHRehnq':'R', # reagan     (conservative)
    'WJBrenn':'R', # eisenhower (liberal!!)
    'WODougl':'D', # fdr        (liberal!!)
}

def tabulate(votes, judges):
    ids_by_nm = {nm:i for i,nm in enumerate(sorted(judges))}
    for n,i in ids_by_nm.items():
        print(i, n)
    vote_table = (
        '{' +
        ','.join('\n    {'+vote_row(maj,min,ids_by_nm)+'}' for maj,min in votes)+
        #','.join('\n    {'+vote_row(maj,min,ids_by_nm, parties)+'}' for maj,min in votes)+
        '\n}'
        )
    pres_table = '{'+','.join(('DEM' if parties[j]=='D' else 'REP') for j in sorted(judges))+'}'
    name_table = '{'+','.join('"'+j+'"' for j in sorted(judges))+'}'
    return (TEMPLATE
            .replace('<<NB_JUDGES>>',   str(len(judges)))
            .replace('<<NB_CASES>>' ,   str(len(votes )))
            .replace('<<PRES>>'     ,   pres_table      )
            .replace('<<VOTE>>'     ,   vote_table      )
            .replace('<<NAME>>'     ,   name_table      )
            )

if __name__=='__main__':
    with open('./SCDB_2022_01_justiceCentered_Citation.csv', 'r', encoding='utf-8', errors='ignore') as f:
        lns = f.read().split('\n')[1:]
    for ln in lns:
        parse(ln)

    votes = []
    kk = list(rules.keys())
    #for i in range(0,3000, 2):
    for i in range(0,6000, 4):
        #print(kk[-1-i], rules[kk[-1-i]])
        v = rules[kk[-1-i]]
        votes.append((tuple(j for j in v if v[j]==1),
                      tuple(j for j in v if v[j]==0)))

    judges = set(j for v in votes for p in v for j in p)

    print(len(kk))
    print(len(votes))
    print(len(judges))

    tt = tabulate(votes, judges)
    #print(tt)

    with open('../scotus_data.c', 'w') as f:
        f.write(tt)


