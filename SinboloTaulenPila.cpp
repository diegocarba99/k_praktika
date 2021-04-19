#include "SinboloTaulenPila.h"

#include <iostream>

using namespace std;


/*****************/
/* Eraikitzailea */
/*****************/

SinboloTaulenPila::SinboloTaulenPila() {}


/***********/
/* tonorra */
/***********/

SinboloTaula& SinboloTaulenPila::tontorra() {
	return pila.top().st;
}


/************/
/* pilaratu */
/************/

void SinboloTaulenPila::pilaratu(const SinboloTaula& st) {
	Elementu *gainekoa;
	if (pila.empty()) {
		gainekoa = 0;
	}
	else {
		gainekoa = &(pila.top());
	}
	Elementu elementua;
	elementua.gainekoa = gainekoa;
	elementua.st = st;
	pila.push(elementua);
}


/*************/
/* despilatu */
/*************/

void SinboloTaulenPila::despilatu() {
	pila.pop();
}


/*************/
/* lortuMota */
/*************/

string SinboloTaulenPila::lortuMota(string id) {
	string mota;

	if (pila.empty()) {
		throw string(id + " aldagaia erazagutu gabe erabiltzen saiatu zara.");
	}

	Elementu *elementua = &pila.top();

	while (elementua != 0) {
		try {
			mota = elementua->st.lortuMota(id);
			return mota;
		}
		catch (string errore) {
			elementua = elementua->gainekoa;
		}
	}
	throw string(id + " aldagaia erazagutu gabe erabiltzen saiatu zara.");
}


/***************************/
/* lortuParametroarenMotak */
/***************************/

pair<string, string> SinboloTaulenPila::lortuParametroarenMotak(string id, int parametroZbki) {
	pair<string, string> motak;

	if (pila.empty()) {
		throw string(id + " prozedura erazagutu gabe deitzen saiatu zara.");
	}

	Elementu *elementua = &pila.top();

	while (elementua != 0) {
		try {
			motak = elementua->st.lortuParametroarenMotak(id, parametroZbki);
			return motak;
		}
		catch (string errore) {
			elementua = elementua->gainekoa;
		}
	}
	throw string("Ez da modu horretako prozedurarik aurkitu. Baliteke izena gaizki idatzi izana edo argumentu kopuru"
			" okerra pasa izana.");
}


/********************/
/* gehituParametroa */
/********************/

void SinboloTaulenPila::gehituParametroa(string proz, string aldId, string parMota, string aldMota) {
	pila.top().gainekoa->st.gehituParametroa(proz, parMota, aldMota);
	pila.top().st.gehituAldagaia(aldId, aldMota);
}


/***********************/
/* egiaztatuArgKopurua */
/***********************/

void SinboloTaulenPila::egiaztatuArgKopurua(string proz, int argKop) {
	int benetazkoArgKop = pila.top().st.prozedurarenArgKopurua(proz);
	if (benetazkoArgKop != argKop) {
		throw string("Argumentu kopuru okerra.");
	}
}
