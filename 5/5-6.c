#include <stdio.h>

/* Rewrite appropriate programs from earlier chapters and exercises
 * with pointers instead of array indexing... */

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

/* atoi, p. 43 */
int atoi2(char *s) {
    int i, n;

    n = 0;
    for (i = 0; *(s+i)  >= '0' && *(s+i) <= '9'; ++i)
	n = 10 * n + (*(s+i) - '0');

    return n;
}

/* itoa, p. 64 */
void itoa2(int n, char *s) {
    int i, sign;

    if ((sign = n) < 0)
	n = -n;
    i = 0;
    do {
	*(s+(i++)) = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
	*(s+(i++)) = '-';
    *(s+i) = '\0';
    reverse(s);
}

/* reverse, p. 62 */
void reverse2(char *s) {
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
	c = *(s+i);
	*(s+i) = *(s+j);
	*(s+j) = c;
    }
}

/* strindex, p. 69  */
int strindex2(char *s, char *t) {
    int i, j, k;

    for (i = 0; *(s+i) != '\0'; i++) {
	for (j=i, k=0; *(t+k)!='\0' && *(s+j)==*(t+k); j++, k++)
	    ;
	if (k > 0 && *(t+k) == '\0')
	    return i;
    }

    return -1;
}

/*getop, p. 78*/
int getop2(char *s) {
    int i, c;

    while ((*s = c = getch()) == ' ' || c == '\t')
	;
    *(s+1) = '\0';
    if (!isdigit(c) && c != '.')
	return c;
    i = 0;
    if (isdigit(c))
	while (isdigit(*(s+(++i)) = c = getch()))
	    ;
    if (c == '.')
	while (isdigit(*(s+(++i)) = c = getch()))
	    ;
    *(s+i) = '\0';
    if (c != EOF)
	ungetch(c);
    return NUMBER;
}
