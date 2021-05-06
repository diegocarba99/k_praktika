#ifndef LAG_H_
#define LAG_H_

#include <string>
#include <set>
#include <vector>
#include <list>
#include <sstream>

using namespace std;


#define ADI_ERL "adierazpen erlazionala"

#define ADI_ADD 0
#define ADI_SUB 1
#define ADI_MUL 2
#define ADI_DIV 3

#define ERR_NONE 0
#define ERR_IF 1
#define ERR_DO 2
#define ERR_SKIP 3
#define ERR_PRINT 4

#define MOTA_ENT "ent"
#define MOTA_REAL "real"
#define PAR_VAL "val"
#define PAR_REF "ref"




typedef list<int> ref_list;
typedef list<string> message_list;
typedef list<string> id_list;
typedef list<struct identifikadore> identifikadoreak;
typedef list<struct prozedura> prozedurak;

struct ref_list_st {
  ref_list exit;
  ref_list skip;
  message_list error;
};

struct expr_st {
  string   izena ;
  ref_list true_list ;
  ref_list false_list ;
  string   mota ;
};

struct var_st {
  string izena;
  string mota;
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
