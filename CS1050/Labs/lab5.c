#include <stdbool.h>
#include <stdio.h>
#include <math.h>
//import boolean, math, and standard library
void menu(void);
int main(void){
    bool running = true;
    //creates a boolean value that runs the loop until boolean is declared false
    while(running){
        menu();//custom print method to improve readability
        int input;
        printf("\nEnter your choice:\n");
        scanf(" %d", &input);//stores input variable to select choice which is reused later
        switch(input){
            case 1:
                printf("\ncomputing the area of one or more circles\nhow many circles?\n");
                if(input<1){continue;}//if input isnt a positive number greater than 0, skip
                scanf(" %d",&input);
                int r;
                for(int i=0;i<input;i++){//loops based off how many circles the user decides
                    printf("\nRadius #%d:\n",i+1);//asks and stores radius as local temp var
                    scanf(" %d",&r);
                    float pi = 3.14159;
                    printf("\nArea #%d:\n%f",i+1,pi*pow(r,2));//prints the area as radius*pi^2
                }
                break;
            case 2:
                printf("\ncomputing the area of a rectangle\nLength:\n");
                int x,y;//asks for x and y of rectangle and stores them as local vars x and y
                scanf(" %d",&x);
                printf("\nHeight:\n");
                scanf(" %d",&y);
                printf("\nArea:\n%d",x*y);//computes area as x*y
                break;
            case 3:
                printf("\ncomputing the area of a triangle with Heron's formula:\nenter sides A B and C:\n");
                int a,b,c,s;//asks for a b and c sides of triangle, creates s
                scanf("%d %d %d", &a, &b, &c);
                bool valid = (a+b>c&&b+c>a&&a+c>b);//boolean to determine if triangle is valid
                printf((valid?"\ntriangle is valid\n":"\ntriangle is not valid\n"));
                if(valid){
                    s=(a+b+c)/2;
                    printf("Area:\n%f",(sqrt(s*(s-a)*(s-b)*(s-c))));
                }//if valid compute if not dont
                break;
            case 4:
                printf("\ncomputing the area of a square:\nenter a side:\n");
                scanf(" %d",&input);
                printf("\nPerimeter:\n%d",4*input);//stores side length and prints area as 4*s
                break;
            case 5:
                printf("\ndetermining if prime:\nenter a number:\n");
                scanf(" %d",&input);
                if(input<2){
                    printf("\n%d is not a prime number\n",input);
                    continue;
                }
                bool valid2 = true;
                for(int i=2;i<=sqrt(input);i++){
                    if(input%i==0){
                        valid2=false;
                    }
                }
                printf("\n%d",input);
                printf(valid2?" is a prime number\n":" is not a prime number\n");
                break;
            case 6:
                running = false;
                printf("\nExiting the program.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}
void menu(void){
    printf("\n1 -> compute the area of one or more circles\n");
    printf("2 -> compute the area of a rectangle\n");
    printf("3 -> compute the area of a triangle using herons formula\n");
    printf("4 -> compute the perimeter of a square\n");
    printf("5 -> check if a number is prime\n");
    printf("6 -> exit the program\n");
}