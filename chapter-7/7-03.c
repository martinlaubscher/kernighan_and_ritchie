#include <stdio.h>
#include <stdarg.h>

void minprintf(char *, ...);

int main() {
    printf("printf\t\thex: %x, oct: %o, unsigned: %u\n", 16, 16, 16);
    minprintf("minprintf\thex: %x, oct: %o, unsigned: %u\n", 16, 16, 16);
    return 0;
}


/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...) {
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    unsigned uval;
    double dval;

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
            case 'i':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'o':
                uval = va_arg(ap, unsigned);
                printf("%o", uval);
                break;
            case 'x':
            case 'X':
                uval = va_arg(ap, unsigned);
                printf("%x", uval);
                break;
            case 'u':
                uval = va_arg(ap, unsigned);
                printf("%u", uval);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++) {
                    putchar(*sval);
                }
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); /* clean up when done */
}
