#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
    int len;
    int max;
    int c, i;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
	if (len < MAXLINE-1) { /* len is less than the max length */
	    if (len > max) {
		max = len;
		copy(longest, line);
	    }
	} else {
	    if (line[MAXLINE-2] == '\n') {
		if (len > max) {
		    max = len;
		    copy(longest, line);
		}
	    } else {
		for (i = 0; c != '\n'; ++i)
		    c = getchar();
		len = len + i;
		if (len > max) {
		    max = len;
		    copy(longest, line);
		}
	    }
	}

    if (max > 0) {
	printf("%s", longest);
	if (max > MAXLINE-1)
	    printf("\n%i\n", max);
	else
	    printf("%i\n", max);
    }
}

int get_line(char s[], int lim)
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

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
	++i;
}
