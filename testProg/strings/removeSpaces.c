#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
   char *str="hello girls";
   int len = strlen(str);
   char *temp = (char*)malloc((len+1) * sizeof(char));
   int c=0, d=0;
   while(*(str+c)!='\0')
   {
	if(!(*(str+c)==' '))
	{
   	  *(temp+d) = *(str+c);
	  d++;
        }
	   c++;
    }	
   *(temp+d)='\0';
   printf("%s \n:", temp);
   
}
