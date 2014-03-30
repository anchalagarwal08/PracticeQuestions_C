#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void reverseString(char *str, char *str2)
{
	static int i =0;
	if(*str=='\0'){
	return;
        }
	reverseString(str+1,str2);
        str2[i++]=*str;
//	printf("%s", str2);
}
int main(){
char str[] = "this is a test";
char *ptr = str;
int len = strlen(str);
char *str2 = (char*)malloc(len*sizeof(char));
reverseString(str, str2);
printf("\n %s", str2);
getchar();
}
