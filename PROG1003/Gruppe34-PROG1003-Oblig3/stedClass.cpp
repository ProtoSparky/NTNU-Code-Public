/*****************************************************************//**
 * @file   stedClass.cpp
 * @brief  Funksjon definisjon for sted klassen
 *
 * @author Kristupas Kaupas, Rangvald Jansen
 * @date   2026-4-6
 *********************************************************************/
#include<iostream>
#include<string>

#include "stedClass.h"
#include "LesData3.h"
#include "const.h";
#include "utleiestederClass.h"
#include "gjenstandClass.h"
extern UtleieSteder* gUtleiesteder;
using namespace std;

/**
 * @brief  funksjon som lager nytt sted med navn.
 * @param navn
 */
void Sted::nyttSted(string navn) {
	stedNavn = navn;

	tlf = lesInt("Tlf", 0, 999999999);

	cout << "Stedets beslrivelse: "; getline(cin, beskrivelse);

	inntjenteKr = 0;
	tralleVec.clear();
	sykkelVec.clear();
	elsparkesykkelVec.clear();
}

/**
 * @brief  skriver ut basic info på et gitt sted.
 */
void Sted::skrivInfo(){
	cout << "Navn/ID: " << stedNavn << "\n";
	cout << "Beskrivrlse: " << beskrivelse << "\n";
	cout << "Tlf: " << tlf << "\n";
	cout << "Inntekt: " << inntjenteKr << "\n";
	cout << "Antall traller: " << tralleVec.size() << "\n";
	cout << "Antall sykler: " << sykkelVec.size() << "\n";
	cout << "Antall elsparkesykler: " << elsparkesykkelVec.size() << "\n";
}

/**
 * @brief  skriver ut info om et sted, og alle gjenstanders id/type.
 * @see Gjenstand::hentGjenstadNr()
 */
void Sted::skrivAllInfo() {
	cout << "Navn/ID: " << stedNavn << "\n";
	cout << "Beskrivrlse: " << beskrivelse << "\n";
	cout << "Tlf: " << tlf << "\n";
	cout << "Inntekt: " << inntjenteKr << "\n";

	cout << "Antall traller: " << tralleVec.size() << "\n";
	if (tralleVec.size() != 0) {
		for (int i = 0; i < tralleVec.size(); i++) {
			cout << "\tId: " << tralleVec[i]->hentGjenstadNr() << "\n";
		}
	}

	cout << "Antall sykler: " << sykkelVec.size() << "\n";
	if (sykkelVec.size() != 0) {
		for (int i = 0; i < sykkelVec.size(); i++) {
			cout << "\tId: " << sykkelVec[i]->hentGjenstadNr() << "\n";
		}
	}

	cout << "Antall elsparkesykler: " << elsparkesykkelVec.size() << "\n";
	if (elsparkesykkelVec.size() != 0) {
		for (int i = 0; i < elsparkesykkelVec.size(); i++) {
			cout << "\tId: " << elsparkesykkelVec[i]->hentGjenstadNr() << "\n";
		}
	}

}


/**
 * @brief  skriver ut inntekt på et gitt sted.
 */
void Sted::skrivInntekt() {
	cout << "Sted " << stedNavn << " har tjent " << inntjenteKr << "\n";
}

/**
 * @brief lager UI tekst for gjenstand utskrift.
 * @param choice, gjenstand enum i int
 * @return string for utskrift
 */
string Sted::skrivAktuellGjenstand(int choice) {
	string utputt="no";

	switch (choice) {
		case 1:{
			if (tralleVec.size() != 0) {
				utputt = "Sted " + stedNavn + " med tlf " + to_string(tlf) + 
				" har " + to_string(tralleVec.size()) + " traller igjen.\n";
			}
			break;
		}
		case 2: {
			if (sykkelVec.size() != 0) {
				utputt = "Sted " + stedNavn + " med tlf " + to_string(tlf) + 
				" har " + to_string(sykkelVec.size()) + " sykkler igjen.\n";
			}
			break;
		}
		case 3: {
			if (elsparkesykkelVec.size() != 0) {
				utputt = "Sted " + stedNavn + " med tlf " + to_string(tlf) + 
				" har " + to_string(elsparkesykkelVec.size()) + 
				" elsparkesykler igjen.\n";
			}
			break;
		}
	}
	return utputt;
}

