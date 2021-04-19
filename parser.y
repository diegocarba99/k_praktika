%define parse.error verbose

%{

  // C++|ko liburutegi estandarrak 
  #include <stdio.h>
  #include <iostream>
  #include <vector>
  #include <string>

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
  SinboloTaulenPila stPila;

%}

/**
 * Ikurrez izan dezaketen atributu moten definizioa
 */
%union {
    string *izena ;
    string *mota ;
    IdLista *izenak ;
    expressionstruct *adi ;
    ErrefLista *next;
    ErrefLista *exit;
    ErrefLista *skip;
    int erref ;
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
%type <mota> type erag_erl erag_addsub erag_muldiv
%type <adi> expr
%type <izenak> idlist
%type <erref> M
%type <next> N
%type <exit> sententzia sententzia_zerrenda
%type <skip> sententzia sententzia_zerrenda

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
              SinboloTaula st;
              stPila.pilaratu(st);
              delete $<izena>2;
            }
            erazagupenak azpiprogramen_erazagupena TLBRACE sententzia_zerrenda TRBRACE 
            {
              kodea.agGehitu("halt");
              kodea.idatzi();
              stPila.despilatu(); 
            }
;

erazagupenak :  mota id_zerrenda TSEMIC 
                {
                  kodea.erazagupenakGehitu(*$<mota>1, *$<izenak>2);
                  GehituAldagaiakPilara(*stPila, *$<izenak>2, *$<mota>1 );
                  /* SinboloTaula st = stPila.tontorra();
                  stPila.despilatu();
                  while ($<izenak>2->size() > 0) 
                  {
                    st.gehituAldagaia($<izenak>2->back(), *$<mota>1);    
                    $<izenak>2->pop_back();
                  }
                  stPila.pilaratu(st); */
                  delete $<mota>1;
                  delete $<izenak>2;
                }
                erazagupenak
                | /* hutsa */
;

id_zerrenda : TID id_zerrendaren_bestea
              {
                $<izenak>$ = new IdLista;
                $<izenak>2->push_front(*$<izena>1);
                $<izenak>$->merge(*$<izenak>2);  
                delete $<izena>1; 
                delete $<izenak>2;
              }
;

id_zerrendaren_bestea : TCOMMA TID id_zerrendaren_bestea
                        {
                          $<izenak>$ = new IdLista;
                          $<izenak>3->push_front(*$<izena>2);
                          $<izenak>$->merge(*$<izenak>3);  
                          delete $<izena>2; 
                          delete $<izenak>3;
                        }
                        | /* hutsa */
                        {
                          $<izenak>$ = new IdLista;
                        }
;

mota :  RINT
        {
          $<mota>$ = new std::string("ent");
        }
        | RFLOAT
        {
          $<mota>$ = new std::string("real");
        }
;

azpiprogramen_erazagupena : azpiprogramaren_erazagupena azpiprogramen_erazagupena
                            | /* hutsa */
;

azpiprogramaren_erazagupena : RPROC TID 
                              {
                                kodea.agGehitu( "proc " + std::string(*$<izena>2)); 
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
                  kodea.parametroakGehitu(std::string(*$<mota>1), *$<izenak>3, std::string(*$<mota>2));
                  delete $<mota>1;
                  delete $<izenak>3;
                  delete $<mota>2;
                }
                par_zerrendaren_bestea
;

par_mota :  TOUTPARAM
            {
              $<mota>$ = new std::string("val");
            }
            | TCLE
            {
              $<mota>$ = new std::string("ref");
            }
            | TINOUTPARAM
            {
              $<mota>$ = new std::string("ref");
            }
;

par_zerrendaren_bestea :  TSEMIC mota par_mota id_zerrenda 
                          {
                            kodea.parametroakGehitu(std::string(*$<mota>2), *$<izenak>4, std::string(*$<mota>3));
                            delete $<mota>2;
                            delete $<izenak>4;
                            delete $<mota>3;
                          }
                          par_zerrendaren_bestea
                          | /* hutsa */
;

sententzia_zerrenda : sententzia_zerrenda sententzia
                      {
                        $<exit>$ = new ErrefLista;
                        $<exit>$->merge(*$<exit>1);
                        $<exit>$->merge(*$<exit>2);

                        $<skip>$ = new ErrefLista;
                        $<skip>$->merge(*$<skip>1);
                        $<skip>$->merge(*$<skip>2);

                        delete $<exit>1;
                        delete $<exit>2;
                        delete $<skip>1;
                        delete $<skip>2;

                      }
                      | /* hutsa */
                      {
                        $<exit>$ = new ErrefLista;
                        $<skip>$ = new ErrefLista;
                      }
; 

