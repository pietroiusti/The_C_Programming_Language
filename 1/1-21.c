#include <stdio.h>
#define MAXSTRING 1000
#define TABSTOPS 8

/* write a program entab that replaces strings of blanks
 * by the minimum number of tabs and blanks to achieve
 * the same spacing. Use the same tab stops as for detab.
 * When either a tab or a single blank would suffice to
 * reach a tab stop, which shoud be give preference?
 */

int main(void)
{
    int c, c2, i, nexttabstop;
    char result[MAXSTRING];

    for (i = 0; (c = getchar()) != EOF; i++) {
        nexttabstop = i + TABSTOPS - (i % TABSTOPS);
        if (c != ' ') //if c is not a blank write it into result[]
            result[i] = c;
        else {
            //find how many blanks
            //blank counting stops when is encountered either a char which is not blank
            //or a tabstop.
            int blanks;
            int i2 = i; //use i2 so don't mess up with i which I use as index for writing into result[]; 
            for (blanks = 1; (c2 = getchar()) == ' ' && i2 != nexttabstop; ++blanks, ++i2)
                ;
            if (c2 == ' ') { //if we have encountered a tab stop, there could be other blanks 
                while ( (c2 = getchar()) == ' ') //exhaust all remained blanks 
                    ;
            }
            if (blanks < 4){ //if blanks are less than one tab
                for (int j = 0; j < blanks; ++j, ++i) //write the right amount of blanks into result[]
                    result[i] = ' ';
                result[i] = c2; //do not forget the char next to last blank
            }
            else if (blanks == 4) { //if blanks equals a tab
                result[i] = '\t'; //write one tab into result[]
                ++i;
                result[i] = c2; //do not forget the char next to the last blank
            }
            else {
                //calculate remainder
                int remainder = blanks % 4;
                //calculate nunber of tabs
                int tabs = (blanks - remainder) / 4;
                //put tabs
                for (int j = 0; j < tabs; ++j, ++i)
                    result[i] = '\t';
                //put remaining blanks
                if (remainder > 0)
                    for (int j = 0; j < remainder; ++j, ++i)
                        result[i] = ' ';
                result[i] = c2; //do not forget the char next to the last blank
            }
        }
    }
    result[i] = '\0';

    //print result
    for (i = 0; result[i] != '\0'; i++)
        putchar(result[i]);

    return 0;
}