/**
 * @brief  Velger x antall av en spesifikk gjenstand, og oppretter den. 
 * @see UtleieSteder::oekSisteNr()
 * @see Gjenstand::settGjenstandNr(...)
 * @see UtleieSteder::hentSisteNr(...)
 * @see  Gjentsand::settEnum(...)
 * @see Sykkel::settBoolAttributt(...)
 * @see Tralle::settBoolAttributt(...)
 * @see Elsparkesykkel::settIntAttributt(..)
 */
void Sted::opprettGjenstander(){
	int valg, antall;
	cout << "Velg type gjenstand\n"
		<< "0 - Sykkel \n"
		<< "1 - Tralle \n"
		<< "2 - Elsparkesykkel \n"; 
	valg = lesInt("Valg", 0, 2);

	cout << "skriv inn antall gjenstander som skal opprettes\n";
	antall = lesInt("antall", 0, MAXOPPRETTBAREGJENSTANDER); 

	switch (valg) {
		case 0: {
			for (int i = 0; i < antall; i++) {
				//Øker siste nr, oppretter sykkel, setter dens siste nr til det
				// økte nummeret, og lagrer alt i sin vec
				gUtleiesteder->oekSisteNr(); 
				Sykkel* nySykkel = new Sykkel;
				nySykkel->settGjenstandNr(gUtleiesteder->hentSisteNr());
				nySykkel->settEnum(0);
				nySykkel->settBoolAttributt(DEFAULTSYKKELTILHENGER);
				sykkelVec.push_back(nySykkel);
			}
			break;
		}
		case 1: {
			for (int i = 0; i < antall; i++) {
				gUtleiesteder->oekSisteNr();
				Tralle* nyTralle = new Tralle;
				nyTralle ->settGjenstandNr(gUtleiesteder->hentSisteNr());
				nyTralle->settEnum(1);
				nyTralle->settBoolAttributt(DEFAULTTRALLEDRASELE);
				tralleVec.push_back(nyTralle);
			}
			break;
		}
		case 2: {
			for (int i = 0; i < antall; i++) {
				gUtleiesteder->oekSisteNr();
				Elsparkesykkel* nyElsparkesykkel = new Elsparkesykkel;
				nyElsparkesykkel->settGjenstandNr(gUtleiesteder->hentSisteNr());
				nyElsparkesykkel->settEnum(2);
				nyElsparkesykkel->settIntAttributt(DEFAULTELSPARKESYKKELEFFEKT);
				elsparkesykkelVec.push_back(nyElsparkesykkel);
			}
			break; 
		}
	}
	cout << antall << " gjenstand(er) ble opprettet med siste gjenstand nr "
		 << gUtleiesteder->hentSisteNr(); 

}

/**
 * @brief  Søker etter tralle, elsparkesykkel, osv etter gjenstandnr.
 * @param id int
 * @see Gjenstand::hentGjenstadNr()
 */
bool Sted::sokGjenstand(int id){
	bool funnetGjenstand = false;

	//Sjekker tralle
	for (int i = 0; i < tralleVec.size(); i++) {
		if (tralleVec[i]->hentGjenstadNr() == id) {
			cout << "Funnet Tralle med gjenstand nr "
				<< id << " paa sted '" << stedNavn << "'\n"; 
			funnetGjenstand = true;
			return funnetGjenstand;
		}
	}

	//sjekker sykkel
	for (int i = 0; i < sykkelVec.size(); i++) {
		if (sykkelVec[i]->hentGjenstadNr() == id) {
			cout << "Funnet Sykkel med gjenstand nr "
				 << id << " paa sted '" << stedNavn << "'\n";
			funnetGjenstand = true;
			return funnetGjenstand;
		}
	}

	//Sjekker elsparkesykekl
	for (int i = 0; i < elsparkesykkelVec.size(); i++) {
		if (elsparkesykkelVec[i]->hentGjenstadNr() == id) {
			cout << "Funnet Sykkel med gjenstand nr "
				 << id << " paa sted '" << stedNavn << "'\n";
			funnetGjenstand = true;
			return funnetGjenstand;
		}
	}

	return funnetGjenstand;
}

