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

const int STRLEN = 80; ///< maks tekst lengde
const int timerIÅret = ((8 * 5) * 4.33) * 52; 
/**
 * Hovedprogrammet 
 */
int main(){
    char navn1[STRLEN],  navn2[STRLEN];     //navn for pers
    int navn1Timelønn, navn2Timelønn;       //timelønn for de to folka
    int navn1Ferieuker, navn2Ferieuker;     //ant ferieuker


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


    //Skriver ut for navn 1
    printf("Navn: %s (lengde: %i)", 
        navn1,
        (sizeof(navn1)/sizeof(navn1[0]))    //finner lengde på array
    );
    printf("Timelønn: %d", navn1Timelønn);
    printf("Ferie uker: %d", navn1Ferieuker);
    



    return 0;
}