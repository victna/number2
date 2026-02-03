#include <stdio.h>
int main(void){
    int n[10];
    for(int i=0;i<10;i++){
        n[i]=0;
    }
    for(int i=0;i<10;i++){
        printf("%7d%13d\n",i,n[i]);
    }
    return 0;
}