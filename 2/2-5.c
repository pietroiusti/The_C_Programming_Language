#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Write the function any(s1, s2), which returns the first location
 * in the string s1 where any character from the string s2 occur, or -1
 * if s1 contains no character form s2. (The standard library function 
 * strpbrk does the same job but returns a pointer to the location.)
 */

int any(char s[], char s2[]);

int main(void)
{
    char string1[100] = "Hello world";
    char string2[100] = "Perenne";

    printf("%i\n", any(string1, string2));

    return 0;    
}

int any(char s[], char s2[])
{
    int i, j, k;

    for (i = j = 0; s[i] != '\0'; i++) {
        /* iterate over s2 till we find the char or we get to the end of s2 */
        for (k = 0; s2[k] != s[i] && s2[k] != '\0'; k++)
            ;
        if (s2[k] != '\0') /* if is true that means we haven't found the char in s2 */ 
            return i;
    }
    return -1;
}
