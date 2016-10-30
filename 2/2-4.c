#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXSTRING 100

/* Write an alternate version of squeeze(s1, s2) that 
 * deletes each character in s1 that matches any character
 * in the string s2
 */
void squeeze(char s[], char s2[]);

int main(void)
{
    char string1[MAXSTRING] = "hello world, what's up?";
    char string2[MAXSTRING] = "h?";

    squeeze(string1, string2);

    printf("%s\n", string1);

    return 0;
}

void squeeze(char s[], char s2[])
{
    int i, j, k;

    for (i = j = 0; s[i] != '\0'; i++) {
        /* iterate over s2 till we find the char or we get to the end of s2 */
        for (k = 0; s2[k] != s[i] && s2[k] != '\0'; k++)
            ;
        if (s2[k] == '\0') /* if is true that means we haven't found the char in s2 */ 
            s[j++] = s[i];
    }
    s[j] = '\0';
}
