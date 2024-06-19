#include <stdio.h>

#define MAX_ASCII 127 //max ascii value

int main() {
    int c;
    int max = 0;
    int arr[MAX_ASCII+1];
    
    for (int i = 0; i <= MAX_ASCII; ++i)
        arr[i] = 0;

    while ((c = getchar()) != EOF) { 
        ++arr[c];
        if(arr[c] > max) {
            ++max;
        }
    }

    putchar('\n');
        
    for (int i = max; i > 0; --i) {
        for (int j = 0; j <= MAX_ASCII; ++j) {
            if (arr[j] == i) {
                printf("%3c", '|');
                if (--arr[j] == 0) {
                    arr[j] = 1;
                }
            } else if (arr[j] > 0) {
                printf("%3c", ' ');
            }
        }
        putchar('\n');
    }

    for (int i = 0; i <= MAX_ASCII; ++i) {
        if (arr[i] > 0) {
            if (i > 31) {
                printf("%3c", (char) i);
            } else if (i == '\n') {
                printf("%3s", "\\n");
            } else if (i == '\t') {
                printf("%3s", "\\t");
            } else if (i == '\r') {
                printf("%3s", "\\r");
            }
        }
    }

    putchar('\n');
    return 0;
}
