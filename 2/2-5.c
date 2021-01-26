#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Write the function any(s1, s2), which returns the first location
 * in the string s1 where any character from the string s2 occur, or -1
 * if s1 contains no character form s2. (The standard library function 
 * strpbrk does the same job but returns a pointer to the location.)
 */

int any(char s1[], char s2[]);

main()
{
    char s1[100] = "Hello world";
    char s2[100] = "-thr";
    printf("%i\n", any(s1, s2));
}

int any(char s1[], char s2[])
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
    for (i = 0; s1[i] != '\0'; i++) {
	if (is_in(s1[i], s2))
	    return i;
    }
    return -1;
}
