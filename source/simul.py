''' author: sam tenka
    change: 2022-11-09
    create: 2022-11-09
    descrp: Simulate `whittling` SCOTUS appointment process.  Modeling various
            partisan scenarios, measure sensitivity thereto of resulting Court.
    depend:
    jargon:
    to use: Run `python3 simul.py`.
'''

#===============================================================================
#==  3. PLOT  ==================================================================
#===============================================================================

#--------------  0.0.0. import modules  ----------------------------------------

from matplotlib import pyplot as plt
import numpy as np
import tqdm

#--------------  0.2.1. colors  ------------------------------------------------

WHITE        = np.array([1.0 ,1.0 ,1.0 ])
SMOKE        = np.array([ .9 , .9 , .9 ])
SLATE        = np.array([ .5 , .5 , .5 ])
SHADE        = np.array([ .1 , .1 , .1 ])
BLACK        = np.array([ .0 , .0 , .0 ])

RED          = np.array([1.0 , .0 , .0 ]) #####
ORANGE       = np.array([ .75,0.25, .0 ]) #
BROWN        = np.array([ .5 ,0.5 , .0 ]) ###    # i.e., dark YELLOW
OLIVE        = np.array([ .25,0.75, .0 ]) #
GREEN        = np.array([ .0 ,1.0 , .0 ]) #####
AGAVE        = np.array([ .0 , .75, .25]) #
CYAN         = np.array([ .0 , .5 , .5 ]) ###
JUNIPER      = np.array([ .0 , .25, .75]) #
BLUE         = np.array([ .0 , .0 ,1.0 ]) #####
INDIGO       = np.array([ .25, .0 , .75]) #
MAGENTA      = np.array([ .5 , .0 , .5 ]) ###
AMARANTH     = np.array([ .75, .0 , .25]) #

def overlay_color(background, foreground, foreground_opacity=1.0):
    background += foreground_opacity * (foreground - background)

#--------------  3.0.1. define scatter plot initializer  -----------------------
PLT_SIDE = 256
MARG = 4
def new_plot(data_h=PLT_SIDE, data_w=PLT_SIDE, margin=MARG,
             nb_vert_axis_ticks=10, nb_hori_axis_ticks=10):
    # white canvas
    scatter = np.ones((data_h+2*margin,
                       data_w +2*margin,3), dtype=np.float32)

    # grid lines
    for a in range(1,nb_vert_axis_ticks):
        s = int(data_h * float(a)/nb_vert_axis_ticks)
        scatter[margin+(data_h-1-s),margin:margin+data_w] = SMOKE
    for a in range(1,nb_hori_axis_ticks):
        s = int(data_w * float(a)/nb_hori_axis_ticks)
        scatter[margin:margin+data_h,margin+s]            = SMOKE

    ## tick marks
    #for a in range(nb_vert_axis_ticks):
    #    s = int(data_h * float(a)/nb_vert_axis_ticks)
    #    for i in range(nb_vert_axis_ticks)[::-1]:
    #        color = SLATE + 0.04*i*WHITE
    #        scatter[margin+(data_h-1-s)               ,  :margin+2+i] = color
    #for a in range(nb_hori_axis_ticks):
    #    s = int(data_w * float(a)/nb_hori_axis_ticks)
    #    for i in range(nb_hori_axis_ticks)[::-1]:
    #        color = SLATE + 0.04*i*WHITE
    #        scatter[margin+data_h-2-i:2*margin+data_h , margin+s    ] = color

    ## axes
    #scatter[margin+data_h-1      , margin:margin+data_w] = SLATE
    #scatter[margin:margin+data_h , margin              ] = SLATE

    return scatter

#--------------  3.0.2. define feature space scatter plot  --------------------

def initialize(data_h=PLT_SIDE, data_w=PLT_SIDE, margin=MARG,
               nb_vert_axis_ticks=10, nb_hori_axis_ticks=10  ):
    # initialize
    return new_plot(data_h, data_w, margin,
                    nb_vert_axis_ticks, nb_hori_axis_ticks)

def plot_scatter(ys, xs, scatter,
                color=OLIVE, opacity_factor=1.0, rad2=4.0,
                data_h=PLT_SIDE, data_w=PLT_SIDE, margin=MARG,          ):
    # color in data scatter
    for y,x in zip(ys, xs):
        if not (0.<=y<1. and 0.<=x<1.): continue
        r = margin + data_h-1 - int(data_h * y)
        c = margin +            int(data_w * x)
        for dr in range(-margin,margin+1):
            for dc in range(-margin,margin+1):
                opa = opacity_factor * (rad2/float(rad2 + dr*dr+dc*dc))**4
                overlay_color(scatter[r+dr,c+dc], color, opa)

def plot_save(scatter, file_name):
    # save
    plt.imsave(file_name, scatter)

#--------------  3.0.3. make all plots  ----------------------------------------

