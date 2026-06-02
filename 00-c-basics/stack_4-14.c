#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 5

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_full() {
    if (top == MAX_STACK_SIZE - 1) return 1;
    else return 0;
}

int is_empty() {
    if (top == -1)  return 1;
    else return 0;
}

void push(element item) {
    if (is_full()) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else {
        top = top + 1;
        stack[top] = item;
        printf("push %d\n", item);
    }
}

element pop() {
    element r;
    if (is_empty()) {
        fprintf(stderr, " 스택 공백 에러\n");
        return -1;
    }
    else {
        r = stack[top];
        top = top - 1;
        printf("pop %d\n", r);
        return r;
    }
}

int main() {
    srand(time(NULL));
    element rend_num;

    for (int i = 0; i < 30; i++) {
        rend_num = (rand() % 100) + 1;
        if (rend_num % 2 == 0) {
            push(rend_num);
        }
        else {
            pop();
        }
    }

    return 0;
}