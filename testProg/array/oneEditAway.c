/*Write a function to tell whether two strings are 1 edit away. i.e 1 replacment,1 deletion or 1 insert. We can use edit distance but that will have O(mn) complexity and moreover its used for finding minimum edit requires however here we are give the value of min edit away. hence we can do in O(n)*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
bool findOneEditAway(char *str1, char *str2)
{
	if(abs(strlen(str1)-strlen(str2))>1)
		return false;    
	//char *tmp1 = strlen(str1)>strlen(str2)?str1 :str2;
	//char *tmp2 = strlen(str1)>strlen(str2)?str2: str1;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int index1 = 0,index2=0;
	bool isFalse=false;
	while(index1<len1 && index2<len2)
	{
		if(str1[index1]!=str2[index2])
		{  if(!isFalse)
			isFalse=true;
		    else
			return false;
		
		if(len1>len2)
			index1++;
		else if(len1<len2)
			index2++;
		}
		index1++;index2++;
	}
	return true;
}

int main()
{
	char *str1 = "pale";
	char *str2 = "pales";
	printf("\n %d\n",findOneEditAway(str1,str2));
	return 0;
}
