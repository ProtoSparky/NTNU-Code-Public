#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

const int MAXBANER = 18; ///< Maks antall baner.
const int STRLEN = 100; ///< Maks tekstlengde.

int menu();

int main(){
    char baneBeskrivelse[MAXBANER][STRLEN]; // Beskrivelse av banene.
    int baneLengde[MAXBANER]; // Banenes lengde (i meter).
    int banePar[MAXBANER]; // Forventet antall kast (par)
    // for hver enkelt bane.
    bool baneOB[MAXBANER]; // Har banene OB eller ei
    // (google evt. hva OB er).
    int antallBaner; // Antall baner pr.nå

    menu(); 
    return 0;
}


int menu(){
    char userInput ;
    printf("Menyvalg:");
    printf("\n    L - Legge til bane");
    printf("\n    S - Se alle baner");
    printf("\n    Q - Asvlutt");
    printf("\nValg:");

    
    scanf("%c", &userInput);


    switch(toupper(userInput)){
        case 76: //L
            printf("Bruker L");
            break;
        
        case 83: //S
            printf("Bruker S");
            break;

        case 81: //Q
            printf("Bruker Q");
            break;
        
        default:
            printf("\nInput ikke L,S eller Q");
            menu();
            break;
        
    }


    return 0; 
}