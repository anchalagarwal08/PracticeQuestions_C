/* Given an array of strings with R, G & B as characters. Sort the array such that all R comes first, followed by Gs & followed by Bs. Do it in O(n) time complexity.
   I/P: G G R B R B B G R B R
   O/P: R R R R G G G B B B B */

#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
	printf("a=%c, b=%c", *a, *b);
	char *c;
        *c=*a;
	*a=*b;
	*b=*c;	
}

void sortRGB(char arr[], int len)
{
	int i=0,low=0,mid=0, high=len-1;
	while(mid<=high)
	{
		switch(arr[mid])
		{
			case 'R':
			swap(&arr[low], &arr[mid]);
			low++;mid++;
			break;
			case 'G':
			mid++;
			break;
			case 'B':
			swap(&arr[mid], &arr[high]);
			mid++; high--;
			break;

		}

	}
	
	for(i=0;i<len;i++)
	{
		printf("%c,", arr[i]);
	}
}

int main()
{
	char arr[]= {'G','G','R','B','R','B','B','G','R','B','R'};
	sortRGB(arr, strlen(arr));
	getchar();
	return 0;
}
