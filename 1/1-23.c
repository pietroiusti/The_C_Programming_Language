#include <stdio.h>

#define MAXSTRING 1000

/* Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments do not nest.
 */

/* Single line comments are not contemplated */ 

int main(void)
{
    int i, c, c2;

    // 0 means we are not within a comment, 1 that we are
    int status = 0;

    //the final string
    char result[MAXSTRING];

    i = 0;
    while ((c = getchar()) != EOF) {
        if (status == 0) { //if we are not within a comment 
            if (c == '"') { // char strings case
                result[i] = c;
                ++i;
                while ( (c = getchar()) != '"' ){
                    result[i] = c;
                    ++i;
                }
                result[i] = c;
                ++i;
            }
            else if (c == '/') { //check if we are going into a comment
                if((c2 = getchar()) == '*'){
                    status = 1;
                }
                else { //if c was '/' but c2 wasn't a '*' that's not a comment
                       //so we write both chars into result
                    result[i] = c; 
                    ++i;
                    result[i] = c2;
                    ++i;
                }
            }
            else { //if c wasn't a '/' it's not the case of a comment
                   //so we writo the char into result
                result[i] = c;
                ++i;
            }
        }
        else { //if we are within a comment
            if (c == '*' && (c2 = getchar()) == '/') 
                status = 0;
        }
    }
    result[i] = '\0';

    printf("%s", result);

    return 0;
}
