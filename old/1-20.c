#include <stdio.h>
#define MAXSTRING 1000
#define TABSTOPS 8

/* write a program detab that replaces tabs in the input
 * with the proper number of blanks to space to the next
 * tab stop. Assume a fixed set of tab stop, say every n
 * columns. Should n be a variable or a symbolic parameter?
 */

/* n should be a symbolic parameter since its value will
 * never change through the program
 */

int main(void)
{
    int c, i;
    char input[MAXSTRING];

    for (i = 0; (c = getchar()) != EOF; i++) {
        if (c == '\t') { // if the input char is a tab
            if (i == 0) { // if the tab is at the beginning we handle it this way...
                input[i] = ' ';
                ++i;
            }
            while (i % TABSTOPS != 0) { //condition: till we don't get a multiple of TABSTOPS
                input[i] = ' ';
                ++i;
            }
            i--;
        } 
        else { // if the input char is not a tab
            input[i] = c;
        }
    }
    input[i] = '\0';

    for (i = 0; input[i] != '\0'; i++)
        putchar(input[i]);

    return 0;
}

/*

n = 4
hello\tworld becomes:
hello   world
^   ^   ^   ^ 
123456789

n = 3
hello\tworld becomes:
hello world
^  ^  ^  ^  
123456789
*/
