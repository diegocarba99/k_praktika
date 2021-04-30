%define parse.error verbose

%{

  // C++|ko liburutegi estandarrak 
  #include <stdio.h>
  #include <iostream>
  #include <vector>
  #include <string>
  #include <list>
  #include <cstring>



  // Liburutegi pertsonalizatuak
  #include "Kodea.h"
  #include "Lag.h"
  #include "SinboloTaula.h"
  #include "SinboloTaulenPila.h"

  using namespace std;
  
  extern int yylex();
  extern int yylineno;
  extern char *yytext;
  void yyerror (const char *msg) {
    printf("line %d: %s at '%s'\n", yylineno, msg, yytext) ;
  }

  // Definitutako abstrakzioen aurrerazagupena
  Kodea kodea;
  //SinboloTaulenPila stPila;

%}


%code requires 
{
  #include "Kodea.h"
  #include "Lag.h"
  #include "SinboloTaula.h"
  #include "SinboloTaulenPila.h"
}


/**
 * Ikurrez izan dezaketen atributu moten definizioa
 */
%union {
    int ref;
    std::string *izena;
    std::string *mota;
    id_list *izenak;
    ref_list *next;
    expr_st *expr;
    ref_list_st *sent;
}

/**
 * Tokenen erazagupena. 
 */
%token <izena> TID TFLOAT TINTEGER

%token RPROGRAM RIF RWHILE RFOREVER RDO RPROC RUNTIL RELSE RSKIP REXIT RPRINTLN RREAD RINT RFLOAT
%token TMUL TASSIG TADD TSUB TDIV TCEQ TCGT TCLT TCGE TCLE TCNE TSEMIC TCOMMA TLPAREN TRPAREN TLBRACE TRBRACE TOUTPARAM TINOUTPARAM


/*
    Atributuak dituzten ez-bukaerako ikurren erazagupena
*/
%type <expr> adierazpena
%type <izena> aldagaia 
%type <izenak> id_zerrenda id_zerrendaren_bestea
%type <mota> mota par_mota
%type <ref> M
%type <next> N
%type <sent> sententzia sententzia_zerrenda

/* 
    Lehentasunak ezarri.
*/
%nonassoc TCEQ TCGT TCLT TCGE TCLE TCNE PRECED3
%left TADD TSUB                         PRECED2
%left TMUL TDIV                         PRECED1


/*
    Hasierako ikurraren erazagupena.
*/
%start programa



%%

programa :  RPROGRAM TID 
            {
              kodea.agGehitu("prog " + std::string(*$<izena>2));
              delete $<izena>2;
            }
            erazagupenak azpiprogramen_erazagupena TLBRACE sententzia_zerrenda TRBRACE 
            {
              kodea.agGehitu("halt");
              kodea.idatzi();
            }
;

erazagupenak :  mota id_zerrenda TSEMIC 
                {
                  kodea.erazagupenakGehitu(*$<mota>1, *$<izenak>2);

                  delete $<mota>1;
                  delete $<izenak>2;
                }
                erazagupenak
                | /* hutsa */
;

id_zerrenda : TID id_zerrendaren_bestea
              {
                $<izenak>$ = new id_list;
                $<izenak>2->push_front(*$<izena>1);
                $<izenak>$->merge(*$<izenak>2);  
                delete $<izena>1; 
                delete $<izenak>2;
              }
;

id_zerrendaren_bestea : TCOMMA TID id_zerrendaren_bestea
                        {
                          $<izenak>$ = new id_list;
                          $<izenak>3->push_front(*$<izena>2);
                          $<izenak>$->merge(*$<izenak>3);  
                          delete $<izena>2; 
                          delete $<izenak>3;
                        }
                        | /* hutsa */
                        {
                          $<izenak>$ = new id_list;
                        }
;

mota :  RINT
        {
          $<mota>$ = new string("ent");
        }
        | RFLOAT
        {
          $<mota>$ = new string("real");
        }
;

azpiprogramen_erazagupena : azpiprogramaren_erazagupena azpiprogramen_erazagupena
                            | /* hutsa */
;

azpiprogramaren_erazagupena : RPROC TID 
                              {
                                kodea.agGehitu( "proc " + string(*$<izena>2)); 
                              }
                              argumentuak erazagupenak azpiprogramen_erazagupena TLBRACE sententzia_zerrenda TRBRACE
                              {
                                kodea.agGehitu("endproc");
                                delete $<izena>2;
                              }
