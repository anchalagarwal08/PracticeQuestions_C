#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void insert(node **head, int val){
        node *n = (node*)malloc(sizeof(node));
        n->data = val;
        n->next = *head;
        *head = n;
}
 void printList(node *head)
{
    node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

