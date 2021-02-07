#include <stdio.h>

/* Write a function setbits(x,p,n,y) that returns x with the n bits
 * that begin at position p set to the rightmost n bits of y, leaving
 * the other bits unchanged.
 */

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
    printf("%i\n", setbits(63, 5, 3, 2));
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned result;
    int shift = p-n+1;
    
    unsigned bits = y & (1<<n)-1; /* get the n rightmost bits of y */

    bits <<= shift; /* shift bits the right amount */

    // turn bits on
    result = x | bits;

    //turn bits off
    result = result & ~((~y & ((1<<n)-1) ) << shift);
            
    return result;
}
