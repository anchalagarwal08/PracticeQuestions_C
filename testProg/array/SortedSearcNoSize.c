/*Given an array like data structure Listy which lacks a size method. Has a method elementAt( returns element at index i and returns -1 if i is beyond bounds of data structure. Given Listy and an element return the index*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Listy
{
	int arr[16];
};

int elementAt(int n, struct Listy *list)
{
	if(n>16)
	  return -1;
	else 
	   return list->arr[n];
}

int binarySearch(struct Listy *list, int start, int end, int num)
{
		if(end<start) return -1;
		int mid = (start+end)/2;
		if(elementAt(mid,list)==num)
		  return mid;
		if(num<elementAt(mid,list) || elementAt(mid,list) ==-1)
		  return binarySearch(list, start, mid-1, num);
		else
		  return binarySearch(list, mid+1, end, num);
		  
}
int sortedSearch(struct Listy *list, int num)
{
	int index=1;
	while(elementAt(index, list)!=-1 && num<elementAt(index, list))
	{
		index = index*2;
		printf("\n index=%d\n", index);
	}
	printf("\n index to BS=%d\n",index);
	return binarySearch(list, index/2, index, num);
}

int main()
{
	struct Listy *list = (struct Listy *)malloc(sizeof(struct Listy));
	int i=0;
	for(i=1;i<=14;i++)
	{
		list->arr[i-1] =i; 
	}
	printf("\n index=%d", sortedSearch(list, 13));
	return 0;
}
