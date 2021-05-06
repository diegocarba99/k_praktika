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
  #include "Printer.h"

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
    var_st *var;
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
%type <var> aldagaia 
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
              SinboloTaula st;
              stPila.pilaratu(st);
              delete $<izena>2;
            }
            erazagupenak azpiprogramen_erazagupena TLBRACE sententzia_zerrenda TRBRACE 
            {
              if ( ! $<sent>7->error.empty() )
              {
                printErrors($<sent>7->error);
              } 
              else
              {
                kodea.agGehitu("halt");
                kodea.idatzi();
                stPila.despilatu();
              }
            }
;

erazagupenak :  mota id_zerrenda TSEMIC 
                {
                  kodea.erazagupenakGehitu(*$<mota>1, *$<izenak>2);

                  // st_gehitu_aldagaiak();
                  id_list *izenak = $<izenak>2;
                  SinboloTaula st = stPila.tontorra();
                  stPila.despilatu();
                  while (izenak->size()>0){
                    st.gehituAldagaia(izenak->back(), *$<mota>1);  
                    izenak->pop_back();
                  }
                  stPila.pilaratu(st);


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
          $<mota>$ = new string(MOTA_ENT);
        }
        | RFLOAT
        {
          $<mota>$ = new string(MOTA_REAL);
        }
;

azpiprogramen_erazagupena : azpiprogramaren_erazagupena azpiprogramen_erazagupena
                            | /* hutsa */
;

azpiprogramaren_erazagupena : RPROC TID 
                              {
                                kodea.agGehitu( "proc " + string(*$<izena>2)); 
                                SinboloTaula *st = new SinboloTaula; 
                                st->gehituProzedura(*$<izena>2);
                                stPila.pilaratu(*st);
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

                  // st_gehitu_parametroak
                  id_list *izenak = $<izenak>3;
                  //std::cout << "izenak lista sortu\n";
                  SinboloTaula st = stPila.tontorra();
                  //std::cout << "sinbolo taularen tontorra atzitu\n";
                  stPila.despilatu();
                  string prozeduraID = st.lortuLehenengoId();
                  //std::cout << "sinbolo taulako tontorra despilatu\n";
                  while (izenak->size()>0){
                    st.gehituParametroa(prozeduraID, *$<mota>2, *$<mota>1);
                    //std::cout << "st.gehituParametroa\n";
                    st.gehituAldagaia(izenak->back(), *$<mota>1);
                    //std::cout << "st.gehituAldagaia\n";
                    izenak->pop_back();
                    //std::cout << "izena atera zerrendatik\n";
                  }
                  stPila.pilaratu(st);
                  //std::cout << "pilaratu st\n";


                  delete $<mota>1;
                  delete $<mota>2;
                  delete $<izenak>3;
                }
                par_zerrendaren_bestea
;

par_mota :  TOUTPARAM
            {
              $<mota>$ = new string(PAR_VAL);
            }
            | TCLE
            {
              $<mota>$ = new string(PAR_REF);
            }
            | TINOUTPARAM
            {
              $<mota>$ = new string(PAR_REF);
            }
;

