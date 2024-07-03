#include <stdio.h>
#include <string.h>

#define MAXLEN 1024

void strn_cpy(char *, char *, int);
void strn_cat(char *, char *, int);
int strn_cmp(char *, char *, int);

int main() {
    char s[MAXLEN] = {0};
    char t[] = "meow";
    strn_cpy(s, t, 4);
    printf("%d\n", strn_cmp(s, t, 4));
    strn_cat(t, s, 4);
    printf("%d\n", strn_cmp(s, t, 4));
    return 0;
}

void strn_cpy(char *s, char *t, int n) {
    while (*t && n-- > 0) {
        *s++ = *t++;
    }
    while (n-- > 0) {
        *s++ = '\0';
    }
}

void strn_cat(char *s, char *t, int n) {
    strn_cpy(s+strlen(s), t, n);
}

int strn_cmp(char *s, char *t, int n) {
    while (*s == *t) {
        if (*s == '\0' || --n <= 0) {
            return 0;
        }
        s++;
        t++;
    }
    return *s - *t;
}
