#include <stdio.h>

/*
 * Write a loop equivalent to the for loop above
 * without using && or ||
 */

/*
 *      for (i = 0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 *          s[i] = c;
 *
 */

main()
{
    /* for (i = 0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) { */
    /* 	s[i] = c; */
    /* } */

    int i = 0;
    int keep_going = 1;
    int lim = 10;
    while (keep_going) {
	if (i >= lim-1)
	    keep_going = 0;
	else if ((c=getchar()) == '\n')
	    keep_going = 0;
	else if (c == EOF)
	    keep_going = 0;
	else {
	    s[i] = c;
	}
	++i;
    }

    return 0;
}