par_zerrendaren_bestea :  TSEMIC mota par_mota id_zerrenda 
                          {
                            kodea.parametroakGehitu(string(*$<mota>2), *$<izenak>4, string(*$<mota>3));

                            // st_gehitu_parametroak
                            id_list *izenak = $<izenak>4;
                            SinboloTaula st = stPila.tontorra();
                            stPila.despilatu();
                            string prozeduraID = st.lortuLehenengoId();
                            while (izenak->size()>0){
                              st.gehituParametroa(prozeduraID, *$<mota>3, *$<mota>2);
                              st.gehituAldagaia(izenak->back(), *$<mota>2);
                              izenak->pop_back();
                            }
                            stPila.pilaratu(st);

                            delete $<mota>2;
                            delete $<mota>3;
                            delete $<izenak>4;
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

                        $<sent>$->error.merge($<sent>1->error);
                        $<sent>$->error.merge($<sent>2->error);

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
                $<sent>$ = new ref_list_st;
                if ($<var>1->mota == MOTA_ENT && $<expr>3->mota == MOTA_REAL){
                  $<var>1->mota = MOTA_REAL;
                  kodea.agGehitu("implicit_conversion_to_real " + $<var>1->izena);
                }
                kodea.agGehitu($<var>1->izena + " := " + $<expr>3->izena);

                
                
                if ( $<var>1->mota.compare($<expr>3->mota) != 0) {
                  //$<sent>$->error.merge(kalkulatuErroreak(ERR_NONE,*$<var>1, *$<expr>3)); 
                  kalkulatuErroreak($<sent>$->error, *$<var>1, *$<expr>3); 
                }

                delete $<var>1; 
                delete $<expr>3; 
              }
              | RIF adierazpena TLBRACE M sententzia_zerrenda TRBRACE M TSEMIC
              {
                kodea.agOsatu($<expr>2->true_list, $<ref>4);
                kodea.agOsatu($<expr>2->false_list, $<ref>7);
                $<sent>$ = new ref_list_st;
                $<sent>$->exit.merge($<sent>5->exit);
                $<sent>$->skip.merge($<sent>5->skip);
                $<sent>$->error.merge($<sent>5->error);

                

                if ($<expr>2->mota.compare(ADI_ERL) != 0)
                  kalkulatuErroreak($<sent>$->error, ERR_IF, *$<expr>2);

                delete $<expr>2;
                delete $<sent>5;
              }
              | M RWHILE RFOREVER TLBRACE sententzia_zerrenda TRBRACE M TSEMIC
              {
                kodea.agGehitu("goto " + to_string($<ref>1));
                kodea.agOsatu($<sent>5->exit, $<ref>7+1);
                $<sent>$ = new ref_list_st;
                $<sent>$->error.merge($<sent>5->error);
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

                

                if ($<expr>8->mota.compare(ADI_ERL) != 0)
                  kalkulatuErroreak($<sent>$->error, ERR_DO, *$<expr>8);

                $<sent>$->error.merge($<sent>4->error);
                $<sent>$->error.merge($<sent>12->error);


                delete $<expr>8;
                delete $<sent>4;
                delete $<sent>12;
              }
              | RSKIP RIF adierazpena TSEMIC M
              {
                kodea.agOsatu($<expr>3->false_list, $<ref>5);
                $<sent>$ = new ref_list_st;
                $<sent>$->skip.merge($<expr>3->true_list);

                

                if ($<expr>3->mota.compare(ADI_ERL) != 0)
                  kalkulatuErroreak($<sent>$->error, ERR_SKIP, *$<expr>3);

                delete $<expr>3;
              }
              | N REXIT TSEMIC
              {
                $<sent>$ = new ref_list_st;
                $<sent>$->exit.merge(*$<next>1);
              }
              | RREAD TLPAREN aldagaia TRPAREN TSEMIC
              {
                kodea.agGehitu("read " + $<var>3->izena);
                $<sent>$ = new ref_list_st;
                
                // ikusi ea aldagia definitu den S_Tn

                delete $<var>3;
              }
              | RPRINTLN TLPAREN adierazpena TRPAREN TSEMIC
              {
                kodea.agGehitu("write " + string($<expr>3->izena));
                kodea.agGehitu("writeln");
                $<sent>$ = new ref_list_st;

                if ($<expr>3->mota.compare(ADI_ERL) == 0)
                  kalkulatuErroreak($<sent>$->error, ERR_PRINT, *$<expr>3);

                delete $<expr>3; 
              }
;

aldagaia :  TID
            {
              $<var>$ = new var_st;
              $<var>$->izena = string(*$<izena>1);
              $<var>$->mota = stPila.lortuMota(*$<izena>1);
              delete $<izena>1;
            }
;

