#include <stdio.h>

void horizontal()
{
    int c, count, i, j;
    int arr[15];
    
    count = 0;

    for(i = 0; i < 15; ++i)
        arr[i]=0;

    while((c = getchar()) != EOF) {
         if(c == '\n' || c == ' ' || c == '\t') {
             ++arr[count-1];
             count = 0;
         }
         else {
             ++count;
         }
    }

    for(i = 0; i < 15; ++i) {
        printf("%2d ", i+1);
        for(j = 0; j < arr[i]; ++j)
            putchar('-');
        putchar('\n');
    }
}

void vertical()
{
    int c, count, i, j, max;
    int arr[15];
    
    count = max = 0;

    for(i = 0; i < 15; ++i)
        arr[i] = 0;

    while((c = getchar()) != EOF) { 
        if(c == '\n' || c == ' ' || c == '\t') {
             ++arr[count-1];

             if(arr[count-1] > max)
                 ++max;

             count = 0;
         }
         else {
             ++count;
         }
    }
        
    for(i = max; i > 0; --i) {
        for(j = 0; j < 15; ++j) {
            if(arr[j] == i) {
                printf("%3c", '|');
                --arr[j];
            }
            else
                printf("%3c", ' ');
        }
        putchar('\n');
    }

    for(i = 1; i < 15; ++i)
        printf("%3d", i);

    putchar('\n');
}



int main()
{
    vertical();
}
