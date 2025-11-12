#include <stdio.h>
#include <string.h>
#define MAXPRODUKTER 5
#define MAXPRODUSENTER 2
struct Produkt {
    char  *navn, *beskrivelse;
    int   pris;
};
struct Produsent {
    char   *navn, *by;
    int    antallProdukter;
    struct Produkt* produktene[MAXPRODUKTER];
};

int main(){
    struct Produsent* gProdusentene[MAXPRODUSENTER];

    //lets add a manufacturer
    gProdusentene[0] = malloc(sizeof(struct Produsent)); //allocate memory
    gProdusentene[0]->antallProdukter = 1;
    gProdusentene[0]->navn = "UWU";
    gProdusentene[0]->by = "Oslo";


        


    return 0;
}