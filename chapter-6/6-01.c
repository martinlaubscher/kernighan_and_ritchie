#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXWORD 100

int getword(char*, int);
int comment(void);

int main() {
    char word[MAXWORD];
    getword(word, MAXWORD-1);
    printf("%s\n", word);
    return 0;
}

/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c, d;
    char *w = word;

    while (isspace(c = getc(stdin))) 
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c) || c == '#' || c == '_') {
        for (; --lim > 0; ++w) {
            if (!isalnum(*w = getc(stdin)) && *w != '_') {
                ungetc(*w, stdin);
                break;
            }
        }
    } else if (c == '\'' || c == '"') {
        for (; --lim > 0; ++w) {
            if ((*w = getc(stdin)) == '\\') {
                *++w = getc(stdin);
            } else if (*w == c) {
                ++w;
                break;
            } else if (*w == EOF) {
                break;
            } else if ( c == '/') {
                if ((d = getc(stdin)) == '*') {
                    c = comment();
                } else {
                    ungetc(d, stdin);
                }
            }
            *w = '\0';
            return c;
        }
    *w = '\0';
    return word[0];
    }
}

int comment(void) {
    int c;
    while ((c = getc(stdin)) != EOF) {
        if (c == '*') {
            if ((c = getc(stdin)) == '/') {
                break;
            } else {
                ungetc(c, stdin);
            }
        }
    }
    return c;
}
