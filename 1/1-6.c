#include <stdio.h>

/* verify that the expression getchar() != EOF */

int main(void)
{
    printf("%d\n", (getchar() != EOF));

    return 0;
}
