/**
 * @file oblig2.c
 * @author Kristupas Kaupas
 * @brief program som krypterer passord for en rekke brukere
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
 * @param passord char array med passord
 */
void encrypt(char* passord){
    int charLengde = strlen(passord);
    char kryptertText[charLengde + 1];  //char for passord kryptering
    for(int i = 0; i < charLengde; i++){
        int ascii = passord[i];         // konverterer char til ascii verdi
        int verdi = (((ascii - ASCIINRFORST) + CIPHER) % MOD) + ASCIINRFORST;
        kryptertText[i] = (char)verdi;
    }
    kryptertText[charLengde] = '\0'; //terminerer char så strcpy fungerer ok
    strcpy(passord, kryptertText);   //skriver over passord med kryptert passord
}

/**
 * @brief sjekker om passord er innenfor kravene eller ikke
 * 
 * @param passord 
 * @return true 
 * @return false 
 */
bool sjekkPassord(char* passord){
    int storBokstavStart = 65, storBokstavSlutt = 90;//range for store bokstaver
    int litenBokstavStart = 97, litenBokstavSlutt = 122; //samme for små bokstav
                                //bools som blir sanne om dets krav blir oppnådd
    bool storeBokstaverOK = false, småBokstaverOK = false, alleCharsOK = false; 

    int antChars = strlen(passord);
    for(int i = 0; i < antChars; i++){
        //går gjennom alle tegn i passordet
        int bokstav = passord[i];           //ascii verdi for en gitt bokstav

                                            //sjekker etter store bokstaver
        if(
            (bokstav >= ASCIINRFORST && bokstav <= ASCIINRSIST) &&
            (bokstav >= storBokstavStart && bokstav <= storBokstavSlutt)
        ){storeBokstaverOK = true;}

                                            //sjekker etter små bokstaver
        if(
            (bokstav >= ASCIINRFORST && bokstav <= ASCIINRSIST) &&
            (bokstav >= litenBokstavStart && bokstav <= litenBokstavSlutt)
        ){småBokstaverOK = true;}

                                //sjekker etter spesielle chars, ikke bokstaver
        if(
            (bokstav >= ASCIINRFORST && bokstav <= ASCIINRSIST) && 
            !(bokstav >= storBokstavStart && bokstav <= storBokstavSlutt) && 
            !(bokstav >= litenBokstavStart && bokstav <= litenBokstavSlutt)
        ){alleCharsOK = true;}

    }
    return storeBokstaverOK && småBokstaverOK && alleCharsOK;//alle krav sjekkes 
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
                printf("\n");                 
                if(antBrukere < MAXBRUKERE){
                    char inputBrukernavn[STRLEN];
                    char inputPassord[STRLEN];
                                                            //bruker input
                    printf("Skriv inn brukernavn: ");
                    scanf("%s", &inputBrukernavn);

                    printf("\nskriv inn passord:\n");
                    printf("Passord må ha minst EN stor bokstav, ");
                    printf("minst EN liten bokstav, og minst ET spesiell tegn");
                    printf(". Dvs alle valid ascii tegn. \n");
                    printf("passord: ");
                    scanf("%s", &inputPassord);

                                                //sjekker om passordet er valid
                    if(sjekkPassord(inputPassord)){
                        encrypt(inputPassord);  //krypterer passordet
                        
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
                                                            //bruker input
                printf("\nSkriv inn brukernavn: ");
                scanf("%s", inputBrukernavn); 
                printf("\nSkriv inn passord: ");
                scanf("%s", inputPassord); 
                encrypt(inputPassord);                      //krypterer passord

                //går gjennom alle lagrede brukere og sjekker om
                //  brukernavn og passord er like
                for(int i = 0; i < antBrukere; i ++){
                    if(
                        strcmp(brukerNavn[i], inputBrukernavn)== 0 && 
                        strcmp(brukerPass[i], inputPassord)== 0
                    ){funnetBruker = true;}                    
                }
                
                if(funnetBruker){
                    printf("Bruker %s er logget inn\n\n",inputBrukernavn);
                }
                else{
                    printf("Brukernavn eller passord er feil\n\n"); 
                }

                break;
            }
            case 'S':{
                printf("\n"); 
                printf("%d / %d registrerte brukere\n", antBrukere, MAXBRUKERE);
                printf("ID | Brukernavn | Kryptert passord |\n"); 
                for(int i = 0; i < antBrukere; i++){
                    printf("%d | %s | %s |\n", i+1,brukerNavn[i],brukerPass[i]);
                }
                printf("\n"); 
                break;
            }
            case 'Q':{
                printf("programmet lukkes!\n"); 
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