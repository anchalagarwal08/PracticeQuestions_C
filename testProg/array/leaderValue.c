#include<stdio.h>

void printLeader(int arr[], int size){
 int i;
 int max = arr[size-1];
printf("%d \n", max);
 for(i=size-2; i>=0; i--){
        printf("val: %d \n", arr[i]);
 	if(max < arr[i]){
     		max = arr[i];
		printf("max: %d \n", max);
        }
 }
}

int main(){
int arr[] = {16, 17, 4, 3, 5, 2};
printLeader(arr, 6);
getchar();
return 0;
}
