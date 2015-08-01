#ifndef _LIST_H_
#define _LIST_H_

typedef struct Node node;
struct Node
{
	node *next;
	int data;
};

void insert(node **head, int val);
void printList(node *head);

#endif
