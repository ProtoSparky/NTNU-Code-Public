#include <stdio.h>

int main(){
    int tall1[5], tall2[]={6,2,10,12,19,3,7};
    char tekst[5], navn[]={"Lars Hansen"}, addresse[]={"Ringgata 111"}; 
    
    tall1[0] = 13; tall1[1] = 67; //Legger inn tall på uninitiated arrays 
    tall1[2] = tall1[0] + tall1[1]; //regner ut tallene og lagrer på annen array
    printf("summen av tallene i tall1 er %i \n", tall1[2]); 
    printf("halvparten av dette er %i \n",tall1[2]/2); 

    //legger sammen summen av de fire første elementer og lagrer i tall1[3]
    for(int pointer = 0; pointer <= 4; pointer ++){
        tall1[3] += tall2[pointer];         
    } 

    /*
    ********Verify fucky wucky below 
    
    */

    //summerer de 3 siste tallene i tall2 og lager i tall1[4]
    int tall2Length = sizeof(tall2)/sizeof(tall2[0]);
    for(int pointer = tall2Length; pointer > tall2Length -3; pointer --){
        tall1[4] += tall2[pointer]; 
    }

    printf("Element 1 er %i, Element 2 er %i \n", tall1[3], tall1[4]); 

    //øker tredje element 4 ganger
    for(int pointer = 0; pointer <= 4; pointer ++){
        tall1[2] ++; 
    }

    tekst[1] = 'A'; tekst[3] = 'E'; //fyller på tekst elementene

    //kopierer navn sitt sjette element inn i det første i tekst, 
    //og navn sitt første element inn i det tredje i tekst
    tekst[0] = navn[5]; tekst[2] = navn[0];

    printf("Kua har ");
    for(int pointer = 0; pointer <= 4; pointer ++){
        printf("%c",tekst[pointer]);
    }

    //skriver ut 111 fra addresse
    int addresseLength = sizeof(addresse)/sizeof(addresse[0]) -1;
    for(int pointer = addresseLength; pointer >= addresseLength -3; pointer --){
        printf("%c", addresse[pointer]); 
    }
    printf("\n"); 

    //hele navn og addresse
    int navnLength = sizeof(navn)/sizeof(navn[0]) -1;
    for(int pointer = 0; pointer <= navnLength; pointer ++){
        printf("%c", navn[pointer]); 
    }
    printf("\n");
    for(int pointer = 0; pointer <= addresseLength; pointer ++){
        printf("%c", addresse[pointer]); 
    }

}