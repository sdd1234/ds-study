#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
  int data;
  struct TreeNode* left, * right;
} TreeNode ;

void GenerateArrayTree(int *tree){
int list[]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  for(int i=0;i<15;i++){
  tree[i]=list[i];
}
for(int i=0;i<15;i++){
  printf("%d ",tree[i]);
}
printf("\n");
}
void ArrayPreOrder(int *tree, int index){
  if(index <=15) { 
    printf("[%2d]", tree[index - 1]); 
    int left = index * 2;    
    int right = index * 2 + 1;
    if (left <= 15) {
        ArrayPreOrder(tree, left);
    }
    if (right <= 15) {
        ArrayPreOrder(tree, right);
    }
  }
}

void ArrayInOrder(int *tree, int index){
  if(index <=15) { 
    int left = index * 2;   
    int right = index * 2 + 1; 
    if (left <= 15) {
        ArrayInOrder(tree, left);
    }
    printf("[%2d]", tree[index - 1]); 
    if (right <= 15) {
        ArrayInOrder(tree, right);
    }
  }
}

void ArrayPostOrder(int *tree, int index){
  if(index <= 15) { 
    int left = index * 2;   
    int right = index * 2 + 1; 
    if (left <= 15) {
        ArrayPostOrder(tree, left);
    }
    if (right <= 15) {
        ArrayPostOrder(tree, right);
    }
    printf("[%2d]", tree[index - 1]); 
}

}
void ArrayPreOrders(int *tree,int Input){
  printf("\n전위순회  ");
  ArrayPreOrder(tree,1);
  printf("\n중위순회 ");
  ArrayInOrder(tree,1);
  printf("\n후위순회  ");
  ArrayPostOrder(tree,1);
}
TreeNode* GenerateLinkTree(int data) {
  TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

TreeNode* PlaceNode(int* values, int index, int size) {
  if (index >= size) return NULL;

  TreeNode* node = GenerateLinkTree(values[index]);
  node->left = PlaceNode(values, 2 * index + 1, size);
  node->right = PlaceNode(values, 2 * index + 2, size);

  return node;
}

void LinkPreOrder(TreeNode* root) {
  if (root != NULL) {
      printf("[%2d]", root->data);
        LinkPreOrder(root->left);
        LinkPreOrder(root->right);
  }
}

void LinkInOrder(TreeNode* root) {
  if (root != NULL) {
      LinkInOrder(root->left);
      printf("[%2d]", root->data);
      LinkInOrder(root->right);
  }
}


void LinkPostOrder(TreeNode* root) {
  if (root != NULL) {
    LinkPostOrder(root->left);
    LinkPostOrder(root->right);
      printf("[%2d]", root->data);
  }
}
void  LinkOder(TreeNode* root){
  printf("\n전위순회  ");
  LinkPreOrder(root);
  printf("\n중위순회 ");
  LinkInOrder(root);
  printf("\n후위순회  ");
  LinkPostOrder(root);
}
int main() {
  int Tree[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  int size = sizeof(Tree) / sizeof(Tree[0]);
   TreeNode* root = PlaceNode(Tree, 0,size);
  GenerateArrayTree(Tree);
  ArrayPreOrders(Tree,1);
  LinkOder(root);
 return 0;
}

