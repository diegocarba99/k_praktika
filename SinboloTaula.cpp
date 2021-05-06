#include "SinboloTaula.h"

using namespace std;


/*****************/
/* Eraikitzailea */
/*****************/

SinboloTaula::SinboloTaula() {}


/******************/
/* gehituAldagaia */
/******************/

void SinboloTaula::gehituAldagaia(string id, string mota) {
	Ezaugarriak ezaugarriak;
	ezaugarriak.idMota = string("aldagaia");
	ezaugarriak.aldMota = mota;
	if (!taula.insert(pair<string, Ezaugarriak> (id, ezaugarriak)).second) {
		throw string(id + " identifikadorea behin baino gehiagotan erazagutzen saiatu zara.");
	}
	/*
	std::cout << "[ST] gehituAldagaia(" << id << "," << mota << ")\n";
	for (const auto& x : taula) {
        std::cout << x.first << ": " << x.second.idMota << "|" << x.second.aldMota << "\n";
    }
    std::cout << "----------------------------------\n";
    */
}

/******************/
/* gehituAldagaiak */
/******************

void gehituAldagaiak(list<string> id, string mota) {
	
}
*/

/*******************/
/* gehituProzedura */
/*******************/

void SinboloTaula::gehituProzedura(std::string id) {
	Ezaugarriak ezaugarriak;
	ezaugarriak.idMota = string("prozedura");
	if (!taula.insert(pair<string, Ezaugarriak> (id, ezaugarriak)).second) {
		throw string(id + " identifikadorea behin baino gehiagotan erazagutzen saiatu zara.");
	}
	/*
	std::cout << "[ST] gehituProzedura(" << id << ")\n";
	for (const auto& x : taula) {
        std::cout << x.first << ": " << x.second.idMota << "|" << x.second.aldMota << "\n";
    }
    std::cout << "----------------------------------\n";
    */
}



/*******************/
/* geituParametroa */
/*******************/

void SinboloTaula::gehituParametroa(string id, string parMota, string aldMota) {
	if (taula.count(id) == 0) {
		//std::cout << string("[ST] gehituParametroa() " + id + " prozedura erazagutu gabe erabiltzen saiatu zara.\n");
		throw string(id + " prozedura erazagutu gabe erabiltzen saiatu zara.");
	}
	if (taula.find(id)->second.idMota != "prozedura") {
		//std::cout << string("[ST] gehituParametroa() " + id + " identifikadorea erazagututa dago baina ez da prozedura bat.\n");
		throw string(id + " identifikadorea erazagututa dago baina ez da prozedura bat.");
	}
	pair<string, string> motak(parMota, aldMota);
	taula.find(id)->second.prozParametroak.push_back(motak);
}


/*************/
/* lortuMota */
/*************/

string SinboloTaula::lortuMota(string id) {
	/*
	std::cout << "SinboloTaula::lortuMota("<< id << ")\n";
	for (const auto& x : taula) {
        std::cout << x.first << ": " << x.second.idMota << "|" << x.second.aldMota << "\n";
    }
    std::cout << "----------------------------------\n";
	*/
	if (taula.count(id) == 0) {
		//std::cout << string("[ST] lortuMota() " + id + " aldagaia erazagutu gabe erabiltzen saiatu zara.\n");
		throw string(id + " aldagaia erazagutu gabe erabiltzen saiatu zara.");
	}
	if (taula.find(id)->second.idMota != "aldagaia") {
		//std::cout << string("[ST] lortuMota() " + id + " identifikadorea erazagututa dago baina ez da aldagai bat.\n");
		throw string(id + " identifikadorea erazagututa dago baina ez da aldagai bat.");
	}
	return taula.find(id)->second.aldMota;
}


/***************************/
/* lortuParametroarenMotak */
/***************************/

pair<string, string> SinboloTaula::lortuParametroarenMotak(string id, int parametroZbki) {
	if (taula.count(id) == 0) {
		throw string(id + " aldagaia erazagutu gabe erabiltzen saiatu zara.");
	}
	if (taula.find(id)->second.idMota != "prozedura") {
		throw string(id + " identifikadorea erazagututa dago baina ez da prozedura bat.");
	}
	ParametroMotak parametroMotak = taula.find(id)->second.prozParametroak;
	if (parametroMotak.size() <= unsigned(parametroZbki)) {
		throw string(id + " prozedurari argumentu kopuru okerra pasa zaio.");
	}
	return parametroMotak[parametroZbki];
}


/**************************/
/* prozedurarenArgKopurua */
/**************************/

int SinboloTaula::prozedurarenArgKopurua(std::string proz) {
	return taula.find(proz)->second.prozParametroak.size();
}


/**********/
/* idDago */
/**********/

bool SinboloTaula::idDago(string id) {
	return taula.count(id) > 0;
}


/*************/
/* ezabatuId */
/*************/

void SinboloTaula::ezabatuId(string id) {
	taula.erase(id);
}



/********************/
/* lortuLehenengoId */
/********************/
string SinboloTaula::lortuLehenengoId(){
	return taula.begin()->first;
}