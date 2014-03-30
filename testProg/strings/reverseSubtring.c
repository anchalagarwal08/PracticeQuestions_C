#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int findPosition(char*str, char*sub, int *i, int*j)
{ 

  int start=0, end=0;
  int len = strlen(str);
  int len2 = strlen(sub); 
  int m=0, n=0; 
  while(m<len)
  { 

    if(str[m] == sub[0])
    {
      *i = m; 
       end = m;
       while(n<len2)
       {
	 if(str[++m] == sub[++n])
            end++;
          
       } 
       *j = end;
       printf("%d here \n", *j);
       return 1;
      }
     m++;  
  }
return 0;
}

void reverseSubString(char* str, int* start, int* end)
{
//  int i = *start;
//  int j = *end;
  while(*start<*end)
  {
    char c = str[*start];
    str[*start] = str[*end];
    str[*end] =c;
    (*start)++;
    (*end)--;
  }
}

int main()
{
   char str[] = "algorithms";
   char sub[] = "gorit";
   int i, j;
   int k = findPosition(str, sub, &i, &j);
   printf("%d %d %d \n", k, i, j);
   reverseSubString(str, &i, &j);
   printf("%s \n", str);
   getchar();   
}
