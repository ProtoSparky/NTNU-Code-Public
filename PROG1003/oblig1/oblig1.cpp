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
const int gMinutter[ANTSTOPP][ANTSTOPP] = ///< Min.mellom stoppesteder.
// const vector <vector <int> > gMinutter = // Alternativt (nå lært i vår).
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

void skrivRuter();/*Skriver ut alle data for alle rutene(med ‘-- > ’ 	mellom stoppestedene, unntatt etter den siste) ved bl.a.å bruke funksjonen 	**void ruteSkrivData(const Rute rute)**
Det skrives også ut rutenes indeks, fra 1 og oppover(i tillegg til deres reelle ruteNr).*/

void skrivNesteStoppesteder(const int stopp);/*Skriver alle aktuelle / lovlige stoppesteder etter / ut fra stoppested nr.stopp.*/

void nyRute();
bool ruteLesData(Rute & rute); 


void slettRute();
/*
Er det tomt for ruter, kommer en egen melding.I motsatt fall skrives alle rutene ut
	(inkludert deres indekser fra 1 og oppover).Brukeren spørres så om hvilke(n) som skal slettes.
	- 1 (minus 1) betyr alle, og da kalles void slett() som gjør dette.
	0 (null)betyr ingen, og det kommer en egen melding, før funksjonen avsluttes.
	1 og oppover betyr at den aktuelle ruten slettes.Til dette brukes funksjonen
	void slett(const int nr) som flytter den bakerste i gRuter til den
	slettedes plass(indeks).

*/



/**
 *
 *
 *
 * .
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
			cout << "bruker valgte N";
		}
		else if (input == 'S') {
			//Slett rute
			cout << "B - S";
		}
		else if (input == 'A') {
			//Skriv alle ruter
			cout << "B - A";
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
	for (int i = 0; i < ANTSTOPP; i++) {
		cout << setw(3)<<i + 1 << " | " << gBusstopp[i] << "\n"; 
	}
}


/*
Leser rutens reelle nummer(trenger ikke å sjekke at andre allerede har dette rutenummeret).
Alle mulige stoppesteder skrives ut på skjermen.Det første som leses blir da rutens startsted.
Leser så indeksen for neste lovlige stoppested(bruk tidligere nevnt funksjon), ut fra
nåværende stoppested, inntil brukeren velger ‘0’(null).Navnet på stoppestedene legges
kontinuerlig til bakerst i rutens stopp.Dens totMin oppdateres også hele tiden.Er det
mer enn ett stoppested på ruten, returneres true ellers false.Du trenger ikke å sjekke for
duplikate forekomster av stoppesteder.
*/
bool ruteLesData(Rute& rute) {

}


/* Oppretter en ny rute.Får alle dennes data lest inn vha.funksjonen nedenfor.Gikk innlesningen bra, så legges den inn bakerst i gRuter,
og dens indeks(husk vi nummerere fra 1) skrives ut sammen med alle dens data(jfr.ruteSkrivData(…)), ellers slettes ruten*/
void nyRute() {

}




int main()
{
	skrivMeny();
}



