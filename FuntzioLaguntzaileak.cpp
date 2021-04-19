#include "FuntzioLaguntzaileak.h"
#include "SinboloTaula.h"
#include "SinboloTaulenPila.h"
#include "Lag.h"
#include "Kodea.h"

using namespace std;

void GehituAldagaiakPilara(SinboloTaulenPila *stPila, IdLista *izenak, string *mota )
{
	SinboloTaula st = stPila->tontorra();
    stPila->despilatu();
    while (izenak->size() > 0) 
    {
    	st.gehituAldagaia(izenak->back(), *mota);    
        izenak->pop_back();
    }
    stPila->pilaratu(st);
}