/*****************************************************************//**
 * @file   utleiestederClass.cpp
 * @brief  Funksjon definisjon for utleiesteder klassen
 *
 * @author Kristupas Kaupas, Rangvald Jansen
 * @date   2026-4-6
 *********************************************************************/
#include <iostream>
#include <string>

#include "utleiestederClass.h"
#include "stedClass.h"
#include "LesData3.h"
using namespace std;

/**
 * @brief  constructor for utleiesteder, definerer sisteNr.
 */
UtleieSteder::UtleieSteder() {
	sisteNr = 0;
}

/**
 * @brief funksjon for å lage et nytt sted.
 * @see Sted::nyttSted
 */
void UtleieSteder::nyttSted() {
	string nyttStednavn;
	Sted* nySted;

	cout << "Navnet paa nytt sted: "; getline(cin, nyttStednavn);

	auto finnsFraFor = stedMap.find(nyttStednavn);

	if (finnsFraFor == stedMap.end()) {
		nySted = new Sted;
		nySted->nyttSted(nyttStednavn);

		stedMap.insert({nyttStednavn, nySted});
	} else{
		cout << "Stedet finns fra for\n";
	}

}

/**
 * @brief  går gjennom alle steder og skriver dems info ut.
 * @see skrivInfo
 */
void UtleieSteder::skrivAlleSted() {
	if (stedMap.empty()) {
		cout << "Det finnes ingen steder lagret i systemet\n";
	}
	for (auto it = stedMap.begin(); it != stedMap.end(); it++) {
		it->second->skrivInfo();
		cout << "\n";
	}
}

/**
 * @brief  skriver ut info til et spesifikk sted bruker spør om.
 * @see skrivAllInfo
 */
void UtleieSteder::skrivSpesifikkSted() {
	string id;

	cout << "ID til sted: "; getline(cin, id);

	if (stedMap.find(id) != stedMap.end()) {
		stedMap[id]->skrivAllInfo();
	} else{
		cout << "Sted med ID " << id << " finns ikke.";
	}
}

/**
 * @brief skriver ut inntekt for alle steder.
 * @see skrivInntekt
 */
void UtleieSteder::skrivAllInntekt() {
	for (auto it = stedMap.begin(); it != stedMap.end(); it++) {
		it->second->skrivInntekt();
	}
}

/**
 * @brief skriver ut ant gjenstander med en spesifikk type bruker velger.
 * @see skrivAktuellGjenstand
 */
void UtleieSteder::skrivAlleAktuellGjenstand() {
	int choice;
	bool harSkrivd = false;
	string resultat;

	string compareTo = "no";

	cout << "1 - Tralle\n";
	cout << "2 - Sykkel\n";
	cout << "3 - Elsparkesykkel\n";

	choice = lesInt("Hvilken gjenstand skal skrives", 1, 3);

	for (auto it = stedMap.begin(); it != stedMap.end(); it++) {
		resultat = it->second->skrivAktuellGjenstand(choice);
		
		if(resultat.compare(compareTo)!=0){
			cout << resultat;
			harSkrivd = true;
		}
	}
	if (!harSkrivd) {
		cout << "Ingen gjenstand av valgt type ble funnet.\n";
	}
}

/**
 * @brief  menyvalg for spesifikk utleiested når gjenstander skal lages.
 * @see opprettGjenstander
 */
void UtleieSteder::velgUtleieSted(){
	int i = 0, valg; 
	vector <string> stedsNavn; 

	cout << "Velg utleie sted hvor gjenstand(ene) lagres\n"; 
	if (stedMap.empty()) {
		cout << "Det finnes ingen steder gjentander kan opprettes i\n"; 
	}
	else {
		cout << "Indeks | Sted navn\n"
			 << "--------------------\n"; 
	}

	//printer ut alle steder
	for (auto sted : stedMap) {
		cout << i << " | " << sted.first << "\n"; 

		//lagrer alle navn i en vec for å gi map en index
		stedsNavn.push_back(sted.first);
		i++; 
	}

	//spør bruker om sted, og kjører func for å opprette gjenstander på stedet
	if (!stedMap.empty()) {
		valg = lesInt("velg sted", 0, i-1);
		stedMap.at(stedsNavn[valg])->opprettGjenstander(); 

	}
}

/**
 * @brief  øker sisteNr, feks når en gjenstand lages.
 */
void UtleieSteder::oekSisteNr(){
	sisteNr ++; 
}

/**
 * @brief  henter siste nr.
 * @return int
 */
