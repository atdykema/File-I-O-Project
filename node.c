#include <stdio.h>
#include <stdlib.h>
#include "node.h"
//node for BST
struct Node * node(char* data, struct Node* left, struct Node* right, int count){
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    if(newNode == NULL){
        return NULL;
    }
    else{
        newNode->data = data;
        newNode->left = left;
        newNode->right = right;
        newNode->count = count;
    }
    return newNode;
}