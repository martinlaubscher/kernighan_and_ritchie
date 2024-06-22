#include <stdio.h>

#define WIDTH 8

void entab(int);

int main() {
    
    char c;
    int blanks = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
            while ((c = getchar()) == ' ') {
                ++blanks;
            }
        }
        if (blanks > 0) {
            entab(blanks);
            blanks = 0;
        }
        putchar(c);
    }
}


void entab(int blanks) {
    for (; blanks > WIDTH; blanks -= WIDTH) {
        putchar('\t');
    }
    for (; blanks > 0; --blanks) {
        putchar(' ');
    }
}
