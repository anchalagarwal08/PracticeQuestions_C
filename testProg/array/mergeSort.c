/*Sort an array of integers such that –
– All odd numbers are in left side and sorted in increasing order.
– all even numbers are sorted in decreasing order and start where odd numbers end.
Eg –
I/P – 2, 3, 4, 5, 8 , 10, 12, 11
O/P – 3, 5, 11, 12, 10, 8, 4, 2
*/

#include <stdio.h>
void merge(int *arr, int start, int mid, int end)
{
	int i =0,n1=mid-start+1,n2=end-mid,j=0,k=start;
        int tmp1[n1];
	int tmp2[n2];
        for(i=0;i<n1;i++)
        {
                tmp1[i] = arr[start+i];
        }
        for(i=0;i<n2;i++)
        {
                tmp2[i] = arr[mid+1+i];
        }
	i=0;
        while(i<n1 && j<n2)
	{
		if(tmp1[i]<=tmp2[j])
		   {arr[k] =tmp1[i];i++;}
		else{
	 	   arr[k] = tmp2[j];j++;}		
		k++;
	}
	while(i<n1)
	{
		arr[k] = tmp1[i];
		k++;i++;
	}
	while(j<n2)
	{
		arr[k] = tmp2[j];
		j++;k++;
	}
}
void mergeSort(int *arr, int start, int end)
{
	if(start<end)
	{
		int mid = (start+end)/2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}
void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
void partitionEvenOdd(int *arr, int size, int *end_odd, int *start_even)
{
	printf("\n size=%d\n", size);
	int i=0, j=size, k=0;
	while(i<j)
	{
		if((arr[i]%2==0) && (arr[j-1]%2==1))
		{
			swap(&arr[i], &arr[j-1]);
			i++;j--;
		}
		else if((arr[i]%2==0) && (arr[j-1]%2==0))
		   j--;
		else
		   i++;
	}
	for(k=0;k<size;k++)
	{
		printf(" %d,",arr[k]);
	}
	if(arr[i]%2==0)
	{
		*end_odd=i-1; *start_even=i;
	}
	else{
		*end_odd = i; *start_even =i+1;
	}

}
int main()
{
	int arr[] = {2,4,5,3,7,6,1,8};
	int end_odd, start_even;
	partitionEvenOdd(arr,8, &end_odd, &start_even);
	printf("\n end_odd=%d , start_even=%d", end_odd, start_even);
	mergeSort(arr, start_even, sizeof(arr)/sizeof(arr[0])-1);
	mergeSort(arr, 0, end_odd);
	int i=0;
	printf("\n");
	for(i=0;i<8;i++)
	{  printf("%d,",arr[i]);
	 } 
        printf("\n");

	return 0;
}
