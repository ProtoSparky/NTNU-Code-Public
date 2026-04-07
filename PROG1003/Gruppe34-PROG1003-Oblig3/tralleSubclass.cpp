/*****************************************************************//**
 * @file   tralleSubclass.cpp
 * @brief  Funksjon definisjon for tralle subclassen
 *
 * @author Kristupas Kaupas, Rangvald Jansen
 * @date   2026-4-6
 *********************************************************************/
#include <iostream>

#include "stedClass.h"
#include "gjenstandClass.h"
#include "const.h";
#include"tralleSubclass.h"
using namespace std;

/**
 * @brief  skriver ut gjenstandens attributt.
 * @see Gjenstand::hentGjenstadNr()
 */
void Tralle::visGjenstand() {
	cout << hentGjenstadNr() << " | " << "tralle ";

	if (drasele) {
		cout << "med drasele\n";
	} else{
		cout << "uten drasele\n";
	}
}

/**
 * @brief  Setter drasele attributt.
 * @param data bool
 */
void Tralle::settBoolAttributt(bool data) {
	drasele = data; 
}

/**
 * @brief  Ikke brukt for tralle.
 * @param data
 */
void Tralle::settIntAttributt(int data) {

}

/**
 * @brief henter drasele attributt.
 * @return bool drasele
 */
bool Tralle::hentBoolAtributt(){
	return drasele;
}

/**
 * @brief  Ikke brukt for tralle.
 * @return 0, ikke brukt
 */
int Tralle::hentIntAtrubutt() {
	return 0;
}

/**
 * @brief  gir pris for tralle.
 * @return int, pris
 */
int Tralle::beregnPris(){
	return TRALLEPRIS; 
}
