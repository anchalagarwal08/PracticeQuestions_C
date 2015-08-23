/*Construct a binary tree from inorder and preorder traversal*/
#include <stdio.h>
#include "Node.h"

int indexOf(int val, int *arr,int start, int end)
{
	int i=0;
	for(i=start;i<=end;i++)
	{
		if(arr[i]==val)
		  return i;
	}

}
node *constructBT(int *in, int *pre, int start, int end)
{
	static int preIndex=0;
	if(start>end)
	  return NULL;
	node *root = newNode(pre[preIndex++]);
	if(start==end)
	   return root;
	int mid = indexOf(pre[preIndex-1],in,start, end);
	root->left = constructBT(in, pre, start, mid-1);
	root->right = constructBT(in, pre, mid+1,end);
	return root;
}

void printInorder(node* node)
{
  if (node == NULL)
     return;
  printInorder(node->left);
  printf("%d ", node->data);
  printInorder(node->right);
}

int main()
{
	int in[] = {1, 3, 2, 4, 6, 7};
	int pre[] = {4, 3, 1, 2, 6, 7};
	int len = sizeof(in)/sizeof(in[0]);
	node *root = constructBT(in, pre, 0, len - 1);

	/* Let us test the built tree by printing Insorder traversal */
	printf("\n Inorder traversal of the constructed tree is \n");
	printInorder(root);
	getchar();
}
