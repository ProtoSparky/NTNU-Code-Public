#include <stdio.h>
#include <time.h>

const int STRLEN = 80;
const int MAXTILFELDIG = 100;
const int MAXFLOAT = 5; 

int main(){

    time_t result = time(NULL);    //  Henter maskinens tidspunkt.
                                   //  Utskrift på ulike formater:
    printf("Nåværende tid i UK:  %s",   asctime(gmtime(&result)));
    printf("Nåværende tid:       %s\n", asctime(localtime(&result)));

    return 0; 
}