/*
Lowest Common Ancestor in a Binary Tree. O(n) as it is done in bottom up manner
*/
#include <stdio.h>
#include "Node.h"
#include <stdbool.h>
#include <stdlib.h>
node* newNode(int data)
{
	node *n = (node*)malloc(sizeof(node));
	n->left = n->right=NULL;
	n->data = data;
	return n;
}

node* findLCA(node* root, int n1, int n2, int *v1, int *v2)
{
  if(root==NULL)
	return NULL;
  if(root->data ==n1)
  {
  	*v1 = 1;
	return root;
  }
  if(root->data ==n2)
  {
        *v2 = 1;
        return root;
  }
  node *left = findLCA(root->left, n1, n2, v1, v2);
  node *right = findLCA(root->right, n1, n2, v1, v2);
 
  if(left && right)
	return root;
  if(left!=NULL)
	return left;
  else
	return right;
}

int findNodes(node *root, int n1){
	if(root==NULL)
	  return 0;
	if(root->data == n1 || findNodes(root->left, n1)||findNodes(root->right, n1))
	  return 1;
	else
	  return 0;
}

node *findLcaBT(node *root, int n1, int n2)
{
 	int  v1 = 0, v2=0;
	node *temp = findLCA(root, n1, n2, &v1, &v2);
	printf("%d %d %d\n",v1,v2, temp->data);
        if(v1 && v2 || v1 && findNodes(temp,n2)|| v2 && findNodes(temp,n1))
	  return temp;
	 
        return NULL;
}

int main()
{
    node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    node *lca =  findLcaBT(root, 4, 5);
    if (lca != NULL)
       printf("\n LCA(4, 5) = %d",lca->data);
    else
       printf("Keys are not present ");
 
    return 0;


}
