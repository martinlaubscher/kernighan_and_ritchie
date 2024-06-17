#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("%s", "\\t");
        } else if (c == '\b') {
            printf("%s", "\\b");
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
    }
    return 0;
}
