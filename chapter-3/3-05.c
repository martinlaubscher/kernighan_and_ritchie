#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void itoa(int, char[], int);
void reverse(char[]);

int main() {
    char s[64];
    itoa(123, s, 16);
    printf("%s\n", s);
    return 0;
}

void itoa(int n, char s[], int b) {
    int i, j, sign;
    if ((sign = n) < 0) {            /* record sign */
        n = abs(n);
    }
    i = 0;
    do {                            /* generate digits in reverse order */
        j = n % b;                  /* get next digit */
        s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
    } while ((n /= b) > 0);        /* delete it */
    if (sign < 0)
        s[i++] = '-';
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
