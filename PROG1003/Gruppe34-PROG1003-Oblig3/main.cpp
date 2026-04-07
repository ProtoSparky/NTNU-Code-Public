/*****************************************************************//**
 * @file   main.cpp
 * @brief  Et proram som holder på utleie av ulike gjenstander
 * 
 * @author Kristupas Kaupas, Rangvald Jansen
 * @date   2026-4-6
 *********************************************************************/
#include <iostream>
#include <string>
#include <list>
#include <vector> 

#include "LesData3.h"
#include "const.h"
#include "enum.h"
#include "globaleFunksjoner.h"
#include "kunderClass.h"
#include "kundeClass.h"
#include "utleiestederClass.h"
#include "stedClass.h"
#include "gjenstandClass.h"
#include "tralleSubclass.h"
#include "sykkelSubclass.h"
#include "elsparkesykkelSubclass.h"
Kunder* gKunder = new Kunder;
UtleieSteder* gUtleiesteder = new UtleieSteder();
using namespace std; 

/**
Starten av programmet
*/
int main()
{
	lsFraFil(); //henter lagret data
	char valg;
	skrivHovedmeny();
	valg = lesChar("Kommando");
	while (valg != 'Q') {
		switch (valg) {
			case'K':{
				kMeny();
					break;
			}
			case 'S': {
				stedMeny();
				break;
			}
			case 'G': {
				gMeny();
				break; 
			}
			default: {
				skrivHovedmeny();
			}

		}
		cout << "\n"; 
		valg = lesChar("Kommando");
	}
	skrivTilFil(); //lagrer all data til filer

	return 0;
}


