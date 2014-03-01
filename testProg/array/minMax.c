/*
Write a C function to return minimum and maximum in an array. You program should make minimum number of 
comparisons.
*/

#include <stdio.h>

typedef struct minmax minmax;
struct minmax{
 int min;
 int max;
};

minmax calculateMinMax(int arr[], int size){
 
 minmax m;
 int i;
 if(size==1){
   m.min = arr[0];
   m.max = arr[0];
   return m;
 }
 if(arr[0]>arr[1]){
   m.max = arr[0];
   m.min = arr[1];
 }
 else{
   m.max = arr[1];
   m.min = arr[0]; 
 }
 for(i=2;i<size;i++){
  if(arr[i]<m.min)
     m.min = arr[i];
  else if(arr[i]>m.max)
     m.max = arr[i];
 }
   
return m;
}

int main(){
 int arr[] = {1000, 11, 445, 1, 330, 3000};
 minmax m = calculateMinMax(arr, 6);
 printf("min: %d \n", m.min);
  printf("max: %d \n", m.max);

}
