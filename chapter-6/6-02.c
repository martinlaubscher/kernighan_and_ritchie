#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAXWORD 100

typedef struct tnode {
    char *word;
    int match;
    struct tnode *left;
    struct tnode *right;
} tnode;

tnode *addtreex(tnode *, char *, int, bool *);
void treexprint(tnode *);
int compare(char *, tnode *, int, bool *);
int getword(char *, int);
int comment(void);

int main(int argc, char **argv) {
    tnode *root;
    char word[MAXWORD];
    bool found = 0;
    int num;

    num = (argc > 1 && isdigit((*++argv)[0])) ? atoi(argv[0]) : 6;
    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && strlen(word) >= num) {
            root  = addtreex(root, word, num, &found);
        }
        found = 0;
    }
    treexprint(root);
    return 0;
}

tnode *addtreex(tnode *p, char *w, int num, bool *found) {
    int cond;
    if (p == NULL) {
        p = (tnode *) malloc(sizeof(tnode));
        p->word = strdup(w);
        p->match = *found;
        p->left = p->right = NULL;
    } else if ((cond = compare(w, p, num, found)) < 0) {
        p->left = addtreex(p->left, w, num, found);
    } else if (cond > 0) {
        p->right = addtreex(p->right, w , num, found);
    }
    return p;
}

int compare(char *s, tnode *p, int num, bool *found) {
    int i;
    char *t = p->word;

    for (i = 0; *s == *t; i++, s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    if (i >= num) {
        *found = 1;
        p->match = 1;
    }
    return *s - *t;
}


void treexprint(tnode *p) {
    if (p != NULL) {
        treexprint(p->left);
        if (p->match) {
            printf("%s\n", p->word);
        }
        treexprint(p->right);
    }
}

/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c, d;
    char *w = word;

    while (isspace(c = getc(stdin))) {
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
