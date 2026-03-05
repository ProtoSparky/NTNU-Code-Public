
#include <iostream>
#include <vector>
using namespace std; 

enum sorbetTyper {Sorbe, Granite, Slush};


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
		}
		virtual void fyllUtIskrem() {
			//fyller ut smak og pris
		}

};


class Sorbet : Iskrem {
	private: 
		sorbetTyper type; 
};

class Floteis : Iskrem {
	private:
		bool vegan; 

};


class Isbil {
	private:
		string sted;		
		vector <Iskrem*> iskremSortiment; //pekere til alle [Iskrem] den har
	public:
		Isbil() {
			//leser isbilens innhold fra fil
		}
		~Isbil() {
			//sletter alle iskremene i bilens liste
		}
		void leggTilIskrem() {
			//legger til ny iskrem i iskrem sortiment. Enten [Sorbet] eller [Floteis]
		}
		void skrivOppsummering() {
			//skriver ut [sted] og størrelse på [iskremSortiment]
		}
		void skrivDetaljertOppsummering() {
			//samme som skrivOppsummering
			// skriver også ut all info om alle iskrem i [iskremsortiment]
		}
		void lagreBil() {
			//lagrer all data som [Isbil] har
		}
		void skrivSted() {
			//skriver ut [sted]
		}
};

vector <Isbil*> gIsbiler; //liste med alle isbiler

void skrivMeny(); 
void skrivAlleIsbiler(); 
void skrivBilOgEvtLeggInn(const bool leggInn); 
void skrivTilFil(); 
void lesFraFil(); 




int main()
{
    
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
		<< "Ta ett valg:";
}

/*
 – skriver ut alle hoveddataene om alle isbilene
	(ved å bruke funksjonen i 4d).
*/
void skrivAlleIsbiler() {

}



/*
 – Kaller først
funksjonen i pkt.7. Leser så et stedsnavn, inntil brukeren kun skriver ENTER (tom tekst) eller at
stedet blir funnet (vha. funksjonen i pkt.11). Om stedet/bilen blir funnet, så skrives alle dens data vha.
funksjonen i pkt.4e. Om i tillegg leggInn er true, så legges det inn en ny is i den aktuelle bilen.
For begge funksjonene i pkt.7 og 8 kommer det en egen melding om det er helt tomt for isbiler.

*/
void skrivBilOgEvtLeggInn(const bool leggInn) {

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
