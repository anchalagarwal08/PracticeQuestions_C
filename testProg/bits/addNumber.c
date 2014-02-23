#include <stdio.h>

int addOne(int x){
  int m = 1;
  while(x&m){
    x = x^m;
    m = m<<1;
  }
  
  x= x^m;
  return x;
}
int main(){
int n =15;
printf("increament: %d ", addOne(n));
}
