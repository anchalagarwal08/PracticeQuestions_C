/*Fox Ciel has a long ciphertext containing a positive integer. Convert this number to hexadecimal. If you get the representation of a valid hexspeak word, return that word. Otherwise, return the string "Error!" (quotes for clarity). In other words, you should return "Error!" if the hexadecimal representation of ciphertext contains some occurrence of a digit between 2 and 9, inclusive.
 
Definition
    	
Class:	Hexspeak
Method:	decode
Parameters:	long
Returns:	String
Method signature:	String decode(long ciphertext)
(be sure your method is public)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decode(long cipher)
{
	int temp, i, j, c;
	char hex[1000];
	while(cipher!=0)
	{
		temp = cipher%16;
		if((temp>1 && temp<10)){
		  c=-1;
		  break;
		}
		else if(temp==0)
		  hex[i++]='O';
		else if(temp==1)
		  hex[i++]= 'I';
		else
		  hex[i++] = temp+55;
		cipher=cipher/16;
	}

	if(c==-1)
		printf("\n error \n");
	else
	{
		for(j=i-1;j>=0;j--)
		{
			printf("%c", hex[j]);
		}
	}
	printf("\n");
}

int main()
{
	long cipher = 257;
	decode(cipher);
	return 0;
}
