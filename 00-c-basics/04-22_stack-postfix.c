#include <stdio.h>
#include <stdlib.h> 

#define MAX_STACK_SIZE 10

typedef int element;
typedef struct Stacktype {
    element* data;
    int capacity;
    int top;
} StackType;

void init(StackType* sptr, int ofs) {
    sptr->data = (element*)malloc(sizeof(element) * ofs);
    sptr->top = -1;
    sptr->capacity = ofs;
}

int is_full(StackType* sptr) {
    return (sptr->top == sptr->capacity - 1);
}

int is_empty(StackType* sptr) {
    return (sptr->top == -1);
}

void push(StackType* sptr, element item) {
    if (is_full(sptr)) {
        fprintf(stderr, "Stack is full\n");
        return;
    }
    sptr->top++;
    sptr->data[sptr->top] = item;
}

element pop(StackType* sptr) {
    if (is_empty(sptr)) {
        fprintf(stderr, "Stack is empty\n");
        return -1;
    }
    return sptr->data[sptr->top--];
}

int eval(char* expression) {
    StackType s;
    init(&s, 20);
    int i = 0;
    while (expression[i] != '\0') {
        int ch = expression[i];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int op1 = pop(&s);
            int op2 = pop(&s);
            switch (ch) {
            case '+': push(&s, op2 + op1); break;
            case '-': push(&s, op2 - op1); break;
            case '*': push(&s, op2 * op1); break;
            case '/': push(&s, op2 / op1); break;
            }
        }
        else if (ch >= '0' && ch <= '9') {
            push(&s, ch - '0');
        }
        
        i++;
    }
    return pop(&s);
}

int main() {
    char expr[20];
    printf("postfix Expression: ");
    fgets(expr, sizeof(expr), stdin);
    int result = eval(expr);
    printf("Result: %d\n", result);
    return 0;
}