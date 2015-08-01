/*Given pointer to a middle node in a linklist. delete that node. Nothing else is given*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void deleteNodeMiddle(node *n)
{
	printf("\n n=%d\n", n->data);
	node *next = n->next;
	n->data = next->data;
	n->next = next->next;
	printf("\n n=%d\n", n->data);
}

int main()
{
	node *head = NULL;
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 3);
	insert(&head, 2);
	insert(&head, 1);
	printList(head);
	node *n = head;
	n = n->next->next;
	deleteNodeMiddle(n);
	return 0;
}
