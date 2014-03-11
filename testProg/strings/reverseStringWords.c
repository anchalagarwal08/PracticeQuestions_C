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
char* reverseWords(char *s)
{
   int len = strlen(s);
   char *ptr = (char*)malloc((len+1)*sizeof(char));
   rev(s, 0,len-1);
   ptr = s; 
   ptr[len]='\0';
   int i =0, start=0;
   for(i=0;i<=len;i++){
	if(ptr[i]==' ' || ptr[i]=='\0'){
	  rev(ptr, start, i-1);
          printf("ptr now: %s \n",ptr);
   	  start = i+1;
	}
    }   

   printf("reverse s : %s\n", ptr);
   return ptr;
}   
    
int main() 
{   
  char s[] = "i like this program very much";
  char *temp = s;
  temp =reverseWords(s);
  printf("%s", temp);
  getchar();
  return 0;
}
