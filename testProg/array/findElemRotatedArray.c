/*Given a sorted array that has been rotated n number of times. Find an element in such an array*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int search(int arr[], int x, int start, int end)
{
	int mid = (start+end)/2;
	if(arr[mid]==x)
	  return mid;
	if(end<start)
	  return -1;
	if(arr[mid] < arr[start])
	{
		if(x>=arr[start] && x<=arr[mid])
			return search(arr, x, start, mid-1);
		else
			return search(arr, x, mid+1, end);
	}
	else if(arr[mid]>arr[start])
	{
		if(x>=arr[start] && x<=arr[mid])
			return search(arr, x, start, mid-1);
		else
			return search(arr, x, mid+1, end);
	}
	else if(arr[mid]==arr[start])
	{
		if(arr[mid]!=arr[end])
		  return search(arr, x, mid+1, end);
		else{
			int result = search(arr, x, start, mid-1);
			if(result ==-1)
			    result = search(arr, x, mid+1, end);
			else
			    return result;
		}
		
	}
	return -1;
}

int main()
{
	int arr[12] = {15,16,19,20,25,1,3,4,5,7,10,14};
	printf("\n i=%d\n",search(arr, 5, 0, 11));
	return 0;
}