sententzia :  aldagaia TASSIG adierazpena TSEMIC
              {
                kodea.agGehitu(std::string(*$<izena>1) + " := " + $<adi>3->izena);
                $<exit>$ = new ErrefLista;
                $<skip>$ = new ErrefLista;
                delete $<izena>1; 
                delete $<adi>3; 
              }
              | RIF adierazpena TLBRACE M sententzia_zerrenda TRBRACE M TSEMIC
              {
                kodea.agOsatu($<adi>2->trueL, $<erref>4);
                kodea.agOsatu($<adi>2->falseL, $<erref>7);
                $<exit>$ = new ErrefLista($<exit>5);
                $<skip>$ = new ErrefLista($<skip>5);
                delete $<adi>2;
                delete $<exit>5;
                delete $<skip>5;
              }
              | M RWHILE RFOREVER TLBRACE sententzia_zerrenda TRBRACE M TSEMIC
              {
                kodea.agGehitu("goto " + string($<erref>1));
                kode.agOsatu(*$<exit>5, $<erref>7+1);
                $<exit>$ = new ErrefLista;
                $<skip>$ = new ErrefLista;
                delete $<exit>5;
              }
              | RDO M TLBRACE sententzia_zerrenda TRBRACE RUNTIL M adierazpena RELSE M TLBRACE sententzia_zerrenda TRBRACE TSEMIC
              {
                kodea.agOsatu($<adi>8->trueL, $<erref>10);
                kodea.agOsatu($<adi>8->falseL, $<erref>2);
                kodea.agOsatu(*$<exit>4, $<erref>10);
                kodea.agOsatu(*$<skip>4, $<erref>7);
                $<exit>$ = new ErrefLista($<exit>12);
                $<skip>$ = new ErrefLista($<skip>12);
                delete $<adi>8;
                delete $<exit>4;
                delete $<exit>12;
                delete $<skip>4;
                delete $<skip>12;
              }
              | RSKIP RIF adierazpena TSEMIC M
              {
                kodea.agOsatu($<adi>3->falseL, $<erref>5);
                $skip$ = new ErrefLista($<adi>3->trueL);
                $exit$ = new ErrefLista;
                delete $<adi>3;
              }
              | N REXIT TSEMIC
              {
                $exit$ = new ErrefLista($<next>1);
                $skip$ = new ErrefLista;

              }
              | RREAD TLPAREN aldagaia TRPAREN TSEMIC
              {
                kodea.agGehitu("read " + string(*$<izena>3));
                $exit$ = new ErrefLista;
                $skip$ = new ErrefLista;
                delete $<izena>3;
              }
              | RPRINTLN TLPAREN adierazpena TRPAREN TSEMIC
              {
                kodea.agGehitu("write " + string($<adi>3->izena));
                kodea.agGehitu("writeln");
                $exit$ = new ErrefLista;
                $skip$ = new ErrefLista;
                delete $<adi>3; 
              }
;

aldagaia :  TID
            {
              $izena$ = new string(*$<izena>1);
              delete $<izena>1;
            }
;

