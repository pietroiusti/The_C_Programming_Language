#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
    int len;
    int overflow = 0;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
	if (len != MAXLINE-1) {
	    if (overflow > 0)
		len = len + ((MAXLINE-1) * overflow);
	    overflow = 0;
	    printf("%s", line);
	    printf("Length: %i\n", len);
	} else {
	    if (line[MAXLINE-2] == '\n') {
		if (overflow > 0)
		    len = len + ((MAXLINE-1) * overflow);
		overflow = 0;
		printf("%s", line);
		printf("Length: %i\n", len);
	    } else {
		++overflow;
		printf("%s", line);
	    }
	}
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
