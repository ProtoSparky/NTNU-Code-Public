#include <stdio.h>
#include <stdbool.h>

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

    switch(userInput):
        case "L":
        printf("Bruker L");
        break;
        case "S":
        printf("Bruker S");
        


    return 0; 
}