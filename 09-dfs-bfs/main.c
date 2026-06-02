#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 100
#define MAX_QUEUE_SIZE 100
#define MAX_VERTICES 100

typedef struct {
	int data[MAX_STACK_SIZE];
	int top;
} StackType;

typedef struct {
	int data[MAX_QUEUE_SIZE];
	int front;
	int rear;
} QueueType;

typedef struct {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphMatType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, int item) {
	if (is_full(s)) {
		fprintf(stderr, "Stack is full\n");
		return;
	}
	s->data[++(s->top)] = item;
}

int pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	return s->data[(s->top)--];
}

int peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	return s->data[s->top];
}

void init_queue(QueueType* q) {
	q->front = 0;
	q->rear = 0;
}

bool is_empty_queue(QueueType* q) {
	return q->front == q->rear;
}

bool is_full_queue(QueueType* q) {
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(QueueType* q, int item) {
	if (is_full_queue(q)) {
		fprintf(stderr, "Queue is full\n");
		exit(1);
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

int dequeue(QueueType* q) {
	if (is_empty_queue(q)) {
		fprintf(stderr, "Å½»ö ½ÇÆÐ\n");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int peek_queue(QueueType* q) {
	if (is_empty_queue(q)) {
		fprintf(stderr, "Queue is empty\n");
		exit(1);
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}



GraphMatType* create_mat_graph() { //그래프생성
	return (GraphMatType*)malloc(sizeof(GraphMatType));
}

void destroy_mat_graph(GraphMatType* g) { //그래프삭제
	free(g);
}

void init_mat_graph(GraphMatType* g) { //그래프 초기화
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++)
		for (int j = 0; j < MAX_VERTICES; j++)
			g->adj_mat[i][j] = 0;
}

//버텍스 삽입
void insert_vertex_mat_graph(GraphMatType* g, int v) {
	if ((g->n) >= (MAX_VERTICES - 1)) {
		fprintf(stderr, "Over number of vertex\n");
		return;
	}
	(g->n)++;
}

//엣지 삽입
void insert_edge_mat_graph(GraphMatType* g, int s, int e) {
	if (g->n <= s || g->n <= e) {
		fprintf(stderr, "vertex number error\n");
		return;
	}
	g->adj_mat[s][e] = 1;
	g->adj_mat[e][s] = 1;
}


void print_adj_mat(GraphMatType* g) {
	printf("     ");
	for (int i = 0; i < g->n; i++) {
		printf(" %02d ", i);
	}
	printf("\n_____");
	printf("_______");
	printf("\n");
	for (int i = 0; i < g->n; i++) {
		printf(" %02d: ", i);
		for (int j = 0; j < g->n; j++)
			printf(" %02d ", g->adj_mat[i][j]);
		printf("\n");
	}
}

//깊이우선탐색함수 
void DFS(GraphMatType* g, int start, int target, int* count) {
	int visited[MAX_VERTICES] = { 0 };
	StackType stack;
	init_stack(&stack);

	push(&stack, start);
	visited[start]++;

	while (!is_empty(&stack)) {
		int current = peek(&stack);
		printf("%d ", current);
		(*count)++;

		if (current == target) {
			printf("\n탐색 성공 : %d\n", target);
			printf("방문한 노드의 수 : %d\n", *count);
			return;
		}

		int next_node = -1;
		for (int i = 0; i < g->n; i++) {
			if (g->adj_mat[current][i] && visited[i] == 0) {
				next_node = i;
				break;
			}
		}

		if (next_node != -1) {
			push(&stack, next_node);
			visited[next_node]++;
		}
		else {
			pop(&stack);
		}
	}

	printf("\n탐색 실패\n");
}

//너비우선탐색험슈
void BFS(GraphMatType* g, int start, int target, int* count) {
	int visited[MAX_VERTICES] = { 0 };
	QueueType queue;
	init_queue(&queue);

	enqueue(&queue, start);
	visited[start]++;

	while (!is_empty(&queue)) {
		int current = dequeue(&queue);
		printf("%d ", current);
		(*count)++;

		if (current == target) {
			printf("\n탐색 성공 : %d\n", target);
			printf("방문한 노드의 수 : %d\n", *count - 1);
			return;
		}

		for (int i = 0; i < g->n; i++) {
			if (g->adj_mat[current][i] && visited[i] == 0) {
				enqueue(&queue, i);
				visited[i]++;
			}
		}
	}

	printf("\n탐색 실패\n");
}

//인터페이스 구성
void runUserInterface(GraphMatType* root) {
	while (true) {
		for (int i = 0; i < 15; i++) {
			printf("ㅡ");
		}

		printf("\n");
		printf("| 1   : 깊이 우선 탐색        |\n");
		printf("| 2   : 너비 우선 탐색        |\n");
		printf("| 3   : 종료                  |\n");

		for (int i = 0; i < 15; i++) {
			printf("ㅡ");
		}

		printf("\n메뉴 입력: ");

		int select;
		scanf_s("%d", &select);

		switch (select) {
		case 1:
			printf("시작 번호와 탐색할 값 입력: ");
			int start_vertex, search_value;
			int count = 0;
			if (scanf("%d %d", &start_vertex, &search_value) != 2) {
				printf("잘못된 입력입니다.\n");
				while (getchar() != '\n'); 
				continue;
			}
			DFS(root, start_vertex, search_value, &count);
			break;

		case 2:
			printf("시작 번호와 탐색할 값 입력: ");
			int start_vertex1, search_value1;
			int count1 = 0;
			if (scanf("%d %d", &start_vertex1, &search_value1) != 2) {
				printf("잘못된 입력입니다.\n");
				while (getchar() != '\n'); 
				continue;
			}
			BFS(root, start_vertex1, search_value1, &count1);
			break;

		case 3:
			return;

		default:
			printf("잘못된 입력입니다.\n");
			break;
		}
	}
}

int main() {

	GraphMatType* g;

	g = create_mat_graph();
	init_mat_graph(g);

	insert_vertex_mat_graph(g, 0);
	insert_vertex_mat_graph(g, 1);
	insert_vertex_mat_graph(g, 2);
	insert_vertex_mat_graph(g, 3);
	insert_vertex_mat_graph(g, 4);
	insert_vertex_mat_graph(g, 5);
	insert_vertex_mat_graph(g, 6);
	insert_vertex_mat_graph(g, 7);
	insert_vertex_mat_graph(g, 8);
	insert_vertex_mat_graph(g, 9);
	insert_vertex_mat_graph(g, 10);
	insert_edge_mat_graph(g, 0, 2);
	insert_edge_mat_graph(g, 0, 4);
	insert_edge_mat_graph(g, 0, 5);
	insert_edge_mat_graph(g, 0, 6);
	insert_edge_mat_graph(g, 0, 9);
	insert_edge_mat_graph(g, 1, 4);
	insert_edge_mat_graph(g, 1, 7);
	insert_edge_mat_graph(g, 1, 10);
	insert_edge_mat_graph(g, 1, 5);
	insert_edge_mat_graph(g, 2, 3);
	insert_edge_mat_graph(g, 2, 4);
	insert_edge_mat_graph(g, 3, 4);
	insert_edge_mat_graph(g, 3, 5);
	insert_edge_mat_graph(g, 4, 5);
	insert_edge_mat_graph(g, 4, 6);
	insert_edge_mat_graph(g, 4, 7);
	insert_edge_mat_graph(g, 6, 7);
	insert_edge_mat_graph(g, 6, 8);
	insert_edge_mat_graph(g, 7, 10);
	insert_edge_mat_graph(g, 8, 9);
	insert_edge_mat_graph(g, 8, 10);
	runUserInterface(g);

	destroy_mat_graph(g);

}