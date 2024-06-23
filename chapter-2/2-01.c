#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("signed char range: %d - %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char range: %d - %d\n", 0, UCHAR_MAX);
    printf("signed short range: %d - %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short range: %d - %d\n", 0, USHRT_MAX);
    printf("signed int range: %d - %d\n", INT_MIN, INT_MAX);
    printf("unsigned int range: %d - %u\n", 0, UINT_MAX);
    printf("signed long range: %ld - %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long range: %d - %lu\n", 0, ULONG_MAX);

    return 0;
}


