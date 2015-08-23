#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Heap.h"

void swap(int *a, int *b)
{
	int c = (int)*a;
	*a = *b;
	*b = c;
}

void insertMinHeap(heap *h, int val)
{
	if(h->size==h->capacity)
	{
		printf("\n print heap full. \n");
		return;
	}
	int i = h->size;
	h->arr[i] = val;
	(h->size)++;
	while(i!=0 && h->arr[i/2] > h->arr[i])
	{
		swap(&h->arr[i/2], &h->arr[i]);
		i = i/2;
	} 
}

void minHeapify(heap *h, int i)
{
	int l = 2*i;
	int r = 2*i+1;
	int smallest=i;
	if(l<h->size && (h->arr[l]<h->arr[i]))
	   smallest = l;
	if(r<h->size && (h->arr[r]<h->arr[smallest]))
	  smallest = r;
	if(i!=smallest){
	  swap(&h->arr[i],&h->arr[smallest]);
	  minHeapify(h, smallest);
	}
}

int extractMin(heap *h)
{
	if(h->size==0)
	  return -1;
	if(h->size==1)
	  return h->arr[1];
	int root = h->arr[1];
	h->arr[1] = h->arr[(h->size)-1];
	(h->size)--;
	minHeapify(h, 1);
	return root;
}

int main()
{
	heap *h = initHeap(10);
	int i =0;
	insertMinHeap(h, 29);
	insertMinHeap(h, 50);
	insertMinHeap(h, 12);
        insertMinHeap(h, 5);
	insertMinHeap(h, 21);
        insertMinHeap(h, 15);
        insertMinHeap(h, 7);
        insertMinHeap(h, 6);

	for(i=0;i<9;i++)
	{
		printf("\n val = %d", h->arr[i]);

	}
	for(i=0;i<3;i++)
	{
		printf("\n %dth min=%d\n",i,extractMin(h));
	}
	if(h)
	  free(h);
	return 0;
}
