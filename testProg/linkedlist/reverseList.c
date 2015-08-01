#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#if 0
typedef struct Node Node;
struct Node{
  int data;
  Node *next;
};
#endif

void reverseList(Node **head)
{
  Node *curr = *head;
  Node *prev = NULL;
  Node *next;
  while(curr!=NULL){
	next = curr->next;
	curr->next = prev;
	prev = curr;
	curr = next;
  }
  *head = prev;
}
#if 0
void insert(Node **head, int val){
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = val;
	node->next = *head;
	*head = node;
}
 void printList(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

#endif
int main(){

  Node *head = NULL;
  insert(&head, 5);
  insert(&head, 4);
  insert(&head, 3);
  insert(&head, 2);
  insert(&head, 1);
  printList(head);
  reverseList(&head);
  printList(head);
  getchar();
}    

