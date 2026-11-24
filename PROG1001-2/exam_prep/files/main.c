/**
 * @file main.c
 * @author Sparky
 * @brief small example file for reading and writing files in c
 * @version 0.1
 * @date 2026-11-24
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <stdio.h> 
int main(){
    //writing a file
    FILE* fileWrite; //create file
    fileWrite = fopen("./bullshit.txt","w"); 
    if(fileWrite){
        //file is openable
        fprintf(fileWrite, "some text here\n"); 
        fprintf(fileWrite, "another line\n"); 
        fprintf(fileWrite,"%d",23); //write with specific data type

        /*
        data looks like this

        some text here
        another line
        23
        */
    }
    else{printf("failed to open file\n");}

    fclose(fileWrite);



    //Reading the file
    FILE* fileRead; //create reader
    fileRead = fopen("./bullshit.txt", "r"); 
    if(fileRead){
        //file exists

        /* or read the whole file like this
        char ch; 
        while ((ch = fgetc(fileRead)) != EOF) {
            printf("%c", ch);
        }
        */

        char string[100];
        fgets(string, 100,fileRead);
        printf("%s", string); 
        
        fgets(string, 100,fileRead);
        printf("%s", string); 

        //read number into var. 
        int number;
        fscanf(fileRead,"%d", &number); 
        getc(fileRead); //reads potential \n char at the end
        printf("%d", number); 


    }
    fclose(fileRead); 
    

}