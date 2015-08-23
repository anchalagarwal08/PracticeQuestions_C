/*Level order traversal f binary tree using recursion*/

#include <stdio.h>
#include<stdlib.h>
#include "Node.h"

int getHeight(node *root)
{
	if(root==NULL)
	  return 0;
	int lh = getHeight(root->left);
	int rh = getHeight(root->right);
	if(lh>rh)	
	  return lh+1;
	else 
	  return rh+1;
}
void printLevel(node *root, int level)
{
	if(root==NULL)
	  return;
	if(level==0)
	  printf("%d ,",root->data);
	printLevel(root->left, level-1);
	printLevel(root->right, level-1);
}
void printLevelWrapper(node *root)
{
	int h = getHeight(root);
	printf("\n height = %d\n",h);
	int i =0;
	for(i=0;i<h;i++)
	{
		printf("\n level: %d \n",i);
		printLevel(root,i);
	}

}
int main()
{
  node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left  = newNode(6);
  root->right->right = newNode(7);

  printf("Level Order traversal of binary tree is \n");
  printLevelWrapper(root);

  getchar();
  return 0;
}

