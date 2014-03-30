#include<stdio.h>
#include <stdlib.h>
void func( int *p)

{

printf("%d \n", *((int *)p - 2));

// Add code to print MEMORY SIZE which is pointed by pointer p.

}

int main()

{

int *p = (int *) malloc (10);

func(p);
free(p);
}
