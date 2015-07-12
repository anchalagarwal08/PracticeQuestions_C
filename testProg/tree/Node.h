#include <stdio.h>
#include <stdlib.h>
typedef struct Node node;
struct Node{
	node *left;
	node *right;
	int data;
};

node *newNode(int val)
{
  node *temp = (node*)malloc(sizeof(node));
  temp->left=NULL;
  temp->right =NULL;
  temp->data=val;
  return temp;
}

node* createBST()
{
 node *root = newNode(19);
 root->left = newNode(6);
 root->right = newNode(30);
 root->left->left = newNode(4);
 root->left->right = newNode(8);
 root->right->left = newNode(29);
 root->right->right = newNode(40);
 root->right->right->left = newNode(38);
 root->right->right->right = newNode(42);
 return root;
}

void inorderTraversal(node *root)
{
	if(root==NULL)
	  return;
	inorderTraversal(root->left);
	printf("%d ,", root->data);
	inorderTraversal(root->right);
}
