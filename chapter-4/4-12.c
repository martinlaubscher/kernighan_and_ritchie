#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 64

void itoa(int, char[]);
void reverse(char[]);

int main() {
    char s[MAXLEN];
    itoa(-123, s);
    printf("%s\n", s);
    return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
    
    static int i;

    if (n / 10) {
        itoa(n / 10, s);
    } else {
        i = 0;
        if (n < 0) {
            s[i++] = '-';
        }
    }

    s[i++] = (abs(n) % 10) + '0';
    s[i] = '\0';
    return;
}

