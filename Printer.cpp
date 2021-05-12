#include <iostream>
#include "Lag.h"
#include "Printer.h"

using namespace std;


void printErrorsPreamble()
{
	cout << "Erroreak daude zure programan. Mesedez ber-begiratu" << endl;
}

void printErrors ( message_list errors)
{
	cout << "ERRORS:" << endl;
	for ( auto v: errors )
		cout << v << endl;
}

int kalkulatuMota(expr_st &e, expr_st &e1, expr_st &e2)
{

	if (e1.mota.compare(e2.mota))
	{
		e.mota = string(MOTA_REAL);
		if (e1.mota == MOTA_REAL) 
			return 2;
		else
			return 1;
	}
	e.mota = e1.mota.data();

	if (e1.mota.compare(MOTA_ERL) == 0 || e1.mota.compare(MOTA_BOL) == 0 )
		e.error.push_front(string(e1.izena + " ez da adierazpen aritmetiko bat"));

	if (e2.mota.compare(MOTA_ERL) == 0 || e2.mota.compare(MOTA_BOL) == 0 )
		e.error.push_front(string(e1.izena + " ez da adierazpen aritmetiko bat"));

	return 0;

	
}

void kalkulatuErroreak(message_list &errors, var_st &var, expr_st &expr)
{
	stringstream stream;
	 
	stream << "ezin da esleitu \'" << expr.izena << "\'(" << expr.mota << ") adierazpena " << var.izena << "(" << var.mota << ") aldagaiari";
	stream << "\n\tmota bateraezinak " << expr.mota << " =/= " << var.mota;
			
	errors.push_front(stream.str());
}

void kalkulatuErroreak(message_list &errors, int type, var_st &var)
{
	stringstream stream;
	switch (type) {
		case ERR_NOT_DEFINED:
			stream << var.izena << "(" << var.mota << ") ezin da erabili";
			stream << "\n\tez dago definiturik";
			break;

		case ERR_READ:
			stream << "adierazpen okerra 'read(" << var.izena << ")' sententzian";
			stream << "\n\t" << var.izena << "ez dago aldez aurretik definitua";
			break;
		}

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

		case ERR_ELSIF:
			stream << "adierazpen okerra 'elsif " << expr.izena << "' sententzian";
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