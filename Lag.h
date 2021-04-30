#ifndef LAG_H_
#define LAG_H_

#include <string>
#include <set>
#include <vector>
#include <list>

using namespace std;

typedef list<int> ref_list;
typedef list<string> id_list;
typedef list<struct identifikadore> identifikadoreak;
typedef list<struct prozedura> prozedurak;

struct ref_list_st {
  ref_list exit;
  ref_list skip;
};

struct expr_st {
  string   izena ;
  ref_list true_list ;
  ref_list false_list ;
  //string   mota ;
};



struct zerrendastruct {
  id_list izenak;
  id_list motak;
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
