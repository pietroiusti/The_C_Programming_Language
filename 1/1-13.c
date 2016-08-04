#include <stdio.h>

#define IN    1    /* inside a word */
#define OUT   0    /* outside a word */

/* write a program to print a histogram of
 * the lengths of words in its input. 
 * Horizontal histogram version.
 */

int main(void)
{
    /*array of words lengths*/
    int lengths[100];

    int i, j;
    for (i = 0; i < 100; i++) {
        lengths[i] = 0;
    }

    int c, length, wordcount, state;
    state = OUT;
    wordcount = length = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN){
                lengths[wordcount] = length;        
                length = 0;
                ++wordcount;
            }
            state = OUT;
        }
        else{
            state = IN;
            ++length;
        }
    }

    /*print arrays of lengths. not necessary*/
    for (i = 0; i < 5; i++) 
        printf("%d ", lengths[i]);
    printf("\n");

    /*print horizontal histogram*/
    for (i = 0; i < wordcount; i++) {
        for (j = 0; j < lengths[i]; j++)
            putchar('#');
        putchar('\n');
    }

    return 0;
}
