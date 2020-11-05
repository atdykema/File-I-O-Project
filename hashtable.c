#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h> 
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "node.h"
#include "hashtable.h"
int longestN;
int longestS;
//algo to balance the BST while also placing nodes in tree
void placeNode(struct Node* header, struct Node* input){
    //for when word already exists
    if(strcmp(header->data, input->data) == 0){
        header->count += 1;
        if(header->count > longestN){
            longestN = header->count;
        }
    }
    //for when new word it less than header
    else if(strcmp(header->data, input->data) > 0){
        if(header->left == NULL){
            header->left = input;
        }else{
            placeNode(header->left, input);
        }
    }
    //for when new word is more than header
    else if(strcmp(header->data, input->data) < 0){
        if(header->right == NULL){
            header->right = input;
        }else{
            placeNode(header->right, input);
        }
    }
}

//simple function to get hash key for the hashtable
int getKey(char firstLetter){
    return firstLetter - 'a';
}

//algo to prepare a new node to be put into the table by getting the proper key and checking to make sure the BST is not null
void putInTable(char* input, struct Node *table[26]){
    int key = getKey(input[0]);
    if(table[key] == NULL){
        struct Node* newNode = node(input, NULL, NULL, 1);
        table[key] = newNode;
    }else{
        struct Node* newNode = node(input, NULL, NULL, 1);
        placeNode(table[key], newNode);
    }

}

//main function for intaking all different kinds of inputs
void getInput(int fdin, struct Node *table[26]){
    //buffers and counters to parse inputs
    ssize_t cnt;
    char buf[1024];
    char wordArray[100];
    int wordIndex;
    //loop while there is text in document
    while((cnt = read(fdin, buf, 1024))>0){
        for(int i = 0; i < cnt; i++){
            //check to see if the word is continued to be built or to add the word to the hashtable due to delimiter
            if(isalpha(buf[i])){
                wordArray[wordIndex] = tolower(buf[i]);
                wordIndex++;    
            }else{
                //moving new word to hashtable
                if(wordIndex > longestS){
                    longestS = wordIndex;
                }
                wordArray[wordIndex] = '\0';
                if(wordArray[0] == '\0'){
                    continue;
                }
                char* word = (char*)malloc(sizeof(char));
                memcpy(word, wordArray, wordIndex);
                putInTable(word, table);
                wordArray[0] = '\0';
                wordIndex = 0;
            }  
        } 
    }
    //close file
    if((close(fdin)) == -1){
        printf("error closing file\n");
    }
}

//function to recursively process in order traversal
void printBST(struct Node* node, int file){
    if(node == NULL){
        return;
    }
    char buf[128] = "";
    buf[127] = '\0';
    //print left
    printBST(node->left, file);
    //print each node
    sprintf(buf, "%-*s : %*i\n", longestS, node->data, longestN, node->count);
    int writer = write(file, buf, 4+longestS+longestN);
    //check for error
    if(writer == -1){
        perror("Error opening BST write");
    }
    
    //print right
    printBST(node->right, file);


}

//creating the outfile or truncating it if it already exists
void printToFile(struct Node* table[26]){
    int outfile = open("output.txt", O_TRUNC|O_RDWR, 0644);
    if(outfile == -1){
        printf("error opening outfile");
        outfile = open("output.txt", O_CREAT|O_RDWR, 0644);
    }
    //finding word with most digits for formatting
    int numOfDigits = 1;
    while(longestN >= 10){
        longestN = longestN / 10;
        numOfDigits++;
    }
    longestN = numOfDigits;
    for(int i = 0; i < 26; i++){
        printBST(table[i], outfile);
    }
}

//helper function for freeBST
void freeSingleBst(struct Node* node){
    if(node == NULL){
        return;
    }
    freeSingleBst(node->left);

    freeSingleBst(node->right);

    free(node);
}

//free all bst nodes in hashtable
void freeBST(struct Node* table[26]){
    for(int i = 0; i < 26; i++){   
        if(table[i] == NULL){
            return;
        }else{
            freeSingleBst(table[i]);
        }
        
    }
}

