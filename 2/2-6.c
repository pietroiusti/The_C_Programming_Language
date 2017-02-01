#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
    //printf("~(getbits(~0, 3, 4) << 3) = %x\n", ~(getbits(~0, 3, 4) << 3));

    //printf("getbits(0x79, 3, 4) << 3 = %x\n", getbits(0x79, 3, 4) << 3);

    printf("%x\n", setbits(0xa2, 5, 3, 0xf3));

    return 0;
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

/* setbits: return x with the n bits that begin at position p
 * set to the rightmost n bits of y, leaving the other bits
 * unchanged.
 */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return (x & ( ~ (getbits(~0, n-1, n) << (p+1-n)))) | (getbits(y, n-1, n) << (p+1-n));
}
