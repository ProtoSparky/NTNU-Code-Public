/*****************************************************************//**
 * @file   gjenstandClass.cpp
 * @brief  Funksjon definisjon for gjenstand class
 *
 * @author Kristupas Kaupas, Rangvald Jansen
 * @date   2026-4-6
 *********************************************************************/
#include <iostream>;
#include <vector>

#include "gjenstandClass.h";
#include "LesData3.h"
#include "const.h"
using namespace std; 

/**
 * @brief  ikke brukt på gjenstand.
 * @return 0, ikke brukt
 */
int Gjenstand::beregnPris() {
	return 0;
}


/**
 * @brief spør bruker om å de ønsker å endre attributt på en gitt gjenstand.
 * 
 * @see Gjenstand::hentGjenstandEnum()
 * @see Sykkel::settBoolAttributt(...)
 * @see Tralle::settBoolAttributt(...)
 * @see Elsparkesykkel::settIntAttributt(...)
 */
void  Gjenstand::endreAttrubutt() {
	int valg;
	switch (hentGjenstandEnum()) {
	case 0: {
		//sykkel
		cout << "0 for aa fjerne paa tilhenger,"
			<< "1 for aa sette paa tilhenger\n";

		valg = lesInt("valg", 0, 1);
		settBoolAttributt(valg);
		break;
	}
	case 1: {
		//tralle
		cout << "0 for aa fjerne drasele, 1 for aa sette paa drasele\n";
		valg = lesInt("valg", 0, 1);
		settBoolAttributt(valg);
		break;
	}
	case 2: {
		//elsparkesykkel
		cout << "0 for " << DEFAULTELSPARKESYKKELEFFEKT << "w, "
			<< "1 for " << MAXELSPARKESYKKELEFFEKT << "w motor\n";

		valg = lesInt("valg", 0, 1);
		if (valg == 0) {
			settIntAttributt(DEFAULTELSPARKESYKKELEFFEKT);
		}
		else {
			settIntAttributt(MAXELSPARKESYKKELEFFEKT);
		}
		break;
	}
	}
}

/**
 * @brief  Ikek brukt for gjenstand.
 * @return false, ingenting
 */
bool Gjenstand::hentBoolAtributt() {
	return false;
}

/**
 * @brief  Henter gjenstand nummer.
 * @return int
 */
int Gjenstand::hentGjenstadNr() {
	return gjenstandNr;
}

/**
 * @brief  returner enum fra en gjenstand.
 * @return int
 */
int Gjenstand::hentGjenstandEnum() {
	switch (gjenstandEnum) {
		case sykkel: {
			return 0;
			break;
		}
		case tralle: {
			return 1;
			break;
		}
		case elsparkesykkel: {
			return 2;
			break;
		}
	}
}

/**
 * @brief  Ikke brukt for gjenstand.
 * @return 0, ingenting
 */
int Gjenstand::hentIntAtrubutt() {
	return 0;
}

/**
 * @brief Ikke brukt for gjenstand.
 * @param data
 */
void Gjenstand::settBoolAttributt(bool data) {}

/**
 * @brief får tall og setter enum utifra den.
 * @param enumTall int - Styrer type gjenstand
 */
void Gjenstand::settEnum(int enumTall) {
	switch (enumTall) {
	case 0: { gjenstandEnum = sykkel; break; }
	case 1: { gjenstandEnum = tralle; break; }
	case 2: { gjenstandEnum = elsparkesykkel; break; }

	}
}

/**
 * @brief setter gjenstandNr.
 * @param nr int
 */
void Gjenstand::settGjenstandNr(int nr) {
	gjenstandNr = nr;
}

/**
 * @brief Ikke brukt for gjenstand.
 * @param data
 */
void Gjenstand::settIntAttributt(int data) {}

/**
 * @brief  Ikke brukt på gjenstand. Bare hos virtuals for gjenstandene
 */
void Gjenstand::visGjenstand() {}

/**
 * @brief  Skriver ut all data for en gitt gjenstand.
 * @param gjenstand
 * @see Gjenstand::hentGjenstadNr()
 * @see Gjenstand::hentGjenstandEnum()
 * @see Sykkel::hentBoolAtributt()
 * @see Tralle::hentBoolAtributt()
 * @see Elsparkesykkel::hentIntAtrubutt()
 * @see Sykkel::beregnPris()
 * @see Tralle::beregnPris()
 * @see Elsparkesykkel::beregnPris()
 */
void Gjenstand::visGjenstandTabell(Gjenstand* gjenstand) {
	//| ID | Type | Attributt | Pris

	cout << gjenstand->hentGjenstadNr() << " | ";

	//printer ut attributtene
	switch (gjenstand->hentGjenstandEnum()) {
	case 0: {
		cout << "sykkel\t\t | Tilhenger J/N (";
		if (gjenstand->hentBoolAtributt()) { cout << "J"; }
		else { cout << "N"; }
		break;
	}
	case 1: {
		cout << "tralle\t\t | Drasele J/N (";
		if (gjenstand->hentBoolAtributt()) { cout << "J"; }
		else { cout << "N"; }
		break;
	}
	case 2: {
		cout << "elsparkesykkel | Effekt ("
			<< gjenstand->hentIntAtrubutt() << "w";
		break;
	}
	}
	cout << ")   | " << gjenstand->beregnPris() << "kr";

}