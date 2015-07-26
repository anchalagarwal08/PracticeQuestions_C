/*Find subarray(conotiguous subsequence) with given sum*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 50
void contigSubseqSum(int *arr, int sum, int *size)
{
	int temp[MAX_SIZE] = {0,};
	int tmp_sum,i,k=0;
	temp[0] = arr[0];
	printf("\narr->");
	for(i=0;i<=*size;i++)
	{
		printf("%d ,",arr[i]);
	}
	for(i=1;i<=*size;i++)
	{
		temp[i] = arr[i]+temp[i-1];
		if(temp[i]==sum){
		   printf("\n val=%d\n",i); 
		   break;
		}
		if(temp[i]>sum)
		{
			tmp_sum=temp[i];k=0;
			while(k<i && tmp_sum>sum)
			{
				tmp_sum-=arr[k++];
				if(tmp_sum==sum){
				  printf("\n range= %d to %d", k, i);
				  break;
				}
			}
		}
	}


}
/*
int main()
{
	int arr[] = {10,-3,11};
	printf("\n i=%d\n",contigSubseqSum(arr, 8, 3));
	return 0;
}*/
