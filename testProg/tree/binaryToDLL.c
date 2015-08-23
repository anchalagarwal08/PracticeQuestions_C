/*Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL). The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Node.h"

/* Function to print nodes in a given doubly linked list */
void printList(node *node)
{
    printf("\n print:\n");
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->left;
    }
}

void convertToDLL(node *root, node **prev)
{
	if(root==NULL)
	  return;
	convertToDLL(root->left, prev);
	printf(" %d ", root->data);
	if(*prev==NULL)
	{
		(*prev) = root;
	}
	else
	{
		(*prev)->right=root;
		root->left = *prev;
		*prev=root;
	}
	convertToDLL(root->right,prev);
}

int main()
{
    node *root        = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
      root->left->right->left = newNode(26);
    root->right->left = newNode(36);	
    root->right->left = newNode(35);
    node *prev=NULL;
    convertToDLL(root,&prev);
    printList(prev);
    return 0;
}	
