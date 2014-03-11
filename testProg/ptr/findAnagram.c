/*
Anagrams in O(n) time and O(1) space
*/

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 256

int findAnagrams(char *str1, char *str2){
  int count[MAX_SIZE] = {0};
  int i,j;
  if(strlen(str1)!=strlen(str2))
	return 0;

  for(i=0; str1[i] && str2[i];i++)
  {
  	count[str1[i]]++;
	count[str2[i]]--;
  }

  for(j=0; j<MAX_SIZE;j++){
	if(count[j]>0)
	  return 0;
  }

return 1;
}

int main()
{
  char str1[] = "abc";
  char str2[] = "daufdgj";
  printf("%d \n", findAnagrams(str1, str2));
  getchar();
  return(0);
}
