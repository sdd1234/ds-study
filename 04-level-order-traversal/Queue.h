#pragma once
#include "LevelTraversal.h"

typedef TreeNode* element;	// 요소의 타입
typedef struct QueueNode {	// 큐의 노드의 타입 
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct {		// 큐 ADT 구현
	QueueNode* front, * rear;
} LinkedQueueType;

extern void init(LinkedQueueType* q);
extern int is_empty(LinkedQueueType* q);
extern void enqueue(LinkedQueueType* q, element data);
extern element dequeue(LinkedQueueType* q);
