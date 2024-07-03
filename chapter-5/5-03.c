#include <stdio.h>
#include <string.h>

#define MAXBUF 1024

void stringcat(char *, char *);

int main() {
    char t[] = "meow";
    char s[MAXBUF] = {0};
    stringcat(s, t);
    printf("%s\n", s);
    char t2[] = " and another meow";
    stringcat(s, t2);
    printf("%s\n", s);
    return 0;
}

void stringcat(char *s, char *t) {
    while (*s) {
        ++s;
    }
    while (*s++ = *t++) {
        ;
    }
}
