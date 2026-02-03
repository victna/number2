#include <stdlib.h>
#include <stdio.h>
enum Status {
    STATUS_OK ,
    STATUS_WARNING ,
    STATUS_ERROR
};
struct Reading {
    int id ;
    double value ;
    enum Status status ;
};
struct Reading *createReadings(int count){
    if(count <= 0){
        return NULL;
    }
    struct Reading *p = malloc(count * sizeof(struct Reading));
    if (p == NULL) {
        return NULL; //check if successful
    }
    for (int i = 0; i < count; i++) {
        p[i].id = 0;
        p[i].value = 0.0f;
        p[i].status = STATUS_OK;
    }
    return p;
}
void initReading(struct Reading *r, int id, double value, enum Status status){
    if(r = NULL){   
        return;
    }
    r->id = 0;
    r->value = 0.0f;
    r->status = STATUS_OK;
    return;
}
int countByStatus(const struct Reading *readings, int count, enum Status status){
    if(readings == NULL || count <= 0){
        return 0;
    }
    int statusCount = 0;
    const struct Reading *p = readings;
    for (int i = 0; i < count; i++) {
        if (p->status == status) {
            statusCount++;
        }
        p++;
    }
    return statusCount;
}
void freeReadings(struct Reading *readings)
{
    if(readings != NULL){
        free(readings);
    }
}
struct Reading *filterByStatus(const struct Reading *readings, int count,enum Status status, int *outCount){
    if(readings == NULL || count <= 0 || outCount == NULL){
        return NULL;
    }
    int matchCount = 0;
    const struct Reading *p = readings;
    for (int i = 0; i < count; i++) {
        if (p->status == status) {
            matchCount++;
        }
        p++;
    }
    if(matchCount == 0){
        *outCount = 0;
        return NULL;
    }
    struct Reading *filteredReadings = malloc(matchCount * sizeof(struct Reading));
    if(filteredReadings == NULL){
        *outCount = 0;
        return NULL;
    }
    p = readings;
    struct Reading *q = filteredReadings;
    for (int i = 0; i < count; i++) {
        if (p->status == status) {
            *q = *p;
            q++;
        }
        p++;
    }
    *outCount = matchCount;
    return filteredReadings;
}