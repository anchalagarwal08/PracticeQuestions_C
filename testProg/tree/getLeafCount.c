/*Get leaf count in a binary tree*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Node.h"

void getLeafCount(node *root, int *count)
{
	if(root==NULL)
	  return;
	if(root->right==NULL && root->left==NULL)
	  (*count)++;
	getLeafCount(root->left, count);
	getLeafCount(root->right, count);
}

int main()
{
	node *root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5);    
	root->right->left= newNode(8);
        root->right->right = newNode(9);
	int count =0;
	getLeafCount(root,&count);
	printf("\n count = %d",count);
	return 0;
}
