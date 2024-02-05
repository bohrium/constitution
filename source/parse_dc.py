# author: samtenka
# change: 2023-01-03
# create:
# descrp:
# to use:

import re
import tqdm
import PyPDF2
import glob
import random


CIRCUIT = 'dc'


cache_template = lambda circuit, year, year_idx: (
                     '../data/circ{:2s}.{:02d}-{:04d}.pdf'.format(
                         circuit, year%100, year_idx
                     )
                 )

'Dissenting opinion by Circuit Judge H ENDERSON .'

sss = '''
Before: R
OGERS  and T ATEL , Circuit Judges , and
SILBERMAN , Senior Circuit Judge .
Opinion for the Court filed by Senior Circuit Judge
SILBERMAN .
Dissenting opinion filed by Circuit Judge ROGERS .
'''

sss=sss.replace('\n',' ').replace('  ',' ')

#sss = '''
#Before: R OGERS and T ATEL , Circuit Judges , and SILBERMAN , Senior Circuit Judge .
#Opinion for the Court filed by Senior Circuit Judge
#SILBERMAN .
#Dissenting opinion filed by Circuit Judge ROGERS .
#'''

allow_spaces = lambda s:'[ ]{0,1}'.join(s)

JNM = '({}|{}|{})'.format('[A-Z][A-Za-z][A-Z]+'     ,
                          '[A-Z]+(?:[ ]{1,2})[A-Z]+',
                          '[A-Z][A-Za-z][A-Za-z]+'      )

___ = '(?:[ ]*)'
TIT = (
        '(?:'+allow_spaces('Chief')+'|'+allow_spaces('Senior')+'|)' +___+
        '(?:'+allow_spaces('Circuit')+'|'+allow_spaces('District')+'|)' +___+
        '(?:'+allow_spaces('Judge')+'|'+allow_spaces('Judges')+'|)'
        )
PUN = '(?:;|,|)'+___+'(?:[*]|)'
SEP = '(?:'+allow_spaces('and')+'|,)'
#JNMT = ___ + JNM + ___ + PUN + ___ + '(?:and|)' + ___ + TIT + ___ + PUN
#PANEL = 'Before: {} {} {}'.format(JNMT, JNMT, JNMT)
SKP  = ___+'(?:' + '(?:'+PUN+___+TIT+___+PUN+___+'|)' + SEP + '|)'+___
PANEL = allow_spaces('Before')+'[:]? {}{} {}{} {}{}'.format(JNM, SKP, JNM, SKP, JNM, SKP)


#'(?:, J\.)' +
#DISS = JNM + '(?:.(?!{}))'.format(JNM)+'{,60}' + 'dissent'
DISS = allow_spaces('Dissenting opinion filed by') + ___ + TIT + ___ + JNM
#+ '(?:.(?![A-Z][A-Za-z][A-Z]+)){,60}' + 'dissent'

def get_judges(txt):
    mm = re.search(PANEL, txt)
    return [nm.replace(' ','') for nm in list(mm.groups())]

def get_dissent(txt):
    mm = re.search(DISS, txt.replace('\n', ' '))
    rr = [] if mm is None else mm.groups()
    return [nm.replace(' ','') for nm in list(rr)]

def extract_page(cache_nm):
    if cache_nm.endswith('pdf'):
        with open(cache_nm, 'rb') as f:
            reader = PyPDF2.PdfFileReader(f, strict=False)
            return '\n'.join(reader.getPage(p).extractText() for p in range(2))
    else:
        with open(cache_nm, 'r') as f:
            return str(f.read())

if __name__=='__main__':
    print('\033[32m')
    for YEAR in list(range(2021,2023)):
        print('\033[31m{}\033[32m'.format(YEAR))
        for k in range( 9,10000):
            try:
                #cache_nm = cache_template(CIRCUIT, YEAR, k)
                gg = glob.glob(cache_template(CIRCUIT, YEAR, k).replace('.pdf','.*'))
                if not gg: break
                cache_nm = gg[0]
                tt = extract_page(cache_nm)
                tt = (tt.replace('\n',' ')
                        .replace('  ',' ')
                        .replace('  ',' ')
                        .replace('  ',' '))
                jj = get_judges(tt)
                dd = get_dissent(tt)
                if dd:
                    print('{:5d} -- {} -- \033[33m{}\033[32m'.format(k, ' : '.join(jj), ' : '.join(dd)))
                elif hash(str((YEAR,k)))%100 < 10:
                    print('{:5d} -- {} -- \033[33m{}\033[32m'.format(k, ' : '.join(jj), ' : '.join(dd)))
            except AttributeError:
                print('\033[35m$$\033[32m', k)
            except PyPDF2.errors.PdfReadError:
                print('\033[35m<>\033[32m', k)
            except UnicodeDecodeError:
                print('\033[35m??\033[32m', k)
            except IndexError:
                print('\033[35m[]\033[32m', k)
            except FileNotFoundError:
                break
