#include <stdio.h>

/* Rewrite the temperature conversion program of  
 * Section 1.2 to use a function for conversion.
 */

float fahrToCelsius(float fahr);

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
        celsius = fahrToCelsius(fahr);
        printf("%3.0f\t\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

float fahrToCelsius(float fahr)
{
    return (5.0/9.0) * (fahr-32.0); 
}
