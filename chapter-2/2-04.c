#include <stdio.h>
#include <stdbool.h>

void squeeze(char[], char[]);

int main() {

    char s1[] = "meowmeow";
    char s2[] = "oe";
    
    squeeze(s1, s2);
    return 0;
}

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    k = 0;
    bool del;

    for (i = 0; s1[i] != '\0'; i++) {
        del = 0;
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                del = 1;
                break;
            }
        }
        if (!del) {
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0';
    printf("%s\n", s1);
}



