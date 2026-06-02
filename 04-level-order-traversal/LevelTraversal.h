#pragma once

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

extern int level_order_x(TreeNode* root);
extern int GetSumOfNodes(TreeNode* root);
extern int GetNumberOfNodes(TreeNode* root);
extern int GetHeightOfTree(TreeNode* root);
extern int GetNumberOfLeafNodes(TreeNode* root);
extern void GenerateLinkTree(TreeNode* root);
extern void PlaceNode(TreeNode* node, int direction, int data);