adierazpena : adierazpena TADD adierazpena
              {
                $<adi>$ = new expressionstruct;
                $<adi>$->izena = kodea.idBerria();
                $<adi>$->trueL = new ErrefLista;
                $<adi>$->falseL = new ErrefLista; 
                //$<adi>$->mota = kalkulatuMota($<adi>1->mota, $<adi>3->mota);
                kodea.agGehitu($<adi>$->izena + " := " + $<adi>1->izena  + " + " + $<adi>3->izena);
                delete $<adi>1;
                delete $<adi>3;
              }
              | adierazpena TSUB adierazpena
              {
                $<adi>$ = new expressionstruct;
                $<adi>$->izena = kodea.idBerria();
                $<adi>$->trueL = new ErrefLista;
                $<adi>$->falseL = new ErrefLista; 
                $<adi>$->mota = kalkulatuMota($<adi>1->mota, $<adi>3->mota);
                //kodea.agGehitu($<adi>$->izena + " := " + $<adi>1->izena  + " - " + $<adi>3->izena);
                delete $<adi>1;
                delete $<adi>3;
              }
              | adierazpena TMUL adierazpena
              {
                $<adi>$ = new expressionstruct;
                $<adi>$->izena = kodea.idBerria();
                $<adi>$->trueL = new ErrefLista;
                $<adi>$->falseL = new ErrefLista; 
                //$<adi>$->mota = kalkulatuMota($<adi>1->mota, $<adi>3->mota);
                kodea.agGehitu($<adi>$->izena + " := " + $<adi>1->izena  + " * " + $<adi>3->izena);
                delete $<adi>1;
                delete $<adi>3;
              }
              | adierazpena TDIV adierazpena
              {
                $<adi>$ = new expressionstruct;
                $<adi>$->izena = kodea.idBerria();
                $<adi>$->trueL = new ErrefLista;
                $<adi>$->falseL = new ErrefLista; 
                //$<adi>$->mota = "real";
                kodea.agGehitu($<adi>$->izena + " := " + $<adi>1->izena  + " / " + $<adi>3->izena);
                delete $<adi>1;
                delete $<adi>3;
              }
              | adierazpena TCEQ adierazpena
              {
                $<adi>$ = new expressionstruct;
                $<adi>$->izena = "";
                $<adi>$->trueL = new ErrefLista(1, kodea.lortuErref());
                $<adi>$->falseL = new ErrefLista(1, kodea.lortuErref()+1); 
                kodea.agGehitu("if " + $<adi>1->izena  + " == " + $<adi>3->izena + " goto ");
                kodea.agGehitu("goto ");
              }
              | adierazpena TCGT adierazpena
              {
                $<adi>$ = new expressionstruct;
                $<adi>$->izena = "";
                $<adi>$->trueL = new ErrefLista(1, kodea.lortuErref());
                $<adi>$->falseL = new ErrefLista(1, kodea.lortuErref()+1); 
                kodea.agGehitu("if " + $<adi>1->izena  + " > " + $<adi>3->izena + " goto ");
                kodea.agGehitu("goto ");
              }
              | adierazpena TCLT adierazpena
              {
                $<adi>$ = new expressionstruct;
                $<adi>$->izena = "";
                $<adi>$->trueL = new ErrefLista(1, kodea.lortuErref());
                $<adi>$->falseL = new ErrefLista(1, kodea.lortuErref()+1); 
                kodea.agGehitu("if " + $<adi>1->izena  + " < " + $<adi>3->izena + " goto ");
                kodea.agGehitu("goto ");
              }
              | adierazpena TCGE adierazpena
              {
                $<adi>$ = new expressionstruct;
                $<adi>$->izena = "";
                $<adi>$->trueL = new ErrefLista(1, kodea.lortuErref());
                $<adi>$->falseL = new ErrefLista(1, kodea.lortuErref()+1); 
                kodea.agGehitu("if " + $<adi>1->izena  + " >= " + $<adi>3->izena + " goto ");
                kodea.agGehitu("goto ");
              }
              | adierazpena TCLE adierazpena
              {
                $<adi>$ = new expressionstruct;
                $<adi>$->izena = "";
                $<adi>$->trueL = new ErrefLista(1, kodea.lortuErref());
                $<adi>$->falseL = new ErrefLista(1, kodea.lortuErref()+1); 
                kodea.agGehitu("if " + $<adi>1->izena  + " <= " + $<adi>3->izena + " goto ");
                kodea.agGehitu("goto ");
              }
              | adierazpena TCNE adierazpena
              {
                $<adi>$ = new expressionstruct;
                $<adi>$->izena = "";
                $<adi>$->trueL = new ErrefLista(1, kodea.lortuErref());
                $<adi>$->falseL = new ErrefLista(1, kodea.lortuErref()+1); 
                kodea.agGehitu("if " + $<adi>1->izena  + " != " + $<adi>3->izena + " goto ");
                kodea.agGehitu("goto ");
              }
              | aldagaia
              {
                $<adi>$ = new expressionstruct;
                $<adi>$->izena = string(*$<izena>1);
                $<adi>$->trueL = new ErrefLista;
                $<adi>$->falseL = new ErrefLista; 
                delete $<izena>1;
              }
              | TINTEGER
              {
                $<adi>$ = new expressionstruct;
                $<adi>$->izena = std::string(*$<izena>1);
                $<adi>$->trueL = new ErrefLista;
                $<adi>$->falseL = new ErrefLista; 
                $<adi>$->mota = "ent"; 
                delete $<izena>1;
              }
              | TFLOAT
              {
                $<adi>$ = new expressionstruct;
                $<adi>$->izena = std::string(*$<izena>1);
                $<adi>$->trueL = new ErrefLista;
                $<adi>$->falseL = new ErrefLista; 
                $<adi>$->mota = "real"; 
                delete $<izena>1;
              }
              | TLPAREN adierazpena TRPAREN
              {
                $<adi>$ = new expressionstruct;
                $<adi>$->izena = std::string(*$<adi>2->izena);
                $<adi>$->trueL = new ErrefLista($<adi>2->trueL);
                $<adi>$->falseL = new ErrefLista($<adi>2->falseL); 
                //$<adi>$->mota = ;
                delete $<adi>2;
              }
    
;

M : /* hutsa */ 
    { 
      $<erref>$ = kodea.lortuErref(); 
    }
  ;


N : /* hutsa */
    { 
      $<next>$ = new ErrefLista;
      $<next>$->push_back(kodea.lortuErref());
      kodea.agGehitu("goto");
    }
  ;
%%

