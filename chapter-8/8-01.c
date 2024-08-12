#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

void error(char *, char*);
void filecopy(int, int);

int main(int argc, char **argv) {
    int fd_in;
    if (argc == 1) {
        filecopy(0, 1);
    } else {
        while (--argc > 0) {
            if ((fd_in = open(*++argv, O_RDONLY, 0)) == -1) {
                error("cat: can't open %s", *argv);
            } else {
                filecopy(fd_in, 1);
                close(fd_in);
            }
        }
    }
    return 0;
}

void filecopy(int fd_in, int fd_out) {
    int n;
    char buf[BUFSIZ];

    while ((n = read(fd_in, buf, BUFSIZ)) > 0) {
        if (write(fd_out, buf, n) != n) {
            error("cp: write error%s", "");
        }
    }
}

void error(char *fmt, char *s) {
    fprintf(stderr, fmt, s);
    fprintf(stderr, "\n");
    exit(1);
}
