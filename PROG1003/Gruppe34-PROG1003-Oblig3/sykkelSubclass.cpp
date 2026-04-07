/*****************************************************************//**
 * @file   sykkelSubclass.cpp
 * @brief  Funksjon definisjon for sykkel subclass
 *
 * @author Kristupas Kaupas, Rangvald Jansen
 * @date   2026-4-6
 *********************************************************************/
#include <iostream>

#include "stedClass.h"
#include "gjenstandClass.h"
#include "const.h"
#include "sykkelSubclass.h"
using namespace std;

/**
 * @brief  Viseer en gjenstands attributter. 
 * @see Gjenstand::hentGjenstadNr()
 */
void Sykkel::visGjenstand() {
	cout << hentGjenstadNr() << " | " << "sykkel ";

	if (harTilhenger) {
		cout << "med tilhenger\n";
	}
	else {
		cout << "uten tilhenger\n";
	}
}

/**
 * @brief  Setter tilhenger data.
 * @param data
 */
void Sykkel::settBoolAttributt(bool data){
	harTilhenger = data; 
}

/**
 * @brief  Ikke brukt for sykkel.
 * @param data
 */
void Sykkel::settIntAttributt(int data){

}

/**
 * @brief  returner tilhenger attributt.
 * @return harTilhenger
 */
bool Sykkel::hentBoolAtributt(){
	return harTilhenger;
}

/**
 * @brief  ikke brukt for sykkel.
 * @return 0, ikke brukt
 */
int Sykkel::hentIntAtrubutt(){
	return 0;
}

/**
 * @brief Gir pris for sykkel.
 * @return sykkel pris; 
 */
int Sykkel::beregnPris() {
	return SYKKELPRIS;
}
