/**
 *   @file     oblig1.c
 *   @author   Kristupas Kaupas
 *   @date     2025-09-22
 *   @brief    Obligatorisk oppgave nummer 1
 *   @details  Samler inn navn, sidetall, og sjanger på 2 ulike bøker
 */

#include <stdio.h>                  // printf, scanf, gets
#define STRLEN 512                  ///< Max input char lengde for bøker

// GLOBALE VARIABLER
char bok1[STRLEN], bok2[STRLEN];    ///< Bok navn
int sider[2];                       ///< Sidetall ints for begge bøkene
char sjanger[2]={};                 ///< Sjanger array for begge bøkene (B,F,T)

// DEKLARASJON AV FUNKSJONER
void getBookInfo(int bookId);



/**
 * @brief Startpunktet for programmet.
 * @details Henter informasjon om 2 bøker via getBookInfo, og viser dem pent.
 * @return returnerer int 0 etter den var kjørt
 */
int main(){
    printf("************************************************\n");
    getBookInfo(0);     //Henter bok data fra bruker for bok 1
    printf("************************************************\n");
    getBookInfo(1);     //Henter bok data fra bruker for bok 2
    printf("************************************************\n");

    //Skriver ut data som på eksempel
                                                    //Bok 1
    printf("Navn: %s \n",bok1);
    printf("Sjanger: %c \n\n", sjanger[0]);
                                                    //Bok 2
    printf("Navn: %s \n", bok2);
    printf("Sjanger: %c \n\n", sjanger[1]);        

    printf("Bøker lest: 2 \n");
    printf("Sider lest totalt: %i \n", sider[0] + sider[1]); //summerer sidetall

    printf("************************************************\n");
    return 0;
}


/**
*   @brief Spør bruker om info for bøker.
*   @param bookId input integer for kontroll av bok navn array som brukes.(0,1)
*   @note scanf() erstatter gets() i hengold med nyere C versjoner
*/
void getBookInfo(int bookId){
    if(bookId == 0){        //Bruker if for å lagre data i separate variabler
        printf("Navn på bok %i: \n",bookId + 1); 
        scanf("%511[^\n]", &bok1);  //Leser input til newline. maks 511 char
    }else{
        printf("Navn på bok %i: \n",bookId + 1); 
        scanf("%511[^\n]", &bok2);
    }   
    getchar(); //Tømmer \n fra buffer etter if seksjonen
                                                    
    printf("Antall sider på bok %i: \n",bookId + 1);
    scanf(" %d",&sider[bookId]); getchar();     //Henter sider på bok n

    printf("Sjanger på bok (B - Biografi, F - Fiksjon, T - Thriller): \n");
    scanf(" %c",&sjanger[bookId]); getchar();    //Henter sjanger char
    
}
