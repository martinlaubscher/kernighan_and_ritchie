#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    
    char c;
    char prev = '\0';

    while ((c = getchar()) != EOF) {
        if (c == '/' && prev == '/') {
            while ((c = getchar()) != '\n') ;
            prev = '\0';
            c = getchar();
        } else if (c == '*' && prev == '/') {
            while (!((c = getchar()) == '/' && prev == '*')) {
                prev = c;
            }
            prev = '\0';
            c = getchar();
        }
        
        if (prev != '\0') {
            putchar(prev);
        }
        prev = c;
    }
    putchar('\n');
}

