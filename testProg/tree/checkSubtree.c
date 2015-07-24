/*Check if a binary tree is subtree of another binary tree */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Node.h"
#include <stdbool.h>

int isIdentical(node *t1, node *s1)
{
	if(t1==NULL && s1==NULL)
	  return 1;
	if(t1==NULL || s1==NULL)
	  return 0;
	if(t1->data == s1->data)
	  return 1;
	else
	   return 0;
	return (isIdentical(t1->left, s1->left) & isIdentical(t1->right, s1->right));
}

int checkSubtree(node *t, node *s)
{
	if(s==NULL)
	  return 1;
	if(t==NULL)
	  return 0; //find s in t, so s can be null but t canno
	if(t->data == s->data)
	  return(isIdentical(t,s));
	//if(isIdentical(t, s))
	  //  return 1;
	return (checkSubtree(t->left, s) || checkSubtree(t->right, s));
}

int main()
{
	node *T        = newNode(26);
	T->right              = newNode(3);
	T->right->right       = newNode(3);
	T->left               = newNode(10);
	T->left->left         = newNode(4);
	T->left->left->right  = newNode(30);
	T->left->right        = newNode(6);
	/*subtree to find*/
	node *S    = newNode(10);
	S->right          = newNode(6);
	S->left           = newNode(4);
	S->left->right    = newNode(30);
	if (checkSubtree(T, S))
		printf("\nTree S is subtree of tree T\n");
	else
		printf("\nTree S is not a subtree of tree T\n");

	return 0;
}
