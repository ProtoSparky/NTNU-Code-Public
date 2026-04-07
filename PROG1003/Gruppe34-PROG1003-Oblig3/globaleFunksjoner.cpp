/*****************************************************************//**
 * @file   globaleFunksjoner.cpp
 * @brief  Funksjon definisjon for globale funksjoner
 *
 * @author Kristupas Kaupas, Rangvald Jansen
 * @date   2026-4-6
 *********************************************************************/
#include <iostream>
#include <fstream>

#include "LesData3.h"
#include "kundeClass.h"
#include "kunderClass.h"
#include "utleiestederClass.h"
#include "const.h"
extern Kunder* gKunder ; 
extern UtleieSteder* gUtleiesteder;
using namespace std;

/**
 * @brief  skriver ut menyvlgene for hovedmenyen.
 */
void skrivHovedmeny() {
	cout << "K - Kundeadministrasjom\n"
		<< "S - Sted administrasjon\n"
		<< "G - Gjenstand administrasjon\n"
		<< "Q - Avslutt programm\n";
}

/**
 * @brief  skriver ut S menyvalgene.
 */
void skrivStedmeny() {
	cout << "STEDMENY\n"
		<< "N - Nytt sted\n"
		<< "A - Skriv alle\n"
		<< "1 - Skriv spesifikk\n"
		<< "T - Skriv inntekt\n"
		<< "I - Gjenstander igjen paa lager\n"
		<< "O - Overfor gjenstand mellom steder\n"
		<< "S - Slett sted\n"
		<< "Q - Tilbake\n";
}

/**
 * @brief meny for S valgene.
 * @see UtleieSteder::nyttSted()
 * @see UtleieSteder::skrivAlleSted()
 * @see UtleieSteder::skrivSpesifikkSted()
 * @see UtleieSteder::skrivAllInntekt()
 * @see UtleieSteder::skrivAlleAktuellGjenstand()
 * @see UtleieSteder::flyttGjenstanderTilAnnetSted()
 * @see UtleieSteder::slettSted()
 * @see skrivHovedmeny()
 * @see skrivStedmeny()
 */
void stedMeny() {
	char valg;
	skrivStedmeny();

	do{
		valg = lesChar("Kommando");
		switch (valg) {
			case'N':{
				gUtleiesteder->nyttSted();
				break;
			}
			case'A':{
				gUtleiesteder->skrivAlleSted();
				break;
			}
			case'1':{
				gUtleiesteder->skrivSpesifikkSted();
				break;
			}
			case'T':{
				gUtleiesteder->skrivAllInntekt();
				break;
			}
			case'I':{
				gUtleiesteder->skrivAlleAktuellGjenstand();
				break;
			}
			case'O':{
				gUtleiesteder->flyttGjenstanderTilAnnetSted(); 
				break;
			}
			case'S':{
				gUtleiesteder->slettSted(); 
				break;
			}
			case'Q': {
				skrivHovedmeny();
				break;
			}
			default: {
				skrivStedmeny();
			}
		}
		cout << "\n";
	} while (valg != 'Q');
}
/**
 * @brief  Skriver ut K meny.
 */
void skrivKmeny(){
	cout
		<< "======== Kunde meny ========\n"
		<< "N - Ny kunde\n"
		<< "A - Skriv ut alle kunder\n"
		<< "1 - Skriv ut spesifikk kunde nr\n"
		<< "H - Laan gjenstander \n"
		<< "L - Lever alle gjenstander\n"
		<< "S - Slett kunde\n"
		<< "Q - Tilbake til hovedmeny\n"; 
}


/**
 * @brief  Logic for K meny.
 * @see skrivKmeny()
 * @see Kunde::nyKunde()
 * @see Kunder::leggTilNyKunde(...)
 * @see Kunder::visAlleKunder()
 * @see Kunder::visKunde(...)
 * @see Kunder::hentKundeNr()
 * @see Kunder::laanGjenstandHentKunde()
 * @see Kunder::leverGjenstander()
 * @see Kunder::slettKunde(...)
 * 
 */
