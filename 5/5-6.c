#include <stdio.h>

/* Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing... */

/* getline, p.29 */
int getline2(char *s, int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
	*(s+i) = c;
    if (c == '\n') {
	*(s+i) = c;
	++i;
    }
    *(s+i) = '\0';
    return i;
}