;

argumentuak : TLPAREN par_zerrenda TRPAREN
              | /* hutsa */
;

par_zerrenda :  mota par_mota id_zerrenda 
                {
                  kodea.parametroakGehitu(string(*$<mota>1), *$<izenak>3, string(*$<mota>2));
                  delete $<mota>1;
                  delete $<izenak>3;
                  delete $<mota>2;
                }
                par_zerrendaren_bestea
;

par_mota :  TOUTPARAM
            {
              $<mota>$ = new string("val");
            }
            | TCLE
            {
              $<mota>$ = new string("ref");
            }
            | TINOUTPARAM
            {
              $<mota>$ = new string("ref");
            }
;

par_zerrendaren_bestea :  TSEMIC mota par_mota id_zerrenda 
                          {
                            kodea.parametroakGehitu(string(*$<mota>2), *$<izenak>4, string(*$<mota>3));
                            delete $<mota>2;
                            delete $<izenak>4;
                            delete $<mota>3;
                          }
                          par_zerrendaren_bestea
                          | /* hutsa */
;

sententzia_zerrenda : sententzia_zerrenda sententzia
                      {
                        $<sent>$ = new ref_list_st;
                        $<sent>$->exit.merge($<sent>1->exit);
                        $<sent>$->exit.merge($<sent>2->exit);

                        $<sent>$->skip.merge($<sent>1->skip);
                        $<sent>$->skip.merge($<sent>2->skip);

                        delete $<sent>1;
                        delete $<sent>2;
                      }
                      | /* hutsa */
                      {
                        $<sent>$ = new ref_list_st;
                      }
; 

sententzia :  aldagaia TASSIG adierazpena TSEMIC
              {
                kodea.agGehitu(string(*$<izena>1) + " := " + $<expr>3->izena);
                $<sent>$ = new ref_list_st;
                delete $<izena>1; 
                delete $<expr>3; 
              }
              | RIF adierazpena TLBRACE M sententzia_zerrenda TRBRACE M TSEMIC
              {
                kodea.agOsatu($<expr>2->true_list, $<ref>4);
                kodea.agOsatu($<expr>2->false_list, $<ref>7);
                $<sent>$ = new ref_list_st;
                $<sent>$->exit.merge($<sent>5->exit);
                $<sent>$->skip.merge($<sent>5->skip);
                delete $<expr>2;
                delete $<sent>5;
              }
              | M RWHILE RFOREVER TLBRACE sententzia_zerrenda TRBRACE M TSEMIC
              {
                kodea.agGehitu("goto " + to_string($<ref>1));
                kodea.agOsatu($<sent>5->exit, $<ref>7+1);
                $<sent>$ = new ref_list_st;
                delete $<sent>5;
              }
              | RDO M TLBRACE sententzia_zerrenda TRBRACE RUNTIL M adierazpena RELSE M TLBRACE sententzia_zerrenda TRBRACE M TSEMIC
              {
                kodea.agOsatu($<expr>8->true_list, $<ref>10);
                kodea.agOsatu($<expr>8->false_list, $<ref>2);
                kodea.agOsatu($<sent>4->exit, $<ref>10);
                kodea.agOsatu($<sent>4->skip, $<ref>7);
                kodea.agOsatu($<sent>12->exit, $<ref>14);
                $<sent>$ = new ref_list_st;
                $<sent>$->skip.merge($<sent>12->skip);
                delete $<expr>8;
                delete $<sent>4;
                delete $<sent>12;
              }
              | RSKIP RIF adierazpena TSEMIC M
              {
                kodea.agOsatu($<expr>3->false_list, $<ref>5);
                $<sent>$ = new ref_list_st;
                $<sent>$->skip.merge($<expr>3->true_list);
                delete $<expr>3;
              }
              | N REXIT TSEMIC
              {
                $<sent>$ = new ref_list_st;
                $<sent>$->exit.merge(*$<next>1);
                cout << "$<sent>$->exit: ";
                for(auto v : $<sent>$->exit) cout << v;
                cout << endl;

              }
              | RREAD TLPAREN aldagaia TRPAREN TSEMIC
              {
                kodea.agGehitu("read " + *$<izena>3);
                $<sent>$ = new ref_list_st;
                delete $<izena>3;
              }
              | RPRINTLN TLPAREN adierazpena TRPAREN TSEMIC
              {
                kodea.agGehitu("write " + string($<expr>3->izena));
                kodea.agGehitu("writeln");
                $<sent>$ = new ref_list_st;
                delete $<expr>3; 
              }
