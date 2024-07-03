#include <stdio.h>
#include <string.h>

#define MAXLEN 1024

void reverse(char[], int, int);

int main () {
    char s[] = "meow";
    reverse(s, 0, strlen(s)-1);
    printf("%s\n", s);
    return 0;
}

void reverse(char s[], int beg, int end) {
    int tmp;
    if (beg < end) {
        tmp = s[beg];
        s[beg] = s[end];
        s[end] = tmp;
        reverse(s, ++beg, --end);
    }
}
