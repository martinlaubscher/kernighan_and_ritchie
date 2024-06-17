#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */

int main () {
    float fahr, celsius;
    float lower, upper, step;
    lower = -20;
    upper = 150;
    step = 5;

    celsius = lower;
    
    printf("%s %13s\n", "Celsius", "Fahrenheit");

    while (celsius <= upper) {
        fahr = (celsius / (5.0 / 9.0)) + 32.0;
        printf("%7.0f %13.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}
