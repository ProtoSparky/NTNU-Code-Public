#include <stdio.h>
#include "LesData.h"

#define ANTHULL 18 ///< Antall hull på golfbanen.
#define ANTUTTRYKK 9 ///< Antall ulike uttrykk for slagprestasjoner.
#define STRLEN 15 ///< Maks tekstlengde.

const int MAXSLAG = 5; ///< Maks antall par-slag på hvert hull.
const char uttrykk[ANTUTTRYKK][STRLEN] = { "Triple Bogey", "Double Bogey", "Bogey", "Par",
"Birdie", "Eagle", "Albatross", "Kondor", "Hole-in-one" };

int finnUttrykk(const int slag, const int par);
void lesPar();
void lesSlag();
int lesTall(const int min, const int max);
void skrivPrestasjon();
void skrivSlag();
int summer(const int arr[], const int n);
int gPar[ANTHULL]; ///< Par-slagene for hvert hull.
int gSlag[ANTHULL]; ///< Reelt/aktuelt antall slag for hvert hull.

/**
* Hovedprogram.
*/
int main(){
    lesPar();/*
    lesSlag();
    skrivSlag();
    skrivPrestasjon();
    printf("Banens par: %i\n", summer(gPar, ANTHULL));
    printf("Spillerens total: %i\n", summer(gSlag, ANTHULL));*/

    return 0;
}

/**
 * @brief leser inn KUN tall mellom min og max 
 * 
 * @param min 
 * @param max 
 * @return int 
 */
int lesTall(const int min, const int max){
    int tall = -1;

    do{
        printf("Skriv inn tall. Tillate tall er %d til %d\n", min, max); 
        scanf("%d", &tall);
    }
    while(!
        (
            tall >= min && 
            tall <= max
        )        
    ); 
    return tall;    
}

/**
 * @brief Leser inn antall mulige slag for alle hullene i banen
 * 
 */
void lesPar(){
    printf("Fyll ut antall par for alle %d hull\n", ANTHULL);
    for(int valgtPar = 0; valgtPar < ANTHULL; valgtPar ++){
        printf("Par %d/%d\n", valgtPar, ANTHULL);
        gPar[valgtPar] = lesTall(2,MAXSLAG);
    }
}