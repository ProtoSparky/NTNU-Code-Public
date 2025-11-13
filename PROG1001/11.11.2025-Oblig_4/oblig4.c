/**
 *  grunnlag for oblig nr 4 i GrProg, høsten 2025.
 *
 *  Det er mulig å:
 *     - legge inn nye produsenter
 *     - legge inn nytt produkt hos en produsent
 *     - skrive ALLE produsenter
 *     - skrive ALLE produkter hos/for EN produsent
 *     - skrive ALLE produkter
 *     - slette ALLE produsenter og deres produkter
 *
 *  @file    oblig4.c
 *  @author  Kristupas Kaupas
 */


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LesData.h"     //   Ligger på emnets EKSEMPLER-katalog.


#define MAXPRODUSENTER  50      ///< Max antall produsenter
#define MAXPRODUKTER    20      ///< Max antall produkter hos hver produsent
const int STRLEN  =    100;     ///< Max tekstlengde
const int MAXPRIS = 100000;     ///< Max pris


/**
 *  Produkt (med navn, beskrivelse, pris).
 */
struct Produkt {
    char  *navn, *beskrivelse;
    int   pris;
};


/**
 *  Produsent (med navn, by, antallprodukter, og array med produktene).
 */
struct Produsent {
    char   *navn, *by;
    int    antallProdukter;
    struct Produkt* produktene[MAXPRODUKTER];
};


struct Produkt* finnProdukt(const struct Produsent* produsent, const char* navn);
struct Produsent* finnProdusent(const char* navn);
void   fjernAllkokerteData();
void   leggTilEttProdukt();
void   nyProdusent();
void   produktLesData(struct Produkt* produkt, const char* navn);
void   produktSkrivData(const struct Produkt* produkt);
void   produktSlettData(struct Produkt* produkt);
void   produsentLesData(struct Produsent* produsent, const char* navn);
void   produsentNyttProdukt(struct Produsent* produsent, const char* navn);
void   produsentSkrivData(const struct Produsent* produsent);
void   produsentSlettData(struct Produsent* produsent);
void   skrivAbsoluttAlt();
void   skrivMeny();


struct Produsent* gProdusentene[MAXPRODUSENTER];    ///< Alle produsentene.
int gAntallProdusenter = 0;         ///< Antall produsenter registrert hittil.


/**
 *  Hovedprogrammet.
 */
int main() {
    char kommando;

    skrivMeny();
    kommando = lesChar("\nKommando");

    while (kommando != 'Q')  {
        switch (kommando) {
            case 'N': nyProdusent();         break;
            case 'L': leggTilEttProdukt();   break;
            case 'A': skrivAbsoluttAlt();    break;
            default:  skrivMeny();           break;
        }
        kommando = lesChar("\nKommando");
    };
    
    fjernAllkokerteData();

return 0;
}


/**
 *  Returnerer (om mulig) peker til et navngitt produkt hos en produsent.
 *
 *  @param    produsent  - Produsenten for produktet
 *  @param    navn       - Navnet til produktet
 *  @return   Peker til produktet eller NULL
 */
struct Produkt* finnProdukt(const struct Produsent* produsent, const char* navn) {
    for(int i = 0; i < produsent->antallProdukter; i++){
        if(strcmp(produsent->produktene[i]->navn, navn) == 0){
            return produsent->produktene[i];
        }
    }
    return NULL; 
}


/**
 *  Returnerer (om mulig) peker til en navngitt produsent.
 *
 *  @param    navn   - Navnet til produsenten
 *  @return   Peker til produsenten eller NULL
 */
struct Produsent* finnProdusent(const char* navn) {

//     Lag innmaten
}


/**
 *  Fjerner ALLE allokerte data fra minnet/memory.
 *
 *  @see   produsentSlettData(...)
 */
void fjernAllkokerteData() {

//     Lag innmaten
}


/**
 *  Legger til (om mulig) ETT nytt produkt hos en produsent.
 *
 *  @see   finnProdusent(...)
 *  @see   finnProdukt(...)
 *  @see   produsentNyttProdukt(...)
 */
void leggTilEttProdukt()  {

//     Lag innmaten
}


/**
 *  Legger inn (om mulig) en ny produsent.
 *
 *  @see   finnProdusent(...)
 *  @see   produsentLesData(...)
 */
