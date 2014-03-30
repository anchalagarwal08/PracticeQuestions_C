#include <stdio.h>

unsigned int reverseBits(unsigned int num, int i, int j)
{
 int lo = ((num>>i)&1);
 int hi = ((num>>j)&1);
 if(lo^hi){
  num=num^((1<<i)|(1<<j));
 }
printf("num :%d \n",num);
return num;

}

unsigned int reverse(int num,int size, int i, int j)
{
  if(i>=size/2)
	return;
  else{
	i++;
	reverse(num,size, i , size-i-1);
  }
  num = reverseBits(num, i,j);
  return num;
}
int main()
{
  unsigned int num = 137;
  unsigned int n = sizeof(num);
   printf("old:%d", n);
  int i=0;
  //num = reverse(num, n, 0, n-1);
  for(i=0;i<n/2;i++){
   num = reverseBits(num, i, n-i-1);
  }
printf("new: %d \n", num);
}
