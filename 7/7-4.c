#include <stdio.h>
#include <stdarg.h>

/* Write a private version of scanf analogous to minprintf from the
 * previous section */

void minscanf(char *fmt, ...);

int main(void)
{
    int i, c;
    float f;
    char s[100];

    minscanf("%d %f %s", &i, &f, s);
    printf("%d %.2f %s\n", i, f, s);

    return 0;
}

void minscanf(char *fmt, ...)
{
    va_list ap;
    char *p;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
	if (*p != '%') {
	    if (*p == ' ' || *p == '\t')
		continue;
	}
	switch (*++p) {
	case 'd':
	    scanf("%d", va_arg(ap, int *) );
	    break;
	case 'c':
	    scanf("%c", va_arg(ap, int *));
	    break;
	case 'f':
	    scanf("%f", va_arg(ap, float *));
	    break;
	case 's':
	    scanf("%s", va_arg(ap, char *));
	    break;
	default:
	    break;
	}
    }
    va_end(ap);
}
    
