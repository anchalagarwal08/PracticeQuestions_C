#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
int lcs(char *x, char *y, int m , int n)
{
        int arr[m+1][n+1];
        int i, j;
        for(i=0;i<=m;i++)
        {
                for(j=0;j<=n;j++)
                {
                   if(i==0 || j==0)
                        arr[i][j]=0;
                   else if(x[i-1]==y[j-1])
                        arr[i][j]=arr[i-1][j-1]+1;
                   else
                        arr[i][j] = (arr[i-1][j]>arr[i][j-1]) ? arr[i-1][j] : arr[i][j-1];

                }

        }
        return arr[m][n];
}
/*int main()
{
        char *x = "GXTXAYB";
        char *y = "AGGTAB";
        int m = strlen(x);
        int n = strlen(y);
        int ret = lcs(x, y, m, n);
        printf("\n ret=%d\n", ret);
        return 0;
}*/
