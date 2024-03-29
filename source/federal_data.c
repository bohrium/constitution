
#define nb_judges 22
#define nb_cases  459

party_t pres[nb_judges] = {REP,DEM,DEM,DEM,DEM,DEM,DEM,DEM,REP,REP,REP,REP,REP,REP,REP,REP,DEM,REP,DEM,DEM,DEM,DEM};
votes_t vote[nb_cases][nb_judges] = {
    {_,_,_,_,_,_,_,_,_,N,_,_,_,_,Y,_,_,Y,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,Y,_,_,_,_,_,_,_,_,Y,N,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,N,Y,_,_,_,_,_,_,_,_,_,_,_},
    {N,_,_,_,_,_,_,_,_,_,Y,_,_,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,N,Y,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,Y,_,_,_,_,_,_,_,_,_,Y,_,N,_,_,_,_},
    {_,N,_,_,_,Y,_,_,_,_,_,_,_,_,_,Y,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,Y,N,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,Y,_,_,_,_,_,N,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_},
    {_,Y,_,_,_,_,_,_,_,_,_,_,N,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,_,_,N,Y,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,Y,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,N,_,_,_,_,Y,Y,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,N,_,_,_,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,N,Y,_,Y,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,N,_,Y,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,N,_,_,_,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,N,Y,_,_,_,_,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,N,_,_,_,_,Y,_,_,Y,_,_,_,_},
    {_,_,_,_,_,Y,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,N,_,_,Y,_,_,_,_,_,_},
    {Y,_,_,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,_},
    {_,_,_,_,Y,_,_,_,N,_,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,Y,_,_,_,N,_,_,_,_,_,_,_},
    {_,_,_,_,_,Y,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,N,_,_,Y,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,Y,_,Y,_,_,_,N,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,Y,_,_,_,N,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,_,_,Y,N,_,_,_,_,_,_,_,_,_},
    {_,Y,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,Y,_,N,_,_,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,Y,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,_},
    {Y,_,_,_,N,_,_,_,_,_,_,Y,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,_,Y,N,_,_,_,_,_,_,_},
    {_,_,_,_,Y,Y,_,_,_,_,N,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,Y,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,Y,_,N,_,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,Y,_,_,_,_,N,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,Y,_,_,_,_,_,_,N,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,N,_,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,_,_,Y,N,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,N,_,_,_,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,Y,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,_,N,Y,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,N,_,_,_,_,Y,_,_,_,_,_,_,_},
    {Y,_,_,_,_,N,_,_,_,_,_,_,Y,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,_,_,_,N,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,Y,N,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,_,N,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,Y,_,_,N,_,_,_,_,_,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,Y,_,_,_,N,Y,_,_,_,_,_,_},
    {_,N,_,_,_,_,_,Y,_,_,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,N,_,_,_,_,_,_,_,_,_,Y,_,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,_,N,Y,_,_,Y,_,_,_,_},
    {_,_,_,_,_,Y,_,_,Y,_,_,_,_,_,N,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,N,_,Y,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,Y,N,_,_,_,Y,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,Y,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,N,_,_,Y,_,_,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,N,_,_,_,_,_,_,Y,_,_,_,_,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,Y,_,_,_,_,_,N,_,_,_,_,_,_},
    {_,_,_,_,N,Y,_,_,_,_,_,Y,_,_,_,_,_,_,_,_,_,_},
    {_,Y,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,_,_,_,_,Y,_,_,N,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,Y,Y,_,_,N,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,_,_,N,Y,_,_,_,_,_,_},
    {_,_,_,_,_,N,_,Y,_,Y,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,Y,_,_,N,_,_,_,_,_,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,Y,_,Y,_,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,Y,_,N,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,Y,_,N,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,Y,_,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,Y,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,Y,_,_,_,_,_,N,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,_,Y,_,N,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,N,Y,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,_,Y,_,_,_,_},
    {_,Y,_,_,_,_,_,Y,_,_,_,_,_,_,_,_,N,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,N,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,_,_,N,Y,_,_,_,_,_,_},
    {_,_,_,_,_,N,_,_,_,_,_,_,_,_,Y,Y,_,_,_,_,_,_},
    {_,N,_,_,_,_,_,_,Y,_,_,_,_,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,_,_,_,_,_,Y,_,N,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,N,_,_,Y,Y,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,_,_,N,_,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,_,_,Y,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,N,_,_,_,Y,_,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,_,_,_,_,N,Y,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,_,_,_,_,Y,N,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,_,_,_,N,_,_,_,Y,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,Y,_,_,_,N,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,N,_,_,Y,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,Y,_,N,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,N,_,_,_,_,_,Y,_,Y,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,N,Y,_,_,_,Y,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,N,_,_,Y,Y,_,_,_,_,_,_,_,_},
    {_,N,_,_,_,_,_,Y,_,_,_,_,_,_,_,_,Y,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,Y,_,_,N,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,N,_,_,_,Y,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,_,N,_,_,Y,_,_,_,_,_},
    {_,_,_,_,N,_,_,_,Y,_,_,_,_,_,_,_,Y,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,_,_,Y,_,N,_,_,_,_,_},
    {_,N,_,_,_,_,_,_,_,_,_,_,Y,_,_,_,Y,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,N,_,Y,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,N,_,_,Y,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,Y,_,N,_,Y,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,_,Y,_,_,_,_,Y},
    {_,_,_,_,_,_,_,_,Y,_,_,_,_,_,_,N,Y,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,_,_,Y,_,_,_,_,N,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,_,_,_,Y,_,_,_,_,_,_,_,_,N},
    {_,_,_,_,Y,_,_,_,_,_,_,_,_,_,Y,_,N,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,Y,Y,_,_,_,_,_,_,_,N},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,Y,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,N,Y,_,_,_,_,_,_,_,_,Y},
    {_,_,_,_,N,_,_,_,_,_,_,Y,Y,_,_,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,Y,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,N,_,_,Y,_,_,_,_,_,_,_},
    {_,_,Y,_,_,_,_,_,_,_,_,_,_,_,Y,N,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,_,_,Y,N,Y,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,Y,_,_,_,_,_,_},
    {_,_,N,_,_,_,_,_,_,_,_,_,_,_,Y,_,Y,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,_,_,_,_,N,Y,_,_,_,_},
    {_,_,Y,_,_,_,_,_,_,_,_,Y,N,_,_,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,_,_,_,Y,N,_,_,_,_,_,_,_,_,_},
    {_,_,N,_,_,_,_,_,_,Y,_,_,_,_,_,_,_,_,_,_,_,Y},
    {_,N,_,_,_,_,Y,_,_,_,_,_,_,_,_,_,Y,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,Y},
    {_,_,_,_,_,_,_,Y,_,_,_,Y,_,_,_,_,N,_,_,_,_,_},
    {_,_,Y,_,_,_,_,_,_,N,_,_,_,_,_,_,Y,_,_,_,_,_},
    {_,_,_,_,_,_,Y,_,_,_,_,_,_,_,_,_,Y,_,_,_,_,N},
    {_,_,Y,_,_,_,_,_,_,N,_,_,_,_,_,_,_,_,_,_,_,Y},
    {_,_,Y,_,_,_,_,_,_,Y,_,_,_,_,N,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,Y,_,Y,_,_,_,_,_,_,N},
    {_,_,_,_,_,_,Y,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,N,Y,_,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,Y,_,_,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,_,_,N,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_,_,_,Y},
    {_,_,_,_,Y,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,_,_,N},
    {_,_,N,_,_,_,_,_,Y,_,_,_,Y,_,_,_,_,_,_,_,_,_},
    {_,N,Y,_,_,_,_,_,_,_,_,Y,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,_,_,N,_,Y,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,_,_,_,_,_,Y},
    {_,N,_,_,_,_,Y,_,_,_,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,N,_,_,_,_,Y,_,_,_,_,_,_,_,_,_,Y,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,_,Y,_,_,_,_,Y},
    {_,_,_,_,_,_,_,_,_,_,_,_,Y,Y,_,_,N,_,_,_,_,_},
    {Y,_,_,_,N,_,_,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,_,_,Y,_,_,_,_,N,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,Y,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,N,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,_,_,_,Y,Y,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,_,_,Y,N,_,_,_,_,_,_},
    {_,_,_,_,N,_,_,_,_,_,Y,_,_,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,_,_,_,N,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,N,_,_,_,Y,_,_,_,_,_,_},
    {_,Y,_,_,N,_,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,Y,_,Y,_,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,N,_,_,_,_,_,Y,_,_,Y,_,_,_,_},
    {_,_,_,_,Y,_,_,_,N,_,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,Y,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,N,_,_,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,Y},
    {_,_,_,_,_,_,_,_,_,_,_,N,Y,_,_,_,_,_,_,_,_,Y},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,Y,_},
    {_,_,_,_,_,_,Y,_,_,_,_,_,N,Y,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,Y,_,_,_,_,_,N,Y,_,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,_,_,_,_,Y,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,_,_,_,_,_,Y},
    {_,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,_,Y,N,_,_,_,_},
    {_,N,_,_,Y,_,_,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,N,Y,_,_,_,_,_,_,_,_,Y},
    {_,Y,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,Y,_,_,_,N,_,_,Y,_,_},
    {_,_,_,_,Y,_,_,_,Y,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,N,_,_,_,_,Y,_,_,_,_,_,_,Y,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,_,_,Y,_,_,Y,_,N,_,_},
    {_,_,_,_,Y,_,_,_,_,N,_,_,_,_,_,_,Y,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,_,_,Y,_,_,_,_,N,_,_},
    {_,_,_,_,_,_,Y,_,_,_,_,Y,_,_,_,_,_,_,_,_,_,N},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,_,_,_,Y,_,Y},
    {_,_,_,_,Y,_,_,_,_,_,_,_,_,_,Y,_,_,_,_,N,_,_},
    {_,_,_,_,Y,_,Y,_,_,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,Y},
    {_,_,_,_,_,_,_,_,Y,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,_,_,Y,_,N,_,_,_,Y,_},
    {_,_,_,_,N,_,_,_,_,_,_,_,_,_,_,_,Y,_,_,_,Y,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,_,_,_,_,Y,_,_,_,_,N},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,Y},
    {_,_,_,_,_,_,Y,_,Y,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,_,Y},
    {_,Y,_,_,_,_,N,_,_,_,_,Y,_,_,_,_,_,_,_,_,_,_},
    {_,_,Y,_,_,_,_,_,_,_,_,_,N,_,_,_,_,_,_,_,_,Y},
    {_,_,_,_,_,_,Y,_,Y,_,_,_,_,_,N,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,_,Y,_,_},
    {_,Y,_,_,Y,_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,_,_},
    {_,Y,_,_,Y,_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,_,_},
    {_,Y,_,_,Y,_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,Y,_,Y,_,_,_,_,_,_,N},
    {_,_,_,_,_,_,_,_,_,_,_,Y,_,_,Y,_,N,_,_,_,_,_},
    {_,_,Y,_,_,_,_,_,_,_,_,_,_,N,_,_,_,_,_,_,Y,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,Y,_,N,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,_,_,_,_,Y,_},
    {_,_,_,_,_,_,Y,Y,_,_,_,_,_,_,_,_,_,_,_,_,_,N},
    {_,_,_,_,_,_,_,_,Y,_,_,_,N,_,_,_,_,_,_,Y,_,_},
    {_,Y,Y,_,_,_,_,_,_,N,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,N,_,_,_,_,_,_,Y,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,N,_,_,_,_,_,_,_,_,Y},
    {_,_,_,_,Y,_,_,_,_,_,_,_,_,N,_,_,Y,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,N,_,_,_,Y,_,_,_,Y,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,N,_,_,Y,_,_,_,_,_,_,Y,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,_,Y,_,Y},
    {_,_,Y,_,_,_,_,_,_,_,_,_,N,_,_,_,_,_,_,_,Y,_},
    {_,_,_,_,_,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,Y,_,N},
    {_,_,_,_,Y,_,_,_,_,_,_,_,_,N,_,_,Y,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,N,Y,_,_,_,_,_,_,_,_,Y},
    {_,_,_,_,_,_,N,_,_,_,_,_,_,_,_,_,Y,_,_,Y,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,_,N,_,_,Y,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,_,_,_,_,_,Y},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,_,Y,_,_,Y,_},
    {_,_,_,_,N,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,_,_,Y},
    {_,_,_,_,_,_,Y,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,N},
    {_,_,_,_,_,_,_,Y,_,_,_,_,_,Y,_,_,_,_,_,_,N,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,_,_,_,_,Y,_,_,_,_,N},
    {_,_,_,_,_,_,_,_,_,_,_,_,_,_,Y,_,_,_,_,N,_,Y},
    {_,_,_,_,_,_,_,_,Y,_,_,_,_,_,Y,_,N,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,Y,_,_,_,_,Y},
    {_,_,_,_,_,_,_,_,_,_,_,Y,_,_,_,_,Y,_,_,_,N,_},
    {_,_,Y,_,Y,_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,_,_},
    {_,_,Y,_,N,_,_,_,_,_,_,Y,_,_,_,_,_,_,_,_,_,_},
    {_,N,Y,_,_,_,_,_,_,_,_,Y,_,_,_,_,_,_,_,_,_,_},
    {_,_,Y,_,Y,_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,Y,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,Y,Y},
    {_,_,_,_,_,_,_,_,Y,_,_,_,_,_,_,_,Y,_,_,_,N,_},
    {_,_,_,_,Y,_,_,_,N,_,_,_,_,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,_,_,_,_,N,_,_,_,Y,_},
    {_,Y,_,_,_,_,_,_,_,Y,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,Y,Y,_,_,_,_,N},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,_,_,_,_,Y,_},
    {_,_,Y,_,_,_,_,_,_,N,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,Y,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,Y,_},
    {_,_,_,_,_,_,_,_,_,N,_,_,_,_,Y,_,Y,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,Y,_,N,_,_,_,_,_,_,Y},
    {_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,Y,Y,_,_,_,N,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,N,_,_,_,_,_,_,_,Y,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,Y,_,_,_,N,_,_,_,Y,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,_,N,_,_,_,_,_,_,Y,_},
    {_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,_,Y,_,_,_,_,Y},
    {_,Y,_,_,_,_,_,_,N,_,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,_,_,Y,_,_,_,_,_,_,N},
    {_,_,_,_,N,_,_,_,_,Y,_,_,_,_,_,_,Y,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,Y,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,N,_,_,_,_,_,_,Y,_,_,_,_,_,Y},
    {_,_,_,_,Y,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_},
    {_,Y,_,_,N,_,_,_,_,_,_,Y,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,N},
    {_,Y,_,_,_,_,_,_,_,Y,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,N,_,_,_,_,_,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,N,_,_,_,_,_,_,_,Y,_,Y,_,_,_,_,_,_,_,_,_,_},
    {_,Y,_,_,Y,_,_,_,_,N,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,N,_,_,Y,_,_,_,_,_,_,_,_,_,Y},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,N,_,_,_,_,_,_,_,_,_,_,_,_,Y},
    {_,N,_,_,_,_,_,_,_,_,_,_,Y,Y,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,N,_,_,_,_,_,Y,Y,_,_,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,Y,_,_,_,_,_,_,_,_,N,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,_,_,_,N,_,_,_,_,_,Y,_,_,_,_},
    {_,Y,_,_,_,_,_,Y,_,_,_,_,_,_,_,_,N,_,_,_,_,_},
    {_,Y,_,_,_,_,_,Y,_,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,Y,_,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,N,_,_,_,_,Y,_,Y,_,_,_,_,_,_},
    {_,Y,_,_,_,N,_,_,_,_,_,Y,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,Y,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,N,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,N,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,Y,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,Y,_,_,_,N,_,_,_,Y,_,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,Y,_,_,N,_,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,Y,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,N,_,Y,_,_,Y,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {Y,_,_,_,_,_,_,_,_,_,_,_,_,_,N,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,Y,_,Y,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,N,_,Y,_,_,Y,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,Y,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,N,_,Y,_,Y,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,Y,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,N,_,_,_,_,_,_,Y,Y,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,N,_,_,Y,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,Y,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,Y,Y,_,_,_,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,N,_,_,_,_,_,_,_,_,_,_,Y,_,Y,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,Y,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,N,_,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,N,_,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,_,_,N,Y,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,_,_,_,N,_,_,_,_,Y,_,_,_,_},
    {_,Y,_,_,Y,_,_,_,_,_,_,_,_,_,N,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,Y,_,N,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,Y,_,N,_,Y,_,_,_,_,_,_,_},
    {_,Y,_,_,_,N,_,_,_,_,_,_,_,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,Y,_,_,N,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,N,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,N,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,N,_,_,_,_,_,_,_,Y,_,_,Y,_,_,_,_,_,_},
    {Y,_,_,_,_,_,_,_,_,_,Y,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,Y,_,_,N,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,Y,_,_,_,_,_,_},
    {Y,_,_,_,_,Y,_,_,_,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,Y,_,Y,N,_,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,Y,_,N,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,Y,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {Y,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,_,_,_,_,N,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,Y,N,_,_,_,_,_,_,_,_,_,_,_,_},
    {Y,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,N,_,Y,_,_,Y,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_},
    {_,_,_,_,N,_,_,_,Y,_,_,_,_,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,_,N,_,Y,_,_,_,_,Y,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,Y,Y,_,_,_,_,_,_,_,_,_,N,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,N,_,_,_,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,Y,_,_,Y,_,_,N,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,Y,_,_,Y,_,_,N,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,_,_,Y,N,_,Y,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,N,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,N,_,_,_,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,Y,Y,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,Y,_,_,Y,_,_,_,_,N,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,N,_,_,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,N,_,_,_,Y,_,_,_,_,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,N,_,_,_,Y,Y,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,Y,_,_,N,_,_,_,_,_,_,_,_,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,_,Y,_,_,_,_,_,_,Y,_,_,_,_,N,_,_,_,_},
    {_,Y,_,_,Y,_,_,_,_,N,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,N,_,_,Y,_,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,N,_,_,_,Y,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {N,_,_,_,Y,Y,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,N,_,_,_,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,N,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,_,N,_,Y,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,Y,_,_,_,N,_,_,Y,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,_,_,Y,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,N,Y,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,N,_,_,_,_,Y,Y,_,_,_,_,_,_,_,_,_,_,_},
    {Y,_,_,_,_,Y,_,_,N,_,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,N,_,_,_,_,Y,_,_,_,Y,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,Y,_,_,_,N,_,_,_,_,_,Y,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,Y,_,_,_,_,_,_,_,_,N,_,_,_,_},
    {_,_,_,_,_,_,_,Y,Y,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,_,Y,_,_,_,_},
    {_,Y,_,_,N,_,_,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,Y,_,N,_,_,Y,_,_,_,_,_,_,_,_,_,_,_},
    {_,Y,_,_,_,_,_,_,_,_,Y,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,Y,_,_,_,Y,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,_,_,N,_,_,_,_,_,Y,_},
    {_,_,_,_,N,_,_,_,_,_,_,Y,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,N,_,_,_,_,_,_,Y,_,_},
    {_,_,Y,_,_,_,_,_,_,_,_,_,_,_,Y,_,_,_,_,_,_,N},
    {_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,Y,Y},
    {_,Y,Y,_,_,_,_,_,_,N,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,_,_,_,_,N,_,_,_,_,Y},
    {_,_,_,_,N,_,Y,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,N,_,_,Y,_,_,_,_,Y,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,Y,_,_,_,_,_,_,_,Y,_,_,_,_,_,_,N},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,Y,_},
    {_,_,_,_,_,_,_,_,Y,N,_,_,Y,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,_,_,N,_,_,_,_,_,_,Y},
    {_,_,_,_,_,_,_,_,Y,_,_,_,N,_,_,_,Y,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,Y,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,N,_,_,_,_,_,_,_,_,Y,_},
    {_,_,_,_,N,_,_,_,_,_,_,_,Y,_,_,_,Y,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,Y},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,Y},
    {_,_,Y,_,_,_,_,_,_,_,_,_,N,_,_,_,_,_,_,_,Y,_},
    {_,_,N,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,Y,_,Y,_,_,_,_,_,_,_,N,_,_,_,_,_},
    {_,_,_,_,Y,_,Y,_,_,_,_,_,_,_,_,_,N,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,_,N,_,_,_,_,_,Y,_,_},
    {_,_,_,_,_,_,_,_,N,_,_,_,Y,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,Y,_,_,_,_,_,_,_,_,_,N,_,_,Y,_,_},
    {_,_,Y,_,_,_,_,_,_,_,_,_,N,_,_,_,_,_,_,Y,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,Y,_,_,_,_,N,_,_,_,_,_},
    {_,_,Y,_,_,_,_,_,Y,_,_,N,_,_,_,_,_,_,_,_,_,_},
    {_,_,Y,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,Y},
    {_,_,Y,_,_,_,_,_,_,_,_,Y,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,N,_,_,_,_,_,_,_,_,Y,_,_,_,_,_,Y,_,_},
    {_,_,_,_,_,_,_,_,N,_,_,_,Y,_,_,_,Y,_,_,_,_,_},
    {_,_,_,_,_,_,Y,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,Y,_,_,_,_,_,_,N,_,_,_,Y,_},
    {_,_,_,_,Y,_,_,_,_,_,_,N,_,_,_,_,_,_,_,_,Y,_},
    {_,_,_,_,_,_,Y,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,Y,_,_,_,_,_,N,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,Y,_,_,_,_,N,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,N,Y,_,_,_,Y},
    {_,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,_,_,_,_,_,Y},
    {_,_,_,_,_,_,_,_,_,_,_,Y,Y,_,N,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,Y,_,_,_,N,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,_,_,Y,_,_,_,_,N,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,_,_,_,_,Y,_},
    {_,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,_,Y,_,_,_,N,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,Y,_,_,_,_,_},
    {_,_,Y,_,Y,_,_,_,_,_,_,N,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,N,Y,_,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,Y,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,_,_,N,_,_,_,_,Y,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,Y,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,N,Y,_,_,_,Y},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,_,_,_,_,_,Y},
    {_,_,_,_,_,_,Y,_,Y,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,Y,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,_,Y,_},
    {_,_,_,_,N,_,_,_,_,_,_,Y,_,_,_,_,Y,_,_,_,_,_},
    {_,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,_,N,_,_,_,Y,_},
    {_,N,_,_,_,_,_,_,_,Y,_,_,_,_,_,_,Y,_,_,_,_,_},
    {_,_,_,_,_,_,_,Y,Y,_,_,N,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,Y,Y,_,N,_,_,_,_,_,_,_},
    {_,_,Y,_,_,_,_,Y,_,_,_,_,N,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,N,_,_,_,_,_,_,_,Y,_,_,_,_,_,_,_},
    {_,_,_,_,Y,_,_,_,_,_,_,_,N,_,_,_,_,Y,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,N,_,Y,_,_,_,_,Y,_,_},
    {_,_,_,_,_,_,Y,_,_,_,_,_,_,_,_,_,_,_,_,Y,N,_}
};
char    name[nb_judges][32] = {"Archer","Bryson","Chen","Davis","Dyk","Gajarsa","Hughes","Linn","Lourie","Mayer","Michel","Moore","Newman","Plager","Prost","Rader","Reyna","Schall","Stark","Stoll","Taranto","Wallach"};
