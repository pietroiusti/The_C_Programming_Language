#include <unistd.h>
#include <stdio.h>

/* p. 172 */

int getchar(void);

int main(void)
{
    int c;

    while((c = getchar()) != EOF) {
	write(1, &c, 1);
    }

    /*
    When getchar is called there are two possibilities.  
    Either the buffer is empty; in that case the function prompts the
    user for input and then returns a pointer to the first char of the
    buffer.  
    Or the buffer is not empty; in that case getchar returns a pointer
    to the char next to the one a pointer to which has been previously
    returned.
    */
    
    return 0;
}

/* getchar: simple buffered version */
int getchar(void) {
    static char buf[512];
    static char *bufp = buf;
    static int n = 0;
    
    if (n == 0) { /* buffer is empty */
	n = read(0, buf, sizeof buf);
	bufp = buf;
    }

    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}
