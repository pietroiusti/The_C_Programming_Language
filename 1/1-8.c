#include <stdio.h>

/*count blanks, tabs and lines*/
int main(void)
{
    int c, blanks, tabs, newlines;
    blanks = 0;
    tabs = 0;
    newlines = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n')
            ++newlines;
        if (c == ' ')
            ++blanks;
        if (c == '\t')
            ++tabs;
    }
    printf("Newlines = %d\n", newlines);
    printf("Blanks = %d\n", blanks);
    printf("Tabs = %d\n", tabs);

    return 0;
}
