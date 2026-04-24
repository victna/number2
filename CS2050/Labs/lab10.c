/*
==============================================================
Name: Shawn Gurusinghe
Course: 2050
Section: A
Assignment: Lab 10
User: sg8c6
Files: lab10.c
April 17th, 2026
==============================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "lab10.h"
/*
typedef struct BSTNode{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;
typedef struct BST{
    BSTNode *root;
    int size;
} BST;
*/
//first prototypes of helper functions
BSTNode* createNode(int data);
int getHeightHelper(BSTNode *node);
int isValidHelper(BSTNode *node, int *min, int *max);
void freeHelper(BSTNode *node);
//lab functions
BST* initBST(){
    BST *tree = malloc(sizeof(BST));//attenpts to allocate memory for a new BST structure
    if(!tree){
        perror("Memory allocation failed (line 36)");
        return NULL;
    }
    tree->root = NULL;//initializes the root pointer to NULL and size to 0, indicating an empty tree
    tree->size = 0;
    return tree;//returns a pointer to the new tree
}
int insertBST(BST *tree, int data){
    if(!tree){//first checks if the tree pointer is valid, if not, returns 0 to indicate failure
        perror("Invalid tree pointer (line 45)");
        return 0;
    }
    BSTNode *newNode = createNode(data);
    if(!newNode){//checks if the allocation was successful, if not, returns 0 to indicate failure
        perror("Memory allocation failed (line 50)");
        return 0;
    }
    if(tree->root == NULL){//checks if the tree is empty, if so, new node is the new root node
        tree->root = newNode;
        tree->size++;//increments the size of the tree to reflect the addition of the new node
        return 1;
    }
    BSTNode *current = tree->root;
    while(current != NULL){//if tree is not empty, then we must traverse the tree to find the proper location for the new node
        if(data < current->data){//uses binary search to traverse the tree, comparing the new data value to the current node's data value to determine whether to go left or right
            if(current->left == NULL){//inserts the new node as a left child if the left child pointer is NULL, and increments the tree size, then returns 1 to indicate success
                current->left = newNode;
                tree->size++;
                return 1;
            }
            current = current->left;
        } else if(data > current->data){//otherwise, we go right
            if(current->right == NULL){
                current->right = newNode;
                tree->size++;
                return 1;
            }
            current = current->right;
        } else {//duplicate value, insert as left child
            if(current->left == NULL){
                current->left = newNode;
                tree->size++;
                return 1;
            }
            current = current->left;
        }
    }
    return 0;
}
int getHeightBST(BST *tree){
    if(!tree){//checks if the tree pointer is valid, if not, returns -1 to indicate an error
        perror("Invalid tree pointer (line 87)");
        return -1;
    }
    return getHeightHelper(tree->root);//calls a helper function to recursively calculate the height of the tree, starting from the root node, and returns the result
}
int getHeightHelper(BSTNode *node){
    if(node == NULL){//checks if the current node is NULL, which means we have reached a leaf node, so we return -1 to indicate that the height of an empty subtree is -1
        return -1;
    }
    int leftHeight = getHeightHelper(node->left);//recursively calculates the height of the left subtree
    int rightHeight = getHeightHelper(node->right);//recursively calculates the height of the right subtree
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;//returns the maximum of the left and right subtree heights plus one to account for the current node
}
int getMinimum(BST *tree){
    if(!tree){//checks if the tree pointer is valid, if not, returns -1 to indicate an error
        perror("Invalid tree pointer (line 102)");
        return -1;
    }
    if(tree->root == NULL){//checks if the tree is empty, if so, returns -1 to indicate an error
        perror("Tree is empty (line 106)");
        return -1;
    }
    BSTNode *current = tree->root;//starts at the root node and traverses down the left child pointers until it reaches a leaf node, which will be the minimum value in the tree, then returns that value
    while(current->left != NULL){
        current = current->left;
    }
    return current->data;
}
int getMaximum(BST *tree){
    if(!tree){//checks if the tree pointer is valid, if not, returns -1 to indicate an error
        perror("Invalid tree pointer (line 117)");
        return -1;
    }
    if(tree->root == NULL){//checks if the tree is empty, if so, returns -1 to indicate an error
        perror("Tree is empty (line 121)");
        return -1;
    }
    BSTNode *current = tree->root;//starts at the root node and traverses down the right child pointers until it reaches a leaf node, which will be the maximum value in the tree, then returns that value
    while(current->right != NULL){
        current = current->right;
    }
    return current->data;
}
int isValidBST(BST *tree){
    if(!tree){//checks if the tree pointer is valid, if not, returns 0 to indicate an error
        perror("Invalid tree pointer (line 132)");
        return 0;
    }
    int minVal = INT_MIN;
    int maxVal = INT_MAX;
    return isValidHelper(tree->root, &minVal, &maxVal);//helper function is called to recursively check if the tree satisfies the properties of a binary search tree, starting from the root node, and returns the result (1 for valid BST, 0 for invalid BST)
}
int isValidHelper(BSTNode *node, int *min, int *max){
    if(node == NULL){//checks if the current node is NULL, which means we have reached a leaf node, so we return 1 to indicate that an empty subtree is a valid BST
        return 1;
    }
    if(node->data < *min || node->data > *max){//checks if the current node's data value violates the BST property by being less than or equal to the minimum allowed value or greater than or equal to the maximum allowed value, if so, returns 0 to indicate that the tree is not a valid BST
        return 0;
    }
    int leftMax = node->data;
    int rightMin = node->data;
    return isValidHelper(node->left, min, &leftMax) && isValidHelper(node->right, &rightMin, max);//recursively checks the left subtree, updating the maximum allowed value to the current node's data value, and checks the right subtree, updating the minimum allowed value to the current node's data value, and returns both results to ensure that both subtrees must be valid for the entire tree to be considered a valid BST
}
void freeBST(BST *tree){
    if(!tree){//checks if the tree pointer is valid, if not, does nothing
        perror("Invalid tree pointer (line 152)");
        return;
    }
    freeHelper(tree->root);//frees all the nodes in the tree using a helper function to recursively free each node, starting from the root node
    free(tree);//finally, frees the memory allocated for the BST structure itself
}
void freeHelper(BSTNode *node){
    if(node == NULL){//checks if the current node is NULL, which means we have reached a leaf node, so we do nothing
        return;
    }
    freeHelper(node->left);//frees the left subtree
    freeHelper(node->right);//frees the right subtree
    free(node);//frees the current node
}
BSTNode* createNode(int data){
    BSTNode *newNode = malloc(sizeof(BSTNode));//mallocs a new BST node and initializes its data and child pointers
    if(!newNode){//checks if the allocation was successful, if not, returns NULL to indicate failure
        perror("Memory allocation failed (line 169)");
        return NULL;
    }
    newNode->data = data;//sets the data of the new node to the provided data value
    newNode->left = NULL;//initializes the left and right child pointers to NULL, indicating that the new node is a leaf node
    newNode->right = NULL;
    return newNode;//returns a pointer to the new node
}