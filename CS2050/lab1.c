/*
==============================================================
Name: Shawn Gurusinghe
Course: 2050
Section: A
Assignment: Lab 1
User: sg8c6
Files: lab1.c
January 30th, 2026
==============================================================
*/
#include <stdio.h>
#include <stdlib.h>
int getMedian(int array[], int size, int *result);
int sumNegative(int array[], int size, int *result);
int sumEven(int array[], int size, int *result);
int getMedian(int array[], int size, int *result){
    if(array==NULL||result==NULL){return 1;}
    if(size<=0){
        return 1; //invalid size
    }
    for(int i=0;i<size-1;i++){
        if(array[i]>array[i+1]){
            int temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
            i=-1; //restart the loop
        }
    }
    *result = array[size/2];//returns middle term after sorting array
    return 0;
}
int sumNegative(int array[], int size, int *result){
    if(array==NULL||result==NULL){return 1;}
    if(size<=0){
        return 1; //invalid size
    }
    int sum = 0;
    for(int i=0;i<size;i++){
        if(array[i]<0){//checks if positive or negative
            sum += array[i];//adds to sum
        }
    }
    //sum is stored
    if(sum>=0){return 1;}else{*result=sum;}
    return 0;
}
int sumEven(int array[], int size, int *result){
    if(array==NULL||result==NULL){return 1;}
    if(size<=0){
        return 1; //invalid size
    }
    int sum = 0;
    for(int i=0;i<size;i++){
        if(array[i]%2==0){//checks if mod 2 is zero (no remainder)
            sum += array[i];//adds to sum
        }
    }
    *result = sum;//sum is stored
    return 0;
}