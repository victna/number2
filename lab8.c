#include <stdio.h>
int sumeven(int temp[]);
int sumodd(int temp[]);
int avgeven(int temp[]);
int avgodd(int temp[]);
void productarr(int temp[],int temp2[]);
int main(void){
    int arr[50];
    for(int i=0;i<50;i++){
        arr[i]=i*2;
    }
    for(int i=0;i<50;i++){
        printf("arr[%d]=%d ",i,arr[i]);
    }
    printf("\n\nsum of even intices: %d",sumeven(arr));
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
    return 0;
}
int sumeven(int temp[]){
    int sum=0;
    for(int i=0;i<50;i++){
        if(i%2==0){sum+=temp[i];}
    }
    return sum;
}
int sumodd(int temp[]){
    int sum=0;
    for(int i=0;i<50;i++){
        if(i%2==1){sum+=temp[i];}
    }
    return sum;
}
int avgeven(int temp[]){
    int avg=0;
    for(int i=0;i<50;i++){
        if(i%2==0){avg+=temp[i];}
    }
    avg=avg/25;
    return avg;
}
int avgodd(int temp[]){
    int avg=0;
    for(int i=0;i<50;i++){
        if(i%2==1){avg+=temp[i];}
    }
    avg=avg/25;
    return avg;
}
void productarr(int temp[],int temp2[]){
    for(int i=0;i<50;i++){
        printf("product[%d]=%d, ",i,temp2[i]*temp[i]);
    }
}