#include <stdio.h>

/* Write a pointer version of the function strcat that we showed in
 * Chapter 2: strcat(s,t) copies the string s to the end of s. */

void strcat2(char *s, char *t);

int main(void)
{
    char s1[100] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char s2[] = ", world";

    strcat2(s1, s2);

    printf("%s\n", s1);

    return 0;
}

/* strcat2: concatenate t to end of s; s must be big enough */
void strcat2(char *s, char *t)
{
    while (*s) /* find end of s */
	s++;
    while (*s++ = *t++) /* copy t */
	;
}
