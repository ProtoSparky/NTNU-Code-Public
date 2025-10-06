#include <stdio.h>
#include <stdbool.h> // booleans
#include <ctype.h>  //toupper
#include <string.h> //strcpy

const int MAXBANER = 18; ///< Maks antall baner.
const int STRLEN = 100; ///< Maks tekstlengde.

int main(){
    char baneBeskrivelse[MAXBANER][STRLEN]; // Beskrivelse av banene.
    int baneLengde[MAXBANER]; // Banenes lengde (i meter).
    int banePar[MAXBANER]; // Forventet antall kast for å fullføre banen
    // for hver enkelt bane.
    bool baneOB[MAXBANER]; // Har banene out of bounds
    int antallBaner; // Antall baner pr.nå

    antallBaner = 2;
    baneLengde[0] = 62;
    baneLengde[1] = 94;
    banePar[0] = 3;
    banePar[1] = 3;
    baneOB[0] = true; 
    baneOB[1] = false; 
    strcpy(baneBeskrivelse[0], "Bane med mange trær og kratt");
    strcpy(baneBeskrivelse[1], "Flatt terreng gjennom hele banen");


    ask_for_input:

    char userInput ;
    printf("Menyvalg:");
    printf("\n    L - Legge til bane");
    printf("\n    S - Se alle baner");
    printf("\n    Q - Asvlutt");
    printf("\nValg:");

    scanf("%c", &userInput);
    getchar();
    switch(toupper(userInput)){
        case 76: //L            
            if(antallBaner >= MAXBANER){
                printf("Du har nådd maks baner, og kan ikke legge til flere.");
            }
            else{
                bane_lengde_feil:
                printf("Hvor lang er den %i. banen: ", antallBaner +1);
                int tempBaneLengde;
                int tempPar;
                char tempOB;
                char tempBeskrivelse;

                scanf("%d", &tempBaneLengde); 
                getchar();
                if(tempBaneLengde == 0){
                    printf("\n Avslutter.... \n");
                    goto ask_for_input;
                }
                else if(tempBaneLengde < 0){
                    printf("Tallet kan ikke være mindre enn null!\n");
                    goto bane_lengde_feil; 
                }
                
                baneLengde[antallBaner +1] = tempBaneLengde; //lagrer data

                par_feil:
                printf("Par på banen (2-8): ");
                scanf("%d", &tempPar);
                getchar(); 
                if(tempPar < 2 || tempPar > 8){
                    printf("%i er ikke godkjent. Godkjente tall er (2-8) \n");
                    goto par_feil;
                }
                banePar[antallBaner + 1] = tempPar; //lagrer data

                ob_feil:
                printf("Har banen OB (J/N): ");
                scanf("%c", &tempOB);
                getchar();
                if(toupper(tempOB)!= 'J' && toupper(tempOB)!= 'N'){
                    printf("%c er verken J eller N \n");
                    goto ob_feil;
                }
                baneOB[antallBaner + 1] = tempOB; 

                beskrivelse_feil:
                printf("Bane Beskrivelse: ");
                scanf("%s", &tempBeskrivelse);
                getchar();
                if(strlen(&tempBeskrivelse) > STRLEN -1){
                    printf("Din input på %i er større enn maks lengde på %i",strlen(&tempBeskrivelse) +1, STRLEN);
                    goto beskrivelse_feil; 
                }
                strcpy(baneBeskrivelse[antallBaner + 1], "fuckoff"); 

            }

            break;
        
        case 83: //S
            printf("Bruker S");
            break;

        case 81: //Q
            printf("Bruker Q");
            break;
        
        default:
            printf("\nInput ikke L,S eller Q \n");
            goto ask_for_input; 
    }
 
    return 0;
}