/*Remove nodes on root to leaf paths of length < K
Given a Binary Tree and a number k, remove all nodes that lie only on root to leaf path(s) of length smaller than k. If a node X lies on multiple root-to-leaf paths and if any of the paths has path length >= k, then X is not deleted from Binary Tree. In other words a node is deleted if all paths going through it have lengths smaller than k.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Node.h"

node *removeNodeOnPath(node *root, int sum, int k)
{
	if(root==NULL)
	  return NULL;
	root->left=removeNodeOnPath(root->left, sum+1, k);
	root->right=removeNodeOnPath(root->right, sum+1, k);
	if(sum<k && root->left==NULL && root->right==NULL)
	{
		free(root);
		return NULL;
	}
	return root;
}

int main()
{
    int k = 4;
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(7);
    root->right->right = newNode(6);
    root->right->right->left = newNode(8);
    inorderTraversal(root);
    node *new_root = removeNodeOnPath(root,1, k); 
    printf("\n after\n");
    if(root)
      printf("\n here \n");
      printf("\n root data=%d\n", root->data);
      inorderTraversal(new_root);
    return 0;
}
