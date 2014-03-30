#include <stdio.h>
#include <stdbool.h>
int main()
{
int arr[] = {1,5,4,2,8};
int j=0, i=0;
int len = sizeof(arr)/sizeof(arr[0]);
bool swap = false;
do{
  swap = false;
  for(i=1;i<len;i++){
    if(arr[i-1]>arr[i]){
	int t = arr[i-1];
        arr[i-1] = arr[i];
	arr[i] = t;
	swap = true;
     }
  }
}while(swap);

for(j=0;j<len;j++)
{ 
  printf("%d ,",arr[j]);
}

}

