#include <stdio.h>

/* Write a function expand(s1,s2) that expands shorthand notations
   like a-z in the string s1 into the equivalent complete list
   abc...xyz in s2. Allow for letters of either case and digits, and
   be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
   that a leading or trailing - is taken literally. */

void expand(char s1[], char s2[]);

int main(void)
{
    char foo[] = "-a-f-q-0-9F-P-";
    char bar[1000];

    expand(foo, bar);

    printf("%s\n", bar);

    return 0;
}

void expand(char s1[], char s2[])
{
    int i;  // index for reading from s1
    int j = 0;  // index for writing into s2
    char c;
    for (i = 0; s1[i] != '\0'; i++) {
	if (s1[i] == '-') {
	    if (i == 0) {
		s2[j] = '-';
		j++;
	    } else if (s1[i+1] == '\0') {
		s2[j] = '-';
		j++;
	    } else {
		for (c=s1[i-1]; c<=s1[i+1]; c++,j++) {
		    if (s2[j-1] != c)
			s2[j] = c;
		    else
			j--;
		}
	    }
	}
    }
    s2[j] = '\0';
}
