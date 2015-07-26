/*Find inorder successor in a BST i.e next node to a given node given each node's parent pointer*/
/*Algorithm
==============
1) Either next node is in leftmost of right subtree
2) Either its null
3) Either right subtree is null, so parent node is the next node
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

int findLeftmost(node * root)
{
	if(root==NULL)
	  return 0;
	while (root->left!=NULL)
	{
		root = root->left;
	}
	return root->data;
}

int findInorderSucc(node *n)
{
	if(n==NULL)
	  return 0;
	if(n->parent==NULL ||n->right!=NULL)
	  return findLeftmost(n);
	else 
	{
		while(n->parent!=NULL)
		{
			n = n->parent;
		}

	}
	return n->data;
}