/**
 * @brief  spør bruker om hva slags gjenstander de ønsker å låne.
 * @return gjenstander vector
 * @see Gjenstand::settEnum(...)
 * @see Sykkel::settBoolAttributt(...)
 * @see Tralle::settBoolAttributt(...)
 * @see Elsparkesykkel::settIntAttributt(...)
 * @see Gjenstand::visGjenstandTabell(...)
 * @see Gjentstand::endreAttrubutt()
 */
vector <Gjenstand*> Sted::laanGjenstandVelgGjenstand(){
	int sykkelInventar = 0, tralleInventar = 0, elsparkesykkelInventar = 0;
	int valgtSykkler = 0, valgtTraller = 0, valgtElsparkesykkler = 0;
	int attributtValg; 
	vector <Gjenstand*> gjenstander; //temp variabel for alle gjenstander

	sykkelInventar = sykkelVec.size();
	tralleInventar = tralleVec.size();
	elsparkesykkelInventar = elsparkesykkelVec.size();
	
	//spør kunde om hva de ønsker å velge
	cout << "Det finnes " << sykkelInventar << " sykler, "
		<< tralleInventar << " traller, og " << elsparkesykkelInventar
		<< " elsparkesykler paa '" << stedNavn << "'\n"
		<< "Prisene for staandard oppsett av gjenstandene er:\n"
		<< "Sykkel - " << SYKKELPRIS << "kr\n"
		<< "Tralle - " << TRALLEPRIS << "kr\n"
		<< "Elsparkesykkel - "
		<< ELSPARKESYKKELPRIS.at(DEFAULTELSPARKESYKKELEFFEKT) << "kr\n"
		<< "======================================================\n"
		<< "Hvor mange oensker du aa lane? \n";

	valgtSykkler = lesInt("Sykler", 0, sykkelInventar);
	valgtTraller = lesInt("Traller", 0, tralleInventar);
	valgtElsparkesykkler = lesInt("Elsparkesykler", 0, elsparkesykkelInventar);
	
	
	for (int i = 0; i < valgtSykkler; i++) {
		//lager alle sykler
		Gjenstand* gjenstand = sykkelVec[i]; 

		gjenstand->settEnum(0); 
		gjenstand->settBoolAttributt(DEFAULTSYKKELTILHENGER);

		//lagrer i tempvariabel
		gjenstander.push_back(gjenstand);		
	}
	//fjerner antaall sykler fra stedet (fordi vi kopierte de til kunden)
	sykkelVec.erase(
		sykkelVec.begin(),
		sykkelVec.begin() + valgtSykkler
	); 


	
	for (int i = 0; i < valgtTraller; i++) {
		//lager alle traller
		Gjenstand* gjenstand = tralleVec[i]; 		

		gjenstand->settEnum(1);
		gjenstand->settBoolAttributt(DEFAULTTRALLEDRASELE);

		//lagrer tralle i temp var
		gjenstander.push_back(gjenstand); 
	}
	tralleVec.erase(
		tralleVec.begin(),
		tralleVec.begin() + valgtTraller
	);


	for (int i = 0; i < valgtElsparkesykkler; i++) {
		//lager alle elsparkesykler
		Gjenstand* gjenstand = elsparkesykkelVec[i]; 

		gjenstand->settEnum(2);
		gjenstand->settIntAttributt(DEFAULTELSPARKESYKKELEFFEKT); 

		//lagrer elsparkesykkel i temp var
		gjenstander.push_back(gjenstand);
	}
	elsparkesykkelVec.erase(
		elsparkesykkelVec.begin(),
		elsparkesykkelVec.begin() + valgtElsparkesykkler
	);


	//meny pluss tabell
	do {

		//skriver ut tabell og andre gjenstander
		cout << "Index | ID | Type | Attributt | Pris \n";
		cout << "======================================\n";
		for (int i = 0; i < gjenstander.size(); i++) {
			cout << i << " | "; //skriver ut indeksen
			gjenstander[i]->visGjenstandTabell(gjenstander[i]);
			cout << "\n";
		}
		cout << "======================================\n";
		cout <<"For aa endre en av gjenstand attribttene, skriv inn dens indeks"
			<< ", eller -1 for aa avslutte laanet\n";

		attributtValg = lesInt("Valg", -1, gjenstander.size() - 1);

		//endrer attributt på bare gjenstanden brukeren spurte om
		for (int i = 0; i < gjenstander.size(); i++) {
			if (attributtValg == i) {
				gjenstander[i]->endreAttrubutt(); 
			}
		}

	} while (attributtValg != -1);

	//lagre gjenstander
	return gjenstander; 
}

