/* Sourced from K&R p.142 */
#include "treeprint.h"
#include "addtree.h"

/* treecount: count nodes in tree */
void treecount(struct tnode *p, int *count) {
    if (p != NULL) {
        treecount(p->left, count);
        (*count)++;
        printf("%4d %s\n", p->count, p->word);
        treecount(p->right, count);
    }
}

/* build second node_array: */

/* build_node_array: makes the node array based on node count */
struct tnode *build_node_array(struct tnode *array, int count) {
   if ((array = calloc(count, sizeof(array))) == NULL) {
        perror("Calloc failed");
        exit(-1);
    }
    else {
        return array;
    }
}
/* tree_to_array: put binary tree into array */
void tree_to_array(struct tnode *p, struct tnode *array, int *arraycount) {
    if (p != NULL) {
        array += *arraycount; /* increment array to next element */
        tree_to_array(p->left, array, arraycount);
        array = p;
        (*arraycount)++;
        tree_to_array(p->right, array, arraycount);
    }
}

/* array_print: print out elements in array */
void array_print(struct tnode *array, int count) {
    int i = 0;
    while (i < count) {
        printf("Array: %s\n", array[i].word);
        i++;
    }
}
