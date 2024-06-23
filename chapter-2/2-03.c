#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAXSIZE 17 //unsigned long long is 64 bits, i.e. 16 hex digits (+ /0 terminator for string)

unsigned long long htoi(char[]);

int main() {
    char s[MAXSIZE];
    unsigned long long converted;
    char c;
    int i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (!(c <= '9' && c >= '0') && !(c <= 'f' && c >= 'a') && !(c <= 'F' && c >= 'A')) {
            puts("Input contains invalid character. Allowed are: 0-9, a-f, A-F.");
            exit(0);
        } else if (i >= MAXSIZE - 1) {
            puts("Maximum 16 characters.");
            exit(0);
        } else {
            s[i++] = c;
        }
    }
    s[i] = '\0';
    
    converted = htoi(s);

    printf("hex %s is equal to decimal %llu.\n", s, converted);

    return 0;
}

unsigned long long htoi(char* s) {
    int len = strlen(s)-1;
    int exp = 0;
    int digit;
    char hex;
    unsigned long long tmp, res;
    res = 0;
    for (; len >= 0; len--) {
        hex = s[len];
        switch (hex) {
            case 'a':
            case 'A':
                digit = 10;
                break;
            case 'b':
            case 'B':
                digit = 11;
                break;
            case 'c':
            case 'C':
                digit = 12;
                break;
            case 'd':
            case 'D':
                digit = 13;
                break;
            case 'e':
            case 'E':
                digit = 14;
                break;
            case 'f':
            case 'F':
                digit = 15;
                break;
            default:
                digit = (int) (hex - '0');
        }

        tmp = digit * pow(16, exp++);
        res += tmp;
    }

    return res;
} 