/**
 * @brief  legger på x antall intekt fra lån.
 * @param inntekt int
 */
void Sted::oekInntekt(int inntekt) {
	inntjenteKr += inntekt;
}

/**
 * @brief  tar imot en vector med gjenstander og legger alt i sine vectorer.
 * @param gjenstander vector
 * @see Gjenstand::hentGjenstandEnum()
 * @see Gjenstand::settGjenstandNr(...)
 * @see Gjenstand::hentGjenstadNr()
 * @see Gjenstand::settEnum(..)
 * @see Sykkel::settBoolAttributt(...)
 * @see Tralle::settBoolAttributt(...)
 * @see Elsparkesykkel::settIntAttributt
 */
void Sted::mottaKundeGjenstander(vector <Gjenstand*> gjenstander){
	//går gjennom kundens gjenstander
	for (Gjenstand* gjenstand : gjenstander) {
		//her skal vi hente enum og gjenstandnr, så lage en ny gjenstand med det
		// tallet og dets default verdier. Orginal gjenstanden kommer til å bli
		// slettet.

		switch (gjenstand->hentGjenstandEnum()) {
		case 0: {
			//sykkel
			Sykkel* nySykkel = new Sykkel;
			nySykkel->settGjenstandNr(gjenstand->hentGjenstadNr());
			nySykkel->settEnum(0);
			nySykkel->settBoolAttributt(DEFAULTSYKKELTILHENGER); //default
			sykkelVec.push_back(nySykkel);
			break;
		}
		case 1: {
			//tralle
			Tralle* nyTralle = new Tralle;
			nyTralle->settGjenstandNr(gjenstand->hentGjenstadNr());
			nyTralle->settEnum(1);
			nyTralle->settBoolAttributt(DEFAULTTRALLEDRASELE);
			tralleVec.push_back(nyTralle);
			break;
		}
		case 2: {
			//elsparkesykkel
			Elsparkesykkel* nyElsparkesykkel = new Elsparkesykkel;
			nyElsparkesykkel->settGjenstandNr(gjenstand->hentGjenstadNr());
			nyElsparkesykkel->settEnum(2);
			nyElsparkesykkel->settIntAttributt(DEFAULTELSPARKESYKKELEFFEKT);
			elsparkesykkelVec.push_back(nyElsparkesykkel); 
			break; 
		}
		}
	}
}

/**
 * @brief  Spør bruker om antall traller som flyttes fra sted og returnes.
 * @return tralle vector
 * @param slettAlle - True sletter alle, false spør bruker om antall som slettes
 */
vector <Tralle*> Sted::hentTrallerForFlytting(bool slettAlle) {
	int antall = tralleVec.size();
	vector <Tralle*> traller; 

	if (!slettAlle) {
		cout << "Det finnes " << tralleVec.size() << " traller paa " << stedNavn
			<< " \n Velg antaall traller som flyttes\n";

		antall = lesInt("Antall", 0, tralleVec.size());
	}

		
	//kopierer alle de trallene til temp vector
	for (int i = 0; i < antall; i++) {
		traller.push_back(tralleVec[i]); 
	}

	//sletter de kopierte trallene fra stedets vector
	tralleVec.erase(
		tralleVec.begin(),
		tralleVec.begin() + antall
	);

	

	return traller; 
}

