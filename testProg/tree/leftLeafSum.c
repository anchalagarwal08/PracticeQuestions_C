/*Find sum of all left leaves in a given Binary Tree*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Node.h"

int leftLeafSum(node *root, int isLeft, int *sum)
{
	if(root==NULL)
	  return 0;
	if(root->left ==NULL & root->right==NULL && isLeft)
	  *sum = *sum +root->data;
	leftLeafSum(root->left, 1, sum);
	leftLeafSum(root->right, 0, sum);
	return *sum;
}

int main()
{
    int sum = 0;
    node *root         = newNode(20);
    root->left                = newNode(9);
    root->right               = newNode(49);
    root->right->left         = newNode(23);
    root->right->right        = newNode(52);
    root->right->right->left  = newNode(50);
    root->left->left          = newNode(5);
    root->left->right         = newNode(12);
    root->left->right->right  = newNode(12);
    printf("\n %d\n", leftLeafSum(root, 0, &sum));
    return 0;
}
