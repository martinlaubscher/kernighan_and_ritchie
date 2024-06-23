#include <stdio.h>

int any(char[], char[]);

int main() {
    char s1[] = "meowmeow";
    char s2[] = "diver";
    int pos = any(s1, s2);
    if (pos == -1) {
        puts("None of the characters in s2 occur in s1.");
    } else {
        printf("The first character of s2 that occurs in s1 is \'%c\' at position %d.\n", s1[pos], pos);
    }
    return 0;
}

int any(char s1[], char s2[]) {
    for (int i = 0; s1[i] != '\0'; i++) {
        for(int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }
    return -1;
}

