/*Find second max element in a BST*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Node.h"

void findSecondMaxBST(node *root, int n, int *count)
{
	if(root==NULL || *count>=n)
	  return ;
	findSecondMaxBST(root->right, n, count);
	(*count)++;
	if(*count==n){
	  printf("\n%d\n",root->data);
	  return;}
	findSecondMaxBST(root->left,n ,count);
}

int main()
{
        node *root = createBST();
        int count=0;
	inorderTraversal(root);
        findSecondMaxBST(root, 3, &count);
        return 0;
}

