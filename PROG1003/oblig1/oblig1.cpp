#include <iostream>
#include <LESDATA2>
void skrivMeny();
/*
Lovlige kommandoer er(i tillegg til Quit / avslutt) :
	N - Ny rute, S - Slett rute, A - skriv Alle ruter og B - skriv alle Busstopp
*/


void skrivStopp();
/*
Skriver navnet på alle stoppestedene(som er i gBusstopp),
	nummerert fra 1 og oppover.
*/


void skrivRuter();
/*Skriver ut alle data for alle rutene(med ‘-- > ’ 
	mellom stoppestedene, unntatt etter den siste) ved bl.a.å bruke funksjonen 
	**void ruteSkrivData(const Rute rute)**
Det skrives også ut rutenes indeks, 
fra 1 og oppover(i tillegg til deres reelle ruteNr).
*/


void skrivNesteStoppesteder(const int stopp);
/*Skriver alle aktuelle / lovlige stoppesteder etter / 
	ut fra stoppested nr.stopp.*/

void nyRute();
/*
Oppretter en ny rute.Får alle dennes data lest inn vha.funksjonen nedenfor.Gikk
innlesningen bra, så legges den inn bakerst i gRuter,
og dens indeks(husk vi nummerere fra 1) skrives ut sammen med alle dens 
data(jfr.ruteSkrivData(…)), ellers slettes ruten
*/


bool ruteLesData(Rute & rute); 
/*
Leser rutens reelle nummer(trenger ikke å sjekke at andre allerede har dette rutenummeret).
Alle mulige stoppesteder skrives ut på skjermen.Det første som leses blir da rutens startsted.
Leser så indeksen for neste lovlige stoppested(bruk tidligere nevnt funksjon), ut fra
nåværende stoppested, inntil brukeren velger ‘0’(null).Navnet på stoppestedene legges
kontinuerlig til bakerst i rutens stopp.Dens totMin oppdateres også hele tiden.Er det
mer enn ett stoppested på ruten, returneres true ellers false.Du trenger ikke å sjekke for
duplikate forekomster av stoppesteder.
*/

void slettRute()
/*
Er det tomt for ruter, kommer en egen melding.I motsatt fall skrives alle rutene ut(inkludert
	deres indekser fra 1 og oppover).Brukeren spørres så om hvilke(n) som skal slettes.
	- 1 (minus 1) betyr alle, og da kalles void slett() som gjør dette.
	0 (null)betyr ingen, og det kommer en egen melding, før funksjonen avsluttes.
	1 og oppover betyr at den aktuelle ruten slettes.Til dette brukes funksjonen
	void slett(const int nr) som flytter den bakerste i gRuter til den
	slettedes plass(indeks).

*/



int main()
{

}



