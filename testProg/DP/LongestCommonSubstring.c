/*Given two strings ‘X’ and ‘Y’, find the length of the longest common substring. For example, if the given strings are “GeeksforGeeks” and “GeeksQuiz”, the output should be 5 as longest common substring is “Geeks”. Note: its substring and not subsequence*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longestCommonSubstring(char *str1, char *str2,int m, int n)
{
	int arr[m+1][n+1];
	int i =0,j=0, result = 0;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0 || j==0)
			  arr[i][j] =0;
			else if(str1[i-1]==str2[j-1])
			{
				arr[i][j]=arr[i-1][j-1]+1;
				result = result>arr[i][j]?result :arr[i][j];
			}
			else
			   arr[i][j] =0;
		}
	}
	return result;
}

int main()
{
	char *str1 = "abcdefk";
	char *str2 = "abxdef";
	printf("\n longest substring:%d\n", longestCommonSubstring(str1,str2,strlen(str1),strlen(str2)));


}
