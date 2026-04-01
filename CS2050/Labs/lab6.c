/*
==============================================================
Name: Shawn Gurusinghe
Course: 2050
Section: A
Assignment: Lab 6
User: sg8c6
Files: lab6.c
March 6th, 2026
==============================================================
*/
#include <stdio.h>
#include <stdlib.h>
//typedef
typedef struct Node{
    int data;
    struct Node* next;
} Node;
//helper functions
Node *createNode(int data) {
    Node *p;
    p = malloc(sizeof(Node));
    if(p){
        p->data = data;
        p->next = NULL;
    }
    return p;
}
Node *Insert(int data, Node *first){
    Node *p;
    p = createNode(data);
    if(!p) return first;

    p->next = first;
    return p;
}
Node* addItem(Node *list, int data) {
    Node *p;
    p = createNode(data);
    if (!p) {
        return list;
    }
    p->next = list;
    return p;
}
int countNodes(Node* head){
    int count = 0;
    for(Node* current = head; current != NULL; current = current->next){//increments through the list until null is found, counting how many nodes are in the list
        count++;
    }
    return count;
}
//lab functions
Node* initList(){
    Node* dummy = createNode(0);//creates a dummy node to act as the "head" of the list, intialized with a data value of 0
    if(dummy == NULL){//checks if the dummy node was successfully created
        perror("Memory allocation failed (line 57)");
        return NULL;
    }
    return dummy;//returns a pointer to the dummy node
}
void freeList(Node* dummy){
    if(!dummy){
        perror("Invalid dummy pointer (line 64)");
        return;//checks if dummy pointer is valid, if not, does nothing
    }
    Node* head = dummy->next;//creates a working copy of the real head
    while(head != NULL){//increments through the list until null is found, freeing each node as it goes
        Node* temp = head;//creates a temporary pointer to hold the current node
        head = head->next;//moves the dummy pointer to the next node
        free(temp);//frees the current node
    }
    free(dummy);//frees the dummy node at the end
}
int countOccurrences(Node* dummy, int value){
    if(!dummy){//checks if the dummy pointer is null, if so, returns 0 to indicate failure
        perror("Invalid dummy pointer (line 77)");
        return 0;
    }
    int count = 0;
    for(Node* current = dummy->next; current != NULL; current = current->next){//increments through the list until null is found, counting how many nodes have a data value equal to the given value
        if(current->data == value){
            count++;
        }
    }
    return count;
}
int getNthItem(Node* dummy, int n, int *error){
    if(!dummy || !error){//checks if the dummy pointer or error pointer is null, if so, returns 0 to indicate failure
        perror("Invalid dummy or error pointer (line 90)");
        if(error) *error = 1;//sets the error flag to indicate failure
        return 0;
    }
    if(n < 0||n >= countNodes(dummy->next)){//checks if n is negative or out of bounds, if so, returns 0 to indicate failure
        perror("Invalid index provided (line 95)");
        *error = 1;//sets the error flag to indicate failure
        return 0;
    }
    int i = 0;//creates a working counter variable to keep track of how many nodes have been passed
    for(Node* current = dummy->next; current != NULL; current = current->next){//increments through the list until null is found, counting how many nodes have been passed
        if(i == n){//if i is n, it means the current node is the nth node, so we return its data value
            *error = 0;
            return current->data;
        }
        i++;//increments i for each node passed
    }
    perror("Index out of bounds (line 107)");
    *error = 1;//sets the error flag to indicate failure
    return 0;//returns 0 to indicate failure
}
int insertAfter(Node* dummy, int target, int value){
    if(!dummy){//checks if the dummy pointer is null, if so, returns 0 to indicate failure
        perror("Invalid dummy pointer (line 113)");
        return 0;
    }
    Node* newNode = createNode(value);//creates a new node with the given value, checks if it was successfully created
    if(!newNode){
        perror("Memory allocation failed (line 118)");
        return 0;
    }
    Node* lastNode = NULL;
    for(Node* current = dummy->next; current != NULL; current = current->next){//increments through the list until null is found, looking for a node with a data value equal to the target value
        if(current->data == target){
            newNode->next = current->next;//if a node with the target value is found, we insert the new node after it by updating the next pointers accordingly
            current->next = newNode;
            return 1;//returns 1 to indicate success
        }
        lastNode = current;//keep track of the last node
    }
    if(lastNode == NULL){
        dummy->next = newNode;//if the list is empty, insert at the beginning
    } else {
        lastNode->next = newNode;//if we reach the end of the list without finding the target value, we insert the new node at the end of the list
    }
    return 1;//returns 1 to indicate success
}
int removeAllOccurences(Node* dummy, int value){
    if(!dummy){//checks if the dummy pointer is null, if so, returns -1 to indicate failure
        perror("Invalid dummy pointer (line 139)");
        return 0;
    }
    int count = 0;
    while(countOccurrences(dummy, value) > 0){//while there are still nodes with the target value in the list, we keep trying to remove them
        for(Node* current = dummy->next, *prev = dummy; current != NULL; prev = current, current = current->next){//increments through the list until null is found, looking for nodes with a data value equal to the given value
        //additionally stores both current and current's previous node to make removal easier
            if(current->data == value){
                prev->next = current->next;//if a node with the target value is found, we remove it from the list by updating the previous node's next pointer to skip over the current node
                free(current);//frees the removed node
                count++;//increments the count of removed nodes
                break;//breaks out of the for loop to start over, in case there are multiple nodes with the target value
            }
        }
    }
    if(count == 0){
        perror("Value not found in list (line 155)");
        return 0;//if no nodes with the target value are found, we return 0 to indicate failure
    }
    return count;
}