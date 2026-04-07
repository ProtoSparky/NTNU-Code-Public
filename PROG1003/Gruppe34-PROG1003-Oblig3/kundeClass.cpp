/*****************************************************************//**
 * @file   kundeClass.cpp
 * @brief  Funksjon definisjon for kunde klassen
 *
 * @author Kristupas Kaupas, Rangvald Jansen
 * @date   2026-4-6
 *********************************************************************/
#include <iostream>
#include <iomanip>

#include "kundeClass.h"
#include "kunderClass.h"; 
#include "LesData3.h"
#include "tralleSubclass.h"
#include "sykkelSubclass.h"
#include "elsparkesykkelSubclass.h"
extern Kunder* gKunder;
using namespace std;


/**
 * @brief  Setter opp en ny kunde med basic info.
 * @see Kunder::returnAntKunder()
 */
void Kunde::nyKunde() {
	kundeNr = (gKunder->returnAntKunder()) +1; // setter kundeNr 1 større enn sist brukt. 

	cout << "Skriv inn kunde navn\nInput: ";
	getline(cin, navn);

	tlf = lesInt("skriv inn kunde tlf", 0, 99999999);

}


/**
 * @brief  printer unt oppsummering av info hos kunde.
 */
void Kunde::oppsummerKundeInfo(){
	cout << setw(6) << kundeNr << setw(5) << " | " 
		 << setw(8) << gjenstandVec.size()<< setw(10) << " | "
		 << setw(5) << navn << setw(5) << " | " 
		 << setw(5) << tlf << setw(5) << "\n";
}

/**
 * @brief  returner kunde nummer.
 * @return int
 */
int Kunde::returnKundeNr(){
	return kundeNr;
}

/**
 * @brief viser alle gjenstander kunden har.
 * @see Sykkel::visGjenstand()
 * @see Tralle::visGjenstand()
 * @see Elsparkesykkel::visGjenstand()
 */
void Kunde::visGjenstander(){
	if (!gjenstandVec.empty()) {
		cout << "Nr | Gjenstand type \n"
			 << "----------------------\n"; 

	}
	else {
		cout << "Kunden har ingen gjensntander \n"; 
	}
	for (Gjenstand* valgtGjenstand : gjenstandVec) {
		valgtGjenstand->visGjenstand();
	}
}


/**
 * @brief  søker etter en gjenstand hos kunde og returner true hvis funnet.
 * @param id, altså gjenstandsnr
 * @return true hvis gjenstand funnet, eller false hvis ikke
 * @see Gjenstand::hentGjenstadNr()
 * @see Gjenstand::hentGjenstandEnum()
 */
bool Kunde::sokGjenstand(int id) {
	bool funnetGjenstand = false;

	for (int i = 0; i < gjenstandVec.size(); i++) {
		if (gjenstandVec[i]->hentGjenstadNr() == id) {
			switch (gjenstandVec[i]->hentGjenstandEnum()) {
			case 0: {
				cout << "Funnet sykkel med gjenstand nr " << id 
					 << " hos kunde '" << navn << "'\n";
				funnetGjenstand = true;
				return funnetGjenstand;
				break;
			}
			case 1: {
				cout << "Funnet tralle med gjenstand nr " << id 
					 << " hos kunde '" << navn << "'\n";
				funnetGjenstand = true;
				return funnetGjenstand;
				break;
			}
			case 2: {
				cout << "Funnet elsparkesykkel med gjenstand nr " << id 
					 << " hos kunde '" << navn << "'\n";
				funnetGjenstand = true;
				return funnetGjenstand;
				break;
			}
			}
		}
	}

	return funnetGjenstand;
}

/**
 * @brief  lagrer alle gjenstnder i kundenes vektor.
 * @param gjenstand vector
 */
void Kunde::lagreGjenstander(vector <Gjenstand*> gjenstand){
	for (int i = 0; i < gjenstand.size(); i++) {
		gjenstandVec.push_back(gjenstand[i]);
	}
}

/**
 * @brief  Henter alle gjenstander fra en kunde.
 * @return gjenstander vector
 */
vector <Gjenstand*> Kunde::hentGjenstander() {
	return gjenstandVec;
}

/**
 * @brief Sletter alle gjenstander kunden har.
 */
