#include <stdio.h>
#define MAXLINE 1000

int getLine(char s[], int lim);
void reverse(char to[], char s[], int length);

main()
{
    int len;
    char line[MAXLINE];
    char reversed[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0) {
	reverse(reversed, line, len);
	printf("%s\n", reversed);
    }

    return 0;
}

/* getLine: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/*  reverse string 's' into 'to' */
void reverse(char to[], char s[], int length)
{
    int i, j;

    /* length -2 to skip '\0' */
    for (i = length-2, j = 0; i >= 0; --i, ++j) {
	to[j] = s[i];
    }
    to[j] = '\0';
}
