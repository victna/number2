#include <stdio.h>
#include "lab9.h"
int main(void){
    int image[5][5];
    initializeImage(image);
    drawPixel(image,2,2);
    drawPixel(image,1,4);
    drawPixel(image,2,3);
    drawPixel(image,4,0);
    displayImage(image);
    rotateRight(image);
    displayImage(image);
    invertImage(image);
    displayImage(image);
    flipRow(image,1);
    displayImage(image);
    flipColumn(image,3);
    displayImage(image);
    clearImage(image);
    displayImage(image);
    return 0;
}