/**
 * @brief  tar imot en vector med traller og legger de inn i tralleVec.
 * @param traller vector
 */
void Sted::leggTilTraller(vector <Tralle*> traller) {
	for (Tralle* tralle : traller) {
		tralleVec.push_back(tralle); 
	}
}

/**
 * @brief Spør bruker om antall sykler som flyttes fra sted og returneres .
 * @return sykkel vector
 * @param slettAlle - True sletter alle, false spør bruker om antall som slettes
 */
vector <Sykkel*> Sted::hentSyklerForFlytting(bool slettAlle) {
	int antall = sykkelVec.size();
	vector <Sykkel*> sykler; 

	if (!slettAlle) {
		cout << "Det finnes " << sykkelVec.size() << " sykler paa " << stedNavn
			<< "\nVelg antall sykler som flyttes\n";

		antall = lesInt("Antall", 0, sykkelVec.size());
	}


	//kopierer alle syklene til temp vector
	for (int i = 0; i < antall; i++) {
		sykler.push_back(sykkelVec[i]); 
	}

	//sletter de kopierte trallene fra stedets vector
	sykkelVec.erase(
		sykkelVec.begin(),
		sykkelVec.begin() + antall
	);
	
	return sykler; 
}

/**
 * @brief  tar imot en vector med sykler og legger de inn i sykkelVec.
 * @param sykler
 */
void Sted::leggTilSykler(vector <Sykkel*> sykler) {
	for (Sykkel* sykkel : sykler) {
		sykkelVec.push_back(sykkel);
	}
}

/**
 * @brief  Spør bruker om antall elsparkesykler som flyttes fra sted og return.
 * @return elsparkesykler vector
 * @param slettAlle - True sletter alle, false spør bruker om antall som slettes
 */
vector <Elsparkesykkel*> Sted::hentElsparkesykklerForFlytting(bool slettAlle) {
	int antall = elsparkesykkelVec.size();
	vector <Elsparkesykkel*> elsparkesykler;

	if (!slettAlle) {
		cout << "Det finnes " << elsparkesykkelVec.size() << " elsparkesykler"
			 << " paa " << stedNavn << "\n"
			 << "Velg antall elsparkesykler som flyttes\n";

		antall = lesInt("Antall", 0, elsparkesykkelVec.size());
	}


	//kopierer alle syklene til temp vector
	for (int i = 0; i < antall; i++) {
		elsparkesykler.push_back(elsparkesykkelVec[i]);
	}

	//sletter de kopierte trallene fra stedets vector
	elsparkesykkelVec.erase(
		elsparkesykkelVec.begin(),
		elsparkesykkelVec.begin() + antall
	);

	return elsparkesykler;
}

/**
 * @brief  Tar imot en vector med elsparkesykkler og legger de inn i sin vector.
 * @param elsparkesykler
 */
void Sted::leggTilElsparkesykler(vector <Elsparkesykkel*> elsparkesykler) {
	for (Elsparkesykkel* eksparkesykkel : elsparkesykler) {
		elsparkesykkelVec.push_back(eksparkesykkel);
	}
}

/**
 * @brief  skriver ut advarsel for sletting av en gjenstand.
 * @param type string type gjenstand
 * @param gjenstandNr
 */
void Sted::skrivSlettGjenstandAdvarsel(string type, int gjenstandNr) {
	cout << "!!!!!!!! ADVARSEL - Du er i ferd med aa slette " << type
		<< " med id " << gjenstandNr << " !!!!!!!!\n"
		<< "For aa slette den, maa du skrive gjenstand nr"
		<< " for aa fortsette.\nFeil svar avbryter slettingen\n";
}

