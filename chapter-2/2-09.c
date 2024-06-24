#include <stdio.h>

int bitcount(unsigned);

int main() {
    printf("%d\n", bitcount(15));
    return 0;
}

int bitcount(unsigned x) {
    int b = 0;
    while (x != 0) {
        x &= (x-1);
        ++b;
    }
    return b;
}
