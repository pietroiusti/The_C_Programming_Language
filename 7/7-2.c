#include <stdio.h>
#include <ctype.h>

/* Write a program that will print arbitrary input in a sensible
way. As a minimum, it should print non-graphic characters in octal or
hexadecimal according to local custom, and break long text lines. */

#define MAXLINE 70

int main(void) {
    int c, i = 0;
    while ((c = getchar()) != EOF) {
	if (isprint(c))
	    printf("%c", c);
	else
	    printf("[0x%x]", c);

	i++;
	if (i == MAXLINE) {
	    i = 0;
	    putchar('\n');
	}
    }

    putchar('\n');

    return 0;
}
