#include <stdio.h>

/* verify that the expression getchar() != EOF */

int main(void)
{
    /* if the char given is EOF the ouput will be 0, otherwise 1 */
    printf("%d\n", (getchar() != EOF));

    return 0;
}
