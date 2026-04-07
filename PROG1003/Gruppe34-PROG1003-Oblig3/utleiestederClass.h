#ifndef _utleiestederClass_h
#define _utleiestederClass_h
#include <map>
#include <string>
#include "stedClass.h"
#include <fstream>

class UtleieSteder{
	private: 
		int sisteNr; //nummerering av siste gjenstand
		std::map <std::string, Sted*> stedMap;

	public:
		UtleieSteder();

		void nyttSted();
		void skrivAlleSted();
		void skrivSpesifikkSted();
		void skrivAllInntekt();
		void skrivAlleAktuellGjenstand();
		void velgUtleieSted(); 
		void oekSisteNr(); 
		int hentSisteNr(); 

		bool sokGjenstand(int id); 
		Sted* laanGjenstandHentSted();
		void flyttGjenstanderTilAnnetSted();
		void slettSted();
		void slettGjenstand(); 
		void skrivStederTilFil(std::ofstream& utleieData);
		void lesStederFraFil(std::ifstream& utleieData); 
};

#endif 