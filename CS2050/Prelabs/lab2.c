#include <stdio.h>
#include <stdlib.h>
float * copyFloatArray(float inputArray[], int * outputLength){
    if(inputArray==NULL||outputLength==NULL){
        return NULL;
    }
    if(*outputLength<=0){
        *outputLength=0;
        return NULL;
    }
    float *outputArray = (float*)malloc(*outputLength * sizeof(float));
    if(outputArray==NULL){
        *outputLength=0;
        return NULL;
    }
    for(int i=0;i<*outputLength;i++){
        outputArray[i]=inputArray[i];
    }
    return outputArray;
}