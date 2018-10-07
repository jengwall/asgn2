/* Binary tree used from K&R example p.140 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "addtree.h"
#include "read_long_word.h"

void treeprint(struct tnode *);

/* sort words by frequency */
int main() {
    char *word;

    while((word = read_long_word(stdin)) != NULL) {
        if(word == NULL) {  /* error or end-of-file */
           ;
        }
        else {
            if((int)strlen(word) > 0) 
                printf("%s\n", word);
        }
    }
    return 0;
}
/* sort words */

/* print list */