adierazpena : adierazpena TADD adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = kodea.idBerria();

                int mota_aldaketa = kalkulatuMota(*$<expr>$, *$<expr>1, *$<expr>3);
                string ad1_converted, ad2_converted;

                if (mota_aldaketa == 0)  // ez dago mota aldaketarik. izenak mantendu
                {
                  ad1_converted = $<expr>1->izena;
                  ad2_converted = $<expr>3->izena;
                } 
                else if (mota_aldaketa == 1)  // 1go adierazpena aldatu real motara
                {
                  ad1_converted = kodea.idBerria();
                  ad2_converted = $<expr>3->izena;
                  kodea.agGehitu(ad1_converted + " := ent_to_real(" + $<expr>1->izena  + ")");
                }
                else if (mota_aldaketa == 2)  // 2go adierazpena aldatu real motara
                {
                  ad1_converted = $<expr>1->izena;
                  ad2_converted = kodea.idBerria();
                  kodea.agGehitu(ad2_converted + " := ent_to_real(" + $<expr>3->izena  + ")");
                }
                else  // 1go eta 2n adierazpenak aldatu real motara
                {
                  ad1_converted = kodea.idBerria();
                  ad2_converted = kodea.idBerria();
                  kodea.agGehitu(ad1_converted + " := ent_to_real(" + $<expr>1->izena  + ")");
                  kodea.agGehitu(ad2_converted + " := ent_to_real(" + $<expr>3->izena  + ")");
                }

                kodea.agGehitu($<expr>$->izena + " := " + ad1_converted  + " + " + ad2_converted);
                
                delete $<expr>1;
                delete $<expr>3;
              }
              | adierazpena TSUB adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = kodea.idBerria();

                int mota_aldaketa = kalkulatuMota(*$<expr>$, *$<expr>1, *$<expr>3);
                string ad1_converted, ad2_converted;

                if (mota_aldaketa == 0)  // ez dago mota aldaketarik. izenak mantendu
                {
                  ad1_converted = $<expr>1->izena;
                  ad2_converted = $<expr>3->izena;
                } 
                else if (mota_aldaketa == 1)  // 1go adierazpena aldatu real motara
                {
                  ad1_converted = kodea.idBerria();
                  ad2_converted = $<expr>3->izena;
                  kodea.agGehitu(ad1_converted + " := ent_to_real(" + $<expr>1->izena  + ")");
                }
                else if (mota_aldaketa == 2)  // 2go adierazpena aldatu real motara
                {
                  ad1_converted = $<expr>1->izena;
                  ad2_converted = kodea.idBerria();
                  kodea.agGehitu(ad2_converted + " := ent_to_real(" + $<expr>3->izena  + ")");
                }
                else  // 1go eta 2n adierazpenak aldatu real motara
                {
                  ad1_converted = kodea.idBerria();
                  ad2_converted = kodea.idBerria();
                  kodea.agGehitu(ad1_converted + " := ent_to_real(" + $<expr>1->izena  + ")");
                  kodea.agGehitu(ad2_converted + " := ent_to_real(" + $<expr>3->izena  + ")");
                }

                kodea.agGehitu($<expr>$->izena + " := " + ad1_converted  + " - " + ad2_converted);
                
                delete $<expr>1;
                delete $<expr>3;
              }
              | adierazpena TMUL adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = kodea.idBerria();
                
                int mota_aldaketa = kalkulatuMota(*$<expr>$, *$<expr>1, *$<expr>3);
                string ad1_converted, ad2_converted;

                if (mota_aldaketa == 0)  // ez dago mota aldaketarik. izenak mantendu
                {
                  ad1_converted = $<expr>1->izena;
                  ad2_converted = $<expr>3->izena;
                } 
                else if (mota_aldaketa == 1)  // 1go adierazpena aldatu real motara
                {
                  ad1_converted = kodea.idBerria();
                  ad2_converted = $<expr>3->izena;
                  kodea.agGehitu(ad1_converted + " := ent_to_real(" + $<expr>1->izena  + ")");
                }
                else if (mota_aldaketa == 2)  // 2go adierazpena aldatu real motara
                {
                  ad1_converted = $<expr>1->izena;
                  ad2_converted = kodea.idBerria();
                  kodea.agGehitu(ad2_converted + " := ent_to_real(" + $<expr>3->izena  + ")");
                }
                else  // 1go eta 2n adierazpenak aldatu real motara
                {
                  ad1_converted = kodea.idBerria();
                  ad2_converted = kodea.idBerria();
                  kodea.agGehitu(ad1_converted + " := ent_to_real(" + $<expr>1->izena  + ")");
                  kodea.agGehitu(ad2_converted + " := ent_to_real(" + $<expr>3->izena  + ")");
                }

                kodea.agGehitu($<expr>$->izena + " := " + ad1_converted  + " * " + ad2_converted);

                delete $<expr>1;
                delete $<expr>3;
              }
              | adierazpena TDIV adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = kodea.idBerria();
                $<expr>$->mota = MOTA_REAL;            
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
                $<expr>$->mota = ADI_ERL;
                kodea.agGehitu("if " + $<expr>1->izena  + " = " + $<expr>3->izena + " goto ");
                kodea.agGehitu("goto ");
              }
              | adierazpena TCGT adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = "";
                $<expr>$->true_list.push_front(kodea.lortuErref());
                $<expr>$->false_list.push_front(kodea.lortuErref()+1); 
                $<expr>$->mota = ADI_ERL;
                kodea.agGehitu("if " + $<expr>1->izena  + " > " + $<expr>3->izena + " goto ");
                kodea.agGehitu("goto ");
              }
              | adierazpena TCLT adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = "";
                $<expr>$->true_list.push_front(kodea.lortuErref());
                $<expr>$->false_list.push_front(kodea.lortuErref()+1); 
                $<expr>$->mota = ADI_ERL;
                kodea.agGehitu("if " + $<expr>1->izena  + " < " + $<expr>3->izena + " goto ");
                kodea.agGehitu("goto ");
              }
              | adierazpena TCGE adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = "";
                $<expr>$->true_list.push_front(kodea.lortuErref());
                $<expr>$->false_list.push_front(kodea.lortuErref()+1); 
                $<expr>$->mota = ADI_ERL;
                kodea.agGehitu("if " + $<expr>1->izena  + " >= " + $<expr>3->izena + " goto ");
                kodea.agGehitu("goto ");
              }
              | adierazpena TCLE adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = "";
                $<expr>$->true_list.push_front(kodea.lortuErref());
                $<expr>$->false_list.push_front(kodea.lortuErref()+1); 
                $<expr>$->mota = ADI_ERL;
                kodea.agGehitu("if " + $<expr>1->izena  + " <= " + $<expr>3->izena + " goto ");
                kodea.agGehitu("goto ");
              }
              | adierazpena TCNE adierazpena
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = "";
                $<expr>$->true_list.push_front(kodea.lortuErref());
                $<expr>$->false_list.push_front(kodea.lortuErref()+1); 
                $<expr>$->mota = ADI_ERL;
                kodea.agGehitu("if " + $<expr>1->izena  + " != " + $<expr>3->izena + " goto ");
                kodea.agGehitu("goto ");
              }
              | aldagaia
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = $<var>1->izena.data();
                $<expr>$->mota = $<var>1->mota;
                delete $<var>1;
              }
              | TINTEGER
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = string(*$<izena>1);
                $<expr>$->mota = string(MOTA_ENT);
                delete $<izena>1;
              }
              | TFLOAT
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = string(*$<izena>1);
                $<expr>$->mota = string(MOTA_REAL);
                delete $<izena>1;
              }
              | TLPAREN adierazpena TRPAREN
              {
                $<expr>$ = new expr_st;
                $<expr>$->izena = string($<expr>2->izena);
                $<expr>$->true_list.merge($<expr>2->true_list);
                $<expr>$->false_list.merge($<expr>2->false_list); 
                $<expr>$->mota = $<expr>2->mota;
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

