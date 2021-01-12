#include <stdio.h>
#define MAXTEXT 10000

/* Write a program to remove trailing blanks and tabs from each line
 * of input, and to delete entirely blank lines */

void clean_and_copy_input(char to[]);

main()
{
    char text[MAXTEXT];

    int c, i;

    clean_and_copy_input(text);
    printf(text);
}

/* Remove trailing blanks and tabs and blank lines from input and copy
 * it into `to` */
void clean_and_copy_input(char to[])
{
    int c, i;
    int previous = '\n';
    
    for (i = 0; (c = getchar()) != EOF && i < MAXTEXT; ++i) {
	if (c == '\t' && previous == '\t')
	    --i;
	else if (c == ' ' && previous == ' ')
	    --i;
	else if (c == '\n' && previous == '\n')
	    --i;
	else {
	    to[i] = c;
	    previous = c;
	}
    }
    to[i] = '\0';
}

