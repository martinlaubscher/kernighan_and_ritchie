#include <stdio.h>

unsigned rightrot(unsigned, int);

int main() {
    printf("%u\n", rightrot(2415,4));
    return 0;
}

unsigned rightrot(unsigned x, int n) {
    // extract last n bits
    unsigned x_last = ~(~0 << n) & x;
    //shift last n bits to the start
    unsigned x_last_shifted = x_last << (sizeof(unsigned) * 8 - n);
    return (x >> n) | x_last_shifted;
}
