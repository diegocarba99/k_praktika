#include <iostream>
#include "Lag.h"
#include "Printer.h"

using namespace std;


void printErrors ( message_list errors)
{
	std::cout << "ERRORS:" << std::endl;
	for ( auto v: errors )
		std::cout << v << std::endl;
}

int kalkulatuMota(expr_st &e, expr_st &e1, expr_st &e2)
{
	if (e1.mota == MOTA_ENT && e2.mota == MOTA_ENT) {
		e.mota = string(MOTA_ENT);
		return 0;
	}

	if (e1.mota == MOTA_REAL ) {
		e.mota = string(MOTA_REAL);
		return 2;
	}

	if (e2.mota == MOTA_REAL) {
		e.mota = string(MOTA_REAL);
		return 1;
	}
	return 3;
}

void kalkulatuErroreak(message_list &errors, var_st &var, expr_st &expr)
{
	stringstream stream;
	 
	stream << "ezin da esleitu \'" << expr.izena << "\'(" << expr.mota << ") adierazpena " << var.izena << "(" << var.mota << ") aldagaiari";
	stream << "\n\tmota bateraezinak " << expr.mota << " =/= " << var.mota;
			
	errors.push_front(stream.str());
}

void kalkulatuErroreak(message_list &errors, int type, expr_st &expr)
{
	stringstream stream;
	switch (type) {
		case ERR_IF:
			stream << "adierazpen okerra 'if " << expr.izena << "' sententzian";
			stream << "\n\t" << expr.izena << "ez da adierazpen erlazionala";
			break;

		case ERR_DO:
			stream << "adierazpen okerra 'do-until " << expr.izena << "' sententzian"; 
			stream << "\n\t" << expr.izena << "ez da adierazpen erlazionala";
			break;

		case ERR_SKIP:
			stream << "adierazpen okerra 'skip if" << expr.izena << "' sententzian";
			stream << "\n\t" << expr.izena << "ez da adierazpen erlazionala";
			break;

		case ERR_PRINT:
			stream << "adierazpen okerra 'print(" << expr.izena << ")' sententzian";
			stream << "\n\t" << expr.izena << "adierazpen erlazionala da";
			break;
	}
	errors.push_front(stream.str());
}