/**
 * @brief  Søker gjennom stedets gjenstander, og sletter om gjenstanden finnes.
 * @param gjenstandNr
 * @return bool. True hvis en gjenstand ble slettet
 * @see Gjenstand::hentGjenstadNr()
 * @see Sted::skrivSlettGjenstandAdvarsel(...)
 * @see UtleieSteder::hentSisteNr()
 */
bool Sted::slettGjenstand(int gjenstandNr){
	int brukerSvar;
	int tralleIndex = 0, sykkelIndex = 0, elsparkesykkelIndex = 0; 
	bool tralleSlettet = false, sykkelSlettet = false;
	bool elsparkesykkelSlettet = false;


	//Sjekker for traller
	for (int i = 0; i < tralleVec.size(); i++) {
		if (tralleVec[i]->hentGjenstadNr() == gjenstandNr) {
			//fant gjenstand
			skrivSlettGjenstandAdvarsel("tralle", gjenstandNr);

			//henter gjenstandnr på nytt for å bekrefte setting
			brukerSvar = lesInt("Skriv inn gjenstandNr paa nytt for aa slette",
			1, gUtleiesteder->hentSisteNr());

			//bruker bekreftet svar
			if (brukerSvar == gjenstandNr) {
				//skriver index i vec for videre bruk
				tralleIndex = i;
				tralleSlettet = true;
			}
			else {
				cout << "Sletting avbrutt\n"; 
			}

		}
	}
	//fant en tralle som skal slettes. Sletter data
	if (tralleSlettet) {
		delete tralleVec[tralleIndex]; //sletter ptr data
		tralleVec.erase(tralleVec.begin() + tralleIndex); //sletter ptr
		cout << "Trallen ble slettet\n";
	}

	//Sjekker for sykler
	for (int i = 0; i < sykkelVec.size(); i++) {
		if (sykkelVec[i]->hentGjenstadNr() == gjenstandNr) {
			//fant gjenstand 
			skrivSlettGjenstandAdvarsel("sykkel", gjenstandNr);

			//henter gjenstand nummer på nytt for å bekrefte sletting
			brukerSvar = lesInt("Skriv inn gjenstandNr paa nytt for aa slette",
				1, gUtleiesteder->hentSisteNr());

			//bruker bekreftet svar
			if (brukerSvar == gjenstandNr) {
				sykkelIndex = i;
				sykkelSlettet = true;
			}
			else {
				cout << "sletting avbrutt\n"; 
			}
		}
	}
	//fant en sykkel for sletting
	if (sykkelSlettet) {
		delete sykkelVec[sykkelIndex];
		sykkelVec.erase(sykkelVec.begin() + sykkelIndex);
		cout << "Sykkelen ble slettet\n";
	}


	//Sjekker for elsparkesykler
	for (int i = 0; i < elsparkesykkelVec.size(); i++) {
		if (elsparkesykkelVec[i]->hentGjenstadNr() == gjenstandNr) {
			//fant gjenstand 
			skrivSlettGjenstandAdvarsel("Elsparkesykkel", gjenstandNr);

			//henter gjenstand nummer på nytt for å bekrefte sletting
			brukerSvar = lesInt("Skriv inn gjenstandNr paa nytt for aa slette",
				1, gUtleiesteder->hentSisteNr());

			//bruker bekreftet svar
			if (brukerSvar == gjenstandNr) {
				elsparkesykkelIndex = i;
				elsparkesykkelSlettet = true;
			}
			else {
				cout << "sletting avbrutt\n";
			}
		}
	}
	//fant en elsparkesykkel for sletting
	if (elsparkesykkelSlettet) {
		delete elsparkesykkelVec[elsparkesykkelIndex];
		elsparkesykkelVec.erase(
			elsparkesykkelVec.begin() + elsparkesykkelIndex
		);
		cout << "Elsparkesykkelen ble slettet\n"; 
	}

	//forteller koden som kjørte funksjonen om noe her ble slettet
	if (tralleSlettet || sykkelSlettet || elsparkesykkelSlettet) {
		return true;
	}
	return false;
}

