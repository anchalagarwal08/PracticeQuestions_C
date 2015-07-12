#include <stdio.h>
#include <string.h>
#include <string.h>
#include "Node.h"
int countBST(node *root, int low, int high, int *count)
{
	if(root==NULL)
	  return -1;
	if(root->data >= low && root->data<=high)
	{
	  printf("\n subtree rooted at: %d\n", root->data);
	  (*count)++;
	}
	countBST(root->left, low, high, count);
	countBST(root->right, low, high, count);
	return *count;
} 

int main()
{
	node *root = createBST();
	int count=0;	
	int ret = countBST(root, 4, 29, &count);
	printf("\n count=%d\n", ret);
	return 0;
}
