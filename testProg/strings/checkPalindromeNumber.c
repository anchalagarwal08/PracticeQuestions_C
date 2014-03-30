#include <stdio.h>
#include <stdlib.h>

int checkPalindrome(int num, int res)
{
if(res==0)
  return;
checkPalindrome(num/10, res);
res = res*10+num%10;
return res;
}

int main()
{
 int n =12351;
 int i =0;
 printf("%d \n", checkPalindrome(n,i));

}
