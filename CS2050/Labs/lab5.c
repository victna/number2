/*
==============================================================
Name: Shawn Gurusinghe
Course: 2050
Section: A
Assignment: Lab 5
User: sg8c6
Files: lab5.c
Feburary 27th, 2026
==============================================================
*/
#include <stdio.h>
#include <stdlib.h>

/* Linked list definitions */
typedef int Key;

typedef struct nodestruct {
    Key item;
    struct nodestruct *next;
} Node;

Node *first=NULL, *p;

/* Prelab functions */
Node *createNode(Key item) {
    Node *p;
    p = malloc(sizeof(Node));
    if(p){
        p->item = item;
        p->next = NULL;
    }
    return p;
}

Node *Insert(Key info, Node *first){
    Node *p;
    p = createNode(info);
    if(!p) return first;

    p->next = first;
    return p;
}

Node* addItem(Node *list, Key item) {
    Node *p;
    p = createNode(item);
    if (!p) {
        return list;
    }
    p->next = list;
    return p;
}

//lab functions
int countNodes(Node* head);//prototype for countNodes, because it is used in some of the other functions before its definition
Node* initList(){
    return NULL;//returns an empty list, aka a null pointer
}
Node* moodyInsert(Node* head, int value, int *error){
    if(error == NULL){//if error pointer is null, return head without modifying it, indicating failure
        return head;
        perror("Invalid error pointer (line 63)");
    }
    *error = 0;
    if(value < 0){//if value is negative, set error to 1 and return head without modifying it, indicating failure
        *error = 1;
        perror("Negative value provided (line 68)");
        return head;
    }
    Node *newNode = createNode(value);//creates a new node with the given value, checks if it was successfully created
    if(!newNode){
        *error = 1;
        perror("Memory allocation failed (line 74)");
        return head;
    }
    if(value % 2 != 0){//if odd, insert at head
        newNode->next = head;
        return newNode;
    }//if even, insert at tail
    if(head == NULL){//checks if the list is empty, if so, new node becomes the head (not necesary for other case)
        return newNode;
    }
    Node* current = NULL;
    for(current = head; current->next != NULL; current = current->next);//increments until null is found
    current->next = newNode;//adds new node to the end of the list
    return head;
}
int removeNElementsFromTail(Node* head, int numOfElems){
    if(head == NULL || numOfElems <= 0){//checks if the list is empty or if the number of elements to remove is invalid, returns -1 to indicate failure
        perror("Invalid head pointer or number of elements (line 91)");
        return -1;
        
    }
    if(numOfElems >= countNodes(head)){//checks if the number of elements to remove is greater than the number of nodes in the list, returns 0 to indicate failure
        perror("Number of elements to remove exceeds list length (line 96)");
        return 0;
    }
    for(int i = 0; i < numOfElems; i++){
        Node* current = head;//creates a working copy of head
        Node* prev = NULL;//creates a pointer to keep track of the previous node, initialized to null
        while(current->next != NULL){//increments until null is found, updating prev and current pointers
            prev = current;
            current = current->next;
        }
        if(prev == NULL){//if prev is null after, it means there was only one node in the list, so we free the head and set it to null
            free(head);
            head = NULL;
        } else {//if prev is not null, we free the current tail and set the prevs next pointer to null, effectively removing the tail from the list
            free(current);
            prev->next = NULL;
        }
    }
    return 1;//returns 1 to indicate success
}

void printList(Node* head){
    for(Node* current = head; current != NULL; current = current->next){//increments until null is found, printing each node's item value
        printf("%d ", current->item);
    }
    printf("\n");
}

int listContains(Node* head, int value){
    for(Node* current = head; current != NULL; current = current->next){//increments until null is found, checking if any node's item value matches the given value, returns 1 if a match is found
        if(current->item == value){
            return 1;
        }
    }
    return 0;//no matches found, returns 0
}
int countNodes(Node* head){
    int count = 0;
    for(Node* current = head; current != NULL; current = current->next){//increments loop until null is found, returns count
        count++;
    }
    return count;
}

void freeList(Node* head){
    if(head == NULL){//checks if head pointer is null, if so, there is nothing to free
        perror("Invalid head pointer (line 142)");
        return;
    }
    Node* current = head;//working copy of head pointer to increment through the list
    while(current != NULL){
        Node* temp = current;//creates temp pointer to node before incrementing, to prevent loss of prev pointer
        current = current->next;
        free(temp);
    }
}