int UtleieSteder::hentSisteNr() {
	return sisteNr; 
}

/**
 * @brief  Søker etter en gjenstand utifra gjenstandnr.
 * @param id
 * @see sokGjenstand
 */
bool UtleieSteder::sokGjenstand(int id){
	bool funnetGjenstand = false;

	for (auto sted : stedMap) {
		//sjekker alle gjenstand vektorer for et gitt sted
		funnetGjenstand = sted.second->sokGjenstand(id);

		if (funnetGjenstand) {
			return funnetGjenstand;
		}

	}

	return funnetGjenstand;
}

/**
 * @brief Spør bruker om et valid sted.
 * @return ptr til sted
 */
Sted * UtleieSteder::laanGjenstandHentSted(){
	int stedInput, index = 0;
	if (stedMap.empty()) {
		cout << "Det finnes ingen steder i systemet\n";
	}
	else {
		cout << "Index | Navn\n";
		cout << "-------------\n"; 
	}
	
	//skriver ut sted, og finner maks lengde av map
	for (auto sted : stedMap) {
		cout << index << " | " << sted.first << "\n";
		index++; 
	}

	stedInput = lesInt("velg sted", 0, index - 1);
	index = 0;

	//finner index personen har valgt
	for (auto sted : stedMap) {
		if (index == stedInput) {
			//stedet kunden valgte er funnet. Returner denne
			return sted.second; 
		}
		index++; 
	}

	return nullptr; //Dette skjer bare hvis noe har gått sikkelig galt :3	
}

/**
 * @brief UI for flytting av gjenstander sted A til sted B.
 * @see leggTilSykler
 * @see hentSyklerForFlytting
 * @see leggTilTraller
 * @see hentTrallerForFlytting
 * @see leggTilElsparkesykler
 * @see hentElsparkesykklerForFlytting
 */
void UtleieSteder::flyttGjenstanderTilAnnetSted(){
	int indexA = 0, indexB = 0, i = 0;
	Sted* indexAPtr = nullptr;
	Sted* indexBPtr = nullptr;
	bool ingenSteder = stedMap.empty(); 

	if (ingenSteder) {
		cout << "Det finnes ingen steder i systemet\n";
	}
	else {
		cout << "Index | Navn\n";
		cout << "-------------\n";
	}
	for (auto sted : stedMap) {
		cout << i << " | " << sted.first << "\n";
		i++; 
	}
	i--; //fjerer siste nr
	
	//bugfix så man ikke blir stuck i en loop når ingen steder fins
	if (!ingenSteder) {
		cout << "velg stedet du skal flytte gjenstandene fra, og stedet du skal "
			<< "flytte gjenstandene til\n";

		indexA = lesInt("sted A", 0, i);
		indexB = lesInt("Sted B", 0, i);
	}

	if (indexA == indexB && (!ingenSteder)) {
		cout << "Du kan ikke velge det samme stedet to ganger\n";
	}
	else if (indexA != indexB && (!ingenSteder)) { //bugfix samme som ln 242
		i = 0;
		//finner ptr for sted A
		for (auto sted:stedMap) {
			if (indexA == i) {
				//funnet A
				indexAPtr = sted.second;
			}
			i++; 
		}
		i = 0;

		//finner ptr for sted B
		for (auto sted : stedMap) {
			if (indexB == i) {
				indexBPtr = sted.second;
			}
			i++; 
		}


		//Flytter sykkel fra A til B
		indexBPtr->leggTilSykler(indexAPtr->hentSyklerForFlytting(false)); 

		//-||- for traller
		indexBPtr->leggTilTraller(indexAPtr->hentTrallerForFlytting(false));

		//-||- for elsparkesykler
		indexBPtr->leggTilElsparkesykler(
			indexAPtr->hentElsparkesykklerForFlytting(false)
		); 

	}


}


/**
 * @brief UI for å slette et sted.
 * @see leggTilSykler
 * @see hentSyklerForFlytting
 * @see leggTilTraller
 * @see hentTrallerForFlytting
 * @see leggTilElsparkesykler
 * @see hentElsparkesykklerForFlytting
 */
