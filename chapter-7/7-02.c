#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100
#define HEXLEN 7

int main() {
    int c, pos;
    int inc(int, int);

    pos = 0;
    
    while ((c = getchar()) != EOF) {
        if (iscntrl(c) || c == ' ') {
            pos = inc(pos, HEXLEN);
            printf(" \\0x%02x ", c);
            if (c == '\n') {
                pos = 0;
                putchar('\n');
            }
        } else {
            pos = inc(pos, 1);
            putchar(c);
        }
    }
    return 0;
}

int inc(int pos, int n) {
    if (pos + n < MAXLINE) {
        return pos+n;
    } else {
        putchar('\n');
        return n;
    }
}
