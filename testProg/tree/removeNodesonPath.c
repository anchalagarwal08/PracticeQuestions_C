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

node *removeNodesSumOnPath(node *root, int sum, int k)
{
	if(root==NULL)
	  return NULL;

//	int lsum = *sum + root->data;
//	int rsum = lsum;
	sum = sum+root->data;
	root->left = removeNodesSumOnPath(root->left, sum, k);
	root->right = removeNodesSumOnPath(root->right, sum, k);
//	*sum = lsum>rsum?lsum:rsum;
	if(root->left==NULL && root->right ==NULL)
	{
		if(sum<k){
		free(root);
		return NULL;
		}
	
	}
	return root;

}
int main()
{/*
    int k = 4;
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(7);
    root->right->right = newNode(6);
    root->right->right->left = newNode(8);
  */
  /*tree for sum problem sum>=k*/
    int k = 45;
    int sum=0;
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(12);
    root->right->right->left = newNode(10);
    root->right->right->left->right = newNode(11);
    root->left->left->right->left = newNode(13);
    root->left->left->right->right = newNode(14);
    root->left->left->right->right->left = newNode(15);

    inorderTraversal(root);
    node *new_root = removeNodesSumOnPath(root,0, k); 
    printf("\n after\n");
    if(new_root)
      printf("\n here:%d \n", new_root->data);
      inorderTraversal(new_root);
    return 0;
}
