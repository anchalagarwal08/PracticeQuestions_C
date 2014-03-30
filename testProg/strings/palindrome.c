#include <stdio.h>
#include <string.h>
int palindrome(char *str)
{
  int len = strlen(str);
  len = len/2;
  char *end = str;
  while(*end!='\0'){
    end++;
  }
  end--;
  printf("char: %c \n", *end);
  while(len>0)
  {
	if(*str++== *end--){
	  len--;
        }
        else
           return 0;
  }
  return 1;
}
int main()
{
  char *str = "RADAR";
  printf("%d \n", palindrome(str));
}
