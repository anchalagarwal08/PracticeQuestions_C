#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 500
typedef struct Node node;
struct Node{
  node *left;
  node *right;
  int data;
};
node *newNode(int val)
{
  node *temp = (node*)malloc(sizeof(node));
  temp->left=NULL;
  temp->right =NULL;
  temp->data=val;
  return temp;
}
node** createQueue(int *front, int *rear)
{
  node** queue = (node**)malloc(sizeof(node*)*MAX_SIZE);
  *front =0;
  *rear =0;
  return queue;
}
void enqueue(node **q, int *rear, node* n)
{
  q[*rear]=n;
  (*rear)++;
}
node* dequeue(node **q, int *front)
{
  (*front)++;
  return q[*front-1];
}
void printLevel(node* root)
{
  if(root==NULL)
	return;
  int rear, front;
  node **q = createQueue(&front, &rear);
  node *temp = root;
  while(temp)
  {
    printf("%d \n", temp->data);
    if(temp->left)
	enqueue(q, &rear, temp->left);
    if(temp->right)
	enqueue(q, &rear, temp->right);
    temp = dequeue(q, &front);
  }
}

int main()
{
  node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
 
  printf("Level Order traversal of binary tree is \n");
  printLevel(root);
 
  getchar();
  return 0;
}
