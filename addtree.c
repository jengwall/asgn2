/* Sourced from K&R p.141 */
#include "addtree.h"

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) {    /* a new word has arrived */
        p = talloc();   /* make a new node */
        if (p == NULL) {
            perror("Malloc failed");
            exit(-1);
        }
        if((p->word = strdup(w)) == NULL) { /* error check strdup */
            perror("Strdup failed");
            exit(-1);
        }
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;     /* repeated word */
    else if (cond < 0) /* less than into left subtree */
        p->left = addtree(p->left, w);
    else            /* great than into right subtree */
        p->right = addtree(p->right, w);
    return p;
}

/* talloc: make a tnode */
struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}
