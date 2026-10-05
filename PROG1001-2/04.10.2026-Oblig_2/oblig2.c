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
    }
    strcpy(passord, kryptertText); 
}

/**
 * @brief sjekker om passord er innenfor kravene eller ikke
 * 
 * @param passord 
 * @return true 
 * @return false 
 */
bool sjekkPassord(char* passord){
    int storBokstavStart = 65, storBokstavSlutt = 90;
    int litenBokstavStart = 97, litenBokstavSlutt = 122; 
    bool storeBokstaverOK = false, småBokstaverOK = false, alleCharsOK = false; 
    int antChars = sizeof(passord) / sizeof(passord[0]); 

    for(int i = 0; i < antChars; i++){
        //går gjennom alle tegn i passordet
        int bokstav = passord[i]; 

        //sjekker etter store bokstaver
        if(
            (bokstav >= ASCIINRFORST && bokstav <= ASCIINRSIST) &&
            (bokstav >= storBokstavStart && bokstav <= storBokstavSlutt)
        ){
            storeBokstaverOK = true;
            //printf("Stor bokstav %c\n", bokstav);
        }

        //sjekker etter små bokstaver
        if(
            (bokstav >= ASCIINRFORST && bokstav <= ASCIINRSIST) &&
            (bokstav >= litenBokstavStart && bokstav <= litenBokstavSlutt)
        ){
            småBokstaverOK = true;
            //printf("små bokstave %c\n", bokstav); 
        }

        //sjekker etter spesielle chars, ikke bokstaver
        if(
            (bokstav >= ASCIINRFORST && bokstav <= ASCIINRSIST) && 
            !(bokstav >= storBokstavStart && bokstav <= storBokstavSlutt) && 
            !(bokstav >= litenBokstavStart && bokstav <= litenBokstavSlutt)
        ){
            alleCharsOK = true;
            //printf("chars funnet %c\n", bokstav); 
        }

    }
    return storeBokstaverOK && småBokstaverOK && alleCharsOK; //alle finnes
}




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
        
        switch(menyValg){
            case 'N':{
                printf("Ny bruker lages\n");
                
                if(antBrukere < MAXBRUKERE){
                    char inputBrukernavn[STRLEN];
                    char inputPassord[STRLEN];

                    printf("Skriv inn brukernavn: ");
                    scanf("%s", &inputBrukernavn);

                    printf("\nskriv inn passord:\n");
                    printf("Passord må ha minst EN stor bokstav, ");
                    printf("minst EN liten bokstav, og minst ET spesiell tegn");
                    printf(". Dvs alle valid ascii tegn. \n");
                    printf("passord: ");

                    scanf("%s", &inputPassord);
                    
                    if(sjekkPassord(inputPassord)){
                        encrypt(inputPassord); //krypterer passordet
                        
                        //lagrer brukerdata
                        strcpy(brukerNavn[antBrukere], inputBrukernavn);
                        strcpy(brukerPass[antBrukere], inputPassord);
                        antBrukere ++;
                    }
                    else{
                        printf("passordet oppnår ikke kravene. Prøv på nytt\n");
                    }

                }
                else{printf("Du har oppnådd max ant brukere\n");}
                
                break; 
            }
            case 'L':{
                char inputBrukernavn[STRLEN];
                char inputPassord[STRLEN];
                bool funnetBruker = false;


                printf("\nSkriv inn brukernavn: ");
                scanf("%s", inputBrukernavn); 
                printf("\nSkriv inn passord: ");
                scanf("%s", inputPassord); 
                printf("'%s'\n",inputPassord);
                encrypt(inputPassord);
                for(int i = 0; i < (sizeof(inputPassord)/sizeof(inputPassord[0])); i++){
                    printf("%d\n", inputPassord[i]);
                }

                //går gjennom alle lagrede brukere og sjekker om
                //  brukernavn og passord er like
                for(int i = 0; i < antBrukere; i ++){
                    printf("brukernavn (%s), passord(%s), inputBrukernavn(%s), inputPassord(%s)\n", brukerNavn[i], brukerPass[i], inputBrukernavn, inputPassord);
                    if(
                        strcmp(brukerNavn[i], inputBrukernavn)== 0 && 
                        strcmp(brukerPass[i], inputPassord)== 0
                    ){funnetBruker = true;}                    
                }
                
                if(funnetBruker){
                    printf("Bruker %s er logget inn\n",inputBrukernavn);
                }
                else{
                    printf("Brukernavn eller passord er feil\n"); 
                }


                break;
            }
            case 'S':{
                printf("%d / %d registrerte brukere\n", antBrukere, MAXBRUKERE);
                printf("ID | Brukernavn | Kryptert passord |\n"); 
                for(int i = 0; i < antBrukere; i++){
                    printf("%d | %s | %s |\n", i+1,brukerNavn[i],brukerPass[i]);
                }
                printf("\n");

                break;
            }
            case 'Q':{
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

