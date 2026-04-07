#ifndef kundeClass_h
#define kundeClass_h

#include <vector>
#include <string>
#include "gjenstandClass.h"
#include <fstream>


class Kunde{
	private:
		int kundeNr;
		int tlf; 
		std::string navn;
		std::vector<Gjenstand*> gjenstandVec;
	public:
		void nyKunde();
		void oppsummerKundeInfo(); 
		int returnKundeNr();
		void visGjenstander(); 
		void lagreGjenstander(std::vector <Gjenstand*>  gjenstand);
		std::vector <Gjenstand*> hentGjenstander();
		void fjernKundeGjenstander();
		std::string returnKundeNavn(); 
		void skrivKundeTilFil(std::ofstream & kunderData);
		void lesKundeFraFil(std::ifstream& kunderData);
  	bool sokGjenstand(int id);
};




#endif