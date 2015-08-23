/*n-place conversion of Sorted DLL to Balanced BST*/

#include<stdio.h>
#include<stdlib.h>
#include "Node.h"

node *constructBSTDLL1(node *head)
{
	if(head==NULL || !(head->right))
	  return head;
	node *mid =head, *fast = head;
	while(fast!=NULL && fast->right!=NULL)
	{
		mid = mid->right;
		fast=fast->right->right;
	}
	node *slow =mid;
	if(slow->left)
	  slow->left->right=NULL;
	if(slow->right)
	  slow->right->left=NULL;
	slow->left= constructBSTDLL1(head);
	slow->right = constructBSTDLL1(mid->right);
	return slow;
}

node *constructBSTDLL(node **root, int n)
{
	if(n<=0)
	  return NULL;
	node *left = constructBSTDLL(root,n/2);
//	node *r = newNode((*root)->data);
	node *r = *root;
	r->left=left;
	*root= (*root)->right;
	r->right = constructBSTDLL(root,n-n/2-1);
	return r;
}

/* Function to insert a node at the beginging of the Doubly Linked List */
void push(node** head_ref, int new_data)
{
    node* new_node = newNode(new_data);
    new_node->left = NULL;
    new_node->right = (*head_ref);
    if((*head_ref) !=  NULL)
      (*head_ref)->left = new_node ;
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(node *node)
{
    while(node!=NULL)
    {
        printf("%d ", node->data);
        node = node->right;
    }
}
int main()
{

    node* head = NULL;
    //Created linked list will be 7->6->5->4->3->2->1
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    printf("\n Given Linked List ");
    printList(head);
 
    /* Convert List to BST */
    node *root = constructBSTDLL1(head);//,7);
    printf("\n InOrder Traversal of constructed BST ");
    inorderTraversal(root);
    printf("\n"); 
    return 0;

}
