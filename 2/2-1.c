#include <stdio.h>
#include <limits.h>

/* Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing 
 * appropriate values from standard headers and by direct computation.
 * Harder if you compute them: determine the ranges of the various 
 * floating-point types.
 */

int main(void)
{
    // signed

    printf("Minimum value for 'signed char':\n", SCHAR_MIN);
    printf("\t%d\n", SCHAR_MIN);
    printf("\t%d\n", ~(char)((unsigned char) ~0 >> 1));

    printf("Maximum value for 'signed char':\n");
    printf("\t%d\n", SCHAR_MAX);
    printf("\t%d\n", (char)((unsigned char) ~0 >> 1));

    printf("Minimum value for 'signed short int':\n");
    printf("\t%d\n", SHRT_MIN);
    printf("\t%d\n", ~(short)((unsigned short) ~0 >> 1));

    printf("Maximum value for 'signed short int':\n");
    printf("\t%d\n", SHRT_MAX);
    printf("\t%d\n", (short)((unsigned short) ~0 >> 1));

    printf("Minimum value for 'signed int':\n");
    printf("\t%d\n", INT_MIN);
    printf("\t%d\n", ~(int)((unsigned int) ~0 >> 1));

    printf("Maximum value for 'signed int':\n");
    printf("\t%d\n", INT_MAX);
    printf("\t%d\n", (int)((unsigned int) ~0 >> 1));

    printf("Minimum value for 'signed long int':\n");
    printf("\t%ld\n", LONG_MIN);
    printf("\t%ld\n", ~(long)((unsigned long) ~0 >> 1));

    printf("Maximum value for 'signed long int':\n");
    printf("\t%ld\n", LONG_MAX);
    printf("\t%ld\n", (long)((unsigned long) ~0 >> 1));

    // unsigned

    printf("Maximum value for 'unsigned char':\n");
    printf("\t%u\n", UCHAR_MAX);
    printf("\t%u\n", (unsigned char) ~0);
    
    printf("Maximum value for 'unsigned short int':\n");
    printf("\t%u\n", USHRT_MAX);
    printf("\t%u\n", (unsigned short) ~0);

    printf("Maximum value for 'unsinged int':\n");
    printf("\t%u\n", UINT_MAX);
    printf("\t%u\n", (unsigned int) ~0);

    printf("Maximum value for 'unsinged long int':\n");
    printf("\t%u\n", ULONG_MAX);
    printf("\t%u\n", (unsigned long) ~0);

    return 0;
}
