#include <stdio.h>

unsigned getbits(unsigned, int, int);
unsigned setbits(unsigned, int, int, unsigned);

int main() {
    printf("%u\n", setbits(4095,7,4,283));
    return 0;
}

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // keep only the last n bits of y and shift them to the correct position
    unsigned y_comp = (~(~0 << n) & y) << (p + 1 - n);
    // in x, set n bits starting from p to 0
    unsigned x_comp = ~((~(~0 << n)) << (p + 1 - n)) & x;
    return (x_comp | y_comp);
}