void kMeny(){
	char valg;
	skrivKmeny();
	valg = lesChar("Kommando");
	while (valg != 'Q') {
		switch (valg) {
			case 'N': {
				Kunde* nykunde = new Kunde;
				nykunde->nyKunde(); 
				gKunder->leggTilNyKunde(nykunde);//lagrer ny kunde
				break;
			}
			case 'A': {
				gKunder->visAlleKunder();
				break;
			}
			case '1': {
				gKunder->visKunde(gKunder->hentKundeNr());
				break;
			}
			case 'H': {
				gKunder->visAlleKunder();
				gKunder->laanGjenstandHentKunde(); 
				break;
			}
			case 'L': {		
				gKunder->visAlleKunder();
				gKunder->leverGjenstander(gKunder->hentKundeNr());
				break; 
			}
			case 'S': {
				gKunder->slettKunde(gKunder->hentKundeNr()); 
				break;
			}
			default: {
				skrivKmeny();
			}
		}
		skrivKmeny();
		cout << "\n";
		valg = lesChar("Kommando");
	}
}

/**
 * @brief  skriver ut G meny.
 */
void skrivGmeny(){
	cout
		<< "======== Gjenstand meny ========\n"
		<< "N - Ny gjenstand\n"
		<< "F - Finn gjenstand\n"
		<< "S - Slett gjenstand\n"
		<< "Q - TIlbake til hovedmeny\n";
}

/**
 * @brief Leter etter gjenstander hos kunder og steder og skriver de ut.
 * @see UtleieSteder::hentSisteNr()
 * @see Kunder::sokGjenstand(...)
 * @see UtleieSteder::sokGjenstand(...)
 */
void finnGjenstand() {
	bool funnetGjenstandSted = false;
	bool funnetGjenstandKunde = false;
	bool gjenstanderFinns = true;

	int valgtGjenstandNr, maksGjenstandNr = gUtleiesteder->hentSisteNr();
	
	if (maksGjenstandNr == 0) {
		cout << "Det finnes ingen gjenstander i systemet \n"; 
		gjenstanderFinns = false;
	}

	if (gjenstanderFinns) {
		cout << "Soek etter en spesifikk gjenstand \n";
		valgtGjenstandNr = lesInt("gjenstand nr ", 0, maksGjenstandNr);
	
		//sjekker utleiesteder først
		funnetGjenstandSted = gUtleiesteder->sokGjenstand(valgtGjenstandNr);
		//sjekker kunder
		funnetGjenstandKunde = gKunder->sokGjenstand(valgtGjenstandNr);

		if ((!funnetGjenstandSted) && (!funnetGjenstandKunde)) {
			cout << "Gjenstand ikke funnet/finns ikke\n";
		}
	}	 

}

/**
 * @brief  Logic for G meny.
 * @see skrivGmeny()
 * @see UtleieSteder::velgUtleieSted()
 * @see finnGjenstand()
 * @see UtleieSteder::slettGjenstand()
 */
void gMeny(){
	char valg;
	skrivGmeny();
	valg = lesChar("Kommando");
	while (valg != 'Q') {
		switch (valg) {
			case 'N': {
				gUtleiesteder->velgUtleieSted(); 
				break;
			}
			case 'F': {
				finnGjenstand(); 
				break;
			}
			case 'S': {
				gUtleiesteder->slettGjenstand(); 
				break;
			}
			default: {
				skrivGmeny();
			
			}
		}
		cout << "\n";
		valg = lesChar("Kommando");
	}
}

/**
 * @brief  Lagrer alt i data filene.
 * @see Kunder::returnAntKunder()
 * @see Kunder::skrivKunderTilFil(...)
 * @see UtleieSteder::hentSisteNr()
 * @see UtleieSteder::skrivStederTilFil(...)
 */
void skrivTilFil(){
	ofstream kunderData(KUNDERDTA); //åpner kunder.dta filen
	kunderData << gKunder->returnAntKunder() <<"\n"; //lagrer siste kunde nr 
	gKunder->skrivKunderTilFil(kunderData);

	ofstream utleieData(STEDERDTA);
	utleieData << gUtleiesteder->hentSisteNr() << "\n"; 
	gUtleiesteder->skrivStederTilFil(utleieData); 
	
	kunderData.close();
	utleieData.close(); 
}

/**
 * @brief leser fra fil og fyller på vektorer.
 * @see Kunder::lesKunderFraFil(...)
 * @see UtleieSteder::lesStederFraFil(...)
 */
void lsFraFil(){
	ifstream kunderData(KUNDERDTA); 
	gKunder->lesKunderFraFil(kunderData);

	ifstream utleieData(STEDERDTA);
	gUtleiesteder->lesStederFraFil(utleieData);


	kunderData.close();
	utleieData.close(); 
}
