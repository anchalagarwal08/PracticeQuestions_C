/*Given a binary tree, print out all of its root-to-leaf paths one per line.*/
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

void printRootToLeaf(node *root, int pathlen, int *arr)
{
	if(root==NULL)
	  return;
	int i=0;
	arr[pathlen]=root->data;
	if(root->right==NULL && root->left==NULL)
	{
		printf("\n");
		for(i=0;i<=pathlen;i++)
		  printf("%d ",arr[i]);
	}
	printRootToLeaf(root->left, pathlen+1,arr);
	printRootToLeaf(root->right,pathlen+1,arr);
}

int main()
{
	node *root 	  = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5); 
	int pathlen=0;
	int arr[50];
	/* Print all root-to-leaf paths of the input tree */
	printRootToLeaf(root,pathlen,arr);

	getchar();
	return 0;


}
