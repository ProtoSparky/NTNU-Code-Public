#ifndef _kunderClass_h
#define _kunderClass_h

#include <list>
#include "kundeClass.h"
#include <fstream>

/**
 * Class alle kunder sitter i
 * 
 * sisteNr - Counter som bare teller oppåver av siste kunde nr
 * kundeList - Sortert liste med kunder
 */
class Kunder {
	private:
		int sisteNr; // counter om teller bare oppåver av siste brukte kude nr.
		std::list<Kunde*> kundeList;
	public:
		int returnAntKunder();
		void leggTilNyKunde(Kunde* kunde);
		void visAlleKunder();
		int hentKundeNr();
		void visKunde(int kundeNr);
    bool sokGjenstand(int id);
    void laanGjenstandHentKunde();
		Kunder(); 
		void leverGjenstander(int kundeNr);
		void slettKunde(int kundeNr); 
		void skrivKunderTilFil(std::ofstream & kunderData);
		void lesKunderFraFil(std::ifstream& kunderData); 
};

#endif 