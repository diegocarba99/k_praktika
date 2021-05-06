#ifndef SINBOLOTAULA_H_
#define SINBOLOTAULA_H_

#include <string>
#include <map>
#include <vector>
#include "Kodea.h"
#include "Lag.h"


/* Sinbolo-taula errepresentatuko duen datu-egitura. Honek bidea eman behar du konpilazioan zehar erazagutzen
 * diren sinbolo desberdinak (aldagaiak, prozedurak, ...) eta informazio gehigarria (motak, parametroak, ...) gorde
 * eta kontsultatzeko.
 */
class SinboloTaula {

private:

	/*************************************/
	/* ERABILIKO DIREN MOTEN DEFINIZIOAK */
	/*************************************/

	/* Prozeduren parametro motak adierazteko mota. Bikotez osatutako bektorea.
	 * Bikote bakoitzak <parMota, aldMota> moduko informazioa gordetzen du. */
	typedef std::vector<std::pair<std::string, std::string> > ParametroMotak;

	/* Sinboloen informazio gehigarria gordetzeko egitura. */
	typedef struct {
		std::string idMota; // aldagaia edo prozedura
		std::string aldMota; // aldagaia bada, bere mota (int edo float)
		ParametroMotak prozParametroak; 	// prozedura bada, bere parametroen motak.
											// adibidez: <"in", "float"> edo <"out", "int">
	} Ezaugarriak;


	/**************************/
	/* BARNE ERREPRESENTAZIOA */
	/**************************/

	/* <SinboloId, InfoGehigarria> motako bikotez osatutako hash taula. */
	std::map<std::string, Ezaugarriak> taula;

public:

	/*************************************/
	/* SINBOLO-TAULAREN METODO PUBLIKOAK */
	/*************************************/

	/* Eraikitzailea */
	SinboloTaula();

	/* Aldagai motako sinbolo bat eta bere mota (int edo float) gehitzen ditu. */
	void gehituAldagaia(std::string id, std::string mota);

	/* Prozedura motako sinbolo bat (izena) gehitzen du. Informazio gehigarria beste metodoen bidez gehituko da. */
	void gehituProzedura(std::string id);

	/* Aurrez gehitutako prozedura bati parametro bat gehitzen dio sinbolo-taulan, bere motekin. */
	void gehituParametroa(std::string id, std::string parMota, std::string aldMota);

	/* Aurrez gehitutako aldagai baten mota itzultzen du. */
	std::string lortuMota(std::string id);

	/* Aurrez gehitutako prozedura bati esleitutako parametro baten motak itzultzen ditu: <parMota, aldMota>. */
	std::pair<std::string, std::string> lortuParametroarenMotak(std::string id, int parametroZbki);

	/* Aurrez gehitutako prozedura baten parametro kopurua itzultzen du. */
	int prozedurarenArgKopurua(std::string proz);

	/* Id jakin horrekin sinbolorik definituta dagoen edo ez itzultzen du. */
	bool idDago(std::string id);

	/* Id jakin bat emanda, bere sarrera sinbolo-taulatik ezabatzen du. */
	void ezabatuId(std::string id);

	/* Sinbolo taulan gehitu den lehenengo elementuaren IDa bueltatzen du */
	string lortuLehenengoId();

};

/* Aldagai motako sinbolo asko eta beraien mota (int edo float) gehitzen ditu. *
void gehituAldagaiak(std::list<std::string> ids, std::string mota);
*/

#endif /* SINBOLOTAULA_H_ */
