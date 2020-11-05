#include <stdio.h>
#include <stdlib.h>

//node for BST
struct Node{
    char* data; 
    struct Node *left;
    struct Node *right;
    int count;
    
};

struct Node * node(char* data, struct Node * left, struct Node * right, int count);