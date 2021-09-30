#include <stdio.h>
#define MAXSTRING 1000

/* Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th colummn
 * of input. Make sure your program does something intelligent with very 
 * long lines, and if there are no blanks or tabs before the specified column.
 */

int main(void) 
{
    int c, i, column;
    char result[MAXSTRING];

    for (i = 0, column = 0; (c = getchar()) != EOF; i++, column++) {
        

        if (c == '\n')
            column = 0;
        
        if (column > 70 && c == ' ') {
            result[i] = '\n';
            column = 0;
        } 
        else
            result[i] = c;
        //TODO  if there are no blanks?
    }
    result[i] = '\0';

    printf("%s", result);

    return 0;
}
