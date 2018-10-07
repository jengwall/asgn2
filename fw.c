#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFSIZE 64

struct word {
    char *string;
    int count;
};

char *read_long_word(FILE *fp);

int main() {
    char *word;

    while((word = read_long_word(stdin)) != NULL) {
        if(word == NULL) {  /* error or end-of-file */
           printf("size: %d\n", (int)sizeof(word));
        }
        else {
            if((int)strlen(word) > 0) 
                printf("%s\n", word);
        }
    }
    return 0;
}

/* read words from input */
char *read_long_word(FILE *fp) {
    char c;
    int count, buf_size;
    char *word;

    count = 0;
    buf_size = BUFSIZE;
    word = calloc(buf_size, sizeof(char));
    if (word == NULL) {
        perror("Calloc failed");
        exit(-1);
    }
    while ((c = getc(fp)) != EOF) {
        if (isalpha(c)) { /* test c for alphabetical char */
            *(word + count) = c;    /* assign c to word buffer */
            ++count;
            if(count >= buf_size) {
                buf_size += BUFSIZE; /* increment buffer */
            word = (char *)realloc(word, buf_size * sizeof(char));
            /* check to see if realloc fails */
                if (word == NULL) {
                    perror("Realloc failed");
                    exit(-1);
                }
            }
        } else { /* end of word */
            *(word + count) = '\0';
            return word;
        }
    }
    return NULL;
}

/* sort words */

/* print list */
