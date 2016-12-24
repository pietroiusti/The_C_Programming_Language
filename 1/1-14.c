#include <stdio.h>

/* write a program to print a histogram of the frequencies of
   different characters in its input */

int main(void)
{
    int c, i, j;
    int chars['z'-'a'];
    int freq[26];

    for (i = 0; i < 26; i++) {
        freq[i] = 0;
    }

    while ( (c = getchar()) != EOF ) {
        if (c >= 'a' && c <= 'z')
            ++freq[c-'a'];
    }
    
    /*print histogram*/
    for (i = 0; i <= 26; i++) {
        printf("%c: ", 'a' + i);
        for (j = 0; j < freq[i]; j++)
            putchar('#');
        putchar('\n');
    }

    return 0;
}
