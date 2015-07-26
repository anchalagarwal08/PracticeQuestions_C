/*Given a Bnary tree. Find all paths resulting into the given sum. The path need not start from root or end in a leaf*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Node.h"

/*Prints the path with a given sum. Follow the approach of finding contiguous subsequence in an array =sum*/
void findSumPath(node *root, int *arr, int sum, int size)
{
	if(root==NULL)
	  return;
	arr[size] = root->data;
	if(root->left==NULL && root->right==NULL)
	{
		contigSubseqSum(arr, sum,&size);
		return;
	}
	findSumPath(root->left, arr, sum, size+1);
	findSumPath(root->right, arr, sum,size+1);
}

int main()
{
	node *root;
	int arr[50] ={0,};
	int size=-1;
	root = newNode(10);
	root->left = newNode(5);
	root->right = newNode(-3);
	root->left->left = newNode(3);
	root->left->right = newNode(1);
	root->left->right->right = newNode(2);
	root->left->left->left = newNode(3);
	root->left->left->right = newNode(-2);
	root->right->right = newNode(11);
	findSumPath(root,arr,8,0);
	return 0;
}
