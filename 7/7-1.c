#include <stdio.h>
#include <ctype.h>

/*
  Write a program that converts upper case to lower or lower case to
  upper, depending on the name it is invoked with, as found in argv[0].
*/

char *getname(char *input);
int my_strcmp(char *s1, char *s2);

int main(int argc, char *argv[])
{
    int c;
    char *name = getname(argv[0]);

    if (my_strcmp("uppertolower", name) == 0)
	while ((c = getchar()) != EOF)
	    putchar(tolower(c));
    else if (my_strcmp("lowertoupper", name) == 0)
	while ((c = getchar()) != EOF)
	    putchar(toupper(c));
    else
	printf("Name not recognized...\n");
	    
    return 0;
}

/* Return part of input between last forward slash and end. Return
   input if no forward slash is present */
char *getname(char *input)
{
    int i = 0;
    int fslash_index = -1; // store index of last forward slash we find

    while (input[i] != '\0') {
	if (input[i] == '/')
	    fslash_index = i;
	i++;
    }

    if (fslash_index == -1) {
	return input;
    } else {
	char *pt = input + fslash_index;
	return pt+1;
    }
}

// The function assumes that there is a null character at the end of
// s1, and that s1 and s2 have the same length...
int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0') {
	if (s1[i] != s2[i])
	    return -1;
	i++;
    }
    return 0;
}
