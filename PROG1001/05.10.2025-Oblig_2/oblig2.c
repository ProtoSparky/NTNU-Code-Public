/**
 *   @file     oblig2.c
 *   @author   Kristupas Kaupas
 *   @date     2025-10-06
 *   @brief    Obligatorisk oppgave nummer 2
 *   @details  Samler inn data for frisbeegolf baner og presenterer det pent
 */

#include <stdio.h>  //scanf, print, gets
#include <stdbool.h> // booleans
#include <ctype.h>  //toupper
#include <string.h> //strcpy

const int MAXBANER = 18; ///< Maks antall baner.
const int STRLEN = 100; ///< Maks tekstlengde.

/**
 * @brief Startpunktet for programmet.
 * @details Henter og presenterer informasjon for frisbeegolf baner
 * @return returnerer int 0 etter den var kjørt
 */
int main(){
    char baneBeskrivelse[MAXBANER][STRLEN]; // Beskrivelse av banene.
    int baneLengde[MAXBANER]; // Banenes lengde (i meter).
    int banePar[MAXBANER]; // Forventet antall kast for å fullføre banen
    // for hver enkelt bane.
    bool baneOB[MAXBANER]; // Har banene out of bounds
    int antallBaner; // Antall baner pr.nå

    //Setter inn verdiene for bane 1 og 2    
    antallBaner = 2;
    baneLengde[0] = 62;
    baneLengde[1] = 94;
    banePar[0] = 3;
    banePar[1] = 3;
    baneOB[0] = true; 
    baneOB[1] = false; 
    strcpy(baneBeskrivelse[0], "Bane med mange trær og kratt");
    strcpy(baneBeskrivelse[1], "Flatt terreng gjennom hele banen");

    
    ask_for_input: //lager et punkt slik at koden under kan kjøres flere ganger 

    char userInput[100]; //Input array for menyvalg
    printf("Menyvalg:");
    printf("\n    L - Legge til bane");
    printf("\n    S - Se alle baner");
    printf("\n    Q - Asvlutt");
    printf("\nValg:");

    fgets(userInput, sizeof(userInput), stdin); //Henter input uten /n
    char userChoise = toupper(userInput[0]); //Tar første bokstav
    switch(userChoise){
        case 'L': //Legge til bane            
            if(antallBaner >= MAXBANER){ //tester om max antall baner er oppnådd
                printf("Du har nådd maks baner, og kan ikke legge til flere.");
                goto ask_for_input;//Hopper tilbake til til toppen av input meny
            }
            else{
                bane_lengde_feil:
                //Lager midlertidige input variabler for spørsmålene
                int tempBaneLengde;
                int tempPar;
                char tempOB;
                char tempBeskrivelse[STRLEN -1];
                
                //spør om bruker input
                printf("Hvor lang er den %i. banen: ", antallBaner +1);
                scanf("%d", &tempBaneLengde); 
                getchar();

                //Hvis det er 0, avslutt og hopp til toppe av menyvalg
                if(tempBaneLengde == 0){
                    printf("\n Avslutter.... \n");
                    goto ask_for_input;
                }
                //Stoppe bruker fra å sende inn 0 bane lengde
                else if(tempBaneLengde < 0){
                    printf("Tallet kan ikke være mindre enn null!\n");
                    goto bane_lengde_feil; 
                }
                
                //Lagrer input data hvis alt er riktig
                baneLengde[antallBaner] = tempBaneLengde; 

                par_feil:
                printf("Par på banen (2-8): ");
                scanf("%d", &tempPar);
                getchar(); 
                if(tempPar < 2 || tempPar > 8){
                    printf("%i er ikke godkjent. Godkjente tall er (2-8) \n");
                    goto par_feil;
                }
                //lagrer input data hvis inout er mellom 2 og 8
                banePar[antallBaner] = tempPar; 

                ob_feil:
                printf("Har banen OB (J/N): ");
                scanf("%c", &tempOB);
                getchar();
                //skriver til OB array hvis svaret er ja/nei
                if(toupper(tempOB) == 'J'){
                    baneOB[antallBaner] = true;
                }
                else if(toupper(tempOB) == 'N'){
                    baneOB[antallBaner] = false;
                }
                else{
                    printf("%c er verken J eller N \n");
                    goto ob_feil; 
                }

                beskrivelse_feil:
                printf("Bane Beskrivelse: ");
                fgets(tempBeskrivelse, STRLEN -1, stdin); //input til 99 char
                //skriver input til beskrivelse array
                strcpy(baneBeskrivelse[antallBaner], tempBeskrivelse); 

                antallBaner ++;
                goto ask_for_input; //hopper tilbake til hoved input meny

            }
            break;
        
        case 'S': //Se alle baner
            int printPointer = 0;   //pointer for while loop
            int parCounter = 0;     //teller for totale par
            while(printPointer < antallBaner){
                printf("Bane %i", printPointer +1); 
                printf("\n    Lengde: %i", baneLengde[printPointer]);
                printf("\n    Par: %i",banePar[printPointer]);
                
                //printer "Uten..." eller "Med..." basert på 0 og 1 i array
                if(baneOB[printPointer]){
                    printf("\n    Uten OB");
                }
                else{
                    printf("\n    Med OB");
                }
                printf("\n    Beskrivelse: %s\n",baneBeskrivelse[printPointer]);
                //Øker par telller med nåverende par
                parCounter += banePar[printPointer]; 
                printPointer ++;
            }
            printf("\nAntall baner: %i", antallBaner);
            printf("\nFor å havne på par brukes %i kast.\n", parCounter); 
            goto ask_for_input; //Hopper tilbake til hoved meny

        case 'Q': //Avslutt 
            //Lukker programmet
            printf("\n\nProgrammet lukkes!");
            return 0;
        
        default:
            //Håndterer input som ikke er L,S,Q. Hopper tilbake til hoved meny
            //og spør bruker om ny input siden den forrige er feil
            printf("\nInput ikke L,S eller Q \n");
            goto ask_for_input; 
    }
 
    return 0;
}