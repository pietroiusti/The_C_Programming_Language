#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char s[]);
void itoa(int n, char s[], int l);

/*
   Write a version of itoa that accepts three arguments instead of
   two. The third argument is a minimum field width; the converted
   number must be padded with blanks on the left if necessary to make
   it wide enough.
 */

int main(void)
{
    int n = -2147483648;
    char word[100];

    itoa(n, word, 15);
    printf("%s\n", word);

    return 0;
}

void itoa(int n, char s[], int l) {
    int i, sign;
    sign = n;

    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ( n /= 10 );
    if (sign < 0)
        s[i++] = '-';

    if (i < l)
	while (i < l)
	    s[i++] = ' ';

    s[i] = '\0';

    reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
	c = s[i];
	s[i] = s[j];
	s[j] = c;
    }
}
