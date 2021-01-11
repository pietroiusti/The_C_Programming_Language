#include <stdio.h>

#define MAXLINE 1000
#define MAXTEXT 10000

/* write a program to print all iput lines that are longer 80
 * characters
 */

void copy_input(char to[]);
void print_lines(char text[], int limit);

main()
{
    char text[MAXTEXT];

    copy_input(text);

    printf("Lines longer than 80 chars:\n");
    print_lines(text, 80);
}

/* copy input into `to` */
void copy_input(char to[])
{
    int c, i;
    
    for (i = 0; (c = getchar()) != EOF && i < MAXTEXT; ++i) {
	to[i] = c;
    }
    to[i] = '\0';
}

/* print lines from `text` whose length > `limit` */
void print_lines(char text[], int limit)
{
    int i;
    char line[MAXLINE];
    int j; /* index for line */

    j = 0;
    for (i = 0; text[i] != '\0'; ++i) {
	line[j] = text[i];
	++j;
	if (text[i] == '\n') {
	    if (j-1 > limit ) {
		line[j] = '\0';
		printf(line);
	    }
	    j = 0;
	}
    }
    line[j] = '\0';
    if (j-1 > limit)
	printf(line);
}
