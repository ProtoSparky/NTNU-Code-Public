#ifndef _stedClass_h
#define _stedClass_h
#include <vector>
#include <string>
#include "tralleSubclass.h"
#include "sykkelSubclass.h"
#include "elsparkesykkelSubclass.h"
#include "gjenstandClass.h"
#include <fstream>

class Sted{
	private:
		std::string stedNavn; 
		std::string beskrivelse; //kort forklaring av stedet

		int tlf, inntjenteKr;
		std::vector <Tralle*> tralleVec;
		std::vector <Sykkel*> sykkelVec;
		std::vector <Elsparkesykkel*> elsparkesykkelVec;

	public:

		void nyttSted(std::string navn); 
		void skrivInfo();
		void skrivAllInfo();
		void skrivInntekt();
		std::string skrivAktuellGjenstand(int choice);

		void opprettGjenstander(); 
		bool sokGjenstand(int id);
		std::vector <Gjenstand*> laanGjenstandVelgGjenstand();
		void oekInntekt(int inntekt);
		void mottaKundeGjenstander(std::vector <Gjenstand*> gjenstander); 
		
		std::vector <Tralle*> hentTrallerForFlytting(bool slettAlle);
		std:: vector <Sykkel*> hentSyklerForFlytting(bool slettAlle);
		std::vector <Elsparkesykkel*> hentElsparkesykklerForFlytting(bool slettAlle);
		void leggTilTraller(std::vector <Tralle*> traller);
		void leggTilSykler(std::vector <Sykkel*> sykler);
		void leggTilElsparkesykler(std::vector <Elsparkesykkel*> elsparkesykkler);

		void skrivSlettGjenstandAdvarsel(std::string type, int gjenstandNr); 
		bool slettGjenstand(int gjenstandNr);
		void skrivStedTilFil(std::ofstream& utleieData); 
		void lesStedFraFil(std::ifstream& utleieData, std::string navn);
};

#endif