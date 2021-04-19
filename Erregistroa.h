#ifndef IDENTIFIKADOREAK_H_
#define IDENTIFIKADOREAK_H_
#include <iostream>
#include <sstream>
#include <fstream>
#include <set>
#include <vector>
#include <list>
#include "Lag.h"

class Erregistroa{

private:





public:

void idGehitu(const std::string &motaIzena, const IdLista &idIzenak);

void gehituProzedura(const prozedura &proz);

bool konprobatuProzedura(const deia &deia);

bool konparatuId(const std::string &mota, const std::string &id);

std::list<struct prozedura> prozedurak;

std::list<struct identifikadore> identifikadoreak;
};



#endif /* KODEA_H_ */