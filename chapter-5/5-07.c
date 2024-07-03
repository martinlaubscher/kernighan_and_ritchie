#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000    /* max length of any input line */
#define MAXBUF 5000

int get_line(char *,  int);
int readlines(char*[], char*, int);
void writelines(char*[], int);

char *lineptr[MAXLINES];

int main() {
    int nlines;     /* number of input lines read */
    char buf[MAXBUF];

    if ((nlines = readlines(lineptr, buf, MAXLINES)) >= 0) {
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big\n");
        return 1;
    }
}

/* getline:  read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* readlines:  read input lines */
int readlines(char *lineptr[], char *buf, int maxlines)
{
    int len, nlines;
    char line[MAXLEN];
    char *p = buf;
    char *stop = buf + MAXBUF;

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || p + len == stop)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}

/* writelines:  write output lines */
void writelines(char *lineptr[],  int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

