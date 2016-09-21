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

#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/*print longest input line*/
int main(void)
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* there was a line*/
        printf("%s", longest);
    return 0;
}

/* getLine: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;
/*
    for (i = 0; i<lim-1 && (c=getchar()) != EOF && c!= '\n'; ++i)
        s[i] = c;
*/
    i = 0;
    int keep_going = 1;
    while (keep_going) {
        if (i == lim-1) {
            keep_going = 0;
        }
        else {
            if ((c = getchar()) != EOF) {
                if (c != '\n') {
                    s[i] = c;
                    ++i;
                }
                else {
                    keep_going = 0;
                }
            }
            else {
                keep_going = 0;
            }
        }
    }
if (c == '\n') {
    s[i] = c;
    ++i;
}
s[i] = '\0';
return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
int i;

i = 0;
while ((to[i] = from[i]) != '\0')
    ++i;
}

