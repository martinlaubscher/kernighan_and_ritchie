#include <stdio.h>

#define IN 1    //in a blank string
#define OUT 0   //outside a blank string

int main() {
    int c, state;
    state = OUT;

    while ((c = getchar()) != EOF) {
        if (state == OUT) {
            putchar(c);
            if (c == ' ') {
                state = IN;
            }
        }
        else if (c != ' ') {
            putchar(c);
            state = OUT;
        }
    }
    return 0;
}
