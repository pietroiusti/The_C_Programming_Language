#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXSTRING 100

/* Write the function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 through 9, a through f, and A through F.
 */

int htoi(char s[]);
void reverse(char s[]);
int hextoint(char h);
int ctoi(char s);
int power(int base, int n);
void rmhexprefix(char s[]);

int main(void)
{
    char hexadecimal[MAXSTRING] = "0xAb67";

    printf("%d\n", htoi(hexadecimal));

    return 0;
}

/* remove (in place) the prefix 0x or 0X of a hexadecimal string */
void rmhexprefix(char s[])
{
    int i, j;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        for (i = 2, j = 0; s[i] != '\0'; ++i, ++j) {
            s[j] = s[i]; 
        }
    }
    s[j] = '\0';
}

int htoi(char s[])
{
    /* copy string in a new one (so we don't change the original) */
    char s2[MAXSTRING];
    int i;
    for (i = 0; s[i] != '\0'; ++i) {
        s2[i] = s[i];
    }
    s2[i] = '\0';

    /* remove the 0x or 0X */
    rmhexprefix(s2);
    /* reverse string */
    reverse(s2);    

    /* calculate decimale */
    int result = 0;
    for (i = 0; s2[i] != '\0'; ++i) {
        result = result + ( (hextoint(s2[i])) * power(16, i) );
    }

    return result;
}

/* reverse character string s */
void reverse(char s[])
{
    char temp[MAXSTRING];

    int i, j;
    for (i = strlen(s)-1, j = 0; i >= 0; --i, ++j) {
        temp[j] = s[i];
    }
    temp[j] = '\0';

    for (i = 0; temp[i] != '\0'; ++i)
        s[i] = temp[i];
    s[i] = '\0';
}

/*  hextoint: turn one of the 16 primitive hexadecimal numbers(in form of char)
 *  into its decimal equivalent.
 */
int hextoint(char h)
{
    if (ctoi(h) >= 0 && ctoi(h) <= 9)
        return ctoi(h);
    else {
        if (h == 'a' || h == 'A')
            return 10;
        else if (h == 'b' || h == 'B')
            return 11;
        else if (h == 'c' || h == 'C')
            return 12;
        else if (h == 'd' || h == 'D')
            return 13;
        else if (h == 'e' || h == 'E')
            return 14;
        else if (h == 'f' || h == 'F')
            return 15;
    }
}

/* ctoi: convert char into  the integer it represents */
int ctoi(char s)
{
    return s - 48;
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}
