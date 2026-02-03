
/*
==============================================================
Name: Shawn Gurusinghe
Course: 1050
Section: A
Assignment: Lab 9
User: sg8c6
Files: lab9.c       
October 24th, 2025
==============================================================
*/
#include <stdio.h>
int localizedSearch(const int *startPtr, const int *endPtr, int key){ 
    if(startPtr==NULL||endPtr==NULL)
    return -1;//null check
    int counter = 0;
    for(const int *i = startPtr;i<endPtr;i++){//pointer that increments thru array left to right
        if(*i==key){
            return counter;//returns counter
        }
        counter++;//incremented after return so 0 is possible
    }
    return -1;//no key found
}
void printBackward(const int *lastPtr, int count){
    if(lastPtr==NULL)
        return;//null check type void
    for(const int *i=lastPtr;i>lastPtr-count;i--){//starts with last ptr goes backwards
        printf("%d ",*i);//prints value of i
    }
}
int reverseSearch(const int *basePtr, int size, int key){
    if(basePtr==NULL)
    return -1;//null check
    int counter = size-1;//counter intialized at the end of arr
    for(const int *i = basePtr+size-1;i>=basePtr;i--){//increments thru array right to left
        if(*i==key){
            return counter;//returns counter
        }
        counter--;//decrements
    }
    return -1;//no key found
}
int findAllIndices(const int *basePtr, int size, int key, int *outIndices, int maxOut) {
    if (basePtr == NULL || outIndices == NULL || size <= 0 || maxOut <= 0)
        return -1;  //null check
    int found_elems = 0;//new counter, tracks how many keys found
    for (int i = 0; i < size && found_elems < maxOut; i++) {
        if (basePtr[i] == key) {
            outIndices[found_elems] = i;//stores
            found_elems++;//increments
        }
    }
    return found_elems; //how many matches were actually recorded
}
