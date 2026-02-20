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
void ** allocatedJagged2DArray(int elementSize, int rows, int lengths[]){
    if(elementSize<=0){
            return NULL;
    }
    for(int i=0;i<rows;i++){
        if(lengths[i]<=0){
            return NULL;
        }
    }
    void** jagged2DArray = malloc(rows*sizeof(void*));
    if(jagged2DArray == NULL){
        return NULL;
    }
    for(int i=0;i<rows;i++){
        jagged2DArray[i] = malloc(lengths[i]*elementSize);
        if(jagged2DArray[i] == NULL){
            for(int j=0;j<i;j++){
                free(jagged2DArray[j]);
            }
            free(jagged2DArray);
            return NULL;
        }
    }
    return jagged2DArray;
}
void freeJagged2DArray(void ** jagged2DArray){

}
int getRowCount(void ** jagged2DArray){

}
int getColCount(void ** jagged2DArray, int row){

}
struct _Course{
    int number;
    char department[64], name[64];
};
typedef struct _Course Course;

Course * createCourse(int number, char * department, char * name);

void freeCourse(Course * pCourse){
    free(pCourse);
}

int getCourseInfo(Course * pCourse, char * outputString){
    if(pCourse==NULL||outputString==NULL){//checks if pointer and value are valid
        return 0;//failed
    }
    sprintf(outputString, "%s %d: %s", pCourse->department, pCourse->number, pCourse->name);
}

int setCourseNumber(Course * pCourse, int number){
    if(pCourse == NULL||number<=0){//checks if pointer or value are valid
        return 0;//failed
    }
    pCourse->number = number;
    return 1;
}
int setCourseDepartment(Course * pCourse, char * department){
    if(pCourse == NULL || department == NULL){//checks if pointer and value are valid
        return 0;//failed
    }
    pCourse->department[0] = '\0';
    strncat(pCourse->department, department, 63);
    return 1;
}
int setCourseName(Course * pCourse, char * name){
    if(pCourse == NULL || name == NULL){//checks if pointer and value are valid
        return 0;//failed
    }
    pCourse->name[0] = '\0';
    strncat(pCourse->name, name, 63);
    return 1;
}
