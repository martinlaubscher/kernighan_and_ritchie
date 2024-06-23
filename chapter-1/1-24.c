#include <stdio.h>

#define MAXSIZE 1024

//TODO comments and quotes...

typedef struct {
    int top;
    char arr[MAXSIZE];
} stack;

void push(char, stack*);
char pop(stack*);
char peek(stack*);

int main() {
    int line = 1;
    char c;
    stack stk;
    stk.top = -1;
    
    while ((c = getchar()) != EOF) {
        if(c == '(' || c == '[' || c == '{') {
            push(c, &stk);
        } else if (c == ')') {
            if (peek(&stk) != '(') {
                printf("Unmatched parentheses on line %d\n", line);
            } else {
                pop(&stk);
            }
        } else if (c == ']') {
            if (peek(&stk) != '[') {
                printf("Unmatched brackets on line %d\n", line);
            } else {
                pop(&stk);
            }
        } else if (c == '}') {
            if (peek(&stk) != '{') {
                printf("Unmatched braces on line %d\n", line);
            } else {
                pop(&stk);
            }
        } else if (c == '\n') {
            ++line;
        } 
    }

    while (stk.top > -1) {
        printf("%c not closed\n", stk.arr[stk.top--]);
    }
}

void push(char c, stack* stk) {
    if (stk->top >= MAXSIZE-1) {
        puts("stack overflow");
    } else {
        stk->arr[++stk->top] = c;
    }
}

char pop(stack* stk) {
    if (stk->top == -1) {
        return -1;
    } else {
        return stk->arr[stk->top--];
    }
}

char peek(stack* stk) {
    if (stk->top == -1) {
        return -1;
    } else {
        return stk->arr[stk->top];
    }
}

