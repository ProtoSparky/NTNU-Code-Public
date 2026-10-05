/**
 * @file oblig2.c
 * @author Kristupas Kaupas
 * @brief 
 * @version 0.1
 * @date 2026-10-04
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

const int STRLEN = 40; ///< Max. tekstlengde.
const int MAXBRUKERE = 20; ///< Max. antall brukere.
const int ASCIINRFORST = 33; ///< Første lovlige ASCII-nr som brukes.
const int ASCIINRSIST = 126; ///< Siste lovlige ASCII-nr som brukes.
const int MOD = (ASCIINRSIST-ASCIINRFORST)+1; ///< Intervallets lengde.
const int CIPHER = 42; ///< Antall høyre-skift ved kryptering

/**
 * @brief krypterer passord med caesar cypher
 * 
 * @param passord 
 */
void encrypt(char* passord){
    int charLengde = sizeof(passord) / sizeof(passord[0]);
    char kryptertText[charLengde]; //ferdig kryptert passord
    for(int i = 0; i < charLengde; i++){
        int ascii = passord[i];
        int verdi = (((ascii - ASCIINRFORST) + CIPHER) % MOD) + ASCIINRFORST;
        kryptertText[i] = (char)verdi;
        //printf("orginal char (%c), ascii (%d), kryptert (%c)\n", passord[i], ascii, kryptertText[i]); 
    }
    strcpy(passord, kryptertText); 
}
bool sjekkPassord(char* passord){
    int storBokstavStart = 65, storBokstavSlutt = 90;
    int litenBokstavStart = 97, litenBokstavSlutt = 122; 
    int antChars = sizeof(passord) / sizeof(passord[0]); 
    bool storeBokstaaverOK = false, småBokstaaverOK = false,
    alleCharsOK = false; 


    for(int i = 0; i < antChars; i++){
        //går gjennom alle tegn i passordet
        int bokstav = passord[i]; 

        //sjekker alle etter minst 1 stor bokstav
        for(int x = storBokstavStart; x < storBokstavSlutt; x ++){
            if(bokstav == x){storeBokstaaverOK = true;} //funnet en stor bokstav
        }
        
    }
}
/*
                char passord[] = "ARSENAL";
                encrypt(passord);
                printf("passord er %s", passord);

*/




/**
 * @brief selve programmet
 * 
 * @return int 
 */
int main(){
    char brukerNavn[MAXBRUKERE][STRLEN]; // 2-dim array for brukernavnene.
    char brukerPass[MAXBRUKERE][STRLEN]; // 2-dim array for passordene.
    int antBrukere = 0; // Antall brukere registrert hittil

    char menyValg; //char for menyvalg



    do{
        printf("Skriv et valg: \n");
        printf("N - Ny bruker\n"); 
        printf("L - Logg inn\n");
        printf("S - Skriv alle brukere\n");
        printf("Q - Quit \n");


        printf("Valg: "); 
        scanf(" %c", &menyValg);
        menyValg = toupper(menyValg); //gjør til store bokstaver
        //printf("valg meny er-------------------- %c", menyValg);

        
        switch(menyValg){
            case 'N':{
                printf("Ny bruker lages\n");
                
                if(antBrukere < MAXBRUKERE){
                    char brukernavn[STRLEN];
                    char passord[STRLEN];
                    printf("Skriv inn brukernavn: ");
                    scanf("%s", &brukernavn);
                    printf("\nskriv inn passord:\n");
                    printf("Passord må ha minst EN stor bokstav, ");
                    printf("minst EN liten bokstav, og minst ET spesiell tegn");
                    printf(". Dvs alle valid ascii tegn. \n");
                    printf("passord: ");
                    scanf("%s", &passord);
                    


                }
                else{printf("Du har oppnådd max ant brukere\n");}
                
                break; 
            }
            case 'L':{
                printf("Logg inn bruker");
                break;
            }
            case 'S':{
                printf("skriv alle brukere");
                break;
            }
            default:{
                //feil kommando
                printf("Kommando er feil!\n"); 
                break; 
            }
        }
        

    }
    while(menyValg != 'Q');


    return 0; 
}

