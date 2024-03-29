%option yylineno 

%{
 #include <string>
 #include <iostream>
 #include <vector>
 #include "parser.hpp"
 #include "Lag.h"
 
 using namespace std ;

 #define TOKEN(t) return t 

 #define TOKENST(t) yylval.izena = new std::string(yytext, yyleng) ; return t 

 extern "C" int yywrap() { return(1) ; }  
 extern void processtoken (int t, string id);

%}

%%
program                 			TOKEN(RPROGRAM);
if                      			TOKEN(RIF);
while                   			TOKEN(RWHILE);
forever                 			TOKEN(RFOREVER);
do                      			TOKEN(RDO);
proc                    			TOKEN(RPROC); 
until                   			TOKEN(RUNTIL);
else                    			TOKEN(RELSE);
elsif								TOKEN(RELSIF);
skip                    			TOKEN(RSKIP);
exit                    			TOKEN(REXIT);
println                 			TOKEN(RPRINTLN);
read                    			TOKEN(RREAD);
int                     			TOKEN(RINT);
float                   			TOKEN(RFLOAT);
and									TOKEN(RAND);
or									TOKEN(ROR);
not									TOKEN(RNOT);

"*"                     	  		TOKEN(TMUL);
"="                     	  		TOKEN(TASSIG);
"+"                     			TOKEN(TADD);
"-"                     	  		TOKEN(TSUB);
"/"                     			TOKEN(TDIV);
"=="                    			TOKEN(TCEQ);
">"                     			TOKEN(TCGT);
"<"                     			TOKEN(TCLT);
">="                    			TOKEN(TCGE);
"<="                    			TOKEN(TCLE);
"/="                    			TOKEN(TCNE);
";"                    	 			TOKEN(TSEMIC);
","                     			TOKEN(TCOMMA);
"("                     			TOKEN(TLPAREN);
")"                     			TOKEN(TRPAREN);
"{"                     			TOKEN(TLBRACE);
"}"                     			TOKEN(TRBRACE);
"=>"                    			TOKEN(TOUTPARAM);
"<=>"                   			TOKEN(TINOUTPARAM);

#[^#\n]*\n                    		;
[ \t\n]*                       	    ;
\[\*([^*]|\*+[^*\]])*\*+\]          ;

[a-zA-Z](_?[a-zA-Z0-9])*          	TOKENST(TID); 
[0-9]+\.[0-9]+([eE][-+]?[0-9]+)?	TOKENST(TFLOAT);
[0-9]+                            	TOKENST(TINTEGER); 

.                       		    { cout << "ERR: Token ezezaguna '" << yytext << "'" << endl << "Mesedez kontu gehiago izan idazterakoan..."; yyterminate(); }
%%




