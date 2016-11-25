#include <stdio.h>

/* Verify that the expression getchar() != EOF
 * is 0 or 1
 */

int main(void)
{
    /* if the char given is EOF the ouput will be 0, otherwise 1 */
    printf("%d\n", (getchar() != EOF));

    return 0;
}
