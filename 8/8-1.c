#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/* Rewrite the program cat from Chapter 7 using read, write, open and
 * close instead of their standard library equivalents. Perform
 * experiments to determine the relative speeds of the two
 * versions. */

#undef BUFSIZ
#define BUFSIZ 1 // make things slower...

void copy(int ifd, int ofd);

int main(int argc, char *argv[]) {
    int fd;
    char *prog = argv[0]; /* program name for errors */

    if (argc == 1 ) /* no args; copy standard input */
	copy(0, 1);
    else
	while (--argc > 0)
	    if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
		fprintf(stderr, "%s: can't open %s\n",
			prog, *argv);
		exit(1);
	    } else
		copy(fd, 1);
    exit(0);
}

/* copy: copy ifd to ofd */
void copy(int ifd, int ofd)
{
    char buf[BUFSIZ];
    int n;

    while ( (n = read(ifd, buf, BUFSIZ)) > 0)
	write(ofd, buf, n);
}
