#include <stdio.h>
int main()  {
    int val = 0; 
    while(1 == 1){
        if(val % 2){
            printf("even | %i \n", val);
        }
        else{
            printf("odd  | %i \n", val); 
        }
        //printf("%i \n", val);
        val += 1;
    }    
}