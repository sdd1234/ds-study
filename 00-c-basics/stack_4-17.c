#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

 #define MAX_STACK_SIZE 5

typedef int element;
typedef struct Stacktype {
    element* data;
    int capacity;
    int top;
} StackType;

void init(StackType* sptr) {
    sptr->data = (element*)malloc(sizeof(element) * MAX_STACK_SIZE);
    sptr->top = -1;
    sptr->capacity = MAX_STACK_SIZE;
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
    else {
        if (sptr->top == sptr->capacity - 1) {
            sptr->capacity += 30;
            element* new_data = (element*)realloc(sptr->data, sizeof(element) * sptr->capacity);
            if (new_data == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                return;
            }
            sptr->data = new_data;
        }
        sptr->top++;
        sptr->data[sptr->top] = item;
    }
}

element pop(StackType* sptr) {
    if (is_empty(sptr)) {
        fprintf(stderr, "Stack is empty\n");
        return -1;
    }
    else {
        return sptr->data[sptr->top--];
    }
}

element peek(StackType* sptr) {
    if (is_empty(sptr)) {
        fprintf(stderr, "Stack is empty\n");
        return -1;
    }
    else {
        return sptr->data[sptr->top];
    }
}

int main() {
    StackType s;
    int rand_num;

    srand(time(NULL));

    init(&s);

    for (int i = 0; i < 30; i++) {
        rand_num = rand() % 100 + 1;
        printf("%d \n", rand_num);
        if (rand_num % 2 == 0) {
            if (!is_full(&s)) {
                push(&s, rand_num);
                printf("Push Stack S %d\n", rand_num);
            }
            else {
                printf("Stack is full\n");
            }
        }
        else {
            if (!is_empty(&s)) {
                rand_num = pop(&s);
                printf("Pop Stack S %d\n", rand_num);
            }
            else {
                printf("Stack is empty\n");
            }
        }
    }
    return 0;
}
