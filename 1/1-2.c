#include <stdio.h>

/* Experiment to find out what happens when printf's argument
 * string contains \c, where c is some character not listed 
 * above
 */

main()
{
    printf("Alert (bell) character, \\a:\a");
    printf("\n");

    printf("Backspace, \\b:\b");
    printf("\n");

    printf("Formfeed, \\f:\f");
    printf("\n");

    printf("Newline, \\n:\n");
    printf("\n");

    printf("Carriage return, \\r:\r");
    printf("\n");

    printf("Horizontal tab, \\t:\t");
    printf("\n");

    printf("Vertical tab, \\v:\v");
    printf("\n");

    printf("Backslash, \\\\: \\");
    printf("\n");

    printf("Question mark, \\?: \?");
    printf("\n");

    printf("Single quote, \\': \'");
    printf("\n");

    printf("Double quote, \\\": \"");
    printf("\n");

    printf("Octal number, \\ooo");
    printf("\n");

    printf("Hexadecimal number, \\xhh");
    printf("\n");
}
