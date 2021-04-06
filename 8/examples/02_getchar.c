#include <unistd.h>
#include <stdio.h>

int getchar(void);

/* p. 171 */

int main(void)
{
    int c;
    
    // This makes as many read system calls as the number of char from
    // stdinput. Not very performant.
    while((c = getchar()) != EOF) {
	write(1, &c, 1);
    }

    return 0;
}

/* getchar: unbuffered single character input */
int getchar(void) {
    char c;

    return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}
