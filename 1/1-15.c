#include <stdio.h>

/* Rewrite the temperature conversion program of Section 1.2 to use a
 * function for conversion.
 */

float fahr_to_celsius(float fahr);

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; /* lower limit of temperature talbe */
    upper = 300; // upper limit
    step = 20; /* step size */

    fahr = lower;
    while (fahr <= upper) {
        celsius = fahr_to_celsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

float fahr_to_celsius(float fahr)
{
    return (5.0/9.0) * (fahr-32.0);
}
