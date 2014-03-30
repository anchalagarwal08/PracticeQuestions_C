#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
  int t;
  t = *x;
  *x=*y;
  *y=t;
}
void makeArray(int num, int* arr)
{
  int i =0;
  while(num!=0)
  {
    arr[i++] = num%10;
    num = num/10;
   }
}
void permute(int* arr, int i, int n)
{
  int j, k=0;
  if(i==n)
  {
     printf("\n");
    for(k=0;k<=n;k++){
	printf("%d ", arr[k]);}

  }
  else{

 	for(j=i;j<=n;j++)
	{
	    swap((arr+i),(arr+j));
  	    permute(arr, i+1, n);
  	    swap((arr+i), (arr+j));
	}
   }
}

int main()
{
   int i=0;
   int num = 123;
   int *arr = (int *)malloc(sizeof(int)*3);
   makeArray(num, arr);
   for(i=0;i<3;i++)
   {
   	printf("%d ,", arr[i]);
   }
   permute(arr, 0, 2);
   getchar();
}
