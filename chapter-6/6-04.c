#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define NDISTINCT 1000

typedef struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
} tnode;

tnode *addtreex(tnode *, char *);
void storetreex(tnode *);
void sort();
int getword(char *, int);
int comment(void);

tnode *list[NDISTINCT];
int ntn = 0;

int main() {
    tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtreex(root, word);
        }
    }
    storetreex(root);
    sort();
    for (int i = 0; i < ntn; ++i) {
        printf("%2d:%20s\n", list[i]->count, list[i]->word);
    }

    return 0;
}

tnode *addtreex(tnode *p, char *w) {
    int cond;
    if (p == NULL) {
        p = (tnode *) malloc(sizeof(tnode));
        p->word = strdup(w);
        ++(p->count);
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        ++(p->count);
    } else if (cond < 0) {
        p->left = addtreex(p->left, w);
    } else {
        p->right = addtreex(p->right, w);
    }
    return p;
}

void storetreex(tnode *p) {
    if (p != NULL) {
        storetreex(p->left);
        if (ntn < NDISTINCT) {
            list[ntn++] = p;
        }
        storetreex(p->right);
    }
}

void sort() {
    int gap, i, j;
    tnode *tmp;

    for (gap = ntn/2; gap > 0; gap /= 2) {
        for (i = gap; i < ntn; i++) {
            for (j = i - gap; j >= 0; j -= gap) {
                if ((list[j]->count) >= (list[j+gap]->count)) {
                    break;
                }
                tmp = list[j];
                list[j] = list[j+gap];
                list[j+gap] = tmp;
            }
        }
    }
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
