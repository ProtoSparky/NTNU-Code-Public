/*****************************************************************//**
 * @file   oblig3.cpp
 * @brief  Program som holder oversikt over isbiler og dems iskrem. 
 * 
 * OBS!!! FILPLASS krever Windows 1252 text encoding UTEN BOM
 * 
 * @author Kristupas Kaupas
 * @date   2026-3-9
 *********************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>			//ifstream, ofstream
#include "lesdata2.h";		//Lesint
using namespace std; 
enum sorbetTyper {Sorbe, Granite, Slush};
const string FILPLASS = "./ISBIL.DTA";	// Sted hvor program lagrer sin data
										//	på disk

class Iskrem {
	private:
		string smak;
		int pris; 

	public:
		Iskrem(ifstream& file);
		Iskrem() {}
		virtual void lagreData(ofstream& file);
		virtual void skrivData();
		virtual void nyIskrem();

};

class Sorbet : public Iskrem {
	private: 
		sorbetTyper type; 
	public:
		Sorbet(ifstream& file);
		Sorbet() {}
		void skrivData() override;
		void nyIskrem() override;
		void lagreData(ofstream& file) override;
};

class Floteis : public Iskrem {
	private:
		bool vegan; 
	public:
		Floteis(ifstream& file);
		Floteis() {}
		void skrivData() override;
		void nyIskrem() override;		
		void lagreData(ofstream& file) override;
};


class Isbil {
	private:
		string sted;		
		vector <Iskrem*> iskremSortiment; //pekere til alle [Iskrem] den har
	public:
		Isbil(ifstream & file);
		~Isbil();
		void leggTilIskrem();
		void skrivOppsummering();
		void skrivDetaljertOppsummering();
		void lagreBil(ofstream & file);
		string returnSted();
};

vector <Isbil*> gIsbiler;				//liste med alle isbiler

void skrivMeny(); 
void skrivAlleIsbiler(); 
void skrivBilOgEvtLeggInn(const bool leggInn); 
void skrivTilFil(); 
void lesFraFil(); 


/**
 * Hovedprogrammet
 */
int main(){	
	lesFraFil(); 

	char cmd;
	skrivMeny();
	cmd = lesChar("valg");
	while (cmd != 'Q') {
		switch (cmd) {
			case 'A':
				skrivAlleIsbiler();
				break;
			case 'E':
				skrivBilOgEvtLeggInn(false); 
				break;
			case 'L':
				skrivBilOgEvtLeggInn(true);
				break;
			case 'S':
				skrivTilFil();
				break; 
		}
		skrivMeny();
		cmd = lesChar("valg");
	}
	return 0;
}


/**
 * @brief Fyller ut vegan bool fra fil.
 * @param file
 */
Floteis::Floteis(ifstream& file) : Iskrem(file) {
	file >> vegan;
}

/**
 * @brief Kjører funksjoner for å legge til sorbet eler fløteis.
 * @param file
 */
Isbil::Isbil(ifstream& file) {
	string buffer;
	file >> buffer;								//Hopper over "ISBIL" 
	file >> sted;
	int counter;
	file >> counter;							//antall iskrem sortiment 

	for (int i = 0; i < counter; i++) {
		file >> buffer;
		//Sjekker om filen har SORBET 
		// eller FLOTEIS, og kjører 
		// de riktige klassene
		if (buffer == "SORBET") {
			Sorbet* nySorbet = new Sorbet(file);
			iskremSortiment.push_back(nySorbet);
		}
		else if (buffer == "FLOTEIS") {
			Floteis* nyFloteis = new Floteis(file);
			iskremSortiment.push_back(nyFloteis);
		}
	}

}

/**
 * @brief Destructor sletter alle iskrem i bilens liste.
 */
Isbil::~Isbil() {
	for (int i = 0; i < iskremSortiment.size(); i++) {
		delete iskremSortiment[i];							//sletter pointers
	}
	iskremSortiment.clear();								//Tømmer lista
}

/**
 * @brief  Constructor som fyller inn smak og pris fra fil.
 * @param file
 */
Iskrem::Iskrem(ifstream& file) {
	file >> smak;
	file >> pris;
}

/**
 * @brief  Setter iskrem type enum fra fil.
 * @param file
 */
Sorbet::Sorbet(ifstream& file) : Iskrem(file) {
	string buffer;
	file >> buffer;
	if (buffer == "Granite") {
		type = Granite;
	}
	else if (buffer == "Sorbe") {
		type = Sorbe;
	}
	else if (buffer == "Slush") {
		type = Slush;
	}
}

