/*Find inorder successor*/

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

node* inOrderSuccessor(node *root, int *flag, int val)
{
	if(root==NULL)
	  return NULL;
	inOrderSuccessor(root->left, flag, val);
	if(root->data ==val)
	  *flag =1;
	else if(*flag==1 && root->data!=val)
	{  printf("\n successor->%d\n", root->data);	 
	   *flag=0;
	   return root;
	}
	inOrderSuccessor(root->right, flag, val);
}

int main()
{
  node *root = newNode(20);
  root->left        = newNode(8);
  root->right       = newNode(22);
  root->left->left  = newNode(4);
  root->left->right = newNode(13);
  root->left->right->left  = newNode(10);
  root->left->right->right = newNode(16);
  root->left->right->right->left = newNode(15);
  root->left->right->right->left->left = newNode(14);

  int i =0;
  node * temp = inOrderSuccessor(root, &i, 15);
  if(temp!=NULL)
  	printf("\n ret=%d\n",temp->data);
  else
	printf("\n no successor\n");
  return 0;

}