void Kunde::fjernKundeGjenstander(){
	for (Gjenstand* gjenstand : gjenstandVec) {
		delete gjenstand; //sletter data i pointers
	}
	gjenstandVec.clear(); 
}

/**
 * @brief  Henter kundens navn.
 * @return string navn
 */
string Kunde::returnKundeNavn() {
	return navn;
}

/**
 * @brief går gjennom alle kundenes data og skriver det til fil .
 * @param kunderData
 * @see Gjenstand::hentGjenstadNr()
 * @see Gjenstand::hentGjenstandEnum()
 * @see Tralle::hentBoolAtributt()
 * @see Sykkel::hentBoolAtributt()
 * @see Elsparkesykkel::hentIntAtrubutt()
 */
void Kunde::skrivKundeTilFil(std::ofstream & kunderData){
	kunderData << "KUNDE\n"; //lager overskrift for kunder 
	
	kunderData << kundeNr << "\n";
	kunderData << tlf << "\n";
	kunderData << navn << "\n";
	kunderData << gjenstandVec.size() << "\n"; 

	//går gjennom kundenes gjenstander
	for (Gjenstand* gjenstand : gjenstandVec) {
		kunderData << "GJENSTAND\n";
		kunderData << gjenstand->hentGjenstadNr() << "\n"; //lagrer gjenstand nummer
		kunderData << gjenstand->hentGjenstandEnum() << "\n";
		
		switch (gjenstand->hentGjenstandEnum()) {
			case 0: {
				//sykkel
				kunderData << gjenstand->hentBoolAtributt(); break;
			}
			case 1: {
				//tralle
				kunderData << gjenstand->hentBoolAtributt(); break;
			}
			case 2: {
				//elsparkesykkel
				kunderData << gjenstand->hentIntAtrubutt(); break;
			}
		}
		kunderData << "\n";

	}

}

/**
 * @brief  leser inn kunde info fra fil, ink gjenstander.
 * @param kunderData
 * @see Gjenstand::settEnum(...)
 * @see Gjenstand::settGjenstandNr(...)
 * @see Tralle::settBoolAttributt(...)
 * @see Sykkel::settBoolAttributt(...)
 * @see Elsparkesykkel::settIntAttributt(...)
 */
void Kunde::lesKundeFraFil(ifstream& kunderData){
	string temp; //her sendes tekst som jeg ikke ønsker å bruke
	int antGjenstander = 0; 
	kunderData >> temp; //fjerner overskrift "KUNDER"

	kunderData >> kundeNr; 
	kunderData >> tlf;
	getline(kunderData>>ws, navn); //bruker getline her for navn kan ha mellomrom
	kunderData >> antGjenstander; 

	for (int i = 0; i < antGjenstander; i++) {
		int gjenstandNr = 0, gjenstandEnum;
		kunderData >> temp; //fjerner overskrift

		kunderData >> gjenstandNr;
		kunderData >> gjenstandEnum;




		/* Switchen trengs egentlig ikke, for det bestemmer bare prisen på
		gjenstanden når det lånes, men jeg laster den fortsatt inn, for
		dette programmet kan i teorien bli oppdatert 
		(selv om det er et midlertidig prosjekt)
		*/
		switch (gjenstandEnum) {
			case 0: {
				//sykkel
				bool harTilhenger;
				kunderData >> harTilhenger;

				Sykkel* sykkel = new Sykkel; 
				sykkel->settEnum(gjenstandEnum);
				sykkel->settGjenstandNr(gjenstandNr);
				sykkel->settBoolAttributt(harTilhenger);
				gjenstandVec.push_back(sykkel);
				break;

			}
			case 1: {
				//tralle
				bool harDrasele;
				kunderData >> harDrasele;
				Tralle* tralle = new Tralle;

				tralle->settEnum(gjenstandEnum);
				tralle->settGjenstandNr(gjenstandNr);
				tralle->settBoolAttributt(harDrasele);
				gjenstandVec.push_back(tralle);
				break; 
			}
			case 2: {
				int watt;
				kunderData >> watt;

				Elsparkesykkel* elsparkesykkel = new Elsparkesykkel;
				elsparkesykkel->settEnum(gjenstandEnum);
				elsparkesykkel->settGjenstandNr(gjenstandNr);
				elsparkesykkel->settIntAttributt(watt);
				gjenstandVec.push_back(elsparkesykkel);
				break; 
			}
		}
	}

}