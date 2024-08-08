#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAXWORD 100

typedef struct lnode {
    int line;
    struct lnode *next;
} lnode;

typedef struct tnode {
    char *word;
    lnode *lines;
    lnode *lines_tail;
    struct tnode *left;
    struct tnode *right;
} tnode;

tnode *addtreex(tnode *, char *, int);
void addline(tnode *, int);
void treexprint(tnode *);
int getword(char *, int);
int comment(void);
int noise(char *);

int main() {
    tnode *root;
    char word[MAXWORD];
    int line = 1;

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && noise(word) == -1) {
            root = addtreex(root, word, line);
        } else if (word[0] == '\n') {
            ++line;
        }
    }
    treexprint(root);
    return 0;
}

tnode *addtreex(tnode *p, char *w, int line) {
    int cond;

    if (p == NULL) {
        p = (tnode *) malloc(sizeof(tnode));
        p->word = strdup(w);
        p->lines = (lnode *) malloc(sizeof(lnode));
        p->lines->line = line;
        p->lines->next = NULL;
        p->lines_tail = p->lines;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        addline(p, line);
    } else if (cond < 0) {
        p->left = addtreex(p->left, w, line);
    } else {
        p->right = addtreex(p->right, w, line);
    }
    return p;
}

void addline(tnode *p, int line) {
    lnode *tail = p->lines_tail;
    if (tail->line != line) {
        tail->next = (lnode *) malloc(sizeof(lnode));
        tail->next->line = line;
        tail->next->next = NULL;
        p->lines_tail = tail->next;
    }
}

void treexprint(tnode *p) {
    lnode *tmp;
    if (p != NULL) {
        treexprint(p->left);
        printf("%10s: ", p->word);
        for (tmp = p->lines; tmp != NULL; tmp = tmp->next) {
            printf("%4d ", tmp->line);
        }
        printf("\n");
        treexprint(p->right);
    }
}

int noise(char *w) {
    static char *nw[] = {
        "a",
        "and",
        "are",
        "in",
        "is",
        "of",
        "or",
        "that",
        "the",
        "this",
        "to"
    };
    int cond, mid;
    int low = 0;
    int high = sizeof(nw) / sizeof(char *) - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(w, nw[mid])) < 0) {
            high = mid - 1;
        } else if (cond > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c, d;
    char *w = word;

    while (isspace(c = getc(stdin))&& c != '\n') {
        ;
    }
    if (c != EOF)
        *w++ = c;
    if (isalpha(c) || c == '#' || c == '_') {
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
            }
        }
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
