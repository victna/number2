#include <stdio.h>
#include <string.h>

#define MAX_ANIMALS 5   /* you can enforce the Animal size with this */

struct Animal {
    char name[30];
    int  age;
    char origin[30];
};

int addAnimal(struct Animal animals[], int *count, struct Animal newAnimal);
void printAnimalsByOrigin(const struct Animal *animals, int count, const char *origin);
void sortAnimalsByAge(struct Animal animals[], int count);

#ifdef HONORS
int findOldestFromOrigin(const struct Animal *animals, int count, const char *origin);
#endif