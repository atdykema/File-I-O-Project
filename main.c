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
//variable to find the largest string to account for length in sprintf
static int longestS = 0;
//variable to find the largest digit to account for length in sprintf
static int longestN = 0;



int main(int argc, char* argv[]){
    int fdin;
    //initialize hashtable
    struct Node *table[26] = {NULL};
    //get environ
    char* envfile = getenv("WORD_FREAK");

    //environment input
    if(envfile != NULL){
        fdin = open(envfile, O_RDONLY);
        getInput(fdin, table);
    }

    //basic input from commandline
    if(argc > 1){
        for(int i = 1; i < argc; i++){
            fdin = open(argv[i], O_RDONLY);
            getInput(fdin, table);

        }
    }
    //piping in input
    getInput(STDIN_FILENO, table);

    //print table after getting all input
    printToFile(table);
    
    freeBST(table);
    return 0;
    
}