#include <stdio.h>

/* Write a function expand(s1,s2) that expands shorthand notations
   like a-z in the string s1 into the equivalent complete list
   abc...xyz in s2. Allow for letters of either case and digits, and
   be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
   that a leading or trailing - is taken literally. */

void expand(char s1[], char s2[]);

int main(void)
{
    char foo[] = "a-z";
    char bar[1000];

    expand(foo, bar);

    printf(bar);

    return 0;
}

void expand(char s1[], char s2[])
{
    char foo = s1[0];
    int i;
    for (foo = s1[0], i = 0; foo <= s1[2]; foo++, i++) {
	s2[i] = foo;
    }
    s2[i] = '\0';
    // TODO: handle multiple expansions and leading/trailing '-'
}

