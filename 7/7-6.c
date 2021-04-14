#include <stdio.h>

/* Write a program to compare two files, printing the first line where
 * they differ. */

#define MAXLINE 1000

int strcmp(char *s, char *t);

int main(int argc, char *argv[])
{
    char s1[1000], s2[1000];
    FILE *fp1, *fp2;

    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");
    
    int line_n = 0;
    while (fgets(s1, MAXLINE, fp1)) {
	fgets(s2, MAXLINE, fp2);
	line_n++;
	if (strcmp(s1, s2) != 0) {
	    printf("At line %d:\n", line_n);
	    printf("%s: %s", argv[1], s1);
	    printf("%s: %s", argv[2], s2);
	    break;
	}
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}

int strcmp(char *s, char *t)
{
    int i;

    for (i = 0; s[i] == t[i]; i++)
	if (s[i] == '\0')
	    return 0;
    return s[i] - t[i];
}
