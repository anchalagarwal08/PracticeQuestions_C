/*find loop in a link list. Also find the start of the loop*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

void findLoop(node *head)
{
	node *slow, *fast, *curr;
	curr=head;
	fast=head->next;
	slow=head;
	while(fast!=NULL && fast->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if(fast==slow)
		{
			printf("\n loop found\n");
			break;  
		}
	}
	if(fast!=slow){
		printf("\n no loop\n");}
	else{

		slow = head;
		while(slow!=fast)
		{
			fast=fast->next;
			if(slow==fast)
			  break;
			slow= slow->next;
		}
		printf("\n starting point:%d\n", slow->data);
	}
}

int main()
{
	node *head = (node *)malloc(sizeof(node));
	head->data = 5;
	head->next = NULL;
	node *cur =head;

	node *n1 = (node *)malloc(sizeof(node));
	n1->data = 6;
	n1->next = NULL;
	cur->next = n1;
	cur = cur->next;

	node *n2 = (node *)malloc(sizeof(node));
	n2->data = 8;
	n2->next = NULL;
	cur->next = n2;
	cur = cur->next;

	node *n3 = (node *)malloc(sizeof(node));
	n3->data = 7;
	n3->next = NULL;
	cur->next = n3;
	cur = cur->next;

	node *n4 = (node *)malloc(sizeof(node));
	n4->data = 9;
	n4->next = NULL;
	cur->next = n4;
	cur = cur->next;
	
	node *n5 = (node *)malloc(sizeof(node));
        n5->data = 19;
        n5->next = NULL;
        cur->next = n5;
        cur = cur->next;

	cur->next = n2;

	findLoop(head);
	return 0;
}
