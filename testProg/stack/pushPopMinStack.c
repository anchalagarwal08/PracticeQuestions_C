/*
Design a stack with push pop and min function. min() should return minimum element at a particular stack state. All 3 should be 
O(1)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include <limits.h>
int min(stack *s)
{
	if(s->size==0)
	  return INT_MAX;
	else
	  return peek(s);
}
void spclPush(stack *s, stack *super, int val)
{
	if(val<min(s))
	{
	  push(val,s);
	}

	push(val,super);
}

int spclPop(stack *s, stack *super)
{
	int data = pop(super);
	if(data == peek(s))
	   pop(s);
	return data;
}

int main()
{
	
        int i=0;
        stack *s, *super;
        s = (stack *)initStack(s);
        super= (stack *)initStack(super);
	spclPush(s,super,7);
	printf("\nmin: %d\n",min(s));
	spclPush(s,super,3);
	printf("min: %d\n",min(s));
	spclPush(s,super,6);
	spclPush(s,super,5);
	spclPush(s,super,1);
	printf("min: %d\n",min(s));
	printf("pop:%d",spclPop(s,super));
	printf("min: %d\n",min(s));
        printf("pop:%d\n",spclPop(s,super));
	if(s)
        {
                free(s);
        }
        if(super)
         free(super);
        return 0;

}