void UtleieSteder::slettSted(){
	int indexA = 0, indexB = 0, i = 0;
	Sted* indexAPtr = nullptr;
	Sted* indexBPtr = nullptr;
	string slettetStedNavn, brukerSlettetStedNavn;
	bool stederBorte = stedMap.empty();
	if (stederBorte) {
		cout << "Det finnes ingen steder i systemet\n";
	}
	else {
		cout << "Index | Navn\n";
		cout << "-------------\n";
	}
	for (auto sted : stedMap) {
		cout << i << " | " << sted.first << "\n";
		i++;
	}
	i--; //fjerer siste nr


	//stopper bruker fra å måtte velge sted hvis ingen eksisterer
	if (!stederBorte) {
		cout << "velg stedet du skal slette , og stedet du skal "
			<< "flytte det slettede stedets gjenstander til\n";
		indexA = lesInt("Sted som skal slettes", 0, i);
		indexB = lesInt("Sted gjenstandene flyttes til", 0, i);
	}

	if (indexA == indexB && (!stederBorte)) {
		cout << "Du kan ikke velge det samme stedet to ganger."
			 << " Sletting avbrutt\n";
	}
	else {
		i = 0;
		//finner ptr for sted A
		for (auto sted : stedMap) {
			if (indexA == i) {
				//funnet A
				indexAPtr = sted.second;
				slettetStedNavn = sted.first; 
			}
			i++;
		}
		i = 0;

		//finner ptr for sted B
		for (auto sted : stedMap) {
			if (indexB == i) {
				indexBPtr = sted.second;
			}
			i++;
		}
	}

	if (indexAPtr != nullptr && indexBPtr != nullptr) {


		cout << "!!!!!!!!! ADVARSEL - Du er i ferd med aa slette stedet '"
			<< slettetStedNavn << "' !!!!!!!!!\n"
			<< "Skriv inn stedets navn for aa fortsette. Feil svar avslutter"
			<< " slettingen.\n"
			<< "Skriv inn sted navn: ";
		getline(cin, brukerSlettetStedNavn);

		if (slettetStedNavn == brukerSlettetStedNavn) {
			//starter slettingen

			//flytter gjenstandene fra slettet sted til stedet bruker valgte
			//Flytter sykkel fra A til B
			indexBPtr->leggTilSykler(indexAPtr->hentSyklerForFlytting(true));

			//-||- for traller
			indexBPtr->leggTilTraller(indexAPtr->hentTrallerForFlytting(true));

			//-||- for elsparkesykler
			indexBPtr->leggTilElsparkesykler(
				indexAPtr->hentElsparkesykklerForFlytting(true)
			);

			//sletter stedet i map, og sletter stedets data
			stedMap.erase(slettetStedNavn);
			delete indexAPtr;

			cout << "Stedet '" << slettetStedNavn << "' ble slettet\n";
		}
		else {
			cout << "Avslutter sletting. Ingenting slettet\n";
		}
	}
}

/**
 * @brief prøver å sette en gjenstand på alle steder utifra nr.
 * @see hentSisteNr
 * @see Sted::slettGjenstand
 */
void UtleieSteder::slettGjenstand(){
	int gjenstandNr = 0;
	bool gjenstandSlettet = false;
	cout << "skriv inn et gjenstandsNr for en gjenstand som skal slettes \n";
	gjenstandNr = lesInt("Gjenstand Nr", 1, hentSisteNr()); 

	//går gjennom alle steder, prøver å slette gjenstanden
	// blir en gjenstand slettet, så husker vi dette for senere feilmeldinger
	for (auto sted : stedMap) {
		if (sted.second->slettGjenstand(gjenstandNr)) {gjenstandSlettet = true;}		
	}

	if (!gjenstandSlettet) {
		cout << "Ingen gjenstand ble slettet fordi den er hos en kunde"
			<< " eller eksisterer ikke\n";
	}
}

/**
 * @brief går gjennom alle stedene, og ber dem skrive sin data til fil.
 * @param utleieData
 * @see skrivStedTilFil
 */
void UtleieSteder::skrivStederTilFil(ofstream& utleieData){
	utleieData << stedMap.size() << "\n"; //lagrer hvor mange steder vi har 
	for (auto sted : stedMap) {
		sted.second->skrivStedTilFil(utleieData);
	}
}

/**
 * @brief  Leser inn og lager x antall steder fra fil. 
 * @param utleieData
 * @see lesStedFraFil
 */
void UtleieSteder::lesStederFraFil(ifstream& utleieData){
	string temp, navn; 
	int steder = 0; 
	utleieData >> sisteNr;
	utleieData >> steder; 

	for (int i = 0; i < steder; i++) {
		utleieData >> temp; //fjerner overskrift
		getline(utleieData >> ws, navn); //bruker getline siden det kan være space

		Sted* sted = new Sted;
		sted->lesStedFraFil(utleieData, navn);
		stedMap[navn] = sted; //lagrer det nye stedet


	}

}
