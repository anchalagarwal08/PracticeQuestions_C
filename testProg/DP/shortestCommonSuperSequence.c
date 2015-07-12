/* Given a set of n strings arr[], find the smallest string that contains each string in the given set as substring. We may assume that no string in arr[] is substring of another string.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"
int shortestSuperstring(char *x, char *y, int m , int n)
{
	int lcs_length  = lcs(x, y, m, n);
	printf("\n length of LCS=%d\n", lcs_length);
	lcs_length = (m+n)-lcs_length;
	return lcs_length;
}

int main()
{
	char *x = "GXTXAYB";
        char *y = "AGGTAB";

	int m = strlen(x);
	int n = strlen(y);
	int ret = shortestSuperstring(x,y,m,n);
	printf("\n length = %d\n", ret);
	return 0;
}
