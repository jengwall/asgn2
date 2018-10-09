#ifndef TREEPRINT_H
#define TREEPRINT_H

#include "addtree.h"
void treecount(struct tnode *p, int *count);
void tree_to_array(struct tnode *p, struct tnode *array, int *ac);
struct tnode *build_node_array(struct tnode *array, int count);
void array_print(struct tnode *array, int count);
#endif
