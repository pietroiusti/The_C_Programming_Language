#include <stdio.h>

/* Write a program that prints its input one word per line */
int main(void)
{
    int c;

    while ( (c = getchar()) != EOF ) {
        putchar(c);
        if ( c == ' ' )
            putchar('\n');
    }

    return 0;
}
