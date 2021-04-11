#include <stdarg.h>

/* minprintf: minimal printf with variable argument list */

void minprintf(char *fmt, ...)
{
    va_list ap; /* points to each unnamee arg in turn */
    char *p, *sval;
    int ival;
    double dval;
    unsigned uval;

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++) {
	if (*p != '%') {
	    putchar(*p);
	    continue;
	}
	switch (*++p) {
	case 'd':
	    ival = va_arg(ap, int);
	    printf("%d", ival);
	    break;
	case 'c':
	    ival = va_arg(ap, int);
	    printf("%c", ival);
	    break;
	case 'f':
	    dval = va_arg(ap, double);
	    printf("%f", dval);
	    break;
	case 'e':
	    dval = va_arg(ap, double);
	    printf("%e", dval);
	    break;
	case 'a':
	    dval = va_arg(ap, double);
	    printf("%a", dval);
	    break;
	case 'g':
	    dval = va_arg(ap, double);
	    printf("%g", dval);
	    break;
	case 'u':
            uval = va_arg(ap, unsigned int);
            printf("%u", uval);
            break;
	case 'o':
	    uval = va_arg(ap, unsigned int);
	    printf("%o", ival);
	    break;
	case 'x':
	    uval = va_arg(ap, unsigned int);
	    printf("%x", ival);
	    break;
	case 's':
	    for (sval = va_arg(ap, char *); *sval; sval++)
		putchar(*sval);
	    break;
	default:
	    putchar(*p);
	    break;
	}
    }
    va_end(ap); /* clean up when done */
}
