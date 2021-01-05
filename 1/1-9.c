#include <stdio.h>

/* Write a program to copy its input to its output, replacing each
 * string of one or more blanks by a single blank
 */

main()
{
    int current, previous;  

    while ((current = getchar()) != EOF) {
	if (current != ' ') {
	    putchar(current);
	    previous = current;
	}
	if (current == ' ') {
	    if (previous == ' ')
		;
	    if (previous != ' ') {
		putchar(' ');
		previous = ' ';
	    }
	}
    }
}


/* Alternative approach: */

/*
main()
{
    int c, c2;

    while ((c = getchar()) != EOF) {
        if ( c == ' ') {
            putchar(' ');
            while ((c2 = getchar()) == ' ') {
                ;
            }
            putchar(c2);
        } 
        if ( c != ' ') 
            putchar(c);
    }
}
*/
