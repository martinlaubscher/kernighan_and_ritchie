#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 128

void compare(FILE *, FILE *);

int main(int argc, char **argv) {
    FILE *fp1, *fp2;
    if (argc != 3) {
        fprintf(stderr, "Please specify two filenames as arguments.\n");
        exit(1);
    } else {
        if ((fp1 = fopen(*++argv, "r")) == NULL) {
            fprintf(stderr, "can't open %s\n", *argv);
            exit(1);
        } else if ((fp2 = fopen(*++argv, "r")) == NULL) {
            fprintf(stderr, "can't open %s\n", *argv);
            exit(1);
        } else {
            compare(fp1, fp2);
            fclose(fp1);
            fclose(fp2);
            exit(0);
        }
    }
}

void compare(FILE *fp1, FILE *fp2) {
    char line1[MAXLINE], line2[MAXLINE];
    char *lp1, *lp2;

    do {
        lp1 = fgets(line1, MAXLINE, fp1);
        lp2 = fgets(line2, MAXLINE, fp2);
        if (lp1 == line1 && lp2 == line2) {
            if (strcmp(line1, line2) != 0) {
                printf("Difference found!\nfile1:\t%sfile2:\t%s", line1, line2);
                lp1 = lp2 = NULL;
                return;
            }
        } else if (lp1 != line1 && lp2 == line2) {
            printf("End of file 1 at line:\n%s\n", line2);
        } else if (lp1 == line1 && lp2 != line2) {
            printf("End of file 2 at line:\n%s\n", line1);
        }
    } while (lp1 == line1 && lp2 == line2);

    puts("No difference found.");
}
