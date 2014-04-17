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
int printLevel(node* root, node *root1)
{
  if(root==NULL)
	return;
  int rear, front, rear1, front1;
  node **q = createQueue(&front, &rear);
  node **q1 = createQueue(&front1, &rear1);
  
  node *temp = root;
  node * temp1 = root1;
  while(temp && temp1)
  {
    if(temp->data > temp1->data){
        printf("tree1 is bigger: %d \n", temp->data);
        return temp->data;
    }
    else  if(temp1->data > temp->data){
        printf("tree2 is bigger :%d \n", temp1->data);
        return temp1->data;
    }
    if(temp->left)
	enqueue(q, &rear, temp->left);
    if(temp->right)
	enqueue(q, &rear, temp->right);
    if(temp1->left)
        enqueue(q1, &rear1, temp1->left);
    if(temp1->right)
        enqueue(q1, &rear1, temp1->right);
    temp = dequeue(q, &front);
    temp1 = dequeue(q1, &front1);
  }
  if(temp!=NULL){
    printf("\n tree 1 is bigger");
    return temp->data;
  }
  else if(temp1!=NULL){
    printf("\n tree 2 is bigger");
    return temp1->data;
  }
}

int main()
{
  node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
 
  node *root1 = newNode(1);
  root1->right       = newNode(2);
  root1->right->right  = newNode(3);
  root1->right->right->right = newNode(4);

  printf("\n return value: %d",printLevel(root, root1));
 
  getchar();
  return 0;
}
