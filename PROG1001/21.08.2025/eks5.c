#include <stdio.h> 
#include <math.h>
void A();
void B();

int main(){
   B(); 

}


void A(){
    int l,b,h,vol;
    l = 8;
    b = 12;
    h = 16;

    vol = l*b*h;
    printf("Volumet er %i m^3", vol);     
}

void B(){
    int num = 19600406;
    int len;
    int numLeft = -1;
    
    while(1==1){
        if(numLeft ==  -1){
            numLeft = num;
        }
        numLeft = numLeft / 10;
        len ++; 
    }

}
