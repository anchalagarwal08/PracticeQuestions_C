/*Given a permutation of a string find if the string is a palindrome
Sol: string should have all even number of chars and atmost 1 odd number of char*/

#include<stdio.h>
#include<string.h>

int findPalindrome(char str[])
{
	int len = strlen(str);
	int i=0, val=0,count=0;
	char arr[26];
	for(i=0;i<=len;i++)
	{
		if(str[i]>='a' && str[i]<='z')
		  val = str[i]-97;
		if(str[i]>='A' && str[i]<='Z')
		  val = str[i]-65;
		if(arr[val]==1)
		  arr[val]=0;
		else
		  arr[val]=1;
	}
	for(i=0;i<26;i++)
	{
		if(arr[i]==1)
		  count=count+1;
	}
	printf("\n count=%d\n",count);
	return count<=1;
}

int main()
{
	char str[8] = "aacctte";
	printf("\n val = %d\n",findPalindrome(str));
	return 0;
}