/**
 * @brief Finner isbil på gitt sted. Returner pointer til denne, eller nullptr.
 * @param sted
 * @see Isbil::returnSted
 * @return pointer til isbil
 */
Isbil* finnIsbil(string sted) {
	for (int i = 0; i < gIsbiler.size(); i++) {
		if (gIsbiler[i]->returnSted() == sted) {
			return  gIsbiler[i];
		}
	}
	return nullptr;
}

/**
 * @brief Lagrer all data for isbil klassen til file stream.
 * @param file
 * @see Iskrem::lagreData
 */
void Isbil::lagreBil(ofstream& file) {
	file << sted << "\n";
	file << iskremSortiment.size() << "\n";

	for (int i = 0; i < iskremSortiment.size(); i++) {
		iskremSortiment[i]->lagreData(file);   //Kjører func for klasse i listen
	}
}

/**
 * @brief  Lagrer smak og pris til file stream.
 * @param file
 */
void Iskrem::lagreData(ofstream& file) {
	file << smak << "\n";
	file << pris << "\n";
}

/**
 * @brief  Legger på fil "tags" for Sorbet i file stream.
 * @param file
 * @see Iskrem::lagreData
 */
void Sorbet::lagreData(ofstream& file) {
	file << "SORBET\n";
	Iskrem::lagreData(file);
	switch (type) {
	case 0:
		file << "Sorbe"; break;
	case 1:
		file << "Granite"; break;
	case 2:
		file << "Slush"; break;
	}
	file << "\n";
}

/**
 * @brief  Setter på "tag" for fløteis i file stream og om den er vegan.
 * @param file
 * @see Iskrem::lagreData
 */
void Floteis::lagreData(ofstream& file) {
	file << "FLOTEIS\n";
	Iskrem::lagreData(file);
	file << vegan << "\n";
}

/**
 * @brief  Bruker UI for å legge til Sorbet eller Fløteis i isbil.
 * @see Sorbet::nyIskrem
 * @see Floteis::nyIskrem
 */
void Isbil::leggTilIskrem() {
	cout << "Velg type iskrem aa legge til\n"
		<< "\t (0) - Sorbet\n"
		<< "\t (1) - Floteis\n";
	switch (lesInt("Valg", 0, 1)) {
	case 0: {
		Sorbet* nySorbet = new Sorbet;
		nySorbet->nyIskrem();
		iskremSortiment.push_back(nySorbet);
		break;
	}
	case 1: {
		Floteis* nyFloteis = new Floteis;
		nyFloteis->nyIskrem();
		iskremSortiment.push_back(nyFloteis);
		break;
	}
	}
}

/**
 * @brief  Leser direkte fra fil, og legger til alle isbilene.
 */
void lesFraFil() {
	int counter;
	ifstream file(FILPLASS);		 //Lager input file stream for fillagring
	//file.seekg(3); //Fjernet BOM
	file >> counter;				 //henter ant biler fra toppen av filen
	for (int i = 0; i < counter; i++) {
		Isbil* nyIsbil = new Isbil(file);
		gIsbiler.push_back(nyIsbil);		//Lagrer isbil i den globale liseten
	}
	file.close(); 					//Lukker/frigjør filen
}

/**
 * @brief Bruker fyller ut smak og pris på ny iskrem.
 */
void Iskrem::nyIskrem() {
	cout << "sett pris paa iskrem \n";
	pris = lesInt("pris", 0, 999);

	cout << "Sett smak paa iskremen \nsmak: ";
	getline(cin, smak);
}

/**
 * @brief Fyller ut iskrem type enum fra bruker input.
 * @see Iskrem::nyIskrem
 */
void Sorbet::nyIskrem() {
	cout << "Velg sorbet type\n"
		<< "\t (0) Sorbe\n"
		<< "\t (1) Granite\n"
		<< "\t (2) Slush\n";
	switch (lesInt("Velg type", 0, 2)) {
	case 0:
		type = Sorbe; break;
	case 1:
		type = Granite; break;
	case 2:
		type = Slush; break;
	}
	Iskrem::nyIskrem();
}

/**
 * @brief Spør bruker om iskrem er vegant eller ikke.
 * @see Iskrem::nyIskrem()
 */
void Floteis::nyIskrem() {
	cout << "Er isen vegansk?\n"
		<< "\t (0) - Nei\n"
		<< "\t (1) - Ja\n";
	switch (lesInt("valg", 0, 1)) {
	case 0:
		vegan = false; break;
	case 1:
		vegan = true; break;
	}
	Iskrem::nyIskrem();
}

