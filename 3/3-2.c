#include <stdio.h>

/* Write a function escape(s,t) that converts characters like newline
 * and tab into visible escape sequences like \n and \t as it copies
 * the string t to s. Use a switch. Write a function for the other
 * direction as well, converting escape sequences into real
 * characters. */

void escape(char to[], char from[]);
void unescape(char to[], char from[]);

int main(void)
{
    char foo[] = "Hello \t world!\n";
    char bar[100];

    escape(bar, foo);
    printf("%s\n", bar);

    char foobar[] = "Hello \\t world!\\n";
    char baz[100];

    unescape(baz, foobar);
    printf("%s\n", baz);

    return 0;
}

void escape(char to[], char from[])
{
    int i, j;

    i = j = 0;
    
    while (from[i] != '\0') {
	switch(from[i]) {
	case '\n':
	    to[j++] = '\\';
	    to[j] = 'n';
	    break;
	case '\t':
	    to[j++] = '\\';
	    to[j] = 't';
	    break;
	default:
	    to[j] = from[i];
	    break;
	}
	i++;
	j++;
    }
}

void unescape(char to[], char from[])
{
    int i, j;

    i = j = 0;

    while (from[i] != '\0') {
	if (from[i] == '\\') {
	    i++;
	    switch(from[i]) {
	    case 'n':
		to[j] = '\n';
		break;
	    case 't':
		to[j] = '\t';
		break;
	    default:
		to[j++] = '\\';
		to[j] = from[i];
	    }
	} else {
	    to[j] = from[i];
	}
	i++;
	j++;
    }
}
