#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
void enqueue(int num, stack *pushst)
{
    push(num,pushst);
}
/*correct pop functin here. Make new pop with FIFO. In stack.c its LIFO*/
int dequeue(stack *pushst, stack *popst)
{
    if(popst->size>0)
        return pop(popst);
    while(pushst->size!=0)
    {
        push(pop(pushst), popst);
    }
    return pop(popst);

}

int main()
{
	int i=0;
	stack *pushst, *popst;
	pushst = (stack *)initStack(pushst);
	popst= (stack *)initStack(popst);
	for(i=1;i<=5;i++)
	{
		enqueue(i,pushst);
	}
	for(i=1;i<=5;i++)
        {
                 printf("\n %d \n",dequeue(pushst,popst));
        }
	enqueue(6,pushst);
	printf("\n %d \n",dequeue(pushst,popst));
//	printf("%d \n",dequeue(pushst,popst));
	if(pushst)
	{
		free(pushst);
	}
	if(popst)
	 free(popst);
	return 0;

}
