#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void itoa(int, char[], int);
void reverse(char[]);

int main() {
    char s[64];
    itoa(123, s, 8);
    printf("%s\n", s);
    itoa(12345678, s, 8);
    printf("%s\n", s);
    return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int w) {
    int i, sign;
    sign = n;                       /* record sign */
    i = 0;
    do {                            /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0'; /* get next digit - turning only the mod positive solves the issue*/
    } while ((n /= 10) > 0);        /* delete it */
    if (sign < 0)
        s[i++] = '-';
    while (i < w) {
        s[i++] = ' ';                /* add padding */
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
