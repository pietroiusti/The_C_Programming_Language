#include <stdio.h>

/* write a program to print a histogram of the frequencies of
   different characters in its input */

main()
{
    int c, i, j, state;

    int char_lengths[300];
    for (i = 0; i < 300; ++i) {
	char_lengths[i] = 0;
    }

    while ((c = getchar()) != EOF) {
	++char_lengths[c];
    }

    printf("\n");
    
    for (i = 0; i < 300; ++i) {
	if (char_lengths[i] != 0) {
	    printf("%c: ", i);
	    for (j = 0 ; j < char_lengths[i]; ++j) {
		printf("#");
	    }
	    printf("\n");
	}
    }
}
