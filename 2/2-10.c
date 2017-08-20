#include <stdio.h>

/* Rewrite the function lower, which converts upper case letters to
 * lower case letters, with a conditional expression instead of
 * if-else.
 */

int lower(int c)
{
   return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c; 
}

int main(void)
{
    printf("%c\n", lower('B'));

    return 0;
}
