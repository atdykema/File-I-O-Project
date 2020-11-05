#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h> 
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
//main function for intaking all different kinds of inputs
void getInput(int fdin, struct Node* table[]);

//algo to prepare a new node to be put into the table by getting the proper key and checking to make sure the BST is not null
void putInTable(char* input, struct Node* table[]);

//simple function to get hash key for the hashtable
int getKey(char firstLetter);

//algo to balance the BST while also placing nodes in tree
void placeNode(struct Node* header, struct Node* input);

//function to recursively process in order traversal
void printBST(struct Node* node, int file);

//creating the outfile or truncating it if it already exists
void printToFile(struct Node* table[26]);

void freeSingleBst(struct Node* node);

void freeBST(struct Node* table[26]);