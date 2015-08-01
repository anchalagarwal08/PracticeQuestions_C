/*Add two numbers represented by linked lists. The numbers are representde in reverse order. sum 123 + 678 list: 3->2->1 ..*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

node * sumList(node *head1, node *head2)
{
	int carry =0;
	int s, sum=0;
	node *curr3=NULL;
	node *head3=NULL;
	node *curr1= head1; node *curr2 = head2;
	while(curr1!=NULL && curr2!=NULL)
	{
		sum = curr1->data+curr2->data+carry;
		s = sum%10; carry = sum/10;
		node *n = (node *)malloc(sizeof(node));
		n->data = s;
		n->next = NULL;
		if(head3==NULL)
		{
			head3=n;
			curr3=head3;
		}
		else
		{
			curr3->next = n;
			curr3= curr3->next;
		}
		curr1=curr1->next;
		curr2= curr2->next;

	}
	if(carry==1)
	{
		node *n = (node *)malloc(sizeof(node));
                n->data = carry;
		curr3->next = n;
		curr3 = curr3->next;
	}
	return head3;
}

/*what if linked list representing numbers are not reversed*/
node *reverseSumList(node *n1, node *n2, int *carry)
{
	if(n1==NULL || n2==NULL)
		return NULL;
	int sum;
	node *curr = (node *)malloc(sizeof(node));
	curr->next = reverseSumList(n1->next, n2->next, carry);
	sum = n1->data + n2->data + *carry;
	*carry = sum/10;
	sum = sum%10;
	curr->data = sum;
	return curr;
}

int main()
{
	int i=0;
	node *head1 = NULL;
	insert(&head1, 6);
	insert(&head1, 1);
	insert(&head1, 7);
	node *head2 = NULL;
	insert(&head2, 4);
	insert(&head2, 9);
	insert(&head2, 5);
	int carry =0;
	node * head3 = sumList(head1, head2);
	//head3 = reverseSumList(head1, head2, &carry);

	while(head3!=NULL)
	{
		printf("%d->",head3->data);
		head3 = head3->next;
	}
	printf("\n not reverse linl;ist:\n");


}
