#include <stdio.h>
#include <stdlib.h>

/* Write a program to print a set of files, starting each new one on a
 * new page, with a title and a running page count for each file. */

void print_file(char *);
void filecopy(FILE * ifp, FILE *ofp);
void print_page_footer(int page);
void print_page_header(char *title, int page);

int main(int argc, char *argv[]) {
    
    FILE *fp;
    char *prog = argv[0];
    int page = 0;

    if (argc == 1)
	printf("No arguments given...");
    else
	while (--argc > 0)
	    if ((fp = fopen(*++argv, "r")) == NULL) {
		fprintf(stderr, "%s: can't open %s\n", prog, *argv);
		exit(1);
	    } else {
		page++;
		print_page_header(*argv, page);
		filecopy(fp, stdout);
		print_page_footer(page);
		fclose(fp);
	    }
    if (ferror(stdout)) {
	fprintf(stderr, "%s: error writing stdout\n", prog);
	exit(2);
    }

    return 0;
}

void print_file(char * filename) {
    FILE *fp = fopen(filename, "r");
    
    int c;

    while ((c = getc(fp) != EOF))
	putc(c, stdout);
    
    fclose(fp);
}

void filecopy(FILE *ifp, FILE *ofp) {
    int c;

    while ((c = getc(ifp)) != EOF)
	putc(c, ofp);
}

void print_page_header(char *title, int page) {
    printf("####################\tp. %d\t\t####################\n", page); 
    printf("####################\t%s\t\t####################\n", title);
}

void print_page_footer(int page) {
    printf("####################\tEnd of p. %d\t####################", page);
    printf("\n\n");
}
