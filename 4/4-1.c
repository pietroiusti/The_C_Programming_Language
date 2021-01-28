#include <stdio.h>

/* Write the function strrindex(s,t), which returns the position of
 * the rightmost occurrence of t in s, or -1 if there is none */

int strrindex(char s[], char t[]);

main()
{
    char s1[100] = "Hello world world";
    char s2[100] = "world";
    printf("%i\n", strrindex(s1, s2));
    printf("%i\n", strindex(s1, s2));
}

int strrindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
	;

    for (i = i-2; s[i] >= 0; i--) {
	for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
	    ;
	if (k > 0 && t[k] == '\0')
	    return i;
    }
    return -1;
}
