/* Binary tree used from K&R example p.140 */
/* qsort sourced form K&R p.87 */
/* Command-line arg_check is from K&R p.115 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "addtree.h"
#include "read_long_word.h"
#include "treeprint.h"
#include "shellsort.h"

int arg_check(int argc, char *argv[]);

/* sort words by frequency */
int main(int argc, char *argv[]) {
    struct tnode *root, *array, *start;
    char *word;
    int nodecount, arraycount;

    root = array = NULL;
    nodecount =  arraycount = 0;
    /* check command line args */

    while ((word = read_long_word(stdin)) != NULL)
        if (isalpha(word[0]))
            root = addtree(root, word);
        treecount(root, &nodecount);
    array =  build_node_array(root, nodecount);    
    start = array;
    tree_to_array(root, array, &arraycount);
    array_print(array, arraycount);
    /* make an array the size of nodecount to hold tnodes */
    free(root); /* binary tree can be freed now */
    return 0;
}

/* arg_check: check command-line arguments */

