#include <stdio.h>

#define IN    1    /* inside a word */
#define OUT   0    /* outside a word */

/* write a program to print a histogram of the lengths of words in its
 * input. It easy to draw a the histogram with the bars horizontal; a
 * vertical orientation is more challenging.
 */


/* Horizontal histogram version. */

main()
{
    int c, i, j, nw, state;

    int current_word_length = 0;
    int word_lengths[100];

    for (i = 0; i < 100; ++i)
	word_lengths[i] = 0;

    state = OUT;
    nw = 0;
    while ((c = getchar()) != EOF) {
	if (c == ' ' || c == '\n' || c == '\t') {
	    if (state == IN) {
		state = OUT;
		word_lengths[nw-1] = current_word_length;
		current_word_length = 0;
	    }
	}
	else if (state == OUT) {
	    state = IN;
	    ++nw;
	    ++current_word_length;
	}
	else if (state == IN)
	    ++current_word_length;
    }

    for (i = 0; i < nw; ++i) {
	for (j = 0; j < word_lengths[i]; ++j) {
	    printf("#");
	}
	printf("\n");
    }
}
