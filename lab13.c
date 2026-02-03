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
    #include <string.h>
    struct Student {
        char firstname[20];
        char lastname[20];
        float gpa;
    };
    void printStudentInfo(struct Student student );
    int addStudent(struct Student students[], int *count, struct Student newStudent);
    void printStudentsGPAGreaterThan(struct Student *students, int count, float greaterGPA);
    struct Student *findStudentWithMinGPA(struct Student students [] , int count );
    struct Student *findStudentWithMaxGPA(struct Student students [] , int count );
    void printStudentsWithName(struct Student *students, int count, const char *name);



    void printStudentInfo(struct Student student ){
        printf("First Name: %s Last Name: %s GPA: %.2f\n", student.firstname, student.lastname, student.gpa);
    }
    int addStudent(struct Student students[], int *count, struct Student newStudent){
        students[*count] = newStudent;
        (*count)++;
        return 1;
    }
    void printStudentsGPAGreaterThan(struct Student *students, int count, float greaterGPA){
        const struct Student *p = students;
        for (int i = 0; i < count; i++) {
            if (p->gpa > greaterGPA) {
                printStudentInfo(*p);
            }
            p++;
        }
    }
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
    }
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
    }
    void printStudentsWithName(struct Student *students, int count, const char *name){
        const struct Student *p = students;
        for (int i = 0; i < count; i++) {
            if (strcmp(p->firstname, name) == 0){
                printStudentInfo(*p);
            }
            p++;
        }
    }

