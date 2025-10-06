#include <stdio.h>
int main(){
    char chr;
    printf("Enter char: ");
    scanf("%c", &chr);
    getchar();
    printf("ASCII value is %i", chr);  
}