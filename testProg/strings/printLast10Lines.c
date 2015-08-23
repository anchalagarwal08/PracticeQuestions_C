/*Given some text lines in one string, each line is separated by ‘\n’ character. Print the last ten lines. If number of lines is less than 10, then print all lines.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printLast10Lines(char *str, int count)
{
	int len = strlen(str);
	char *temp = str;
	if(len==1 && str[0]=='\n'|| (len==0))
	{
	   printf("\n invalis string\n");
	   return;
	}
	int i= len-1;
	int n =0;
	while(n<count)
	{
		if(str[i]=='\n')
		{
		   temp--;i--;
		   n++;
		   printf("\n");
		}
		else
		{
		  temp--;
		  printf("%c", str[i--]);
		}
	}
printf("\n %s", temp);
}
int main()
{
	char *str1 = "str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7\nstr8\nstr9"
		"\nstr10\nstr11\nstr12\nstr13\nstr14\nstr15\nstr16\nstr17"
		"\nstr18\nstr19\nstr20\nstr21\nstr22\nstr23\nstr24\nstr25";
	char *str2 = "str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7";
	char *str3 = "\n";
	char *str4 = "";
	printLast10Lines(str1, 10);
	return 0;
}
