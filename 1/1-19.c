#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[]);

int main(void)
{
    char string[MAXLINE];
    int c, i;
    i = 0;
    while ( (c = getchar()) != EOF ) {
        if (c == '\n'){
            string[i] = '\0';
            reverse(string);
            printf("%s\n", string);
            i = 0;
        }
        else {
            string[i] = c;
            ++i;
        }
    }

    return 0;
}

//reverse character string s
void reverse(char s[]){
    char temp[MAXLINE];

    int length = 0;
    while ( s[length] != '\0' )
        ++length;

    int i, j;
    for (i = length-1, j = 0; i >= 0; --i, ++j) {
        temp[j] = s[i];
    }
    temp[j] = '\0';

    for (i = 0; temp[i] != '\0'; ++i)
        s[i] = temp[i];
    s[i] = '\0';
}
