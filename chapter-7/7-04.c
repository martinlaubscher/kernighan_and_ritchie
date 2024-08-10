#include <stdio.h>
#include <stdarg.h>

void minscanf(char *, ...);

int main() {
    int day, year;
    char monthname[20];
    scanf("%d %s %d", &day, monthname, &year);
    printf("scanf\t\tDay:%d, Month: %s, Year: %d\n", day, monthname, year);
    minscanf("%d %s %d", &day, monthname, &year);
    printf("minscanf\tDay:%d, Month: %s, Year: %d\n", day, monthname, year);
    return 0;
}

void minscanf(char *fmt, ...) {
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int *ival;
    unsigned *uval;
    double *dval;

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            continue;
        }
        switch (*++p) {
            case 'd':
            case 'i':
                ival = va_arg(ap, int *);
                scanf("%d", ival);
                break;
            case 'o':
                uval = va_arg(ap, unsigned *);
                scanf("%o", uval);
                break;
            case 'x':
            case 'X':
                uval = va_arg(ap, unsigned *);
                scanf("%x", uval);
                break;
            case 'u':
                uval = va_arg(ap, unsigned *);
                scanf("%u", uval);
                break;
            case 'f':
                dval = va_arg(ap, double *);
                scanf("%lf", dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                scanf("%s", sval);
                break;
            default:
                break;
        }
    }
    va_end(ap); /* clean up when done */
}
