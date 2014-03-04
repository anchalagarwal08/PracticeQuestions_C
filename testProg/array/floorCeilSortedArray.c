/*Floor and ceiling values in a sorted array in ascending order
*/
#include <stdio.h>
int findCeiling(int arr[], int x, int low, int high)
{
  if(x<arr[low])
	return arr[0];
  if(x>arr[high])
	return -1;
  
  int mid = (low+high)/2;
  if(x==arr[mid])
	return arr[mid];

  if(x>arr[mid])
  {
	if(mid+1<=high && x<=arr[mid+1])
	  return arr[mid+1];
        else 
	  findCeiling(arr,x,mid+1,high);
  }
  else{
	if(mid-1>=low && x>arr[mid-1])
	  return arr[mid];
	else
	  findCeiling(arr,x,low,mid-1);
  }

}

int main()
{
  int arr[] = {1, 2, 8, 10, 10, 12, 19};
  int size = sizeof(arr)/sizeof(arr[0]);
  int x =9;
  printf("%d \n",findCeiling(arr,x,0,size-1));
}
