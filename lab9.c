#include "lab9.h"
#define SIZE 5
#include <stdio.h>
/*
==============================================================
Course: 1050
Section: A
Assignment: Lab 9
User: sg8c6 (Shawn Gurusinghe)
Files: lab9.c       
October 24th, 2025
==============================================================
*/
void initializeImage(int image[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image[i][j] = 0;//intialize all pixels to 0
        }
    }
}
int drawPixel(int image[SIZE][SIZE], int row, int col){
    if(row<0||row>=SIZE||col<0||col>=SIZE){
        return -1; //indice out of bounds
    }
    image[row][col] = 1;
    return 0; //success
}
void invertImage(int image[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            switch(image[i][j]){
                case 0://if zero flips to one
                    image[i][j] = 1;
                    break;
                case 1://if one flips to zero
                    image[i][j] = 0;
                    break;
                default:
                    break;//not needed but here just in case
            }
        }
    }
}
int flipRow(int image[SIZE][SIZE], int row){
    if(row<0||row>=SIZE){
        return -1; //indice out of bounds
    }
    for(int i=0;i<SIZE;i++){
        switch(image[row][i]){
            case 0://if zero flips to one
                image[row][i] = 1;
                break;
            case 1://if one flips to zero
                image[row][i] = 0;
                break;
            default:
                break;//not needed but here just in case
        }
    }
    return 1;//success
}
int flipColumn(int image[SIZE][SIZE], int col){
    if(col<0||col>=SIZE){
        return -1; //indice out of bounds
    }
    for(int i=0;i<SIZE;i++){
        switch(image[i][col]){
            case 0://if zero flips to one
                image[i][col] = 1;
                break;
            case 1://if one flips to zero
                image[i][col] = 0;
                break;
            default:
                break;//not needed but here just in case
        }
    }
    return 1;//success
}
void clearImage(int image[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image[i][j]=0;//sets all pixels to 0 (resets)
        }
    }
}
void displayImage(int image[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            printf("%d ",image[j][i]);//prints each pixel value
        }
        printf("\n");//new line after each row is printed
    }
    printf("\n");
}
void rotateRight(int image[SIZE][SIZE]){
    int tempImage[SIZE][SIZE];
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            tempImage[j][i]=image[i][j];//copies original image to temp image (but flips rows and columns)
        }
    }
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE/2;j++){
            int temp=tempImage[i][j];//stores current pixel from temp image
            tempImage[i][j]=tempImage[i][4-j];//swaps pixel with opposite pixel in row
            tempImage[i][4-j]=temp;//sets opposite pixel to stored pixel
        }
    }
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image[i][j]=tempImage[i][j];//copies temp image back to original image
        }
    }
}
