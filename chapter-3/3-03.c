#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 64

void expand(char[], char[]);
char find_limit(char, char);

int main() {

    char s1[] = "-l2-8x-";
    char s2[MAXLEN];
    
    expand(s1, s2);

    return 0;
}

void expand(char s1[], char s2[]) {
    int i, j;
    char beg, end; // track the beginning/end of the range to handle leading/trailing hyphens
    for (i = 0; s1[i] != '\0'; ++i) {
        if (isalnum(s1[i]) && s1[i+1] == '-') {
            beg = s1[i];
            end = isalnum(s1[i+2]) ? s1[i+2] : find_limit(s1[i], 'e');
            i += 2;
        } else if (s1[i] == '-' && isalnum(s1[i+1])) {
            beg = find_limit(s1[i+1], 'b');
            end = s1[i+1];
            i += 1;
        }

        while(beg <= end) {
            s2[j++] = beg++;
        }
        s2[j] = '\0';
    }
    printf("%s\n", s2);
}

char find_limit(char c, char function) {
    char beg, end;
    if (islower(c)) {
        beg = 'a';
        end = 'z';
    } else if (isupper(c)) {
        beg = 'A';
        end = 'Z';
    } else if (isdigit(c)) {
        beg = '0';
        end = '9';
    }
    switch (function) {
        case 'b':
            return beg;       
            break;
        case 'e':
            return end;
            break;
        default:
            puts("Specify 'b' to find the beginning of a range or 'e' to find the end of the range.");
            exit(0);
            break;
    }
}
