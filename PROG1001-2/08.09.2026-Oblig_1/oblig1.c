/**
 * @file oblig1.c
 * @author Kristupas Kaupas
 * @brief Ferieuker og sånt
 * @version 0.1
 * @date 2026-09-07
 * 
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
const int STRLEN = 80; ///< maks tekst lengde
/**
 * Hovedprogrammet 
 */
int main(){
    char navn1[STRLEN],  navn2[STRLEN];     //navn for pers
    int navn1Timelønn, navn2Timelønn;       //timelønn for de to folka
    int navn1Ferieuker, navn2Ferieuker;     //ant ferieuker
    bool likeNavn, likeTimeslønn;

    

    //spør etter brukerdata

    printf("Første persons navn: ");
    scanf("%s", &navn1);
    printf("Andre personens navn: ");
    scanf("%s", &navn2);
    
    printf("%s sin timeslønn: ", navn1);
    scanf("%d", &navn1Timelønn); 
    printf("Antall uker ferie: ");
    scanf("%d", &navn1Ferieuker);

    printf("%s sin timeslønn: ", navn2);
    scanf("%d", &navn2Timelønn);
    printf("Antall uker ferie ");
    scanf("%d", &navn2Ferieuker); 


    printf("\n"); //rydder opp terminal output


    //Skriver ut for navn 1
    printf("Navn: %s (lengde: %i)\n", navn1,strlen(navn1));
    printf("Timelønn: %d\n", navn1Timelønn);
    printf("Ferie uker: %d\n", navn1Ferieuker);
    printf("Ukelønn: %d\n", (navn1Timelønn* 8) * 5); 
    printf("Månedslønn %.1f\n", ((navn1Timelønn * 8) * 5) * 4.33); 
    printf("Årslønn: %d\n", ((navn1Timelønn* 8) * 5)* (52 - navn1Ferieuker)); 



    printf("\n"); //rydder opp terminal output



    printf("Navn: %s (lengde: %i)\n",navn2,strlen(navn2));
    printf("Timelønn: %d\n", navn2Timelønn);
    printf("Ferie uker: %d\n", navn2Ferieuker);
    printf("Ukelønn: %d\n", (navn2Timelønn* 8) * 5); 
    printf("Månedslønn %.1f\n", ((navn2Timelønn * 8) * 5) * 4.33); 
    printf("Årslønn: %d\n", ((navn2Timelønn* 8) * 5)* (52 - navn2Ferieuker)); 


    printf("\n"); //rydder opp terminal output

    likeNavn = (strcmp(navn1, navn2) == 0);
    likeTimeslønn = (navn1Timelønn == navn2Timelønn); 

    printf("Like navn: %d\n", likeNavn);
    printf("Lik timeslønn: %d\n", likeTimeslønn); 

    return 0;
}