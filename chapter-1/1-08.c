#include <stdio.h>

int main () {
    int c, blanks, tabs, newlines;
    blanks = 0;
    tabs = 0;
    newlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++newlines;
        } else if (c == '\t') {
            ++tabs;
        } else if (c == ' ') {
            ++blanks;
        }
    }

    printf("blanks: %d\ntabs: %d\nnewlines: %d\n", blanks, tabs, newlines);
    return 0;
}
