/*Write C Code to Determine if Two Trees are Identical
Two trees are identical when they have same data and arrangement of data is also same.*/

#include<stdio.h>
#include<stdlib.h>
#include "Node.h"
#include <stdbool.h>

bool isIdentical(node *root1, node *root2)
{
	if(root1==NULL && root2==NULL)
	  return 1;
	else if(root1!=NULL && root2!=NULL)
	{
		return (root1->data==root2->data)
			&& isIdentical(root1->left, root2->left)
			&& isIdentical(root1->right, root2->right);
	}
	else
	  return 0;
}

int main()
{
	node *root1 = newNode(1);
	node *root2 = newNode(1);
	root1->left = newNode(2);
	root1->right = newNode(3);
	root1->left->left  = newNode(4);
	root1->left->right = newNode(5); 

	root2->left = newNode(2);
	root2->right = newNode(3);
	root2->left->left = newNode(4);
	root2->left->right = newNode(5); 

	if(isIdentical(root1, root2))
		printf("Both tree are identical.");
	else
		printf("Trees are not identical.");

	getchar();
	return 0;
}
