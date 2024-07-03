#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define NAME 'n'
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100
#define MAXLINE 1000

int getop(char []);
void push(double);
double pop(void);
double peek(void);
void duplicate(void);
void swap(void);
void clear(void);
void mathfnc(char []);
int get_line(char[], int);

int sp = 0; /* next free stack position */
double val[MAXVAL];  /* value stack */

int li = 0;
char line[MAXLINE];

/* reverse Polish calculator */
int main() {
    int type, var;
    double op2, v;
    char s[MAXOP];
    double variable[26] = {0.0};

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:
            mathfnc(s);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            v = pop();
            printf("\t%.8g\n", v);
            break;
        case '?':
            peek();
            break;
        case 'd':
            duplicate();
            break;
        case 's':
            swap();
            break;
        case 'c':
            clear();
            break;
        case '=':
            pop();
            if (var >= 'A' && var <= 'Z') {
                variable[var - 'A'] = pop();
            } else {
                puts("no variable");
            }
            break;
        default:
            if (type >= 'A' && type <= 'Z') {
                push(variable[type - 'A']);
            } else if (type == 'v') {
                push(v);
            } else {
                printf("error: unknown command %s\n", s);
            }
            break;
        }
        var = type;
    }
    return 0;
}

/* getop: get next character or numeric operand */
int getop(char s[]) {
    int i, c;
    
    if (line[li] == '\0') {
        if (get_line(line, MAXLINE) == 0) {
            return EOF;
        } else {
            li = 0;
        }
    }

    while ((s[0] = c = line[li++]) == ' ' || c == '\t') {
        ;
    }

    s[1] = '\0';
    i = 0;

    if (islower(c)) {
        while (islower(s[++i] = c = line[li++]))
            ;
        s[i] = '\0';
        if (c != EOF)
            --li;
        if (strlen(s) > 1)
            return NAME;
        else
            return c;
    }

    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* not a number */
    if (c == '-') 
        if (isdigit(c = line[li++]) || c =='.')
            s[++i] = c;
        else {
            if (c != EOF)
                --li;
            return '-';
        }
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = line[li++]))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = line[li++]))
            ;
    s[i] = '\0';
    if (c != EOF)
        --li;
    return NUMBER;
}

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}


double peek(void) {
    if (sp > 0) {
        return val[sp-1];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void duplicate(void) {
    push(peek());
}

void swap(void) {
    if (sp > 1) {
        int tmp1 = pop();
        int tmp2 = pop();
        push(tmp1);
        push(tmp2);
    } else {
        puts("error: less than two elements in the stack.");
    }
}


void clear(void) {
    sp = 0;
}

void mathfnc(char s[]) {
    double op2;

    if (strcmp(s, "sin") == 0) {
        push(sin(pop()));
    } else if (strcmp(s, "exp") == 0) {
        push(exp(pop()));
    } else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    } else {
        printf("unknown command '%s'\n", s);
    }
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; (c=getchar()) != EOF && c != '\n'; ++i)
        if (i < lim - 1) {
            s[i] = c;
        }

    if (c == '\n' && i < lim - 1) {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

