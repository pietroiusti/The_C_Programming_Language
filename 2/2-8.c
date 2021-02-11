#include <stdio.h>

/* Write a function rightrot(x,n) that returns the value of the
 * integer x rotated to the right by n bit positions. */

unsigned rightrot(unsigned x, int n);

int main(void)
{
    printf("%u\n", rightrot(2, 2));

    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    unsigned nmask = (1 << n) - 1;
    int bitsize = (sizeof x) * 8;

    return ((x & nmask) << (bitsize-n)) | x >> n;
}
