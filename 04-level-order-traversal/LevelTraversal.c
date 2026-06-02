#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "LevelTraversal.h"
#include "Queue.h"

int GetHeightOfTree(TreeNode* root) {
	if (root == NULL) return 0;

	LinkedQueueType q;
	init(&q);
	enqueue(&q, root);
	int height = 0;

	while (!is_empty(&q)) {
		int node_count = 0;
		QueueNode* temp = q.front;
		while (temp) {
			node_count++;
			temp = temp->link; 
		}

		while (node_count > 0) {
			TreeNode* node = dequeue(&q);
			if (node->left) enqueue(&q, node->left);
			if (node->right) enqueue(&q, node->right);
			node_count--;
		}
		if (!is_empty(&q)) {
			height++;
		}
	}
	printf("Height of Tree: %d\n", height);
	return height; 
	
}


int GetNumberOfNodes(TreeNode* root) {
	int count = 0;
	LinkedQueueType q;
	TreeNode* ptr = root;
	init(&q);	 // 큐 초기화

	if (root == NULL) return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		count++;
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
	printf("Number of nodes: %d\n", count);
	return count;
}

int GetSumOfNodes(TreeNode* root) {
	int node_sum = 0;
	LinkedQueueType q;
	TreeNode* ptr = root;
	init(&q);  // 큐 초기화

	if (root == NULL) return 0;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		node_sum += ptr->data;
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
	printf("Sum of nodes: %d\n", node_sum);
	return node_sum;
}
int level_order_x(TreeNode* root)
{
	int count=0;
	int node_sum = 0;
	LinkedQueueType q;
	TreeNode* ptr = root;
	init(&q);	 // 큐 초기화

	if (root == NULL) return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf(" [%d] ", ptr->data);
		node_sum += ptr->data;
		count++;
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
	return node_sum;
}

int GetNumberOfLeafNodes(TreeNode* root) {
	if (root == NULL) return 0;

	int leaf_count = 0;
	LinkedQueueType q;
	init(&q);
	enqueue(&q, root);

	while (!is_empty(&q)) {
		TreeNode* node = dequeue(&q);
		if (node->left == NULL && node->right == NULL) {
			leaf_count++;
		}
		if (node->left) {
			enqueue(&q, node->left);
		}
		if (node->right) {
			enqueue(&q, node->right);
		}
	}
	printf("Number of leaf nodes: %d\n", leaf_count);
	return leaf_count;
}

void GenerateLinkTree(TreeNode* root) {
	PlaceNode(root, 0, 2);
	PlaceNode(root, 1, 9);
	PlaceNode(root->left, 0, 3);
	PlaceNode(root->left, 1, 5);
	PlaceNode(root->left->left, 0, 10);
	PlaceNode(root->left->left, 1, 13);
	PlaceNode(root->left->right, 0, 7);
	PlaceNode(root->left->right, 1, 8);
	PlaceNode(root->right, 0, 4);
	PlaceNode(root->right, 1, 6);
	PlaceNode(root->right->right, 0, 11);
	PlaceNode(root->right->right, 1, 12);
	PlaceNode(root->left->right->left, 0, 14);
	PlaceNode(root->left->right->left, 1, 15);
}

void PlaceNode(TreeNode* node, int direction, int data) {
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	if (direction == 0) {
		node->left = newNode;
	}
	else if (direction == 1) {
		node->right = newNode;
	}
}


