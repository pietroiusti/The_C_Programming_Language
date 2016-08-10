#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len;                /* current line lenght */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];      /* current input line */
    char longest[MAXLINE];   /* longest line saved here */

    max = 0; 
    while ((len = getLine(line, MAXLINE)) > 0) {
        //print length of line
        printf("%i ", len);
        //print line
        printf("%s", line);
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)    /* there was a line */
        printf("The longest line was: %s", longest);
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

/* copy: copy 'from' int 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0; 
    while ((to[i] = from[i]) != '\0')
        ++i;
}
