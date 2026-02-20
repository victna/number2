/*
==============================================================
Name: Shawn Gurusinghe
Course: 2050
Section: A
Assignment: Lab 4
User: sg8c6
Files: lab4.c
Febuary 20th, 2026
==============================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ** allocateJagged2DArray(int elementSize, int rows, int lengths[]){
    if(elementSize<=0||rows<=0){//first checks if element size and rows are valid 
        perror("Invalid element size or row count (line 17)");
        return NULL;//failed
    }
    for(int i=0;i<rows;i++){//checks each row if each length is valid
        if(lengths[i]<=0){
            perror("Invalid row length (line 22)");
            return NULL;//failed
        }
    }
    void** jagged2DArray = malloc((rows+1)*sizeof(void*));//creates the array of pointers to rows
    if(jagged2DArray == NULL){//checks if the array of pointers was successfully allocated
        perror("Failed to allocate array (line 28)");
        return NULL;//failed
    }
    for(int i=0;i<rows;i++){
        //allocate extra space to store the column length before the row data
        int totalBytes = sizeof(int) + lengths[i]*elementSize;
        char *raw = malloc(totalBytes);//allocates each row with the appropriate length and element size

        if(raw == NULL){//checks if the row was successfully allocated, frees if unsuccessful
            for(int j=0;j<i;j++){
                //free using stored metadata before each row pointer
                char *ptr = (char*)jagged2DArray[j];
                free(ptr - sizeof(int));
            }
            free(jagged2DArray);
            perror("Failed to allocate row (line 43)");
            return NULL;//failed
        }
        //store length metadata
        *((int*)raw) = lengths[i];
        //store pointer AFTER metadata
        jagged2DArray[i] = raw + sizeof(int);
    }
    //sentinel for row counting
    jagged2DArray[rows] = NULL;
    return jagged2DArray;//returns the void pointer to the allocated jagged 2D array
}

void freeJagged2DArray(void ** jagged2DArray){
    if(jagged2DArray == NULL){//first checks if the pointer is valid
        perror("Invalid pointer (line 63)");
        return;//failed
    }
    for(int i=0;jagged2DArray[i]!=NULL;i++){
        /* move back to beginning of allocation before freeing */
        char *ptr = (char*)jagged2DArray[i];
        free(ptr - sizeof(int));//goes row by row and frees each row until it reaches the end of the array of pointers, then frees the array of pointers itself
    }
    free(jagged2DArray);//frees the array of pointers itself
}

//getters
int getRowCount(void ** jagged2DArray){
    if(jagged2DArray == NULL){//first checks if the pointer is valid
        perror("Invalid pointer (line 72)");
        return 0;//failed
    }
    int count = 0;
    for(int i=0;jagged2DArray[i]!=NULL;i++){
        count++;
    }
    return count;//returns the number of rows by counting until it reaches the sentinel value of NULL in the array of pointers
}

int getColCount(void ** jagged2DArray, int row){
    if(jagged2DArray == NULL || row < 0){//first checks if the pointer is valid and row is valid
        perror("Invalid pointer or row index (line 84)");
        return 0;
    
    }
    if(jagged2DArray[row] == NULL){
        perror("Invalid row index (line 89)");
        return 0;
    }

    /* retrieve stored metadata */
    char *ptr = (char*)jagged2DArray[row];
    int length = *((int*)(ptr - sizeof(int)));

    return length;
}

//struct and typedef for Course ADT
struct _Course{
    int number;
    char department[64], name[64];
};
typedef struct _Course Course;

//constructor
Course * createCourse(int number, char * department, char * name){
    if(number<=0||department==NULL||name==NULL){//checks if the values are valid
        perror("Invalid course information (line 110)");
        return NULL;
    }
    Course * newCourse = malloc(sizeof(Course));//allocates memory for the course struct
    if(newCourse == NULL){//checks if the memory was successfully allocated
        perror("Failed to allocate course (line 115)");
        return NULL;
    }
    newCourse->number = number;//sets the course number

    newCourse->department[0] = '\0';//initializes the department string to be empty
    strncat(newCourse->department, department, 63);//copies the department string into the struct, ensuring it does not exceed the maximum length

    newCourse->name[0] = '\0';//initializes the name string to be empty
    strncat(newCourse->name, name, 63);//copies the name string into the struct, ensuring it does not exceed the maximum length

    return newCourse;//returns a pointer to the newly created course struct
}

//destructor
void freeCourse(Course * pCourse){
    free(pCourse);
}

//getters
int getCourseInfo(Course * pCourse, char * outputString){
    if(pCourse==NULL||outputString==NULL){//checks if pointer and value are valid
        perror("Invalid pointer (line 137)");
        return 0;//failed
    }
    sprintf(outputString, "%s %d: %s", pCourse->department, pCourse->number, pCourse->name);//formats the course information into the output string in the format "DEPARTMENT NUMBER: NAME"
    return 1;
}

//setters
int setCourseNumber(Course * pCourse, int number){
    if(pCourse == NULL||number<=0){//checks if pointer or value are valid
        perror("Invalid pointer or course number (line 147)");
        return 0;//failed
    }
    pCourse->number = number;//sets the course number to number
    return 1;
}

int setCourseDepartment(Course * pCourse, char * department){
    if(pCourse == NULL || department == NULL){//checks if pointer and value are valid
        perror("Invalid pointer or department (line 156)");
        return 0;//failed
    }
    pCourse->department[0] = '\0';
    strncat(pCourse->department, department, 63);//concatenates the new department to course department string
    return 1;
}

int setCourseName(Course * pCourse, char * name){
    if(pCourse == NULL || name == NULL){//checks if pointer and value are valid
        perror("Invalid pointer or name (line 166)");
        return 0;//failed
    }
    pCourse->name[0] = '\0';
    strncat(pCourse->name, name, 63);//concatenates the new name to course name string
    return 1;
}
