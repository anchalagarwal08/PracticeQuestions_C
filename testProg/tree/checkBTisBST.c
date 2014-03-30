/*
check whether a binary tree is BST or not.
O(n). using inorder traversal
*/
#include <stdio.h>
#include "Node.h"
#include <stdbool.h>
bool isBST(node* root)
{
  static node* prev = NULL;
  if(root){
  
    if(!isBST(root->left))
	return false;
  
    if(prev!=NULL && root->data <= prev->data)
	return false;
    prev=root;
    return isBST(root->right);

  }
  return true;
}

int main()
{
  node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(10);
  root->left->right = newNode(3); 
 
  if(isBST(root))
    printf("Is BST");
  else
    printf("Not a BST");
     
  getchar();
  return 0;
}  

