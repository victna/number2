#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void){
    printf("Challenge A:\n");
    for(int i=0;i<10;i++){
        printf("%i\n",(int)(pow(3,i)));
    }
    printf("Challenge B:\n");
    char input[1];
    printf("Pick one of the following riddles:\n\tA: What has keys but can't open locks?\n\tB: What has a head and a tail but no body?\n\tC: \nYour choice: ");
    return 0;
}