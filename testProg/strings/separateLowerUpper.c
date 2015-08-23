/*Microsoft interview question. Separate lower and upper case letters in a string*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*utility function to shift letters. This can be optimized to shift a window of lowercase char rather than shifting one at a time*/
void shiftLetters(char arr[], int ptr1, int ptr2)
{
    char c = arr[ptr2];
    int i=0;
    while(ptr2>=ptr1)
    {
	if(arr[ptr2-1]==' ' && (arr[ptr2-2]>=65 && arr[ptr2-2]<=90)){
	   arr[ptr2] = arr[ptr2-2];
	   ptr2=ptr2-2;
	}
	else{
	  arr[ptr2] = arr[ptr2-1];
        ptr2--;
	}
    }
    arr[ptr1]=c;

}
/*Utility function to manage Spaces. All the extra spaces are shifted to the end of array. Only 1 space is left between upper and lower case char*/
void manageSpaces(char arr[], int ptr, int length)
{

	char temp[length-ptr+1];
	int i=0, j=ptr, count=0;
	while(j<length)
	{
		if(arr[j]==' ')
		   count++;
		else
		  temp[i++]=arr[j];
		j++;
	}
	if(count>0){
		arr[ptr] =' ';
		ptr++;
		i=0;
		while(ptr<j)
		{
			arr[ptr++]=temp[i++];
		}
	}

}
/*Main API to segregate lower case letters from upper case letters*/
void manageString(char arr[], int length)
{
	if(length==0)
		return;
	int i =0, ptr1=0, ptr2=0;
	while(i<length)
	{    
		if(arr[i]>=97 && arr[i]<=122){
			ptr1++;i++;
		}
		else{
		ptr2=ptr1;
		while(!((arr[ptr2]>=97 && arr[ptr2]<=122) || !arr[ptr2]==' '))
		{
			if(ptr2==length-1)
		          break;
			else
			  ptr2++;
		}
		if(ptr2==length-1 && arr[length-1]>=65 && arr[length-1]<=90)
		   break;
		else
		   shiftLetters(arr,ptr1,ptr2);
		}
	}
	
	printf("\n Changed String: %s\n", arr);
	manageSpaces(arr, ptr1, length);
} 

int main()
{
	char str[] = {'H','e',' ','l','L','o','W',' ','R','L','D'};
	printf("\n Original String: %s\n", str);
	manageString(str, 11);
	printf("\n %s\n",str);
	return 0;
}
