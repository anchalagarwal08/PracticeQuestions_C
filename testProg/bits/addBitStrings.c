#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void addBitString(char *s1, char *s2, char *res){
int len1 = strlen(s1);
int len2 = strlen(s2);
int diff,i;
if(len1>len2){
   diff = len1-len2;
 for(i=0;i<diff;i++){
       printf("am here");
        res[i]='0';
   }
strcat(res,s2);
printf("res: %s\n", res);
}
else if(len2>len1){
   diff = len2-len1;
   for(i=0;i<diff;i++){
        s1 = '0'+ s1;
   }
}
/*   char result[diff];
   char *ptr = result;
   for(i=0;i<diff;i++){
	result[i]='0';
   }
   strcat(result, s2);
*/
printf("str2: %s\n", s2);
}
int main(){

char s1[] = "1100011";
char s2[] = "10";
char *ptr1 = s1;
char *ptr2 = s2;
char *res = (char*)malloc(8*sizeof(char));
addBitString(s1,s2, res);
printf("in main: %s \n",res);
}
