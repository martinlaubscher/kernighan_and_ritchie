#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define THRESHOLD 80 /* print lines longer than this */

int get_line(char line[], int maxline);

int main() {
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > THRESHOLD) {
            printf("First 1000 chars of line: %s", line);
        }
    }
    putchar('\n');
    return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; (c=getchar()) != EOF && c != '\n'; ++i)
        if (i < lim - 1) {
            s[i] = c;
        }

    if (c == '\n' && i < lim - 1) {
        s[i] = c;
        ++i;
    }
    
    s[i] = '\0';
    return i;
}

