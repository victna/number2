/*
==============================================================
Course: 1050
Section: A
Assignment: Lab 6
User: sg8c6
Files: lab6.c
October 3rd, 2025
==============================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int count_digits(int n);//function prototypes
int sum_digits(int n);
int is_vowel(char c);
int gcd(int a, int b);
int main(void){//main function
    printf("Enter two integers:\n");
    int a,b;//stores integers as a and b for gcd function
    scanf(" %d %d",&a,&b);
    printf("\nThe GCD of %d and %d is %d\n",a,b,gcd(a,b));
    printf("Enter a letter:\n");
    char c;//stores character as c for is_vowel function
    scanf(" %c",&c);
    is_vowel(c)?printf("\n%c is a vowel\n",c):printf("%c is not a vowel\n",c);
    printf("Enter an integer:\n");
    int n;//stores integer as n for count_digits and sum_digits functions
    scanf(" %d",&n);
    printf("\nThe number of digits in %d is %d\n",n,count_digits(n));
    printf("\nThe sum of the digits in %d is %d\n",n,sum_digits(n));

    return 0;
}
int gcd(int a, int b){//function to find gcd of two integers
    bool solved = false;
    while(!solved){//runs loop until gcd is found (terminates with return statement)
        a=abs(a);//gets absolute values of a and b ensures always positive
        b=abs(b);
        if(a==0||b==0) return 0;
        for(int r=(a>b?b:a);r>=0;r--){//starts with the smaller of a and b and decrements until it finds gcd
            if(a%r==0 && b%r==0){//if r divides both a and b, it is the gcd
                return r;
            }
        }
        return 0;
    }
    return 0;//not really need but included just in case
}
int is_vowel(char c){
    switch(c){//no break statements needed since return exits function and switch statement
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U': return 1;
        default: return 0;//returns 0 if not a vowel
    }
    return 0;//not really need but included just in case
}
int count_digits(int n){//function to count number of digits in an integer
    n=abs(n);//gets absolute value of n to ensure always positive
    if(n==0) return 1;//special case for 0
    int count = 0;//counter determines number of digits
    while(n!=0){
        n/=10;//simple division by 10 to remove last digit, repeat until n is 0 (last digit removed)
        count++;
    }
    return count;
}
int sum_digits(int n){//function to sum digits of an integer
    n=abs(n);//gets absolute value of n to ensure always positive
    int sum = 0;//sum variable to store sum of digits
    while(n!=0){//loops until n is 0 (last digit removed)
        sum+=n%10;//same as earlier but adds last digit to sum variable
        n/=10;
    }
    return sum;
}
