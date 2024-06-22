#include <stdio.h>

#define WIDTH 8

int detab(int, int);

int main() {
    
    char c;
    int pos = 0;
    int blanks = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            blanks = (WIDTH - 1) - (pos%WIDTH);
            pos = detab(blanks, pos);
        } else if (c == '\n') {
            pos = 0;
            putchar(c);
        } else {
            ++pos;
            putchar(c);
        }
    }
    return 0;
}

int detab (int blanks, int pos) {
    for (; blanks >= 0; --blanks) {
        putchar(' ');
        ++pos;
    }
    return pos;
}
