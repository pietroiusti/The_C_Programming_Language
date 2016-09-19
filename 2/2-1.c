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
    printf("char:\n");
    printf("Minimum value for 'signed char': %d\n", SCHAR_MIN);
    printf("Maximim value for 'signed char': %d\n", SCHAR_MAX);
    printf("Minimum value for 'unsigned char': %u\n", 0);
    printf("Maximum value for 'unsigned char': %u\n", UCHAR_MAX);
    printf("\n");

    printf("short:\n");
    printf("Minimum value for 'signed short int': %d\n", SHRT_MIN);
    printf("Maximum value for 'signed short int': %d\n", SHRT_MAX);
    printf("Minimum value for 'unsigned short int': %u\n", 0);
    printf("Maximum value for 'unsinged short int':%u\n", USHRT_MAX);
    printf("\n");

    printf("int:\n");
    printf("Minimum value for 'signed int': %d\n", INT_MIN);
    printf("Maximum value for 'signed int': %d\n", INT_MAX);
    printf("Minimum value for 'unsigned int': %u\n", 0);
    printf("Maximum value for 'unsinged int': %u\n", UINT_MAX);
    printf("\n");
    
    printf("long:\n");
    printf("Minimum value for 'signed long int':%ld\n", LONG_MIN);
    printf("Maximum value for 'signed long int':%ld\n", LONG_MAX);
    printf("Minimum value for 'unsigned long int':%lu\n", 0);
    printf("Maximum value for 'unsinged long int':%lu\n", ULONG_MAX);
 
    return 0;
}
