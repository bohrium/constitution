# author: samtenka
# change: 2023-01-01
# create: 2023-01-01 
# descrp: 
# to use: run `python3 assemble_prose.py`

FILENM = 'constitution.md'
PARTNMS = 'prose-sections/*.md'

import glob

def main():
    if glob.glob(FILENM):
        print('{} already exists'.format(FILENM))
        exit()
    partnms = sorted(glob.glob(PARTNMS))
    texts = []
    for pnm in partnms:
        with open(pnm) as f:
            texts.append(f.read())
    text = '\n'.join(texts)
    with open(FILENM, 'w') as f:
        f.write(text)

if __name__=='__main__':
    main()

