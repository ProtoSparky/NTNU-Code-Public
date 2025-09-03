#include <stdio.h>
enum Ukedag{mandag, tirsdag, onsdag, torsdag, fredag, lordag, sondag}; 

int main(){
    enum Ukedag dag1,dag2;
    dag1=fredag;    dag2 = tirsdag;
    printf("antall dager mellom fredag og tirsdag er %i", dag1-dag2); 
    return 0; 
}