#include <stdio.h>
#include <string.h>
void addBitString(char*, char*);
int main(){

char s1[] = "1100011";
char s2[] = "10";
char *ptr1 = s1;
char *ptr2 = s2;
addBitString(s1,s2);
}

void addBitString(char *s1, char *s2){
int len1 = strlen(s1);
int len2 = strlen(s2);
int diff,i;
printf("len1:%d\n", len1);
printf("len2:%d\n", len2);
if(len1>len2){
   diff = len1-len2;
}
else if(len2>len1){
   diff = len2-len1;
   for(i=0;i<diff;i++){
        s1 = '0'+s1;
   }
}
   char result[diff];
   char *ptr = result;
   for(i=0;i<diff;i++){
	result[i]='0';
   }
   strcat(result, s2);

printf("str1: %s\n", s1);
printf("str2: %s\n", result);
		
}
