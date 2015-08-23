/*Implement a method to perform basic string compression using the counts of repeated characters. ex: aaabbbcddd= a3b3c1d3. Return the original string if compressed string doesn't become smaller*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *stringCompression(char *str)
{
    int len = strlen(str);
    int i=0,count=0;
    char tmp[len];
    count=0;
    int j=0;
    for(i=0;i<len;i++)
    {
        count++;
        if(str[i+1]!=str[i])
        {
            tmp[j]=(char)str[i];
            tmp[j+1]=count+'0';
            j=j+2;
	    count=0;
        }
    }
    if(strlen(tmp)>=strlen(str))
	return str;
    else
    {
    for(i=0;i<strlen(tmp);i++)
   	printf("%c",tmp[i]);
    }
    return NULL;
}

int main()
{
	char *str = "aaaaabbbbcddddeeeef";
	printf("\n %s\n",stringCompression(str));
	return 0;
}
