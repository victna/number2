#include <stdbool.h>
#include <stdio.h>
void menu(void);
int main(void){
    bool running = true;
    while(running){
        menu();
        int input;
        printf("Enter your choice: ");
        scanf("%d", &input);
        switch(input){
            case 1:
                printf("finding factorial of number...\nenter a positive integer:\t");
                scanf("%d", &input);
                if(input>0){
                    bool complete = false;
                    int value = 1,index=0;
                    while(!complete){
                        index++;
                        value *= index;
                        if(index==input){
                            printf("The factorial of %d is %d\n",input,value);
                            complete = true;
                        } else {
                            printf("Invalid input.\n");
                            complete = true;
                        }
                    }
                } else {
                    printf("Invalid input.\n");
                }
                break;
            case 2:
                printf("printing fibbonacci sequence...\nenter a positive integer:\t");
                scanf("%d", &input);
                if(input>0){
                    int t1 = 0, t2 = 1, nextTerm;
                    printf("Fibonacci Series: %d, %d, ", t1, t2);
                    for (int i = 3; i <= input; ++i) {
                        nextTerm = t1 + t2;
                        printf("%d, ", nextTerm);
                        t1 = t2;
                        t2 = nextTerm;
                    }
                    printf("\n");
                } else {
                    printf("Invalid input.\n");
                }
                break;
            case 3:
                printf("You chose option 3\n");
                break;
            case 4:
                printf("You chose option 4\n");
                break;
            case 5:
                running = false;
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
void menu(void){
    printf("1 -> find the factorial of a postitive number\n");
    printf("2 -> print the fibonacci sequence all the way to the nth term\n");
    printf("3 -> calculate the sum of the first n natural numbers\n");
    printf("4 -> test number properties using logical operators\n");
    printf("5 -> exit the program\n");
}