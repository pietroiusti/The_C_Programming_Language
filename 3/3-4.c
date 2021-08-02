#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[]);

/* 
   In a two's complement number representation, our version of itoa
   does not handle the largest negative number, that is, the value of
   n equal to -(2^(wordsize-1)). Explain why not. Modify it to print
   that value correctly, regardless of the machine on which it runs.
 */

int main(void)
{
    int n = -2147483648;
    char word[100];

    /*
    Suppose n == -2147483648. This number is the largest negative
    number we can put in a int (that is, the largest negative number
    we can represent with 4 bites). itoa will do n = -n. But -n is too
    big to be stored in a int. In fact, if we try to make n positive
    by negating it, we get n itself back (given the way two's
    complement representation works). So n will still be
    negative. Given so, the condition n /= 10 will evaluate to a
    negative number. Given so, the while loop body will get executed
    only once.
    */

    itoa(i, word);
    printf("%s\n", word);

    return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0) /* record sign */
	n = -n;         /* make n positive */
    i = 0;
    do { /* generate digits in reverse order */
	s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0);
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
