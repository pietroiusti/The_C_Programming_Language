#include <unistd.h>
#include <stdio.h>

#define BUFSIZE 512

/* p. 171 */

int main(void) /* copy input to output */
{
    char buf[BUFSIZE];
    int n;

    while ((n = read(0, buf, 1) >= 0)) {
	write(1, buf, n);
    }

    return 0;
}
