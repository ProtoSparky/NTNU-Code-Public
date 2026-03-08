
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "lesdata2.h";

using namespace std; 

enum sorbetTyper {Sorbe, Granite, Slush};
const string FILPLASS = "./ISBIL.DTA"; 

class Iskrem {
	private:
		string smak;
		int pris; 

	public:
		Iskrem() {
			//leser iskrem innhold fra fil
		}
		virtual void hentData() {

		}
		virtual void skrivData() {
			//skriver data til skjerm
			cout << smak << " | " << pris << " |";
			
		}
		virtual void nyIskrem() {				
			cout << "sett pris paa iskrem \n"; 
			pris = lesInt("pris", 0, 999);

			cout << "Sett smak paa iskremen \n\tsmak: ";
			getline(cin, smak); 

		}

};


class Sorbet : public Iskrem {
	private: 
		sorbetTyper type; 
	public:
		void skrivData() override {
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
		void nyIskrem() override {
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
			Iskrem:nyIskrem(); 
		}
};

class Floteis : public Iskrem {
	private:
		bool vegan; 
	public:
		void skrivData() override {
			string veganStr = "ukjent";			//Defaut verdi hvis noe feiler
			if (vegan) { veganStr = "Vegan";}else { veganStr = "Ikke vegan";}
			cout << "Floteis (" << veganStr << ") | ";
			Iskrem::skrivData();
			cout << "\n"; 
		}

		void nyIskrem() override {
			cout << "Er isen vegansk?"
				<< "\t (0) - Nei\n"
				<< "\t (1) - Ja\n";
			switch (lesInt("valg", 0, 1)) {
				case 0:
					vegan = false; break;
				case 1:
					vegan = true; break; 
			}
			Iskrem:skrivData();
		}
};


class Isbil {
	private:
		string sted;		
		vector <Iskrem*> iskremSortiment; //pekere til alle [Iskrem] den har
	public:
		Isbil();
		~Isbil();
		void leggTilIskrem();
		void skrivOppsummering();
		void skrivDetaljertOppsummering();
		void lagreBil();
		string returnSted();
};

vector <Isbil*> gIsbiler; //liste med alle isbiler

void skrivMeny(); 
void skrivAlleIsbiler(); 
void skrivBilOgEvtLeggInn(const bool leggInn); 
void skrivTilFil(); 
void lesFraFil(); 




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
		}
		skrivMeny();
		cmd = lesChar("valg");
	}
	return 0;


}



/*
 – skriver meny for valgene:
 * A - tilkaller funksjonen i pkt.7
 * E - tilkaller funksjonen i pkt.8 med parameteren lik false
 * L - tilkaller funksjonen i pkt.8 med parameteren lik true

*/
void skrivMeny() {
	cout << "Meny: \n"
		<< "	A - Vis alle isbiler\n"
		<< "	E - sok etter isbil\n"
		<< "	L - sok etter bil, og legg til iskrem\n";
}

/*
 – skriver ut alle hoveddataene om alle isbilene
	(ved å bruke funksjonen i 4d).
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
 * @brief Finner isbil på gitt sted. Returner pointer til denne, eller nullptr.
 * @param sted
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
 * @brief Viser alle biler, lar bruker søke etter sted, og evt legge til iskrem.
 * @param leggInn
 */

void skrivBilOgEvtLeggInn(const bool leggInn) {
	string sted;
	skrivAlleIsbiler();
	if (gIsbiler.size() > 0) {
		cout << "Velg sted a soke etter\nSted: "; 
		getline(cin, sted);

		if (sted != "") {
			
			Isbil* ptr = finnIsbil(sted);
			ptr->skrivDetaljertOppsummering();


			if (leggInn && ptr != nullptr) {
				ptr->leggTilIskrem();
			}
		}
	}

}

/*
 – skriver alle bilene og alle deres data til filen ‘ISBIL.DTA’.
	Formatet velger du selv, men aller først på filen skal antall biler ligge.
*/
void skrivTilFil() {

}

/*
Leser inn hele datastrukturen (bilene og deres iskremmer) fra samme
filen som i forrige punkt, og etter det selvvalgte formatet.
*/
void lesFraFil(){
	int counter;
	ifstream File (FILPLASS);
	File.seekg(3); //Fjernet BOM

	File >> counter; 
	for (int i = 0; i < counter; i++) {

	}


	File.close(); 
	
}


/**
 * @brief  Skriver ut sted og størrelse på iskrem sortiment.
 */
void Isbil::skrivOppsummering(){
	//skriver ut [sted] og størrelse på [iskremSortiment]
	cout << "Bilen kjorer i '" << sted << "' med "
		 << iskremSortiment.size() << " antall iskrem i lageret\n";
}

/**
 * @brief Skriver ut oppsummering av all data for en gitt isbil.
 */
void Isbil::skrivDetaljertOppsummering() {
	// skriver også ut all info om alle iskrem i [iskremsortiment]

	cout << "Bilen kjorer i '" << sted << "' med "
		<< iskremSortiment.size() << " antall iskrem i lageret\n";

	cout << "Type | Smak | Pris |\n"
		<< "----------------------\n";
	
	for (int i = 0; i < iskremSortiment.size(); i++) {
		iskremSortiment[i]->skrivData();
	}

}

/**
 * @brief return av string sted for gitt isbil.
 * @return sted
 */
string Isbil::returnSted() {
	return sted; 
}

void Isbil::lagreBil() {
	//lagrer all data som [Isbil] har


}

void Isbil::leggTilIskrem() {
	//legger til ny iskrem i iskrem sortiment. Enten [Sorbet] eller [Floteis]
	cout << "Velg type iskrem å legge til\n"
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
Isbil::~Isbil() {
	//sletter alle iskremene i bilens liste
}
Isbil::Isbil() {
	//leser isbilens innhold fra fil
}

