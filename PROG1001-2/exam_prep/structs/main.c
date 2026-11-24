/**
 * @file main.c
 * @author Sparky
 * @brief demo script for structs
 * @version 0.1
 * @date 2026-11-24
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <stdio.h>
#include <string.h>

#define CHARLEN 200
int main(){
    //struct for a person and their info
    struct Person{
        int age, dateOfBirth[2];
        char name[CHARLEN], address[CHARLEN]; 
        float weight; 
    }; 

    //create a new struct
    struct Person sparky;

    //fill it out
    sparky.age = 21; 
    sparky.dateOfBirth[0] = 4;
    sparky.dateOfBirth[1] = 7;
    sparky.dateOfBirth[2] = 2005;
    strcpy(sparky.name, "Kristupas Kaupas"); 
    strcpy(sparky.address, "Merkantilvegen 63, 201");
    sparky.weight = 76.8;

    //print it out

    printf("%s, %d, %d-%d-%d, %s, %f", 
        sparky.name, sparky.age, 
        sparky.dateOfBirth[0], sparky.dateOfBirth[1], sparky.dateOfBirth[2],
        sparky.address, sparky.weight
    );
}