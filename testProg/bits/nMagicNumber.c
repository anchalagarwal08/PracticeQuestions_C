/*
A magic number is defined as a number which can be expressed as a power of 5 or sum of unique powers of 5. First few magic numbers are 5, 25, 30(5 + 25), 125, 130(125 + 5), ….
Write a function to find the n’th Magic number.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double magicNumber(int n)
{
	double arr[50];
	int i=2;
	double j, val=0.0; double p=2;
	
	if(n==1)
          return 5;
	if(n==2)
	  return 25;
	arr[0] = pow(5.0,1.0);
	arr[1] = pow(5.0,2.0);
	while(i<n)
	{
	   if(i==n+1)
	    return arr[i-1];
	   for(j=1 ; j<p ;j++)
	   {
		
		val = pow(5.0,p)+ pow(5.0,(p-j));
		arr[i++]=val;
		if(i==n+1)
		  return arr[i-1];
	   }
	  printf("\n i=%d",i);
	  p = p+1.0;
	  arr[i++] = pow(5.0,p);
	}
	printf("\n i=%d\n",i);
	return arr[i-1];
	
}

int main()
{
	printf("\n magic number: %lf", magicNumber(7));
	return 0;
}
