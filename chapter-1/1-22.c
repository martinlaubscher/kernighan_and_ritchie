#include <stdio.h>
#include <stdbool.h>

#define MAXLEN 16

int main () {
    bool start = 1;
    bool blank = 0;
    int line_pos = 0;
    int buf_pos = 0;
    char c;
    char buffer[MAXLEN+1];


    while ((c = getchar()) != EOF) {
        if (buf_pos >= MAXLEN) {
            buffer[MAXLEN] = '\0';
            printf("%s\n", buffer);
            buf_pos = 0;
            line_pos = 0;
        }

        buffer[buf_pos++] = c;

        if (line_pos < MAXLEN && (c == ' ' || c == '\t')) {
            buffer[buf_pos] = '\0';
            printf("%s", buffer);
            buf_pos = 0;
        } else if (line_pos >= MAXLEN) {
            putchar('\n');
            line_pos = 0;
        }
        ++line_pos;
    }

    buffer[buf_pos] = '\0';
    printf("%s", buffer);
}

