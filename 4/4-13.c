#include <stdio.h>
#include <string.h>

/* Write a recursive version of the function reverse(s), which
 * reverses the string s in place */

void reverse(char s[], int i);

main()
{
    char s[] = "Hello world";
    reverse(s, 0);
    printf("%s\n", s);
    return 0;
}

/* Reverse string in place. Start reversing at index i */
void reverse(char s[], int i)
{
    int len = strlen(s);
    if (i < len/2) {
	int c;
	c = s[i];
	s[i] = s[len-1-i];
	s[len-1-i] = c;
	reverse(s, ++i);
    }
}
