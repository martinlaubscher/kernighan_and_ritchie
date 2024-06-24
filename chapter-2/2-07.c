#include <stdio.h>

unsigned invert(unsigned, int, int);

int main() {
    printf("%u\n", invert(4007, 7, 5));
    return 0;
}

unsigned invert(unsigned x, int p, int n) {
    return (x ^ ((~(~0 << n)) << (p + 1 - n)));
}
