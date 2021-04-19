#ifndef SINBOLOTAULENPILA_H_
#define SINBOLOTAULENPILA_H_

#include <stack>
#include "SinboloTaula.h"

/* Sinbolo-taulen pila errepresentatzeko egitura. Itzultzailearen eta sinbolo-taularen tartean kokatzen da.
 * Honela, egitura honi sinbolo baten informazioa eskatzean, tontorreko taulan begiratuko du. Aurkitzen ez badu,
 * honi lotutako hurrengo sinbolo-taulan begiratuko du, eta horrela aurkitu edo pila bukatu arte.
 */
class SinboloTaulenPila {

private :

	/*************************************/
	/* ERABILIKO DIREN MOTEN DEFINIZIOAK */
	/*************************************/

	/* Pilako elementua. Elementu honek bi atal izango ditu, sinbolo-taula bera batetik eta bere gaineko
	 * elementua (sinbolo-taula + beste erref) bestetik.
	 */
	typedef struct pare {
		SinboloTaula st;
		pare* gainekoa;
	} Elementu;


	/**************************/
	/* BARNE ERREPRESENTAZIOA */
	/**************************/

	/* <sinbolo-taula, gainekoErref> parez osatutako pila. */
	std::stack<Elementu> pila;

public:

	/********************/
	/* METODO PUBLIKOAK */
	/********************/

	/* Eraikitzailea */
	SinboloTaulenPila();

	/* Tontorreko sinbolo-taula itzultzen du. */
	SinboloTaula& tontorra();

	/* Sinbolo-taula berria pilan sartzen du, bere gaineko sinbolo-taula bere erreferentzia izanik. */
	void pilaratu(const SinboloTaula& st);

	/* Tontorreko elementua ezabatzen du. */
	void despilatu();

	/* Tontorreko sinbolo-taulatik abiatuta, pasatako aldagaia aurkitzen saiatzen da eta aurkituz gero
	 * bere mota itzultzen du. */
	std::string lortuMota(std::string id);

	/* Metodo honek bi zeregin ditu:
	 * => Jatorrizko sinbolo-taulan (gainekoan), erazagutzen ari garen prozedurari parametro berri bat gehitzen dio.
	 * => Uneko sinbolo-taulan (erazagutzn ari garen prozedurari dagokiona) parametroa aldagai lokal bezala gehitzen du.
	 */
	void gehituParametroa(std::string proz, std::string aldId, std::string parMota, std::string aldMota);

	/* id prozeduraren parametroZbki-garren argumentuaren parMota eta aldMota itzultzen ditu. */
	std::pair<std::string, std::string> lortuParametroarenMotak(std::string id, int parametroZbki);

	/* proz prozeduraren argumentu kopurua argKop-ekin bat datorren egiaztatzen du. Ezezkoan salbuespena altxako du. */
	void egiaztatuArgKopurua(std::string proz, int argKop);

};

#endif /* SINBOLOTAULENPILA_H_ */
