/*Find the row with maximum number of 1s*/
/*Example
Input matrix
0 1 1 1
0 0 1 1
1 1 1 1  // this row has maximum 1s
0 0 0 0

Output: 2*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define R 4
#define C 4

int binarySearch(bool arr[],int start, int end)
{
	if(end>=start)
	{
		int mid = (start+end)/2;
		if(arr[mid]==1 &&(mid==0 || arr[mid-1]==0))
		   return mid;
		else if(arr[mid]==0)
		  return binarySearch(arr, mid+1, end);
		else
		  return binarySearch(arr, start, mid-1);
	}
	return -1;
}
int findmax1Row(bool mat[R][C])
{
	int index=0, i;
	int  max_index=-1, max_count;
	for(i=0;i<R;i++)
	{
		index = binarySearch(mat[i],0,C-1);
		if(index!=-1 && max_count<(C-index))
		{
			max_count = C-index;
			max_index = i;

		}
	}
	return max_index;		
}

int main()
{
	bool mat[R][C] = { {0, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };
 
    printf("Index of row with maximum 1s is %d \n", findmax1Row(mat));
 
    return 0;
}
