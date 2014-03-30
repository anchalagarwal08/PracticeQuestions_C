#include<stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "test.h"
int reverse(int num, int rev)
{
  if(num>0)
  {
    rev = rev*10+num%10;
    reverse(num/10, rev);
  }
  else
	return rev;

}
int main() 
{ 
char *p,*q; 
p=(char *)malloc(25); 
q=(char*) malloc(25); 
strcpy(p,"amazon" ); 
strcpy(q,"hyd"); 
strcat(p,q); 
printf("%s",p); 
}
