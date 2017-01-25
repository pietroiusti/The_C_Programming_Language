#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXSTRING 100

/* Write an alternate version of squeeze(s1, s2) that 
 * deletes each character in s1 that matches any character
 * in the string s2
 */

void squeeze(char s1[], char s2[]);

int main(void)
{
    char string1[MAXSTRING] = "hello world, what's up?";
    char string2[MAXSTRING] = "h?";

    squeeze(string1, string2);

    printf("%s\n", string1);

    return 0;
}

/* deletes each character in s1 that matches any character
 * in the sting s2
 */
void squeeze(char s1[], char s2[])
{
    int i, j, k;

    /* for every char in s */
    for (i = j = 0; s1[i] != '\0'; i++) {
        /* iterate over s2 till we find the char or we get to the end of s2 */
        for (k = 0; s2[k] != s1[i] && s2[k] != '\0'; k++)
            ;
        if (s2[k] == '\0') /* if we haven't found the char in s2 */ 
            /* we can copy it in s1 and increase j*/
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}
