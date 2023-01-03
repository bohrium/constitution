# author: samtenka
# change: 2023-01-03 
# create: 
# descrp: 
# to use: 

import re
import tqdm
import PyPDF2
import requests
import glob

PAGE = 'https://www.cadc.uscourts.gov/internet/opinions.nsf/'
URL = lambda year, month : (PAGE
                            + 'OpinionsByRDate?OpenView&count=1000&'
                            + 'SKey={:04d}{:02d}'.format(year, month))

'Dissenting opinion by Circuit Judge H ENDERSON .'

ROW = (
      '<div class="row-entry">'
    + '<span class="column-one(?: texticon|)">'
    + '<a href="'
        + '([0-9A-Z]+/\$file/\d+-\d+-\d+.pdf'
        + '|'
        + '[0-9A-Z]+/\$file/\d+-\d+[a-z]?.pdf'
        + '|'
        + '[0-9A-Z]+/\$file/\d+-\d+[a-z]?.txt)'
    + '" target="_blank">'
    + '\d+-\d+'
    + '</a>'
    + '</span>'
    + '<span class="column-two">'
    + '[^<]*'
    + '</span>'
    + '</div>'
    )

def extract_page(url, cache_nm):
    if not glob.glob(cache_nm):
        r = requests.get(url)
        with open(cache_nm, 'wb') as f:
            f.write(r.content)

    with open(cache_nm, 'rb') as f:
        reader = PyPDF2.PdfFileReader(f)

        #print('nb pages:', reader.numPages)

        return '\n'.join(reader.getPage(p).extractText() for p in range(2))


JNM = '({}|{})'.format('[A-Z][A-Za-z][A-Z]+'              ,
                       '[A-Z][A-Z]+(?:[ ]{1,2})[A-Z][A-Z]' )
SPC = '(?:[ ]*)'
TIT = '(?:Chief|Senior|)' +SPC+ '(?:Circuit|District|)' +SPC+ '(?:Judge(?:s?))'
PUN = '(?:;|,|)'
JNMT = SPC + JNM + PUN +SPC+ '(?:and|)' +SPC+ TIT + PUN
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

cache_template =    lambda circuit, year, year_idx, ext: (
                        '../data/circ{:2s}.{:02d}-{:04d}.{}'.format(
                            circuit, year%100, year_idx, ext
                        )
                    )

CIRCUIT = 'dc'

if __name__=='__main__':
    for YEAR in list(range(2007,2023)):
        print('\n\n'+str(YEAR)+'\n')
        pdf_urls = []
        for MONTH in range(0+1,12+1):
            uu = URL(YEAR, MONTH)
            print(uu)
            hh = str(requests.get(uu).content)
            mms = re.findall(ROW, hh)
            for mm in mms:
                #print(mm)
                pdf_urls.append(PAGE+mm)

        for i,uu in tqdm.tqdm(list(enumerate(pdf_urls))):
            if uu.endswith('txt'):
                cache_nm = cache_template(CIRCUIT, YEAR, i+1, 'txt')
            elif uu.endswith('pdf'):
                cache_nm = cache_template(CIRCUIT, YEAR, i+1, 'pdf')
            else:
                assert False

            if glob.glob(cache_nm): continue
            hh = requests.get(uu)
            with open(cache_nm, 'wb') as f:
                f.write(hh.content)

    ##with open(cache_nm, 'wb') as f:
    ##    f.write(r.content)

    #try:
    #    url = url_template.format(YEAR, k)
    #    cache_nm = cache_template.format(CIRCUIT, YEAR, k)
    #    tt = extract_page(url, cache_nm)
    #    jj = get_judges(tt)
    #    dd = get_dissent(tt)
    #    if dd:
    #        print('{:4d} -- {} -- \033[33m{}\033[32m'.format(k, ' : '.join(jj), ' : '.join(dd)))
    #except AttributeError:
    #    print('\033[31m$$\033[32m', k)
    #except PyPDF2.errors.PdfReadError:
    #    print('\033[31m<>\033[32m', k)


