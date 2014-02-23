#include <stdio.h>
void reverseWords(char* s);
int main(){
char arr[] = "geeks";
char *s = arr;
reverseWords(arr);
printf("%s\n", *&s);
getchar();
return(0);
}

void reverseWords(char *s){

  char *begin = s;
  char *end = s;
  char temp;
  while(*end){
	if(*end!='\0')
	  end++;
  }
 end--;
 printf("%c \n", *begin);
 printf("%c \n", *end);
  while(begin<end)
  {
	temp = *begin;
	*begin = *end;
	*end = temp;
	*begin++;
	*end--;
  }
}
