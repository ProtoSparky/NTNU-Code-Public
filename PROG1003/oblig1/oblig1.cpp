#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "lesdata2.h"
using namespace std; 
const int ANTSTOPP = 11;					///< Totalt antall ulike busstopp.
struct Rute {
	vector <string> stopp;					// Rutens ulike stoppesteder.
	int ruteNr,								// Reelt rutenr, f.eks. 42, 165, 718
		totMin;								// Totalt antall minutter å kjøre på ruten
};											// (fra første til siste stoppested).
vector <Rute*> gRuter;						///< Pekere til rutene.
const vector <string> gBusstopp =			///< Navn på alle busstopp.
{ "Skysstasjonen", "Fahlstroms plass", "Sykehuset",
"Gjovik stadion", "Bergslia", "Overby", "Nybrua",
"NTNU", "Kallerud", "Hunndalen", "Mustad fabrikker" };
//const int gMinutter[ANTSTOPP][ANTSTOPP] = ///< Min.mellom stoppesteder.
const vector <vector <int> > gMinutter = // Alternativt (nå lært i vår).
{ { 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Skysstasjonen = 0
{ 3, 0, 3, 0, 0, 0, 3, 0, 0, 0, 4}, // Fahlstrøms plass = 1
{ 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // Sykehuset = 2
{ 0, 0, 1, 0, 3, 0, 0, 0, 0, 0, 0}, // Gjøvik stadion = 3
{ 0, 0, 0, 3, 0, 2, 0, 0, 0, 0, 0}, // Bergslia = 4
{ 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0}, // Øverby = 5
{ 0, 3, 0, 0, 0, 0, 0, 2, 0, 0, 2}, // Nybrua = 6
{ 0, 0, 0, 0, 0, 0, 2, 0, 0, 4, 0}, // NTNU = 7
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Kallerud = 8
{ 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 2}, // Hunndalen = 9
{ 0, 4, 0, 0, 0, 0, 2, 0, 0, 2, 0} }; // Mustad fabrikker = 10

void skrivMeny();
void skrivStopp();
void ruteSkrivData(const Rute rute);
void skrivRuter();
void skrivNesteStoppesteder(const int stopp);
void nyRute();
bool ruteLesData(Rute & rute);
void slettRute();
void slett(const int nr);
void slett();
/*
Er det tomt for ruter, kommer en egen melding.I motsatt fall skrives alle rutene ut
	(inkludert deres indekser fra 1 og oppover).Brukeren spørres så om hvilke(n) som skal slettes.
	- 1 (minus 1) betyr alle, og da kalles void slett() som gjør dette.
	0 (null)betyr ingen, og det kommer en egen melding, før funksjonen avsluttes.
	1 og oppover betyr at den aktuelle ruten slettes.Til dette brukes funksjonen
	void slett(const int nr) som flytter den bakerste i gRuter til den
	slettedes plass(indeks).

*/



void skrivMeny() {
	char input = '\0';
	string ledetekst =
		"Velg et valg\n"
		"    N = Sett rute \n"
		"    S = Slett rute\n"
		"    A = Skriv ut alle ruter \n"
		"    B = Skriv ut alle busstopp\n"
		"Input"; 

	while (input != 'Q') {
		input = lesChar("test");
		if (input == 'N') {
			//Ny rute
			nyRute(); 
		}
		else if (input == 'S') {
			//Slett rute
			slettRute(); 
		}
		else if (input == 'A') {
			//Skriv alle ruter
			skrivRuter();
		}
		else if (input == 'B') {
			//skriv alle busstopp
			skrivStopp(); 
		}
	}
	cout << "Program stoppes!!";

};


/**
 * @brief  Skriver navnent på alle lagrede stoppesteder fra 1 og oppover.
 */
void skrivStopp() {
	cout << "Nr: | Stoppnavn \n";
	cout << "----------------\n";
	for (int i = 0; i < ANTSTOPP; i++) {
		cout << setw(3)<<i + 1 << " | " << gBusstopp[i] << "\n"; 
	}
}


/*
Leser rutens reelle nummer(trenger ikke å sjekke at andre allerede har dette rutenummeret).		X
Alle mulige stoppesteder skrives ut på skjermen.	X
Det første som leses blir da rutens startsted.		X
Leser så indeksen for neste lovlige stoppested(bruk tidligere nevnt funksjon), ut fra
nåværende stoppested, inntil brukeren velger ‘0’(null).		X

Navnet på stoppestedene legges kontinuerlig til bakerst i rutens stopp.		X
Dens totMin oppdateres også hele tiden.Er det
mer enn ett stoppested på ruten, returneres true ellers false.Du trenger ikke å sjekke for
duplikate forekomster av stoppesteder.
*/


/**
 * @brief Lar bruker sette sammen ruter.
 * @param rute
 * @return true/false basert på om det er mer enn 1 stopp som lagres
 */
bool ruteLesData(Rute& rute) {
	int ruteNr = lesInt("Skriv inn rute nummer ", 0, 1000);
	int startStedNr, stedNr;
	bool avslutt = false; 
	rute.ruteNr = ruteNr;
	rute.totMin = 0; 

	cout << "Velg nr for startssted\n";
	skrivStopp();
	startStedNr = lesInt("Start sted" , 1, ANTSTOPP);

	rute.stopp.push_back(gBusstopp[startStedNr - 1]);

	do {
		skrivNesteStoppesteder(startStedNr - 1);
		stedNr = lesInt("Velg neste stoppested. '0' for avslutt. ", 0, ANTSTOPP);
		if (stedNr == 0) {
			avslutt = true; 
		}
		else {
			if (gMinutter[startStedNr - 1][stedNr - 1] != 0) {
				rute.stopp.push_back(gBusstopp[stedNr - 1]);
				rute.totMin += gMinutter[startStedNr - 1][stedNr - 1];
			}
			else {
				cout << "\nStoppet du valgte kan ikke naas fra startstoppet ditt\n";
			}
		}
	} while (!avslutt);
	
	if (rute.stopp.size() > 1) {
		return true;
	}
	return false; // return false hvis stoppesteder mindre enn 2




	/*
	do {
		minutter = 0;

		do {
			skrivNesteStoppesteder(startStedNr - 1);
			stedNr = lesInt("Velg neste stoppested. '0' for avslutt. ", 0, ANTSTOPP);
			if (stedNr == 0) { avslutt = true; }

			minutter = gMinutter[startStedNr][stedNr - 1];
			if (minutter == 0 && !avslutt)
			{
				cout << "Stoppet du valgte kan ikke nås fra startstoppet ditt\n";
			}
		} while (minutter == 0 && !avslutt);

		//lagre data
		rute.stopp.push_back(gBusstopp[stedNr -1]);
		rute.totMin += gMinutter[startStedNr-1][stedNr -1];

	} while (stedNr != 0);
	rute.ruteNr = ruteNr;

	*/
}


/**
 * @brief Skriver lovlige stoppeseder ut fra stopp nr .
 * @param stopp
 */
void skrivNesteStoppesteder(const int stopp) {
	const vector valgtLinje = gMinutter[stopp]; 
	cout << "Mulige stoppesteder er: \n"; 
	cout << "------------------------\n";
	for (int i = 0; i < valgtLinje.size(); i++) {
		if (valgtLinje[i] != 0) {
			cout << setw(3) << i + 1 << " | " << gBusstopp[i] << "\n";
		}
	}
	cout << "\n------------------------\n";
}

/* Oppretter en ny rute.Får alle dennes data lest inn vha.funksjonen nedenfor.	X
Gikk innlesningen bra, så legges den inn bakerst i gRuter,	X

og dens indeks(husk vi nummerere fra 1) skrives ut sammen med alle dens data(jfr.ruteSkrivData(…)), ellers slettes ruten*/
void nyRute() {
	Rute* nyRute = new Rute;
	if (ruteLesData(*nyRute)) {
		gRuter.push_back(nyRute);
		cout << "Indeks | Rute Nummer | Total reisetid(min) | Alle busstopp \n";
		cout << setw(6) << gRuter.capacity() << " | "; 
		ruteSkrivData(*nyRute); 
	}

}


void ruteSkrivData(const Rute rute) {
	cout << setw(11) << rute.ruteNr << " | " << setw(19) << rute.totMin << " | ";
	for (int i = 0; i < rute.stopp.capacity(); i++) {
		cout << rute.stopp[i];
		if (i < rute.stopp.capacity()-1) {
			cout << "-- > "; 
		}
	}
	cout << "\n"; 
	
}

void skrivRuter() {
	//skriver alle ruter
	cout << "Indeks | Rute Nummer | Total reisetid(min) | Alle busstopp \n";
	for (int i = 0; i < gRuter.capacity(); i++) {
		cout << setw(6) << i + 1 << " | ";
		ruteSkrivData(*gRuter[i]);
	}

}



void slettRute() {
	if (gRuter.empty()) {
		cout << "Ingen ruter lagret\n";
	}
	skrivRuter();
	cout << "\n";
	int brukerValg = lesInt("Skriv inn rute index, 0 for ingen, -1 for alle", -1, gRuter.capacity());
	if (brukerValg == -1) {
		//slett alle
	}
	else if (brukerValg == 0) {
		cout << "Ingenting slettet. Går tilbake til hovedmeny \n"; 
	}
	else {
		//slett spesifikk 
	}



}
/*
Er det tomt for ruter, kommer en egen melding.
I motsatt fall skrives alle rutene ut	(inkludert deres indekser fra 1 og oppover).
brukeren spørres så om hvilke(n) som skal slettes.	- 1 (minus 1) betyr alle, og da kalles void slett() som gjør dette.
	0 (null)betyr ingen, og det kommer en egen melding, før funksjonen avsluttes.
	1 og oppover betyr at den aktuelle ruten slettes.Til dette brukes funksjonen
	void slett(const int nr) som flytter den bakerste i gRuter til den
	slettedes plass(indeks).

*/


int main()
{
	skrivMeny();
}



