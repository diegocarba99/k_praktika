%{
   #include <stdio.h>
   #include <iostream>
   #include <vector>
   #include <string>
   using namespace std; 

   extern int yylex();
   extern int yylineno;
   extern char *yytext;
   void yyerror (const char *msg) {
     printf("line %d: %s at '%s'\n", yylineno, msg, yytext) ;
   }

%}

/* 
   Hemen erazagutu ikurrek zein atributu-mota izan dezaketen

%union {
    string *izena ; 
}
*/

/* 
   Tokenak erazagutu. Honek tokens.l fitxategiarekin
   bat etorri behar du.
   Atributu lexikoak ere hemen erazagutu behar dira.
*/
%token 

RPROGRAM
RIF
RWHILE
RFOREVER
RDO
RPROC 
RUNTIL
RELSE
RSKIP
REXIT
RPRINTLN
RREAD
RINT
RFLOAT

TMUL
TASSIG
TADD
TSUB
TDIV
TCEQ
TCGT
TCLT
TCGE
TCLE
TCNE
TSEMIC
TCOMMA
TLPAREN
TRPAREN
TLBRACE
TRBRACE
TOUTPARAM
TINOUTPARAM

TID 
TFLOAT
TINTEGER 

/* Hemen erazagutu atributuak dauzkaten ez-bukaerakoak. Adibidea:
%type <izena> adierazpena
*/

%start programa

%%

programa : RPROGRAM TID erazagupenak azpiprogramen_erazagupena TLBRACE sententzia_zerrenda TRBRACE
         ;

erazagupenak : mota id_zerrenda TSEMIC erazagupenak
             | /* hutsa */
             ;

id_zerrenda : TID id_zerrendaren_bestea
            ;

id_zerrendaren_bestea : TCOMMA TID id_zerrendaren_bestea
                      | /* hutsa */
                      ;

mota : RINT
     | RFLOAT
     ;

azpiprogramen_erazagupena : azpiprogramaren_erazagupena azpiprogramen_erazagupena
                          | /* hutsa */
                          ;

azpiprogramaren_erazagupena : RPROC TID argumentuak erazagupenak azpiprogramen_erazagupena TLBRACE sententzia_zerrenda TRBRACE
                            ;

argumentuak : TLPAREN par_zerrenda TRPAREN
            | /* hutsa */
            ;

par_zerrenda : mota par_mota id_zerrenda par_zerrendaren_bestea
             ;

par_mota : TOUTPARAM
         | TCLE
         | TINOUTPARAM
         ;

par_zerrendaren_bestea : TSEMIC mota par_mota id_zerrenda par_zerrendaren_bestea
                       | /* hutsa */
                       ;

sententzia_zerrenda : sententzia_zerrenda sententzia
                    | /* hutsa */
                    ;

sententzia : TID TASSIG adierazpena TSEMIC
           | RIF adierazpena TLBRACE sententzia_zerrenda TRBRACE TSEMIC
           | RWHILE RFOREVER TLBRACE sententzia_zerrenda TRBRACE TSEMIC
           | RDO TLBRACE sententzia_zerrenda TRBRACE RUNTIL adierazpena RELSE TLBRACE sententzia_zerrenda TRBRACE TSEMIC
           | RSKIP RIF adierazpena TSEMIC
           | REXIT TSEMIC
           | RREAD TLPAREN aldagaia TRPAREN TSEMIC
           | RPRINTLN TLPAREN adierazpena TRPAREN TSEMIC
           ;

aldagaia : TID
         ;
         
adierazpena : adierazpena TADD adierazpena
            | adierazpena TSUB adierazpena
            | adierazpena TMUL adierazpena
            | adierazpena TDIV adierazpena
            | adierazpena TCEQ adierazpena
            | adierazpena TCGT adierazpena
            | adierazpena TCLT adierazpena
            | adierazpena TCGE adierazpena
            | adierazpena TCLE adierazpena
            | adierazpena TCNE adierazpena
            | aldagaia
            | TINTEGER
            | TFLOAT
            | TLPAREN adierazpena TRPAREN
            ;
%%

