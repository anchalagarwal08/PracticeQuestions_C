/*to Convert a Binary Tree into its Mirror Tree*/
#include <stdio.h>
#include<stdlib.h>
#include "Node.h"

node *mirrorTree(node *root)
{
	if(root==NULL)
	  return NULL;
	node *new = newNode(root->data);
	new->right= mirrorTree(root->left);
	new->left = mirrorTree(root->right);
	return new;
}

int main()
{
	node *root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5); 
	printf("\n older \n");
	inorderTraversal(root);
	printf("\n mirror:\n");
	node *new = mirrorTree(root);
	inorderTraversal(new);
	printf("\n");
	return 0;
}
