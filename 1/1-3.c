#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300
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
    printf("Fahr\t\tCelsius\n");
    printf("----\t\t-------\n");

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f\t\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
