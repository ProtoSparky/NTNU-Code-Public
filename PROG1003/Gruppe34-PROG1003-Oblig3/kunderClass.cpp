/*****************************************************************//**
 * @file   kunderClass.cpp
 * @brief  Funksjon definisjon for kunder klassen
 *
 * @author Kristupas Kaupas, Rangvald Jansen
 * @date   2026-4-6
 *********************************************************************/
#include <iostream>
#include <fstream>

#include "kunderClass.h"
#include "kundeClass.h"
#include "LesData3.h"
#include "utleiestederClass.h"
extern UtleieSteder* gUtleiesteder;
using namespace std;

/**
 * @brief  Returner ant kunder lagret.
 * @return int
 */
int Kunder::returnAntKunder() {
	return sisteNr; 
}

/**
 * @brief  lagrer kunde i kundeList.
 * @param kunde
 */
void Kunder::leggTilNyKunde(Kunde* kunde) {
	kundeList.push_back(kunde);
	sisteNr++;
}

/**
 * @brief  Skriver ut opsimmering for alle kunder.
 * @see Kunde::oppsummerKundeInfo()
 */
void Kunder::visAlleKunder() {
	int i=0, antKunder = kundeList.size(); 
	string temp;
	if (antKunder == 0) { cout << "Ingen kunder lagret i systemet!\n"; }
	cout << "Kunde Nr | ANT gjenstander | Navn | Tlf\n";
	cout << "----------------------------------------\n";

	for (Kunde* valgtKunde : kundeList) {
		i++;
		valgtKunde->oppsummerKundeInfo();
		if (i > 19) {
			i = 0;
			cout << "[ENTER] for aa fortsette\n";
			getline(cin, temp); 
		}
	}
}

/**
 * @brief  Spør bruker om kunde nr, og returner hvis valid.
 * @return kundeNr eller -1 hvis det ble avbrutt.
 * @see Kunde::returnKundeNr()
 */
int Kunder::hentKundeNr(){
	vector <int> kundeNrListe;
	int storstKundeNr = 0,minstKundeNr, kundeNr;

	//fyller opp en liste så vi kan finne størst kunde nr
	for (Kunde* valgtKunde : kundeList) {
		kundeNrListe.push_back(valgtKunde->returnKundeNr());
	}
	
	if (kundeNrListe.size() != 0) {
		storstKundeNr = *max_element(kundeNrListe.begin(), kundeNrListe.end());
		minstKundeNr = *min_element(kundeNrListe.begin(), kundeNrListe.end());

		//spør og finner kunde nr lagret i systemet
		kundeNr = lesInt("Skriv inn et kundeNr", minstKundeNr, storstKundeNr);
		for (int i : kundeNrListe) {
			if (i == kundeNr) {
				return kundeNr; // Kunde nr funnet
			}
		}

		cout << "Kunde med det nr var ikke funnet. Prov paa nytt\n";
	}
	else { cout << "Ingen kunder lagret i systemet!\n"; }

	
	return -1; 
}

/**
 * @brief  viser spesifikk kunde info utifra kundenr.
 * @param kundeNr int
 * @see Kunde::returnKundeNr()
 * @see Kunde::oppsummerKundeInfo()
 * @see Kunde::visGjenstander()
 */
void Kunder::visKunde(int kundeNr) {	
	for (Kunde* valgtKunde : kundeList) {
		if (valgtKunde->returnKundeNr() == kundeNr) {
			cout << "Kunde Nr | ANT gjenstander | Navn | Tlf\n";
			cout << "----------------------------------------\n";
			valgtKunde->oppsummerKundeInfo(); 
			valgtKunde->visGjenstander();

		}
	}

}

/**
 * @brief  sjekker kunde listen og får hver kunde til å sjekke for gjenstander.
 * @param id
 * @return true hvis en av kundene fant en gjenstand, false hvs ikke
 */
bool Kunder::sokGjenstand(int id) {
	bool funnetGjenstand = false;
	for (Kunde* valgtKunde : kundeList) {
		funnetGjenstand = valgtKunde->sokGjenstand(id);
		if (funnetGjenstand) {
			return funnetGjenstand;
		}
	}

	return funnetGjenstand;
}

/**
 * @brief  Constructor for Kunder.
 */
Kunder::Kunder(){
	sisteNr = 0; 
}

/**
 * @brief  Søker etter kundenr for å starte låne gjenstand prosessen.
 * @see Kunder::hentKundeNr()
 * @see Kunde::returnKundeNr()
 * @see UtleieSteder::laanGjenstandHentSted()
 * @see Sted::laanGjenstandVelgGjenstand()
 * @see Kunde::lagreGjenstander(...)
 * @see Sykkel::beregnPris(...)
 * @see Tralle::beregnPris(...)
 * @see Elsparkesykkel::beregnPris(...)
 * @see Sted::oekInntekt(...)
 */
