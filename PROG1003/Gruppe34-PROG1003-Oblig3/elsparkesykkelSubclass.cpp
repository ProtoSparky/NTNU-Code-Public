/*****************************************************************//**
 * @file   elsparkesykkelSubclass.cpp
 * @brief  Funksjon definisjon for elsparkesykkel subclass
 * 
 * @author Kristupas Kaupas, Rangvald Jansen
 * @date   2026-4-6
 *********************************************************************/
#include <iostream>

#include"elsparkesykkelSubclass.h"
#include "stedClass.h"
#include "gjenstandClass.h"
#include "const.h"
using namespace std;

/**
 * @brief gir pris for elsparkesykkel.
 * @return int pris
 */
int Elsparkesykkel::beregnPris() {
	return ELSPARKESYKKELPRIS.at(watt);
}

/**
 * @brief ubrukt variabel.
 * @return ingenting
 */
bool Elsparkesykkel::hentBoolAtributt() {
	return false;
}

/**
 * @brief returner effekten på elsparkesykkel.
 * @return watt, int
 */
int Elsparkesykkel::hentIntAtrubutt() {
	return watt;
}

/**
 * @brief  Tom func for at ting skal kompilere.
 * @param data
 */
void Elsparkesykkel::settBoolAttributt(bool data) {
	//ingenting skjer her
}

/**
 * @brief  Setter effekt på elsparkesykkel.
 * @param data - watt
 */
void Elsparkesykkel::settIntAttributt(int data) {
	watt = data;
}

/**
 * @brief Skriver ut all data om en spesifikk gjenstand.
 * @see Gjenstand::hentGjenstadNr()
 */
void Elsparkesykkel::visGjenstand() {
	cout << hentGjenstadNr() << " | " << "elsparkesykkel med " 
		 << watt << "w motor\n";
}
