/* Binary tree used from K&R example p.140 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "addtree.h"
#include "read_long_word.h"
#include "treeprint.h"

/* sort words by frequency */
int main() {
    struct tnode *root;
    char *word;

    root = NULL;
    while ((word = read_long_word(stdin)) != NULL)
        if (isalpha(word[0]))
            root = addtree(root, word);
        treeprint(root);
   return 0;
}
/* sort words */

//    while((word = read_long_word(stdin)) != NULL) {
//       if(word == NULL) {  /* error or end-of-file */
//           ;
//        }
//        else {
//            if((int)strlen(word) > 0) 
//                printf("%s\n", word);
//        }
//    }
/* print list */