def make_judge():
    y = 0.0+1.*np.random.beta(32,  8)
    x = 0.0+1.*np.random.beta( 8,  2)

    x = x-0.5
    if np.random.random() < 0.4:
        x = -x
    repscore = (y+x)/2
    demscore = (y-x)/2
    return (repscore,demscore)

#---  _  ----------------------------------------------------------------------

def worst_of(scores, candidates):
    s, i = min((s, i) for i,s in scores.items() if i in candidates)
    return s, i


def preimage(d, val):
    return {k for k,v in d.items() if v==val}


def worst_of_bunch(downvotes, scores):
    mindown = min(downvotes.values())
    argmins = preimage(downvotes, mindown)
    nearargmins = preimage(downvotes, mindown+1)
    if 2<=len(argmins):# or not nearargmins:
        _, i = worst_of(scores, argmins)
    else:
        _, i = worst_of(scores, argmins.union(nearargmins))
    return i


def collect_finalists(downvotes, scores_by_party):
    mindown = min(downvotes.values())
    argmins = preimage(downvotes, mindown)
    sbp = {
        k:{i:vv for i,vv in v.items() if i in argmins}
        for k,v in scores_by_party.items()
    }
    return sbp


def simul_naive(senators, scores_by_party):
    downvotes = {i:0 for i in scores_by_party['rep']}
    for sen in senators:
        i = worst_of_bunch(downvotes, scores_by_party[sen])
        downvotes[i] += 1
    return collect_finalists(downvotes, scores_by_party)


def simul_defect(senators, scores_by_party):
    ''' assumes that all following will be greedy? '''
    downvotes = {i:0 for i in scores_by_party['rep']}
    for k,sen in enumerate(senators):
        #if sen=='rep':#np.random.random()<0.9:
        if np.random.random()<1.0:
            dv = {i:downvotes[i] for i in scores_by_party['rep']}
            for sen_ in senators[k+1:]:
                j = worst_of_bunch(dv, scores_by_party[sen_])
                dv[j] = dv[j] + 1
            i = worst_of_bunch(dv, scores_by_party[sen])
        else:
            i = worst_of_bunch(downvotes, scores_by_party[sen])
        downvotes[i] += 1
    return collect_finalists(downvotes, scores_by_party)



def simul_major(senators, scores_by_party):
    nb_reps = len([s for s in senators if s=='rep']) + 0.1 * np.random.random()
    nb_dems = len([s for s in senators if s=='dem']) + 0.1 * np.random.random()

    sen = 'rep' if nb_dems<nb_reps else 'dem'

    _, i = max((s, i) for i,s in scores_by_party[sen].items())

    scores_by_party = {k:{i:v[i]} for k,v in scores_by_party.items()}
    return scores_by_party

#---  _  ----------------------------------------------------------------------

def convert_to_coors(scores_by_party):
    rs = scores_by_party['rep']
    ds = scores_by_party['dem']
    return ([rs[i]+ds[i]    for i in rs],
            [rs[i]-ds[i]+.5 for i in rs] )



#---  _  ----------------------------------------------------------------------

NB_REPS = 30 # senator count, not judge count
NB_DEMS = 20 # senator count, not judge count
NB_FINS = 3

#NB_JUDGES = NB_REPS+NB_DEMS+NB_FINS
NB_JUDGES = 21#101



#---  _  ----------------------------------------------------------------------




#---  _  ----------------------------------------------------------------------

scatter = initialize()

for _ in tqdm.tqdm(range(100)):
    scores_by_party = {'rep':{}, 'dem':{}}
    for i in range(NB_JUDGES):
        repscore,demscore = make_judge()
        scores_by_party['rep'][i] = repscore
        scores_by_party['dem'][i] = demscore

    senators = (['rep' for _ in range(NB_REPS)]+
                ['dem' for _ in range(NB_DEMS)] )
    np.random.shuffle(senators)

    finalists = simul_naive(senators, scores_by_party)
    ys,xs = convert_to_coors(finalists)
    plot_scatter(ys, xs, scatter, rad2=4.0, color=MAGENTA, opacity_factor=0.9)

    finalists = simul_defect(senators, scores_by_party)
    ys,xs = convert_to_coors(finalists)
    ii = int(len(ys)*np.random.rand())
    plot_scatter(ys[ii:ii+1], xs[ii:ii+1], scatter, rad2=4.0, color=OLIVE, opacity_factor=0.9)

    finalists = simul_major(senators, scores_by_party)
    ys,xs = convert_to_coors(finalists)
    ii = int(len(ys)*np.random.rand())
    plot_scatter(ys[ii:ii+1], xs[ii:ii+1], scatter, rad2=4.0, color=RED, opacity_factor=0.9)

    ys,xs = convert_to_coors(scores_by_party)
    plot_scatter(ys, xs, scatter, rad2=4.0, color=ORANGE, opacity_factor=0.2)

plot_save(scatter, '../figures/example.png')
