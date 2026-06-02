#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char* message) {
    fprintf(stderr, "%s", message);
    return -1;
}

int is_full(QueueType* q) {
    return (q->front == ((q->rear + 1) % MAX_QUEUE_SIZE));
}

int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

void enqueue(QueueType* q, element item) {
    if (is_full(q)) {
        error("Queue is full\n");
    }
    else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->data[q->rear] = item;
    }
}

element dequeue(QueueType* q) {
    if (is_empty(q)) {
        error("Queue is empty\n");
    }
    else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        return (q->data[q->front]);
    }
}

void print_queue(QueueType* q) {
    int i;
    for (i = (q->front + 1) % MAX_QUEUE_SIZE; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("[%2d] %2d ", i, q->data[i]);
    }
    printf("[%2d] %2d\n", i, q->data[i]);
}


main() {

    QueueType queue;
    element e;
    init_queue(&queue);
    while (1) {
        printf("1,큐에 원소를 삽입\n");
        printf("2,큐에서 원소를 삭제\n");
        printf("3,큐의원소를출력\n");
        printf("4,종료\n");
        printf("메뉴를 선택하시오:\n");
        scanf("%d", &e);
        switch (e)
        {
        case 1:
            printf("입력해주세요");
            scanf("%d", &e);
            enqueue(&queue, e);
            printf("입력완료");
            break;
        case 2:
            dequeue(&queue);
            break;
        case 3:
            print_queue(&queue);
            break;
        case 4:
            exit(0);
        default:
            printf("잘못된 입력입니다.\n");
        }
    }
}
