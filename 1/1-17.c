#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

/* write a program to print all iput lines that are longer
 * 80 characters
 */

int getLine(char line[], int maxline);

int main(void)
{
    int len;                /* current line lenght */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];      /* current input line */
    char longest[MAXLINE];   /* longest line saved here */

    max = 0; 
    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > 80)
            printf("%s", line);
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
