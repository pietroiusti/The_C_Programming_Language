#include <stdio.h>

#define MAXSTRING 1000

/*
 * Write a program to check a C program for rudimentary
 * syntax errors like unbalanced parentheses, brackets
 * and braces. Don't forget about quotes, both single
 * and double, escape sequences, and comments. (this
 * program is hard if you do it in full generality.)
 */

int main(void)
{
    char input[MAXSTRING];

    int i, c;

    /*store input into input[]*/
    for (i = 0; (c = getchar()) != EOF; ++i) {
        input[i] = c;
    }
    input[i] = '\0';

    /* Count parentheses, brackets, braces, single and double quotes
     * and check if they are even. 
     * Careful to:
     *      '(', ')', '[', ']', '{', '}'
     *
     *      "(", ")", "[", "]", "{", "}"
     *
     *      '\'', '\"' (and '"' ?)
     *
     *      "\'", "\"" (and "'" ?)
     *      
     *      comments
     */

    int leftparentheses, rightparentheses, leftbrackets, rightbrackets, leftbraces, rightbraces, singlequotes, doublequotes;
    leftparentheses = rightparentheses = leftbrackets = rightbrackets = leftbraces = rightbraces = singlequotes = doublequotes = 0;
    for (i = 0; input[i] != '\0'; ++i) {

        /*comments*/
        if (input[i] == '/' && input[i+1] == '*'){
            while (input[i-1] != '*' || input[i] != '/') {
                ++i;
                if (input[i] == '\0') {
                    printf("Missing '*/' to terminate comment\n");
                    return 1;
                }
            }
        }

        /*single quotes*/
        if (input[i] == '\'') {
            if (input[i+2] == '\'') {
                singlequotes = singlequotes + 2;
                i = i + 2;
            }
            else if (input[i+1] == '\\' && input[i+3] == '\'') {
                singlequotes = singlequotes + 2;
                i = i + 3;
            }
            else {
                printf("Some problem with single quotes!\n");
                return 1;
            }
        }

        /*double quotes*/
        if (input[i] == '\"') {
            ++doublequotes;
            ++i;
            while (input[i] != '\"') { //we don't count anything if we are within a string
                ++i;
                if ( input[i] == '\0' ) {
                    printf("Missing \"\n");
                    return 1;
                }
            }
            ++doublequotes;
        }

        /*count parentheses, brackets and braces which are not within two
         * single quotes or within /' and a single quote
         */
        if (input[i] == '(' && (input[i-1] != '\'' || input[i+1] != '\''))
            ++leftparentheses;
        if (input[i] == ')' && (input[i-1] != '\'' || input[i+1] != '\''))
            ++rightparentheses;
        if (input[i] == '[' && (input[i-1] != '\'' || input[i+1] != '\''))
            ++leftbrackets;
        if (input[i] == ']' && (input[i-1] != '\'' || input[i+1] != '\''))
            ++rightbrackets;
        if (input[i] == ']' && (input[i-1] != '\'' || input[i+1] != '\''))
            ++rightbrackets;
        if (input[i] == '{' && (input[i-1] != '\'' || input[i+1] != '\''))
            ++leftbraces;
        if (input[i] == '}' && (input[i-1] != '\'' || input[i+1] != '\''))
            ++rightbraces;
    }

    if (leftparentheses != rightparentheses) {
        printf("Parentheses don't match\n");
        return 1;
    }
    if (leftbrackets != rightbrackets) {
        printf("Brackets don't match\n");
        return 1;
    }
    if (leftbraces != rightbraces) {
        printf("Braces don't match\n");
        return 1;
    }
    if ((doublequotes % 2) != 0) {
        printf("Double quotes don't match");
        return 1;
    }

    if ((leftparentheses == rightparentheses) &&
         (leftbrackets    == rightbrackets   ) &&
         (leftbraces      == rightbraces     ) &&
         ((doublequotes % 2) == 0))
        printf("Everything seems all right!\n");

    return 0;
}
