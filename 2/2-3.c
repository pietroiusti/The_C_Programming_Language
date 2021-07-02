#include <stdio.h>
#include <ctype.h>

/* Write the function htoi(s), which converts a string of hexadecimal
 * digits (including an optional 0x or 0X) into its equivalent integer
 * value.  The allowable digits are 0 through 9, a through f, and A
 * through F.
 */

int htoi(char s[]);

int main(void)
{
    char hexadecimal[] = "0xAb67";

    printf("%d\n", htoi(hexadecimal));

    return 0;
}

int htoi(char s[]) {
    int i = 0;
    int n = 0;
    
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i += 2;
    
    while ( isdigit(s[i]) || (s[i] >= 'a' && s[i] <= 'f') ||
            (s[i] >= 'A' && s[i] <= 'F')) {
        if ( isdigit(s[i]) )
            n = 16 * n + (s[i] - '0');    
        else
            n = 16 * n + (tolower(s[i]) - 'W');
        i++;
    }

    return n;
}