/**
 * @brief skriver et steds data til fil.
 * @param utleieData
 * @see Gjenstand::hentGjenstandEnum()
 * @see Gjenstand::hentGjenstadNr()
 * @see Tralle::hentBoolAtributt(...)
 * @see Sykkel::hentBoolAtributt(...)
 * @see Elsparkesykkel::hentIntAtrubutt(...)
 */
void Sted::skrivStedTilFil(ofstream& utleieData){
	utleieData << "STED\n"; 
	utleieData << stedNavn << "\n";
	utleieData << beskrivelse << "\n"; 
	utleieData << tlf << "\n";
	utleieData << inntjenteKr << "\n";

	/* Er usikker på om jeg beholder disse under*/
	utleieData << (
		tralleVec.size() +
		sykkelVec.size() +
		elsparkesykkelVec.size()
		) << "\n"; 

	//går gjennom alle vectors
	for (Tralle* tralle : tralleVec) {
		utleieData << "TRALLE\n"; 
		utleieData << tralle->hentGjenstandEnum() << "\n";
		utleieData << tralle->hentGjenstadNr() << "\n";
		utleieData << tralle->hentBoolAtributt() << "\n";
	}

	for (Sykkel* sykkel : sykkelVec) {
		utleieData << "SYKKEL\n";
		utleieData << sykkel->hentGjenstandEnum() << "\n";
		utleieData << sykkel->hentGjenstadNr() << "\n";
		utleieData << sykkel->hentBoolAtributt() << "\n";
	}

	for (Elsparkesykkel* elsparkesykkel : elsparkesykkelVec) {
		utleieData << "ELSPARKESYKKEL\n";
		utleieData << elsparkesykkel->hentGjenstandEnum() << "\n";
		utleieData << elsparkesykkel->hentGjenstadNr() << "\n";
		utleieData << elsparkesykkel->hentIntAtrubutt() << "\n";
	}
}

/**
 * @brief  leser inn stedets data fra fil, og lager gjenstander utifra det.
 * @param utleieData
 * @param navn
 * @see Gjenstand::settEnum(...)
 * @see Gjenstand::settGjenstandNr(..)
 * @see Sykkel::settBoolAttributt(...)
 * @see Tralle::settBoolAttributt(...)
 * @see Elsparkesykkel::settIntAttributt(..)
 */
void Sted::lesStedFraFil(ifstream& utleieData, string navn) {
	int antGjenstander = 0;
	string temp; //brukt for å fjerne overskrifter 
	stedNavn = navn;

	getline(utleieData >> ws, beskrivelse); //bruker getine for input med space
	utleieData >> tlf;
	utleieData >> inntjenteKr;

	utleieData >> antGjenstander;


	for (int i = 0; i < antGjenstander; i++) {
		int gjenstandType = 0, gjenstandNr = 0;
		utleieData >> temp;//fjerner overskrift
		utleieData >> gjenstandType;
		utleieData >> gjenstandNr;

		switch (gjenstandType) {
			case 0: {
				//sykkel
				bool harTilhenger;
				utleieData >> harTilhenger;

				Sykkel* sykkel = new Sykkel;
				sykkel->settEnum(gjenstandType);
				sykkel->settGjenstandNr(gjenstandNr);
				sykkel->settBoolAttributt(harTilhenger);
				sykkelVec.push_back(sykkel); 
				break; 

			}
			case 1: {
				//tralle
				bool harDrasele;
				utleieData >> harDrasele; 

				Tralle* tralle = new Tralle;
				tralle->settEnum(gjenstandType); 
				tralle->settGjenstandNr(gjenstandNr);
				tralle->settBoolAttributt(harDrasele);
				tralleVec.push_back(tralle);
				break; 
			}
			case 2: {
				int effekt; 
				utleieData >> effekt;

				Elsparkesykkel* elsparkesykkel = new Elsparkesykkel;
				elsparkesykkel->settEnum(gjenstandType);
				elsparkesykkel->settGjenstandNr(gjenstandNr);
				elsparkesykkel->settIntAttributt(effekt);
				elsparkesykkelVec.push_back(elsparkesykkel);
				break; 
			}
		}


	}
}
