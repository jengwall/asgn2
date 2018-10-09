#include "read_long_word.h"

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
