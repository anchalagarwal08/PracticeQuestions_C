#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int findRotation(char *a, char *b)
{
   int len, i=0,j=0;
   int n = strlen(b);
   char *res = (char*)malloc((2*n + 1)*sizeof(char));
   strcpy(res, a); 
   strcat(res, a);
   printf("res: %s \n", res);
   len = strlen(res);
   res[len]='\0';
   while(j<len){
	if(b[0]==res[j++]){
	printf("len: %s \n", b);
	  for(i=1;i<n;i++)
	  {
	    printf("%c ,%c \n", res[j],b[i]);
	    if(b[i]==res[j])
	   	j++;	
	    else
	      return 0;
	  }
          return 1;
	}
   }
	return 0;
}
int main()
{
  char a[] = "abcd";
  char b[] = "cdab";
  printf("%d \n", findRotation(a, b));

}
