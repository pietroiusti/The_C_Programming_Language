#include <stdio.h>

/* Write a function invert(x,p,n) that returns x with the n bits that
 * begin at position p inverted (i.e., 1 changed into 0 and vice
 * versa), leaving the others unchanged */

unsigned invert(unsigned x, int p, int n);

int main(void)
{
    printf("%u\n", invert(63, 6, 3));

    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned nmask = (1 << n) -1;
    int shift = p-n+1;

    return x ^ (nmask << shift);
}
