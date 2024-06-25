#include <stdio.h>
#include <string.h>

int binsearch_old(int, int[], int);
int binsearch_new(int, int[], int);

int main(int argc, char **argv) {
    int v[5] = {1,2,3,4,5};
    if (argc != 2) {
        puts("please specify either 'old' or 'new' as the sole argument");
    } else if(strcmp(argv[1], "old") == 0) {
        printf("%d\n", binsearch_old(2, v, 5));
    } else {
        printf("%d\n", binsearch_new(2, v, 5));
    }
    return 0;
}

int binsearch_old(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid]) {
            high = mid + 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
             /* found match */
            return mid;
        }
    }
    return -1;
    /* no match */
}

int binsearch_new(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid]) {
        if (x < v[mid]) {
            high = mid + 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    if (x == v[mid]) {
        return mid;
    } else {
        return -1;
    }
}
