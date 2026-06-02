#include <stdio.h>
#include <stdlib.h>
#include "LevelTraversal.h"
TreeNode n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15;
int main() {
    TreeNode* root = &n1;
    root->data = 1;
    GenerateLinkTree(root);
    
    GetSumOfNodes(root);
    GetNumberOfNodes(root);
	GetHeightOfTree(root);
    GetNumberOfLeafNodes(root);

    return 0;
}
