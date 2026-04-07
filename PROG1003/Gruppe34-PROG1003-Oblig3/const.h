#ifndef _const_h
#define _const_h
#include <map>
/*
* ==============================================================================
Opprette gjenstander
* ==============================================================================
*/

//max antall gjenstander som kan opprettes på en gang
const int MAXOPPRETTBAREGJENSTANDER = 30;

/*
* ==============================================================================
Default verdier for gjenstander
* ==============================================================================
*/

// Default verdi om tralle har drasele eller ikke
const bool DEFAULTTRALLEDRASELE = false; 

//Default verdi om sykkel har tilhenger eller ikke
const bool DEFAULTSYKKELTILHENGER = false;

//Default elsparkesykkel effekt
const int DEFAULTELSPARKESYKKELEFFEKT = 100; // watt
const int MAXELSPARKESYKKELEFFEKT = 200; //watt


/*
* ==============================================================================
Priser
* ==============================================================================
*/

//priser for elsparkesykkel effekt
const std::map <int, int> ELSPARKESYKKELPRIS = {
	{
		DEFAULTELSPARKESYKKELEFFEKT, 
		250 //kr
	},
	{
		MAXELSPARKESYKKELEFFEKT, 
		500 //kr 
	}
}; 

//pris for tralle
const int TRALLEPRIS = 150; //kr 

//pris for sykkel
const int SYKKELPRIS = 300; //kr 

/**
* ==============================================================================
Datalagring
* ==============================================================================
*/

const std::string KUNDERDTA = "./kunder.dta";
const std::string STEDERDTA = "./steder.dta";

#endif
