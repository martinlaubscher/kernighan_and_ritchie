#include <stdio.h>
#include <string.h>

void escape(char[], char[]);
void unescape(char[], char[]);

int main() {
    char s[] = "meow\nmeow\tmeow";
    char t[strlen(s)*2+1];
    escape(s, t);
    printf("%s\n", t);
    unescape(s, t);
    printf("%s\n", t);
    return 0;
}

void escape(char s[], char t[]) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; ++i) {
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            default:
                t[j++] = s[i];
                break;
        }
    }
    t[j] = '\0';
}

void unescape(char s[], char t[]) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; ++i) {
        switch (s[i]) {
            case '\\':
                if (s[i+1] == 'n') {
                    t[j++] = s[i++];
                } else if (s[i+1] == 't') {
                    t[j++] = s[i++];
                } else {
                    t[j++] = s[i];
                }
                break;
            default:
                t[j++] = s[i];
                break;
        }
    }
    t[j] = '\0';
}
