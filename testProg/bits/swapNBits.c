#include <stdio.h>

unsigned int reverseBits(unsigned int num, unsigned int i, unsigned int j)
{
 printf("here \n");
 int lo = ((num>>i+1)&1);
 int hi = ((num>>j+1)&1);
 if(lo^hi){
  num=num^((1<<i)|(1<<j));
 }
printf("num :%d \n",num);
return num;

}

unsigned int reverse(unsigned int num, unsigned int p1, unsigned int p2){
 unsigned int mid = (p1+p2)/2;
 unsigned int i=0;
 for(i=0;i<=mid/2;i++){
   int pos = p1+i;
   num = reverseBits(num, pos, p2-pos-1);
  }
return num;
}
int main()
{
  unsigned int num = 28;
  unsigned int p1 = 0;
  unsigned int p2 = 3;
  unsigned int n = sizeof(num);
  int i=0;
  num = reverse(num, 1, 5);
  printf("new: %d \n", num);
}
