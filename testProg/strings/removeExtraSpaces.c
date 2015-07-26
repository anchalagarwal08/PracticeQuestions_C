#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeExtraSpaces(char *str)
{
	int i, d=0, len;
	len = strlen(str);
	char *temp = (char*)malloc((len+1) * sizeof(char));
	while(i<len)
	{
		if(*(str+i)==' ' && *(temp+(d-1))!=' ')
		{
		   *(temp+d)=' ';
		    d++;
		}
		else if(*(str+i)!=' ')
		{
		   *(temp+d) = *(str+i);
		    d++;
		}
		i++;
	}
	printf("\n %s \n", temp);
	//return temp;
}

int main()
{
	char *s = "I   live  on earth";
//	printf("\n %s\n", removeExtraSpaces(s));
	removeExtraSpaces(s);
	return 0;
}
