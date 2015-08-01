/*partition a linked list around a value x such that all nodes less than x come before all nodes >=x*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

node *partitionLinkList(node *head, int val)
{
	node *new=NULL; node *curr_new=NULL;
	node *curr=NULL;
	curr=head;
/*making a new list of all ele <x*/
	while(curr!=NULL)
	{
		if(curr->data <val)
		{
			node *temp = (node*)malloc(sizeof(struct Node));
			temp->data = curr->data;
			temp->next =NULL;
			if(new ==NULL){
				new = temp;
				curr_new = new;
			}
			else{
				curr_new->next = temp;
				curr_new = curr_new->next;
			}
		}
		curr=curr->next;
	}
	printf("\n new list: ");
	printList(new);
	curr_new->next = head;
	curr = curr_new->next;
	while(curr!=NULL)
	{
		if(curr->data<val)
		{
			curr_new->next = curr->next;
			curr = curr_new->next;
		}
		else
		{
			curr_new = curr;
			curr = curr->next;
		}

	}
	printf("\n partitioned list :");
	printList(new);
	printf("\n");
	return new;
}

int main()
{
        node *head = NULL;
        insert(&head, 3);
        insert(&head, 5);
        insert(&head, 8);
        insert(&head, 5);
        insert(&head, 10);
	insert(&head, 2);
        insert(&head, 1);
        printList(head);
        head = partitionLinkList(head, 5);
	return 0;
}