/**
 * @brief return av string sted for gitt isbil.
 * @return sted
 */
string Isbil::returnSted() {
	return sted;
}

/**
 * @brief  Skriver ut all hoveddata for alle isbiler.
 * @see void Isbil::skrivOppsummering
 */
void skrivAlleIsbiler() {
	if (gIsbiler.size() == 0) {
		cout << "Det er helt tomt for isbiler!\n";
	}
	for (int i = 0; i < gIsbiler.size(); i++) {
		cout << "---------- Isbil " << i << " ----------\n";
		gIsbiler[i]->skrivOppsummering();
	}
}

/**
 * @brief Viser alle biler, lar bruker søke etter sted, og evt legge til iskrem.
 * @param leggInn
 * @see skrivAlleIsbiler
 * @see Isbil::finnIsbil
 * @see Isbil::skrivDetaljertOppsummering
 * @see Isbil::leggTilIskrem
 */
void skrivBilOgEvtLeggInn(const bool leggInn) {
	string sted;
	skrivAlleIsbiler();
	if (gIsbiler.size() > 0) {
		cout << "Velg sted a soke etter\nSted: ";
		getline(cin, sted);

		if (!sted.empty()) {

			//finner pointer og skriver detaljert oppsummering
			Isbil* ptr = finnIsbil(sted);
			if (ptr != nullptr) {
				ptr->skrivDetaljertOppsummering();
			}
			else { cout << "stedet finnes ikke\n"; }

			if (leggInn && ptr != nullptr) {
				ptr->leggTilIskrem();
			}
		}
	}

}

/**
 * @brief Skriver ut smak og pris til skjerm.
 */
void Iskrem::skrivData() {
	cout << smak << " | " << pris << " |";
}

/**
 * @brief  Henter iskrem type enum og skriver til fil stream.
 * @see Iskrem::skrivData
 */
void Sorbet::skrivData() {
	string typeStr = "ukjent";			//Defaut verdi hvis noe feiler
	switch (type) {
	case 0:
		typeStr = "Sorbe"; break;
	case 1:
		typeStr = "Granite"; break;
	case 2:
		typeStr = "Slush"; break;
	}
	cout << "Sorbet (" << typeStr << ") | ";
	Iskrem::skrivData();
	cout << "\n";
}

/**
 * @brief Skriver it om iskrem er vegant eller ikke i tabell.
 * @see Iskrem::skrivData()
 */
void Floteis::skrivData() {
	string veganStr = "ukjent";			//Defaut verdi hvis noe går galt
	if (vegan) { veganStr = "Vegan"; }
	else { veganStr = "Ikke vegan"; }

	cout << "Floteis (" << veganStr << ") | ";
	Iskrem::skrivData();
	cout << "\n";
}

/**
 * @brief Skriver ut oppsummering av all data for en gitt isbil.
 * @see Iskrem::skrivData
 */
void Isbil::skrivDetaljertOppsummering() {
	cout << "Bilen kjorer i '" << sted << "' med "
		<< iskremSortiment.size() << " antall iskrem i lageret\n";

	cout << "Type | Smak | Pris |\n"
		<< "----------------------\n";

	for (int i = 0; i < iskremSortiment.size(); i++) {
		iskremSortiment[i]->skrivData();
	}

}

/**
 * @brief  Skriver ut menyen som kjøres i main.
 */
void skrivMeny() {
	cout << "Meny: \n"
		<< "\t A - Vis alle isbiler\n"
		<< "\t E - sok etter isbil\n"
		<< "\t L - sok etter bil, og legg til iskrem\n"
		<< "\t S - Lagre alt i fil\n"
		<< "\t Q - Lukk programm\n"; 
}

/**
 * @brief  Skriver ut sted og størrelse på iskrem sortiment.
 */
void Isbil::skrivOppsummering() {
	cout << "Bilen kjorer i '" << sted << "' med "
		<< iskremSortiment.size() << " antall iskrem i lageret\n";
}

/**
 * @brief  Lagrer isbiler og dems data i ISBIL.DTA.
 * @see Isbil::lagreBil
 */
void skrivTilFil() {
	ofstream file(FILPLASS);		 //lager output file stream for fillagring
	file << gIsbiler.size() << "\n"; //Legger på ant isbiler på toppen av filen
	for (int i = 0; i < gIsbiler.size(); i++) {
		file << "ISBIL\n";			 //legger på isbil tag
		gIsbiler[i]->lagreBil(file);
	}
	file.close();					 //lukker filen så andre programmer kan
	// bruke den igjen
}