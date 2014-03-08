#include <stdio.h>

unsigned int reverseBits(unsigned int num, int i, int j)
{
 int lo = ((num>>i)&1);
 int hi = ((num>>j)&1);
 if(lo^hi){
  num^=((1<<i)|(1<<j));
 }
return num;

}
int main()
{
  unsigned int num = 6;
  unsigned int n = sizeof(num);
   printf("%d", n);
  int i=0;
  for(i=0;i<n/2;i++){
   num = reverseBits(num, i, n-i-1);
  }
printf("%d \n", num);
}
