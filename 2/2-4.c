#include <stdio.h>

/* Write an alternate version of squeeze(s1, s2) that 
 * deletes each character in s1 that matches any character
 * in the string s2
 */

void squeeze(char s1[], char s2[]);

main()
{
    char s1[100] = "Hello world";
    char s2[100] = "Hi-there";
    squeeze(s1, s2);
    printf("%s\n", s1);
}

void squeeze(char s1[], char s2[])
{
    // return 0 if c is in s, otherwise 1
    int is_in(int c, char s[])
    {
	int i;
        for (i = 0; s[i] != '\0'; i++)
	    if (s[i] == c)
		return 1;
	return 0;
    }
    
    int i, j;
    for (i = j = 0; s1[i] != '\0'; i++) {
	if (!is_in(s1[i], s2))
	    s1[j++] = s1[i];
    }
    s1[j] = '\0';
}
