/*Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number.
For example, if n is 10, the output should be “2, 3, 5, 7″. If n is 20, the output should be “2, 3, 5, 7, 11, 13, 17, 19″.
The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million or so (Ref Wiki).*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int markMultiple(bool arr[], int a, int n)
{
	int i=2,num=0;
	while((num=i*a)<=n)
	{
		arr[num-1]=1;
		i++;
	}
}

void findPrimeInRange(int n)
{
	if(n>=2)
	{
		bool arr[n];
		memset(arr,0,n);
		int i=0;
		for(i=1;i<n;i++)
		{
			if(arr[i]==0)
			{
				printf("\n%d\n",i+1);
				markMultiple(arr,i+1,n);
			}
		}
	}
}

int main()
{
	findPrimeInRange(30);
	return 0;

}
