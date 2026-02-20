/*
==============================================================
Course: 2050
Section: A
Assignment: Lab 0
User: sg8c6 (Shawn Gurusinghe)
Files: lab0.c       
January 23rd, 2026
==============================================================
*/
//#include "lab0.h"
#include <stdio.h>
int countOccurrences(int size, int array [], int query){
    if(size<0){
        return -1;
    }//checks if size is valid
    int count = 0;
    for(int i = 0; i < size; i++){
        if(array==NULL){//first checks if term actually exists, if it doesnt, skip this loop
            break;
        } else if(array[i] == query){
            count++;
        }//if match found, increment count
    }    return count;
} //return counter properly incremented