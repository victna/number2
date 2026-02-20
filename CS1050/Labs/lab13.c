/*
==============================================================
Name: Shawn Gurusinghe
Course: 1050
Section: A
Assignment: Lab 13
User: sg8c6
Files: lab13.c       
November 21th, 2025
==============================================================
*/
#include <stdio.h>
#include <string.h>//imported libaries
struct Student{//student struct
    char firstname[20];
    char lastname[20];
    float gpa;
};//function prototypes
void printStudentInfo(struct Student student );
int addStudent(struct Student students[], int *count, struct Student newStudent);
void printStudentsGPAGreaterThan(struct Student *students, int count, float greaterGPA);
struct Student *findStudentWithMinGPA(struct Student students [] , int count );
struct Student *findStudentWithMaxGPA(struct Student students [] , int count );
void printStudentsWithName(struct Student *students, int count, const char *name);
int main(void){
    return 0;
}//main func to avoid errors
void printStudentInfo(struct Student student ){
    printf("First Name: %s Last Name: %s GPA: %.2f\n", student.firstname, student.lastname, student.gpa);
}//literally reads all attributes of student struct and prints
int addStudent(struct Student students[], int *count, struct Student newStudent){
    students[*count] = newStudent;
    (*count)++;
    return 1;
}//increments count to max+1 and stores newstudent there
void printStudentsGPAGreaterThan(struct Student *students, int count, float greaterGPA){
    const struct Student *p = students;
    for (int i = 0; i < count; i++) {
        if (p->gpa > greaterGPA) {
            printStudentInfo(*p);
        }
        p++;
    }
}//increments through array, if student gpa is higher than greater gpa, print student
struct Student* findStudentWithMinGPA(struct Student students [], int count){
    if(count == 0){
        return NULL;
    }
    struct Student *minGPAStudent = &students[0];
    for (int i = 0; i < count; i++) {
        if (students[i].gpa < minGPAStudent->gpa) {
            minGPAStudent = &students[i];
        }
    }
    return minGPAStudent;
}//increments through every student, notes lowest until whole array is looped, returns final result
struct Student* findStudentWithMaxGPA(struct Student students [], int count){
    if (count == 0) {
        return NULL;
    }
    struct Student* maxGPAStudent = &students[0];
    for (int i = 0; i < count; i++) {
        if (students[i].gpa > maxGPAStudent->gpa) {
            maxGPAStudent = &students[i];
        }
    }
    return maxGPAStudent;
}//increments through every student, notes highest until whole array is looped, returns final result
void printStudentsWithName(struct Student *students, int count, const char *name){
    const struct Student *p = students;
    for (int i = 0; i < count; i++) {
        if (strcmp(p->firstname, name) == 0){
            printStudentInfo(*p);
        }
        p++;
    }
}//checks (with strcmp) for matches with firstname and name, if matched, print student

