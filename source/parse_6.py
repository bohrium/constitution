import re
import tqdm
import PyPDF2
import requests
import glob

def extract_page(url, cache_nm):
    if not glob.glob(cache_nm):
        r = requests.get(url, stream=True)
        with open(cache_nm, 'wb') as f:
            f.write(r.content)

    with open(cache_nm, 'rb') as f:
        reader = PyPDF2.PdfFileReader(f)

        #print('nb pages:', reader.numPages)

        return '\n'.join(reader.getPage(p).extractText() for p in range(2))


#JNM = '([A-Z][A-Za-z][A-Z]+|[A-Z][A-Z])'
JNM = '({}|{})'.format('[A-Z][A-Za-z][A-Z]+', '[A-Z][A-Za-z][A-Z]+(?:[ ]{1,2})[A-Z][A-Z]')
SPC = '(?:[ ]*)'
TIT = '(?:Chief|Senior|)' + SPC + '(?:Circuit|District|)' + SPC + '(?:Judge|Judges|)'
PUN = '(?:;|,|)'
JNMT = SPC + JNM + PUN + SPC + '(?:and|)' + SPC + TIT + PUN
PANEL = 'Before:{}{}{}'.format(JNMT, JNMT, JNMT)

#'(?:, J\.)' +
#DISS = JNM + '(?:.(?!{}))'.format(JNM)+'{,60}' + 'dissent'
DISS = JNM + '(?:.(?![A-Z][A-Za-z][A-Z]+)){,60}' + 'dissent'

def get_judges(txt):
    mm = re.search(PANEL, txt)
    return list(mm.groups())

def get_dissent(txt):
    mm = re.search(DISS, txt.replace('\n', ' '))
    return [] if mm is None else mm.groups()

url_template = 'https://www.opn.ca6.uscourts.gov/opinions.pdf/{:02d}a{:04d}p-06.pdf'
cache_template = '../data/circ{:02d}.{:02d}-{:04d}.pdf'

CIRCUIT = 6
NB_CASES_BY_YEAR = {
#    22 : 254,
#    21 : 292,
#    20 : 394,
#    19 : 309,
    18 : 293,
#    17 : 282,
#    16 : 304,
#    15 : 302,
#    10 : 398,
#     5 : 490,
#     0 : 422,
}

if __name__=='__main__':
    for YEAR, nb in NB_CASES_BY_YEAR.items():
        print('\033[34m{}\033[32m'.format(YEAR))
        for k in range(   1,  nb):
            try:
                url = url_template.format(YEAR, k)
                cache_nm = cache_template.format(CIRCUIT, YEAR, k)
                tt = extract_page(url, cache_nm)
                jj = get_judges(tt)
                dd = get_dissent(tt)
                if dd:
                    print('{:4d} -- {} -- \033[33m{}\033[32m'.format(k, ' : '.join(jj), ' : '.join(dd)))
            except AttributeError:
                print('\033[31m$$\033[32m', k)
            except PyPDF2.errors.PdfReadError:
                print('\033[31m<>\033[32m', k)
            except IndexError:
                print('\033[31m[]\033[32m', k)

'''
 KETHLEDGE, J., delivered the opinion of the court in which BUSH, J., joined.
NALBANDIAN, J. (pp.  8–12), delivered a separate dissenting opinion.

 CLAY, J., announced the judgment, delivered the opinion of the court , in which
SUHRHEINRICH and MOORE, JJ., joined, with respect to the retaliation claim, and delivered
an opinion with respect to the interference claim.   MOORE, J. (pp. 23 –30), wrote a separate
opinion , in which SUHRHEINRICH, J., joined, concurring  in part in J. Clay’s majority opinion,
and delivered the opinion of the court with respect to the interference claim.  >
No. 21 -2851  Render v. FCA US, LLC  Page 2

 BUSH, J., delivered the opinion of the court in which DONALD, J., joined  in full, and
NALBANDIAN, J., joined in part .  NALBANDIAN, J. (pp. 43–51), delivered a separate opinion
concurring in part and dissenting in part.

 READLER, J., delivered the opinion of the court in which SUT TON, C.J., joined  in full,
and KETHLEDGE, J., joined in part.   KETHLEDGE, J. (pp. 25–26), delivered a separate
opinion concurring in part and dissenting in part.  >

 NORRIS, J., delivered the opinion of the court in which SUHRHEINRICH , J., joined.
CLAY, J. (pp. 9 –14), delivered a separate opinion  concurring in the judgment only.

 WHITE, J., delivered the opinion of the court in which MURPHY, J., joined, and
ROGERS, J., joined in part.  MURPHY, J. (pp. 34 –45), delivered a separate concurring op inion
in which WHITE, J., joined except as to Part II.A.  ROGERS, J. (pp 46 –48), delivered a separate
opinion concurring in part and dissenting in part.
'''

