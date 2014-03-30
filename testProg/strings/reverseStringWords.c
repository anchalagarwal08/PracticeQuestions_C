#include<stdio.h>
#include <stdlib.h>
#include <string.h>
void rev(char *ptr, int start, int end){
char temp;
while(start<end){
   temp = ptr[start];
   ptr[start++] = ptr[end];
   ptr[end--] = temp;
}

}
void reverseWords(char *s)
{
   int len = strlen(s);
   rev(s, 0,len-1);
   int i =0, start=0;
   for(i=0;i<=len;i++){
	if(s[i]==' ' || s[i]=='\0'){
	  rev(s, start, i-1);
          printf("ptr now: %s \n",s);
   	  start = i+1;
	}
    }   

  // printf("reverse s : %s\n", s);
 //  return s;
}   
    
int main() 
{   
  char s[] = "i like this program very much";
  char *temp = s;
  reverseWords(s);
  printf("in main: %s", s);
  getchar();
  return 0;
}
