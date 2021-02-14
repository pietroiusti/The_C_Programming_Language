#include <stdio.h>

/* In a two's complement number system, x &= (x-1) deletes the
 * rightmost 1-bit in x. Explain why. Use this observation to write a
 * faster version of bitcount. */

/*
In a two's complement system -1 is represented as all 1s. This means
that x-1 --- which is the same as x + (all 1s) --- will give back x
where:
    - the rightmost 1-bit is flipped to 0;
    - every bit on the left of it is left as it is;
    - every bit on the right of it is set to 1.
So, &ing x-1 with x will gives you x where:
    - the righmost 1-bit is flipped to 0;
    - every bit on the left of it is left as it is;
    - every bit on the right of it is set to 0.
*/

int bitcount(unsigned x);

int main(void)
{
    printf("%i\n", bitcount(6));
    printf("%i\n", bitcount(15));
}

/* bitcount: count 1-bits in x */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= x-1)
	b++;
    
    return b;
}
