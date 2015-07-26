/*check if Binary tree is balanced: maximum height diff between left tree and right tree shul dbe 1*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Node.h"
#include <stdbool.h>
bool isBalanced(node *root)
{
	if(checkHeight(root)==-1)
	  return false;
	else
	  return true;
}

int max(int a, int b)
{
	return (a>b)?a:b;
}
int checkHeight(node *root)
{
	if(root ==NULL)
	  return 0;
	int lh = checkHeight(root->left);
	if(lh==-1)
	  return -1;
	int rh = checkHeight(root->right);
	if(rh ==-1)
	 return -1;
	int diff = abs(lh-rh);
	if(diff>1)
	  return -1;
	else 
	  return max(lh,rh)+1;
}

int main()
{
	node *root;
	root = createBST();
	if(isBalanced(root))
	  printf("\n is balanced\n");
	else
	  printf("\n not balanced\n");
	return 0;
}
