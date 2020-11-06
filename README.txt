Functions: 
    Main: Makes sure each type of input is in the proper format to be passed into getInput, where the data is parsed. It then prints all of the data
    from the hashtable once all the input is accounted for. Finally, it frees all the memory stored in the BSTs

    getInput: creates buffers and opens specificed files in order to parse its content and detect words stored inside. The program is made to recognize
    when a specific character is indicating the end of a word and then storing that word into its own string where it can be passed on via other
    functions to the hashtable

    getKey: simple function to find the correct placement of a word in the hashtable depending on what letter the word starts with

    putInTable: puts node with word in it in correct spot in hashtable using key. Makes sure that the node isnt being assigned to be attached to 
    a null pointer

    placeNode: function algorithm which correctly sorts where a node should be placed in its proper BST to keep correct ordering.

    printToFile: opens or truncates output file and assigns proper formatting. Then uses printBST to print data to output.txt

    printBST: Takes acutal node data, puts it into a compatable form, then prints it to the output file

    freeBST: main function which starts the freeing process of the BST

    freeSingleBst: helper method to free all bsts using postorder traversal

Output Requirements:

1. STDIN can be input as seen in the main method
2. In the getInput method, inputs are read. In the placeNode, the words are counted and are ordered alphabetically.
3. The Environ input is accounted for first thing in the main method
4. Program is able to handle all forms of input at once as seen in the main method and the getInput method
5. output.txt does adhere to the proper formatting

video link: https://www.youtube.com/watch?v=uXsin0YAWfs
