/*
==============================================================
Name: Shawn Gurusinghe
Course: 2050
Section: A
Assignment: Lab 9
User: sg8c6
Files: lab9.c
April 10th, 2026
==============================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "lab9.h"
//typedef for package struct (removed)
//lab functions
void * createArray(int arraySize, int elementSize){
    if(arraySize <= 0||elementSize <=0){
        perror("Invalid array (line 19)");
        return NULL;
    }
    void *array = malloc(sizeof(int) + (arraySize * elementSize));//allocates memory for an array of the given size and element size
    if(!array){//checks if the memory allocation was successful
        perror("Memory allocation failed (line 24)");
        return NULL;
    }
    array = (char*)array + sizeof(int);//adjusts the pointer to point to the start of the array data,
    //leaving space at the beginning to store the array size as metadata
    *((int*)array - 1) = arraySize;//stores the array size at the beginning of the allocated memory
    return array;//returns a pointer to the allocated array
}
int arraySize(void * array){
    if(!array){//checks if array pointer is valid
        perror("Invalid array pointer (line 34)");
        return -1;
    }
    return *((int*)array - 1);//otherwise, returns the array size stored in the metadata at the beginning of the allocated memory
}
int comparePackages(Package *a, Package *b){
    if(!a||!b){//checks if either package pointer is valid, if not, returns -2 to indicate an error
        perror("Invalid package pointer (line 41)");
        return -2;
    }
    if(a->deliveryDistance == b->deliveryDistance){//check if the delivery distances are equal, if so, return 0 to indicate equality
        return 0;
    } else if(a->deliveryDistance > b->deliveryDistance){//check if a's delivery distance is greater than b's, if so, return 1 to indicate a is greater
        return 1;
    } else {//otherwise, a's delivery distance must be less than b's, so return -1 to indicate a is less
        return -1;
    }
}
int findPackage(Package * array, Package * query){
    if(!array||!query){//checks if either the array pointer or query pointer is valid, if not, returns -2 to indicate an error
        perror("Invalid array or query pointer (line 54)");
        return -2;
    }
    int size = arraySize(array);//first accesses the size of the array using the arraySize function
    return binarySearch(array, query, 0, size - 1);//uses helper function to recursively perform a binary search
    //sends the array, query, and initial left and right indices to the binarySearch function, which will return the index of the query package if found, or -1 if not found
}
int binarySearch(Package * array, Package * query, int left, int right){
    if(left > right){//checks if the left index has surpassed the right index, which means the query package is not in the array, so returns -1 to indicate not found
        //not an error technically, just indicates that the search was unsuccessful, so no perror message is printed
        return -1;
    }
    int mid = left + (right - left) / 2;//finds the middle index of the current array range
    int cmp = comparePackages(&array[mid], query);//uses the comparePackages function to compare the package at the middle index with the query package
    if(cmp == 0){//if the comparePackages function returns 0, it means the package at the middle index is equal to the query package, so we have found the query package and can return its index
        return mid;
    } else if(cmp > 0){//if the comparePackages function returns a value greater than 0, it means the package at the middle index has a greater tracking number than the query package, so we need to search the left half of the array
        return binarySearch(array, query, left, mid - 1);
    } else {//otherwise, the comparePackages function must have returned a value less than 0, which means the package at the middle index has a smaller tracking number than the query package, so we need to search the right half of the array
        return binarySearch(array, query, mid + 1, right);
    }
}
void destroyArray(void * array){
    if(!array){//checks if array pointer is valid, if not, does nothing
        perror("Invalid array pointer (line 78)");
        return;
    }
    free((char*)array - sizeof(int));//frees the memory allocated for the array, adjusting the pointer back to the start of the allocated memory
}