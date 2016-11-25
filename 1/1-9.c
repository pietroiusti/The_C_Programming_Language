#include <stdio.h>

/* Write a program to copy its input to its output, 
 * replacing each string of one or more blanks by a
 * single blank
 */
int main(void)
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
    
    return 0;
}
