#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[][4]={{1,2,3,4},
		     {5,6,7,8},
		     {9,10,11,12},
		     {13,14,15,16}
		     };
	int row = 4, colmax=4,col=0;
	int i=0,j=0;
	for(i=0;i<col;i++)
	{
	  for(j=0;j<=i;j++){
		printf("%d",arr[j][i-j]);
	  }
	  printf("\n");
	}

	for(i=1;i<row;i++)
        { col =colmax;
          for(j=i;j<row;j++){
                printf("%d",arr[j][col]);
		col--;
          }
 printf("\n");
        }

return 0;
}
