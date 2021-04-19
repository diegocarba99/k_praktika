#include "Kodea.h"
#include "Lag.h"
#include "Erregistroa.h"

using namespace std;

void Erregistroa::idGehitu(const string &motaIzena, const IdLista &idIzenak){
    IdLista::const_iterator iter;
    for (iter=idIzenak.begin(); iter!=idIzenak.end(); iter++){
        struct identifikadore *id = new identifikadore;
        id->izena = *iter;
        id->mota = motaIzena;
        identifikadoreak.push_back(*id);
    }
}

void Erregistroa::gehituProzedura(const prozedura &proz){
    prozedurak.push_back(proz);
}

bool Erregistroa::konprobatuProzedura(const deia &deia){
      Prozedurak::const_iterator iter;
      
  for (iter=prozedurak.begin(); iter!=prozedurak.end(); iter++) {
      if(iter->izena.compare(deia.izena)==0){
        if(deia.id.size()!=iter->motak.size()){
            return false;
        }
        else{
        IdLista::const_iterator iter1;
        IdLista::const_iterator iter2;
        iter1=iter->motak.begin();
        for (iter2=deia.id.begin(); iter2!=deia.id.end(); iter2++) {
            if(konparatuId(*iter1, *iter2)==false){
                return false;
            }
        if(iter2==deia.id.end()){
            break;
        }
        else{
        advance(iter1, 1);
        }
        }
        return true; 
        }  
      }
    }
    return false;
}

bool Erregistroa::konparatuId(const string &mota, const string &id){
    Identifikadoreak::const_iterator iter;
    for (iter=identifikadoreak.begin(); iter!=identifikadoreak.end(); iter++){
        if(iter->izena.compare(id)==0){
            if(iter->mota.compare(mota)==0){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}



