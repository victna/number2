/*
==============================================================
Name: Shawn Gurusinghe
Course: 1050
Section: A
Assignment: Lab 9
User: sg8c6
Files: lab9.c       
October 24th, 2025
==============================================================
*/
#include <stdio.h>
#include <string.h>
#define MAX 5
struct Animal {
    char name[30];
    int  age;
    char origin[30];
};
int addAnimal(struct Animal animals[], int *count, struct Animal newAnimal){//if no space returns 0, else adds and increments count
    if(*count >= MAX){
        return 0;
    }
    animals[*count] = newAnimal;
    (*count)++;
    return 1; 
}
void printAnimalsByOrigin(const struct Animal *animals, int count, const char *origin) {
    const struct Animal *p = animals;
    for (int i = 0; i < count; i++, p++) {
        if (strcmp(p->origin, origin) == 0) {
            printf("Name: %s Age: %d Origin: %s\n", p->name, p->age, p->origin);//prints attributes of struct (idk how to do whole structs)
        }
    }
}
void sortAnimalsByAge(struct Animal animals[], int count) {
    for (int i = 0; i < count - 1; i++) {//loops through max animals twice, reordering and checking within the nested loop
        for (int j = 0; j < count - 1 - i; j++) {
            if (animals[j].age > animals[j + 1].age) {
                struct Animal temp = animals[j];
                animals[j] = animals[j + 1];
                animals[j + 1] = temp;
            }
        }
    }
}
int findOldestFromOrigin(const struct Animal *animals, int count, const char *origin) {
    int oldestIndex = -1,oldestAge = -1;//indexing vars
    const struct Animal *p = animals;   // pointer to start
    for (int i = 0; i < count; i++, p++){//increments pointer and i
        if (strcmp(p->origin, origin) == 0){
            if (p->age > oldestAge) {
                oldestAge = p->age;
                oldestIndex = i;
            }
        }
    }
    return oldestIndex;
}
