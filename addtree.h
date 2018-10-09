#ifndef ADDTREE_H
#define ADDTREE_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *talloc(void);
struct tnode *addtree(struct tnode *p, char *w);

#endif
