#include <stdio.h>

int main () {
    
    printf("Not EOF value: %d\n", getchar() != EOF);
    printf("EOF value: %d\n", !(getchar() != EOF));
    return 0;
}
