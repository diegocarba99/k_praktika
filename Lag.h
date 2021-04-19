#ifndef LAG_H_
#define LAG_H_

#include <string>
#include <set>
#include <vector>
#include <list>



typedef std::list<int> ErrefLista;
typedef std::list<std::string> IdLista;
typedef std::list<struct identifikadore> Identifikadoreak;
typedef std::list<struct prozedura> Prozedurak;

struct expresionstruct {
  std::string izena ;
  ErrefLista trueLista ;
  ErrefLista falseLista ;
  std::string mota ;
};

struct zerrendastruct {
  IdLista izenak;
  IdLista motak;
};


struct deia {
  std::string izena;
  std::list<std::string> id;
};

struct prozedura {
  std::string izena;
  std::list<std::string> motak;
  std::list<std::string> param;
};

struct identifikadore {
  std::string izena;
  std::string mota;
};




#endif /* LAG_H_ */