void Kunder::laanGjenstandHentKunde(){
	vector <Gjenstand*> gjenstander; 
	int kundeNr = hentKundeNr();
	int totalSum = 0;
	Sted* stedPtr = nullptr;
	if (kundeNr != -1) {
		for (Kunde* kunde : kundeList) {
			if (kunde->returnKundeNr() == kundeNr) {
				// kunde med kunde nummeret er funnet
				
				//Spør kunde om utleiested og lagrer alle gjenstander	
				stedPtr = gUtleiesteder->laanGjenstandHentSted(); 
				gjenstander = stedPtr->laanGjenstandVelgGjenstand();

				//lagrer alle gjenstandene
				kunde->lagreGjenstander(gjenstander);
				
				//beregner totalsum
				for (Gjenstand* gjenstand : gjenstander) {
					totalSum += gjenstand->beregnPris();
				}
				stedPtr->oekInntekt(totalSum); //legger på totalsummen

				cout << "Gjenstander laant for kunde " << kundeNr 
					 << " med totalsum " << totalSum << "kr \n";

			}
		}
	}
}



/**
 * @brief logic for å levere alle gjenstander hos en kunde.
 * @param kundeNr
 * @see Kunde::returnKundeNr()
 * @see UtleieSteder::laanGjenstandHentSted()
 * @see StedmottaKundeGjenstander(...)
 * @see Kunde::hentGjenstander()
 * @see Kunde::fjernKundeGjenstander()
 */
void Kunder::leverGjenstander(int kundeNr){
	Sted* stedPtr = nullptr; 

	if (kundeNr != -1) {
		for (Kunde* kunde : kundeList) {
			if (kunde->returnKundeNr() == kundeNr) {
				//vi har funnet kunden vår

				//henter et valid sted å levere til
				cout << "Velg et leveringssted\n";
				stedPtr = gUtleiesteder->laanGjenstandHentSted();

				//tar alle kundenes gjenstander, lager nye identiske gjenstander
				//på retur stedet med default attributter
				stedPtr->mottaKundeGjenstander(kunde->hentGjenstander());

				//sletter alle gjenstander fra kundenes vector
				kunde->fjernKundeGjenstander();
			}
		}

	}
}


/**
 * @brief  UI for å slette kunde med kunde nr.
 * @param kundeNr
 * @see Kunde::returnKundeNr()
 * @see Kunde::returnKundeNavn()
 * @see Kunder::leverGjenstander(...)
 */
void Kunder::slettKunde(int kundeNr){
	string brukerKundeNavn;
	Kunde* funnetKundePtr = nullptr;
	if (kundeNr != -1) {
		for (Kunde* kunde : kundeList) {
			if (kunde->returnKundeNr() == kundeNr) {
				//kunde med kundenr funnet
				funnetKundePtr = kunde; //Det skal bare finnes en kunde med nr								
			}
		}


		cout << "!!!!!!!!!!!!!!!! Kunden nr "
			<< funnetKundePtr->returnKundeNr() << " | '"
			<< funnetKundePtr->returnKundeNavn() << "'"
			<< " skal slettes !!!!!!!!!!!!!!!!\n"
			<< "Skriv inn kunde navnet for aa fortsette. "
			<< "Feil tekst avbryter slettingen\nNavn: ";
		getline(cin, brukerKundeNavn);

		if (brukerKundeNavn == funnetKundePtr->returnKundeNavn()) {
			//leverer gjenstander til valid sted
			leverGjenstander(kundeNr);

			kundeList.remove(funnetKundePtr); //sletter ptr
			delete funnetKundePtr; //sletter data ptr peker til
			cout << "Kunden ble slettet \n"; 
		}
		else {
			cout << "Sletting avbrutt\n";
		}
	}
}

/**
 * @brief  går gjennom alle kunder, og ber dem skrive sin data.
 * @param kunderData
 * @see Kunde::skrivKundeTilFil(...)
 */
void Kunder::skrivKunderTilFil(ofstream& kunderData){
	for (Kunde* kunde : kundeList) {
		kunde->skrivKundeTilFil(kunderData);
	}
}

/**
 * @brief går gjennom filen, og og oppretter individuelle kunder.
 * @param kunderData
 * @see Kunde::lesKundeFraFil(...)
 */
void Kunder::lesKunderFraFil(ifstream& kunderData){
	int antKunder = 0;
	kunderData >> antKunder;
	sisteNr = antKunder; //TEMP 
	for (int i = 0; i < antKunder; i++) {
		Kunde* nyKunde = new Kunde; 
		nyKunde->lesKundeFraFil(kunderData);
		kundeList.push_back(nyKunde); 
	}
}
