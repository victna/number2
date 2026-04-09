#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int Key;
typedef struct nodestruct {
    Key item;
    struct nodestruct *next;
} Node;
Node *first=NULL, *p;
Node *createNode(Key item) {
    Node *p;
    p = malloc(sizeof(Node));
    if(p){
        p->item = item;
        p->next = NULL;
    }
    return(p);
}
Node *Insert(Key info, Node *first){
    Node *p;
    p = createNode(info);
    p->next = first;
    return(p);
}
Node*addItem(Node *list, Key item) {
Node *p;
p = createNode(item);
if (!p) {
    perror("Memory allocation failed");
    return(list);
}
p->next = list;
return(p);
}