#include <stdio.h>

int strcmp(char *s, char *r)
{
  for(;*s==*r;s++,r++)
  {
	if(*s=='\0'&& *r=='\0')
	  return 0;
   }
	return *s - *r;

}

int main()
{
  char *s = "Hel";
  char *r = "hel";
  printf("%d\n", strcmp(s, r));

}
