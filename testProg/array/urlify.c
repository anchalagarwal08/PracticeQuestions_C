/* WAP to replace all spaces in a string with %20. Assume string has sufficient space in the end and tru lengh of string is given. true length=length-extra space.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

URLify(char str[], int true_len)
{
	
	int new_length,i=0, space_count=0;
	for(i=0;i<true_len;i++)
	{
		if(str[i]==' ')
		  space_count++;
	}
  	new_length = true_len+space_count*2;
	str[new_length]='\0';	
	int p1 = new_length, p3 = true_len-1;
	printf("\n len=%d\n",new_length);
	while(p3>=0)
	{
		if(str[p3]!=' '){
		  str[p1-1] = str[p3];
		  p1 = p1-1;
		}
			
		else{
			str[p1-1] = '0';
			str[p1-2] = '2';
			str[p1-3] = '%';
			p1 = p1-3;
		}
		p3--;
	}
	printf("\n changed: %s \n",str);
}
int main()
{
	char str[20] = "Mr John Smith";
	int i =0;int len = strlen(str);
	for(i=0;i<6;i++)
	  str[len+i]=' ';
	printf("\n str:%s :%d\n",str,strlen(str));
	URLify(str,13);
	return 0;
}
