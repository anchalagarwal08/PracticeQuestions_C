#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Node.h"
#include <stdbool.h>
int countNodes(node *root, int *count)
{
	if(root==NULL)
	  return 0;
	countNodes(root->left, count);
	(*count)++;
	countNodes(root->right, count);
	return *count;
}

bool checkBinary(node *root, int i, int count)
{
	if(root==NULL)
	  return true;
	if(i>=count)
	  return false;
	return (checkBinary(root->left, 2*i+1, count) && checkBinary(root->right, 2*i+2, count));
}

int main()
{
    node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);   
    int count=0;
    count = countNodes(root, &count);
    printf("\n no. of nodes = %d\n", count);
    printf("\n %d\n", checkBinary(root, 0, count));
    return 0;
}
