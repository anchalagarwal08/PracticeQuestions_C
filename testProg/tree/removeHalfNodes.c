/*
Given A binary Tree, how do you remove all the half nodes (which has only one child)? Note leaves should not be touched as they have both children as NULL.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Node.h"

node *removeHalfNodes(node *root)
{
	if(root==NULL)
	  return NULL;
	root->left = removeHalfNodes(root->left);
	root->right = removeHalfNodes(root->right);
	if(root->left ==NULL && root->right==NULL)
		return root;
	if(root->left ==NULL)
	{
		node *new_root = root->right;
		free(root);
		return new_root;
	}
	if(root->right ==NULL)
	{
		node *new_root = root->left;
		free(root);
		return new_root;
	}

	return root;
}

int main(){

    node *root = newNode(2);
    root->left        = newNode(7);
    root->right       = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left=newNode(1);
    root->left->right->right=newNode(11);
    root->right->right=newNode(9);
    root->right->right->left=newNode(4);
    inorderTraversal(root);
    printf("\n");
    root = removeHalfNodes(root);
    inorderTraversal(root);
    return 0;
}
