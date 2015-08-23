/*Given an input file with 4 billion non-negative integers. Provide an algo to find an integer that is not in thie file. Assume you have 1GB of memory for the task
Since total non-negative are only 2^31 however 4billion= 2^32 roughly, there has to be duplicates
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findMissing1GB(FILE *fp)
{
	char arr[1000000000]={0,};
	int i =0,k,j;
	while(!feof(fp))
	{
		fscanf(fp, "%d,", &i);
		arr[i/8]|=1<<(i%8);
	}
	for(j=0; j<sizeof(arr)/sizeof(char);j++)
	{
		for(k=0;k<8;k++)
		{
			if((arr[j]&(1<<k))==0)
				return (8*j+k);
		}

	}
	return -1;
}
int main()
{
	FILE *fp = fopen("somefile.txt","r");
	printf("%d",findMissing1GB(fp));
	return 0;
}
