/* readword function was used from K&R p.20
 *
 */
#include <stdio.h>

void readword(FILE *fp);

struct word {
    char *string;
    int count;
};

/* Returns a sorted list, by frequency, of words in a file */
int main() {
    readword(stdin); 
    /*get a file*/
    /* read file looking for words */

    return 0;
}

/* readword: read a word from file or standard input */
void readword(FILE *fp) {
    int c;
    while((c = getc(fp)) != EOF) {
        printf("%c", (char)c);;
    }
}
