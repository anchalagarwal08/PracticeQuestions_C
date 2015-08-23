/*left view and right view of binary tree. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

/*for right view traverse right tree first*/
void leftView(node *root, int curr_level, int *prev_level)
{
	if(root ==NULL)
	  return;
	if(curr_level>*prev_level)
	{
	  printf("\n %d", root->data);
	  *prev_level = curr_level;
	}
	leftView(root->left, curr_level+1, prev_level);
	leftView(root->right, curr_level+1, prev_level);
}

void leftView2(node *root, int level, int *isTrue)
{
	if(root==NULL)
	  return;
	if(level==1 && *isTrue!=1)
	{
		printf("%d ,",root->data);
		*isTrue=1;
	}
	else if(level>1)
	{
	leftView2(root->left, level-1, isTrue);
	leftView2(root->right, level-1, isTrue);
	}
}
int main()
{
    node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
    int lev =0,i=0, j=0;
    leftView(root,1,&lev);
    printf("*************\n****************");
    for(i=1;i<=3;i++){
	j=0;
	leftView2(root,i,&j);
    }

    return 0;
}
