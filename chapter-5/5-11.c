#include <stdio.h>
#include <stdlib.h>

#define WIDTH "8"
#define TAB 8

void entab(int, char **);
void detab(int, char **);
int settab(int, int, int);
void setblank(int, int);

int main(int argc, char **argv) {

    char *width[] = {WIDTH};

    if (argc < 2) {
        puts("Insufficient arguments. Use 'e' for entab, 'd' for detab");
    }
    else if (*argv[1] == 'e') {
        argc == 2 ? entab(--argc, width) : entab(argc-2, argv+2);
    } else if (*argv[1] == 'd') {
        argc == 2 ? detab(--argc, width) : detab(argc-2, argv+2);
    } else {
        puts("Unexpected argument. Use 'e' for entab, 'd' for detab.");
    }
    return 0;    
}


void entab(int argc, char **tabs) {
    char c;
    int pos = 0;
    int blanks = 0;
    int i = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
            while ((c = getchar()) == ' ') {
                ++blanks;
            }
        } else if (c == '\n') {
            pos = 0;
            i = 0;
        }
        while (blanks > 0) {
            int width = atoi(tabs[i%argc]);
            blanks = settab(pos, blanks, width);
            ++i;
        }
        putchar(c);
        ++pos;
    }
}

void detab(int argc, char **tabs) {
    char c;
    int pos = 0;
    int blanks = 0;
    int i = 0;
    int width;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            width = atoi(tabs[i%argc]);
            blanks = width - (pos%width);
            setblank(blanks, pos);
            pos = 0;
            ++i;
        } else if (c == '\n') {
            pos = 0;
            i = 0;
            putchar(c);
        } else {
            ++pos;
            putchar(c);
        }
    }
}

int settab(int pos, int blanks, int width) {
    if (TAB - pos%width <= blanks) {
        blanks -= (TAB - pos%width);
        putchar('\t');
    } else {
        while (--blanks >= 0) {
            putchar(' ');
        }
    }
    return blanks;
}

void setblank(int blanks, int pos) {
    while (--blanks >= 0) {
        putchar(' ');
        ++pos;
    }
}