;

aldagaia :  TID
            {
              $<izena>$ = new string(*$<izena>1);
              delete $<izena>1;
            }
;

adierazpena : adierazpena TADD adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = kodea.idBerria();
                kodea.agGehitu($<expr>$->izena + " := " + $<expr>1->izena  + " + " + $<expr>3->izena);
                delete $<expr>1;
                delete $<expr>3;
              }
              | adierazpena TSUB adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = kodea.idBerria();
                kodea.agGehitu($<expr>$->izena + " := " + $<expr>1->izena  + " - " + $<expr>3->izena);
                delete $<expr>1;
                delete $<expr>3;
              }
              | adierazpena TMUL adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = kodea.idBerria();
                kodea.agGehitu($<expr>$->izena + " := " + $<expr>1->izena  + " * " + $<expr>3->izena);
                delete $<expr>1;
                delete $<expr>3;
              }
              | adierazpena TDIV adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = kodea.idBerria();
                kodea.agGehitu($<expr>$->izena + " := " + $<expr>1->izena  + " / " + $<expr>3->izena);
                delete $<expr>1;
                delete $<expr>3;
              }
              | adierazpena TCEQ adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = "";
                $<expr>$->true_list.push_front(kodea.lortuErref());
                $<expr>$->false_list.push_front(kodea.lortuErref()+1); 
                kodea.agGehitu("if " + $<expr>1->izena  + " = " + $<expr>3->izena + " goto ");
                kodea.agGehitu("goto ");
              }
              | adierazpena TCGT adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = "";
                $<expr>$->true_list.push_front(kodea.lortuErref());
                $<expr>$->false_list.push_front(kodea.lortuErref()+1); 
                kodea.agGehitu("if " + $<expr>1->izena  + " > " + $<expr>3->izena + " goto ");
                kodea.agGehitu("goto ");
              }
              | adierazpena TCLT adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = "";
                $<expr>$->true_list.push_front(kodea.lortuErref());
                $<expr>$->false_list.push_front(kodea.lortuErref()+1); 
                kodea.agGehitu("if " + $<expr>1->izena  + " < " + $<expr>3->izena + " goto ");
                kodea.agGehitu("goto ");
              }
              | adierazpena TCGE adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = "";
                $<expr>$->true_list.push_front(kodea.lortuErref());
                $<expr>$->false_list.push_front(kodea.lortuErref()+1); 
                kodea.agGehitu("if " + $<expr>1->izena  + " >= " + $<expr>3->izena + " goto ");
                kodea.agGehitu("goto ");
              }
              | adierazpena TCLE adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = "";
                $<expr>$->true_list.push_front(kodea.lortuErref());
                $<expr>$->false_list.push_front(kodea.lortuErref()+1); 
                kodea.agGehitu("if " + $<expr>1->izena  + " <= " + $<expr>3->izena + " goto ");
                kodea.agGehitu("goto ");
              }
              | adierazpena TCNE adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = "";
                $<expr>$->true_list.push_front(kodea.lortuErref());
                $<expr>$->false_list.push_front(kodea.lortuErref()+1); 
                kodea.agGehitu("if " + $<expr>1->izena  + " != " + $<expr>3->izena + " goto ");
                kodea.agGehitu("goto ");
              }
              | aldagaia
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = string(*$<izena>1);
                delete $<izena>1;
              }
              | TINTEGER
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = string(*$<izena>1);
                delete $<izena>1;
              }
              | TFLOAT
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = string(*$<izena>1);
                delete $<izena>1;
              }
              | TLPAREN adierazpena TRPAREN
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = string($<expr>2->izena);
                $<expr>$->true_list.merge($<expr>2->true_list);
                $<expr>$->false_list.merge($<expr>2->false_list); 
                delete $<expr>2;
              }
    
;

M : /* hutsa */ 
    { 
      $<ref>$ = kodea.lortuErref(); 
    }
  ;


N : /* hutsa */
    { 
      $<next>$ = new ref_list;
      $<next>$->push_back(kodea.lortuErref());
      kodea.agGehitu("goto");
    }
  ;
%%

