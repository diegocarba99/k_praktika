#include <iostream>
#include "Lag.h"
#include "Printer.h"

extern int yylineno;

using namespace std;

void printErrorsPreamble()
                           

{
	printf("\x1b[1;32m");
	printf(R"(
           _                     
            \
             \                  ______________________________
             |\                /   ______   _____    _____    \
             /|                |  | | ____ | | \ \  | | \ \   |
            /'|                |  | |  | | | |  | | | |  | |  |
          ,' //                |  |_|__|_| |_|_/_/  |_|_/_/   |              
        ,'..`/                 \_____________________________/
       /   '/                          the interprter                  _...._.---._
     /:   ,'                                                         .' ,--. ,--.  \
   ,'    ,                                                           | /... /...|  |,..._
  ,'    /                                   _..---------..__         \.\_O_/  O /  '     \
 .'  _, /                 .---..._       ,-'  __.-.....__   '-  ___.-----._'---'     ,'  |
 |-`'  (                  |       `--..,'_,-''   '.     `''"-._( .-.'.--.         _.'   /
 |      \                 |  ,.__     /,'  |      |      \     \ | / |  /      ,,'  __ /
 |     .`.               /  .'  _)--..'    |       |     '\     \`  ..--:`     _.--' \
 |   .'  .-.__           |  |,-' _.-\      |       |      |     |`\''''''''_.-'   ,' (__...'
  \         ,-`''-- =--::|   \-'|    |     |       |      |     | `'.....-' .,:-'  |  \
   `.    ,  /  /     '`. |   |  |    |     |       |      |     |  \__.-` `..      \   \
    '.  /  /  /         '|   |  |    [     |       |       |    |    ,       '._    |  |
      `.  /  | .--------'    `-. |   '     |       |       |    |,L______       `--..   \
        ``.  | \               |-^---''".  |      |       .'    |.'      ``-..._         \
           `.-..\.__...---....,'-.....--'`'"-........_____|.. `'                `'`--..../ 

)");
	printf("\x1b[1;32m\x1b[4;32m");
	printf("Arranopola! Ematen duenez, gdd-k arazoak aurkitu ditu zure kodean, ikus ditzagun zeintzuk diren:\n\n");
	printf("\x1b[40m\x1b[0;37m\x1b[0m");



}





void printErrors ( message_list &errors)
{
	for ( auto v: errors )
		cout << v;
}

int kalkulatuMota(expr_st &e, expr_st &e1, expr_st &e2)
{

	if (e1.mota.compare(MOTA_REAL) == 0 && e2.mota.compare(MOTA_ENT) == 0 )
	{
		e.mota = string(MOTA_REAL);
		return 2;
	}
	else if (e1.mota.compare(MOTA_ENT) == 0  && e2.mota.compare(MOTA_REAL) == 0 )
	{
		e.mota = string(MOTA_REAL);
		return 1;	
	}
	e.mota = e1.mota.data();

	string line = to_string(yylineno);
	stringstream stream;

	if (e1.mota.compare(MOTA_ERL) == 0 || e1.mota.compare(MOTA_BOL) == 0 ){
		stream << COLOR_BLUE_BOLD << line << " lerroan" << COLOR_RESET << " - " << COLOR_RED_BOLD << "errorea" COLOR_RESET << ": ";
		stream << COLOR_BOLD << "'" << e1.izena << "'" << COLOR_RESET << " ez da adierazpen aritmetiko bat" << endl;
		stream << "\t" << e.deskribapena << endl;
		e.error.push_front(stream.str());
	}

	if (e2.mota.compare(MOTA_ERL) == 0 || e2.mota.compare(MOTA_BOL) == 0 ){
		stream << COLOR_BLUE_BOLD << line << " lerroan" << COLOR_RESET << " - " << COLOR_RED_BOLD << "errorea" COLOR_RESET << ": ";
		stream << COLOR_BOLD << "'" << e2.izena << "'" << COLOR_RESET << " ez da adierazpen aritmetiko bat" << endl;
		stream << "\t" << e.deskribapena << endl;
		e.error.push_front(stream.str());
	}
	return 0;
}

void kalkulatuErroreak(message_list &errors, var_st &var, expr_st &expr)
{
	stringstream stream;

	stream << COLOR_BLUE_BOLD << yylineno << " lerroan" << COLOR_RESET << " - " << COLOR_RED_BOLD << "errorea" COLOR_RESET << ": ";
	stream << "ezin zaio esleitu " << COLOR_BOLD << "'" << expr.mota << "'" << COLOR_RESET << " motako balio bat ";
	stream << COLOR_BOLD << "'" << var.izena << "'" << COLOR_RESET << "aldagaiari, mota bateraezinak" << endl;
	stream << "\t" << var.izena << " = " << expr.deskribapena << endl;
			
	errors.push_front(stream.str());
}



void kalkulatuErroreak(message_list &errors, int type, expr_st &expr)
{
	stringstream stream;

	switch (type) {
		case ERR_IF:
			stream << COLOR_BLUE_BOLD << yylineno << " lerroan" << COLOR_RESET << " - " << COLOR_RED_BOLD << "errorea" COLOR_RESET << ": ";
			stream << "sententzia kondizionalean adierazpen erlazional bat espero da" << endl;
			stream << "\tif " << expr.deskribapena << " { ..."<< endl;
			break;

		case ERR_ELSIF:
			stream << COLOR_BLUE_BOLD << yylineno << " lerroan" << COLOR_RESET << " - " << COLOR_RED_BOLD << "errorea" COLOR_RESET << ": ";
			stream << "sententzia kondizionalean adierazpen erlazional bat espero da" << endl;
			stream << "\telsif " << expr.deskribapena << " { ..."<< endl;
			break;

		case ERR_DO:
			stream << COLOR_BLUE_BOLD << yylineno << " lerroan" << COLOR_RESET << " - " << COLOR_RED_BOLD << "errorea" COLOR_RESET << ": ";
			stream << "sententzia kondizionalean adierazpen erlazional bat espero da" << endl;
			stream << "\tdo { ... } until " << expr.deskribapena << endl;
			break;

		case ERR_SKIP:
			stream << COLOR_BLUE_BOLD << yylineno << " lerroan" << COLOR_RESET << " - " << COLOR_RED_BOLD << "errorea" COLOR_RESET << ": ";
			stream << "sententzia kondizionalean adierazpen erlazional bat espero da" << endl;
			stream << "\tskip if " << expr.deskribapena << " ;"<< endl;
			break;

		case ERR_PRINT:
			stream << COLOR_BLUE_BOLD << yylineno << " lerroan" << COLOR_RESET << " - " << COLOR_RED_BOLD << "errorea" COLOR_RESET << ": ";
			stream << "inprimatu daitezkeen adierazpenak aritmetikoak izan dira, ezin da " << expr.mota << "bat inprimatu" << endl;
			stream << "\tprint(" << expr.deskribapena << ")" << endl;
			
			break;
	}
	errors.push_front(stream.str());
}