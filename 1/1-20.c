#include <stdio.h>
#define MAXSTRING 1000

int main(void)
{
    int n = 3;
    int c, i;
    char input[MAXSTRING];

    for (i = 0; (c = getchar()) != EOF; i++) {
        if (c == '\t') {
            while (i % n != 0) {
                input[i] = ' ';
                ++i;
            }
            i--;
        } 
        else {
            input[i] = c;
        }
    }
    input[i] = '\0';

    for (i = 0; input[i] != '\0'; i++)
        putchar(input[i]);

    return 0;
}

/*

n = 4
hello\tworld becomes:
hello   world
^   ^   ^   ^ 
123456789

n = 3
hello\tworld becomes:
hello world
^  ^  ^  ^  
123456789
*/