void nyProdusent()  {
    //check for max amount of manufacturers
    char produsentNavn[STRLEN];
    memset(produsentNavn, 0, sizeof(produsentNavn)); //setter array til 0

    bool produsentEksisterer = false;
    if(gAntallProdusenter == MAXPRODUSENTER){
        printf("Det er allerede fullt med produsenter");
    }
    printf("Skriv in produsent navn ");
    fgets(produsentNavn, STRLEN, stdin);
    

    //g. Ellers lages en ny produsent, antall produsenter telles opp, og produsentens data leses inn av
    struct Produsent* produsentStruct = malloc(sizeof(struct Produsent)); //initialiserer produsent

    produsentLesData(produsentStruct, produsentNavn); 

} 


/**
 *  Leser inn ALLE dataene om ETT produkt.
 *
 *  @param   produkt  - Produktet som får sine data lest inn
 *  @param   navn     - Hittil innlest produktnavn
 */
void produktLesData(struct Produkt* produkt, const char* navn){


}


/**
 *  Skriver ALLE et produkts data på skjermen.
 *
 *  @param   produkt  - Produktet hvis alle data skrives ut.
 */
void produktSkrivData(const struct Produkt* produkt) {

//     Lag innmaten
}


/**
 *  Sletter ALLE et produkts allokerte data fra minnet.
 *
 *  @param   produkt  - Produktet som får slettet sine allokerte data
 */
void produktSlettData(struct Produkt* produkt) {

//     Lag innmaten
}


/**
 *  Leser inn en produsents data, inkl initielle produkter.
 *
 *  @param   produsent  - Produsenten som det leses inn data til
 *  @param   navn       - Navnet til produsenten
 *  @see     finnProdukt(...)
 *  @see     produsentNyttProdukt(...)
 */
void produsentLesData(struct Produsent* produsent, const char* navn){
    char input[STRLEN];
    bool inputIkkeFerdig = true;
    bool produktNavnEksisterer = false;
    struct Produkt *produktPeker;
    char produktNavn[STRLEN];
    int menyInput; 
    memset(produktNavn, 0, sizeof(produktNavn)); //setter array til 0

    produsent->navn = navn;
    produsent->antallProdukter = 0;
    printf("Hvilken by er %s i?: ", navn);
    fgets(input, STRLEN, stdin);
    produsent->by = input;

    struct Produkt* prod = malloc(sizeof(struct Produkt)); //allocate memory for products
    do{
        if(produsent->antallProdukter < MAXPRODUKTER){
            printf("Produsenten har nådd maks produkter!");
            inputIkkeFerdig = false; //NEEDS TO BE FIXED
        }

        do{
            //spør om produkt navn
            printf("Skriv inn produkt navn for %s", navn);
            fgets(produktNavn, STRLEN, stdin);
            produktPeker = finnProdukt(produsent, produktNavn);
            if(produktPeker != NULL){
                printf("Produktet eksisterer allerede. Prøv på nytt!");
                produktNavnEksisterer = true;
            }

        }
        while(produktNavnEksisterer);

        produsentNyttProdukt(produsent, navn);

        
        printf("Legge til et nytt produkt (J/N): ");
        scanf(" %c", menyInput);
        menyInput = toupper(menyInput); 
        if(menyInput = 'J'){inputIkkeFerdig = true;}
        else{inputIkkeFerdig = false;}
        
    }
    while(inputIkkeFerdig);


//     Lag innmaten
}


/**
 *  Legger enn ETT nytt produkt hos en produsent.
 *
 *  @param   produsent  -  Produsenten å legge inn nytt produkt hos
 *  @param   navn       -  Nytt produkts navn
 *  @see     produktLesData(...)
 */
void produsentNyttProdukt(struct Produsent* produsent, const char* navn)  {

//     Lag innmaten
}


/**
 *  Skriver ALLE en produsents data ut på skjermen.
 *
 *  @param    produsent  - Produsenten hvis alle data skrives ut.
 *  @see      produktSkrivData(...)
 */
void produsentSkrivData(const struct Produsent* produsent) {

//     Lag innmaten
}


/**
 *  Sletter ALLE en produsents allokerte data fra minnet.
 *
 *  @param   produsent  - Produsenten som får slettet sine allokerte data
 *  @see     produktSlettData(...)
 */
void produsentSlettData(struct Produsent* produsent) {

//     Lag innmaten
}


/**
 *  Skriver alt om alle produsenter.
 *
 *  @see   produsentSkrivData(...)
 */
void skrivAbsoluttAlt()  {

//     Lag innmaten
}


/**
 *  Skriver alle kommandoene tilgjengelig i programmet.
 */
void skrivMeny() {
  printf("\nProgrammets kommandoer:");
  printf("\n\tN - Ny  produsent (og produkter)");
  printf("\n\tL - Legg til ett produkt hos en produsent");
  printf("\n\tA - skriv Alle produsenter og alle deres produkter");
  printf("\n\tQ - Quit/avslutt\n");
}
