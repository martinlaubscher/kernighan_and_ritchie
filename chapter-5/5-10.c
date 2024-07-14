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

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
double peek(void);
void duplicate(void);
void swap(void);
void clear(void);
void mathfnc(char []);
void ungets(char []);


int sp = 0; /* next free stack position */
double val[MAXVAL];  /* value stack */

int buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/* reverse Polish calculator */
int main(int argc, char **argv) {
    int type, var;
    double op2, v;
    char s[MAXOP];
    double variable[26] = {0.0};

    while (--argc > 0) {
        ungets(" ");
        ungets(*++argv);
        switch (type = getop(s)) {
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
    printf("%f\n", pop());
    return 0;
}

/* getop: get next character or numeric operand */
int getop(char s[]) {
    int i, c;
    static int lastc = 0;

    if (lastc == 0) {
        c = getch();
    } else {
        c = lastc;
        lastc = 0;
    }
    
    while ((s[0] = c) == ' ' || c == '\t')
        c = getch();

    s[1] = '\0';
    i = 0;

    if (islower(c)) {
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c!= EOF)
            lastc = c;
        if (strlen(s) > 1)
            return NAME;
        else
            return c;
    }

    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* not a number */
    if (c == '-') 
        if (isdigit(c = getch()) || c =='.')
            s[++i] = c;
        else {
            if (c != EOF)
                lastc = c;
            return '-';
        }
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        lastc = c;
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

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
 /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[]) {
    int len = strlen(s);

    while (len > 0) {
        ungetch(s[--len]);
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

