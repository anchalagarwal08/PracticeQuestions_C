#include <stdio.h>

int strcmp(char *s, char *r)
{
  for(;*s==*r;s++,r++)
  {
	if(*s=='\0')
	  return 0;
   }
	return *s - *r;

}

int main()
{
  char *s = "gel";
  char *r = "hel";
  printf("%d\n", strcmp(s, r));

}
