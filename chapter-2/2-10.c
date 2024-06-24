#include <stdio.h>

char lower(char);

int main() {
    char c;
    while ((c = getchar()) != EOF) {
        putchar(lower(c));
    }
    putchar('\n');
    return 0;
}

char lower(char c) {
    int offset = 'a' - 'A';
    return (c >= 'A' && c <= 'Z') ? (c + offset) : c;
}
