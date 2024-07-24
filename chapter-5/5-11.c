#include <stdio.h>
#include <stdlib.h>

#define WIDTH "8"

void entab(int, char **);
void detab(int, char **);
int settab(int, int);
int setblank(int, int);

int main(int argc, char **argv) {

    //char **width;
    //*width = WIDTH;
    
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
    int blanks = 0;
    int i = 0;

    //printf("argc: %d", argc);

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
            while ((c = getchar()) == ' ') {
                ++blanks;
            }
        }
        while (blanks > 0) {
            int width = *tabs[i%argc] - '0';
            blanks = settab(blanks, width);
            //printf("\nblanks: %d\twidth:%d\targc: %d\ti: %d\ti++%%argc: %d\n", blanks, width, argc, i, (i%argc));
            ++i;
        }
        putchar(c);
    }
}

void detab(int argc, char **tabs) {
    char c;
    int pos = 0;
    int blanks = 0;
    int i = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int width = *tabs[i%argc] - '0';
            blanks = (width - 1) - (pos%width);
            pos = setblank(blanks, pos);
            ++i;
        } else if (c == '\n') {
            pos = 0;
            putchar(c);
            i = 0;
        } else {
            ++pos;
            putchar(c);
        }
    }
}

int settab(int blanks, int width) {
    if (blanks >= width) {
        blanks -= width;
        putchar('\t');
    } else {
        while (--blanks > 0) {
            putchar(' ');
        }
    }
    //printf("\nblanks: %d\n", blanks);
    return blanks;
}

int setblank (int blanks, int pos) {
    for (; blanks >= 0; --blanks) {
        putchar(' ');
        ++pos;
    }
    return pos;
}
