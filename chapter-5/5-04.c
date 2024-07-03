#include <stdio.h>
#include <stdbool.h>

bool strend(char *, char *);

int main() {
    char s[] = "hello, world";
    char t[] = "world";
    char s2[] = "world, hello";
    printf("%d\n", strend(s, t));
    printf("%d\n", strend(s2, t));
    return 0;
}

bool strend(char *s, char *t) {
    char *bt = t; //beg of t
    while (*s) {
        ++s;
    }
    while (*t) {
        ++t;
    }
    while (t - bt > 0) {
        if (*--t != *--s) {
            return 0;
        }
    }
    return 1;
}

