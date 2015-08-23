#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

stack *initStack(stack *s1)
{
	s1 = (stack *)malloc(sizeof(stack));
	s1->size=0;
	s1->top=0;
//	s->data[100] = {0};
	return s1;
}
void push(int item, stack *s)
{
    if(s->size<100)
    {
        s->data[++(s->top)]=item;
        (s->size++);
    }
    else
        printf("\n Stack is full\n");
}
int pop(stack *s)
{
    if(s->size==0)
        return -1;
    int data = s->data[s->top];
    s->data[s->top]=-1;
    (s->top)--;
    (s->size)--;
    return data;
}

int peek(stack *s)
{
	if(s->size==0)
	  return -1;
	return s->data[s->top];

}
