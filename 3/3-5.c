#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
  Write the function itob(n,s,b) that converts the integers n into a
  base b character representation in the string s. In particular,
  itob(n,s,16) formats n as a hexadecimal integer in s.
*/

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
    char s[100];

    itob(1234512, s, 16);

    printf("%s\n", s);

    return 0;
}

void itob(int n, char s[], int b)
{
    if ( b < 2 || b > 36 ) {
        printf("Incorrect usage. 2 <= base <= 36");
        return;
    }

    int i, sign;
    sign = n;
    int to_skip = 'A' - '9'; // number of chars between '9' and 'A'

    i = 0;
    do {
	s[i++] = isdigit(abs(n % b) + '0') ?
	    abs(n % b) + '0' : abs(n % b) + '0' + to_skip;
    } while ( n /= b );
    if (sign < 0)
        s[i++] = '-';
    
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
