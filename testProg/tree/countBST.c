#include <stdio.h>
#include <string.h>
#include <string.h>
#include "Node.h"
#include <stdbool.h>
bool isleaf(node *root)
{
	return (root->left ==NULL && root->right==NULL);
}

bool isValidNode(node *root, int low, int high)
{
	if(root->data >= low && root->data<=high)
		return true;
	else
		return false;
}
bool countBST(node *root, int low, int high, int *count)
{
	if(root==NULL)
	 return true;

	bool l = root->left ?countBST(root->left, low, high, count) : true;
	bool r = root->right ?countBST(root->right, low, high, count): true;
	if(l && r && isValidNode(root,low, high))
	{
		printf("\n data node=%d\n", root->data);
		(*count)++;
		return true;

	}
	return false;
}

int main()
{
	node *root = createBST();
	int count=0;	
	int ret = countBST(root, 4, 30, &count);
	printf("\n count=%d\n", count);
	return 0;
}
