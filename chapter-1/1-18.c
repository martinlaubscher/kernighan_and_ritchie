#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);

int main() {
    int len;
    int line_nr = 1; 
    char line[MAXLINE];
    
    while ((len = get_line(line, MAXLINE)) > 0) {
        printf("First 1000 chars of line %d: ", line_nr);
        for (int i = 0; i < len; ++i) {
            putchar(line[i]);
        }
        ++line_nr;
    }
    putchar('\n');
    return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim) {
    int c, i;
    bool trailing = 0; // keeps track if the last encountered character was a blank
    int blank_start = 0; // keeps track where the last blank block started

    for (i = 0; (c=getchar()) != EOF && c != '\n'; ++i)
        if (i < lim - 1) {
            if (c == ' ' || c == '\t') {
                if (!trailing) {
                    trailing = 1;
                    blank_start = i;
                }
            } else {
                trailing = 0;
            }
            s[i] = c;
        }

    if (trailing) {
        i = blank_start;
    }

    if (c == '\n' && i < lim - 1) {
        s[i] = c;
        ++i;
    }
    
    s[i] = '\0';
    return i;
}

