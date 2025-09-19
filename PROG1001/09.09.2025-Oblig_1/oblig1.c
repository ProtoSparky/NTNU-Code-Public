/**
 *   Obligatorisk oppgave nummer 1.
 *
 *   Samler inn navn, sidetall, og sjanger på 2 ulike bøker
 *
 *   @file     oblig1.c
 *   @author   Kristupas Kaupas
 */

#include <stdio.h>
#define STRLEN 512                  //512 char så de fleste titler får plass
char bok1[STRLEN], bok2[STRLEN];    //Setter opp variabler for navn på bøker
int sider[2]; char sjanger[2]={};   //-||- men for sjanger og sider

//lager en funksjon som spør bruker om bok info
//blir brukt flere ganger
//scanf() erstatter gets() pga den er ikke lenger med i nyere C versjoner!!
void getBookInfo(int bookId){
    if(bookId == 0){        //bruker if for å lagre data i separate variabler
        printf("Navn på bok %i: \n",bookId + 1); 
        scanf("%511[^\n]", &bok1);  //leser input til newline. maks 511 char
    }else{
        printf("Navn på bok %i: \n",bookId + 1); 
        scanf("%511[^\n]", &bok2);
    }   
    getchar();

    printf("Antall sider på bok %i: \n",bookId + 1);
    scanf(" %d",&sider[bookId]); getchar();

    printf("Sjanger på bok (B - Biografi, F - Fiksjon, T - Thriller): \n");
    scanf(" %c",&sjanger[bookId]); getchar();    
    
}

// ***************************************************************************
// ***************************************************************************

int main(){
    printf("************************************************\n");
    getBookInfo(0);     //Kjører for bok 1
    printf("************************************************\n");
    getBookInfo(1);     //Kjører for bok 2
    printf("************************************************\n");
    //printer ut data som vist på eksempel
    printf("Navn: %s \n",bok1);
    printf("Sjanger: %c \n\n", sjanger[0]);

    printf("Navn: %s \n", bok2);
    printf("Sjanger: %c \n\n", sjanger[1]);

    printf("Bøker lest: 2 \n");
    printf("Sider lest totalt: %i \n", sider[0] + sider[1]); 

    printf("************************************************\n");
    return 0;
}
