#include <stdio.h>

/* Write a program to print the corresponding Celsius to Fahrenheit
 * table.
 */

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; /* lower limit of temperature talbe */
    upper = 300; // upper limit
    step = 20; /* step size */

    /*heading*/
    printf("----\t\t-------\n");
    printf("Celsius\t\tFahr\n");
    printf("----\t\t-------\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = (celsius / (5.0/9.0)) + 32.0;
        printf("%3.0f\t\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
