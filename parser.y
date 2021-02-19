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
%token TID TINTEGER TFLOAT TMUL TASSIG TLBRACE TRBRACE TSEMIC RPROGRAM

/* Hemen erazagutu atributuak dauzkaten ez-bukaerakoak. Adibidea:
%type <izena> adierazpena
*/

%start programa

%%

programa : RPROGRAM TID TLBRACE sententzia_zerrenda TRBRACE
         ;


sententzia_zerrenda : sententzia_zerrenda sententzia
                    | /* hutsa */
                    ;

sententzia :  TID TASSIG adierazpena TSEMIC
           ;

adierazpena : TID
            | TINTEGER
            | TFLOAT
            ;
%%

