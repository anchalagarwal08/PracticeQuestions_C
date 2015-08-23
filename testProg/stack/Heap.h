#ifndef _HEAP_H
#define _HEAP_H

typedef struct Heap heap;
struct Heap{
	int size;
	int capacity;
	int *arr;
};

heap * initHeap(int cap)
{
	heap *h = (heap*)malloc(sizeof(heap));
	h->size=1;
	h->capacity=cap;
	h->arr = (int *)malloc(sizeof(int)*cap);
}
#endif
