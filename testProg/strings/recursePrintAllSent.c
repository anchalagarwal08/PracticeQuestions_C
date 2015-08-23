/*Given a list of word lists How to print all sentences possible taking one word from a list at a time via recursion?*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define R 3
#define C 3
void printAllSentences(char *arr[R][C], int k, char *str[])
{
      int i=0,j=0;
	if(k==C)
	{
		for (j=0; j<R; j++)
		{
			printf("%s ", str[j]);
		}
		printf("\n");
		return;
	}
	for(i =0; i<C;i++)
	{
		if(arr[k][i]!=NULL){
		   str[k] = arr[k][i];
		   printAllSentences(arr, k+1, str);		
		}
	}
}
int main()
{
	char *arr[][3] = {{"you","we"},{"have","are"},{"sleep","eat", "drink"}};
	char **str = malloc(sizeof(char*) *20);
	int i, j;
	printAllSentences(arr, 0,str);
	if(str)
	 free(str);

	return 0;

}
