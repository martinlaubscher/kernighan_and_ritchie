#include <stdio.h>

#define swap(t, x, y) { t _tmp; \
                        _tmp = y; \
                        y = x; \
                        x = _tmp; }

int main() {
    int i = 1;
    int j = 2;
    printf("i before swap: %d, j before swap: %d\n", i, j);
    swap(int, i, j);    
    printf("i after swap: %d, j after swap: %d\n", i, j);
    return 0;
}
