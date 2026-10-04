/**
 * @file oblig2.c
 * @author Kristupas Kaupas
 * @brief 
 * @version 0.1
 * @date 2026-10-04
 */

#include <stdio.h>
#include <ctype.h>

const int STRLEN = 40; ///< Max. tekstlengde.
const int MAXBRUKERE = 20; ///< Max. antall brukere.
const int ASCIINRFORST = 33; ///< Første lovlige ASCII-nr som brukes.
const int ASCIINRSIST = 126; ///< Siste lovlige ASCII-nr som brukes.
const int MOD = (ASCIINRSIST-ASCIINRFORST)+1; ///< Intervallets lengde.
const int CIPHER = 42; ///< Antall høyre-skift ved kryptering

/**
 * @brief selve programmet
 * 
 * @return int 
 */
int main(){
    char brukerNavn[MAXBRUKERE][STRLEN]; // 2-dim array for brukernavnene.
    char brukerPass[MAXBRUKERE][STRLEN]; // 2-dim array for passordene.
    int antBrukere = 0; // Antall brukere registrert hittil

    char menyValg;




    do{
        printf("Skriv et valg: \n");
        printf("N - Ny bruker\n"); 
        printf("L - Logg inn\n");
        printf("S - Skriv alle brukere\n");
        printf("Q - Quit \n");


        printf("Valg: "); 
        scanf("%c", &menyValg);
        menyValg = toupper(menyValg); //gjør til store bokstaver
        printf("valg meny er %c", menyValg);

    }
    while{1};


    return 0; 
}
