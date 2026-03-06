
#include <iostream>
#include <vector>
#include <string>
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
		virtual void lesData() {

		}
		virtual void skrivData() {
			//skriver data til skjerm
			cout << smak << " | " << pris << " |";
			
		}
		virtual void fyllUtIskrem() {
			//fyller ut smak og pris
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




int main()
{
	char cmd;
	skrivMeny();
	cmd = lesChar("");
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
		<< "	L - sok etter bil, og legg til iskrem\n"
		<< "Ta ett valg";
}

/*
 – skriver ut alle hoveddataene om alle isbilene
	(ved å bruke funksjonen i 4d).
*/
void skrivAlleIsbiler() {
	for (int i = 0; i < gIsbiler.size(); i++) {
		cout << "---------- Isbil " << i << " ----------\n";
		gIsbiler[i]->skrivOppsummering(); 
	}
}



/*
 – Kaller først
funksjonen i pkt.7. Leser så et stedsnavn, inntil brukeren kun skriver ENTER (tom tekst) eller at
stedet blir funnet (vha. funksjonen i pkt.11). Om stedet/bilen blir funnet, så skrives alle dens data vha.
funksjonen i pkt.4e. Om i tillegg leggInn er true, så legges det inn en ny is i den aktuelle bilen.
For begge funksjonene i pkt.7 og 8 kommer det en egen melding om det er helt tomt for isbiler.

*/
void skrivBilOgEvtLeggInn(const bool leggInn) {
	string sted;
	skrivAlleIsbiler();

	getline(cin, sted); 
	if (sted != "") {

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
}
Isbil::~Isbil() {
	//sletter alle iskremene i bilens liste
}
Isbil::Isbil() {
	//leser isbilens innhold fra fil
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
