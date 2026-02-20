/*
==============================================================
Course: 1050
Section: A
Assignment: Lab 8
User: sg8c6
Files: lab8.c
October 17th, 2025
==============================================================
*/
#include <stdio.h>
int sumeven(int temp[]);//function prototypes
int sumodd(int temp[]);
int avgeven(int temp[]);
int avgodd(int temp[]);
void productarr(int temp[],int temp2[]);
int main(void){//main, intialize two arrs (int) and uses for loops to intialize values, and print values
    int arr[50];
    for(int i=0;i<50;i++){
        arr[i]=i*2;
    }
    for(int i=0;i<50;i++){
        printf("arr[%d]=%d ",i,arr[i]);
    }
    printf("\n\nsum of even intices: %d",sumeven(arr));//calling and formating all functions
    printf("\nsum of odd intices: %d",sumodd(arr));
    printf("\navg of even intices: %d",avgeven(arr));
    printf("\navg of odd intices: %d\n",avgodd(arr));

    int arr2[50];
    for(int i=0;i<50;i++){
        arr2[i]=i*2+1;
    }
    for(int i=0;i<50;i++){
        printf("arr[%d]=%d ",i,arr2[i]);
    }
    productarr(arr,arr2);
    return 0;//included just in case, terminate program
}
int sumeven(int temp[]){//sums all the even intices of the given arr temp
    int sum=0;
    for(int i=0;i<50;i++){
        if(i%2==0){sum+=temp[i];}
    }
    return sum;
}
int sumodd(int temp[]){//sums all the odd intices of the given arr temp
    int sum=0;
    for(int i=0;i<50;i++){
        if(i%2==1){sum+=temp[i];}
    }
    return sum;
}
int avgeven(int temp[]){//averages all the even intices of the given arr temp
    int avg=0;
    for(int i=0;i<50;i++){
        if(i%2==0){avg+=temp[i];}
    }
    avg=avg/25;
    return avg;
}
int avgodd(int temp[]){//averages all the odd intices of the given arr temp
    int avg=0;
    for(int i=0;i<50;i++){
        if(i%2==1){avg+=temp[i];}
    }
    avg=avg/25;
    return avg;
}
void productarr(int temp[],int temp2[]){//multiplies the intices of the given arrs temp and temp2
    for(int i=0;i<50;i++){
        printf("product[%d]=%d, ",i,temp2[i]*temp[i]);
    }
}