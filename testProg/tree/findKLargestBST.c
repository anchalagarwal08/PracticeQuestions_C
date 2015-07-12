#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Node.h"

void reverseInorder(node *root, int k, int *count)
{
	if(root==NULL || *count>k)
	  return;
	reverseInorder(root->right, k, count);
	(*count)++;
	if(k==*count){
	  printf("\n data= %d\n", root->data);
	  return;
	}
	reverseInorder(root->left, k, count);
}

int main()
{
	node *root = createBST();
	int count =0;
	reverseInorder(root, 3,&count);
	return 0;
}
