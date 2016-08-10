#include <stdio.h>
#define MAXBLANKS 100
#define MAXSTRING 1000

void removeblanklines(char s[]);

int main(void)
{
    char string[MAXSTRING];
    int c, c2, c3;
    int j = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t') {
            //putchar(c);
            string[j] = c;
            ++j;
        }
        else { 
            int i;
            char temp[MAXBLANKS]; 
            if (c == ' ')
                temp[0] = ' ';
            else
                temp[0] = '\t';

            for (i = 1; (c2 = getchar()) == ' ' || c2 == '\t'; ++i)
                temp[i] = c2;
            if (c2 != '\n') { //if they are not trailing
                temp[i] = c2;
                ++i;
                temp[i] = '\0';
                //printf("%s", temp);
                for (i = 0; temp[i] != '\0'; ++i, ++j) {
                    string[j] = temp[i];    
                }
            }
            else {//if they are trailing
               //putchar('\n'); 
               string[j] = '\n';
               ++j;
            }
        }
    }
    string[j] = '\0';

    removeblanklines(string);

    printf("%s", string);

    return 0;
}

void removeblanklines(char s[])
{
    char temp[1000];

    int i, j;

    for (i = 0, j = 0; s[i] != '\0'; ++i, ++j) {
        if ( s[i] != '\n')
            temp[j] = s[i];
        else {
            temp[j] = '\n';
            while (s[i] == '\n')
                ++i;
            ++j;
            temp[j] = s[i];
        }
    }
    temp[i] = '\0';

    for (i = 0; temp[i] != '\0'; ++i) {
        s[i] = temp[i];
    }
    s[i] = '\0';
}
