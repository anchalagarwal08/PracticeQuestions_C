#include <stdio.h>
#define INT_SIZE 32

int leftRotate(int n, unsigned int d){
 return (n<<d)|(n>>(INT_SIZE-d));
}

int rightRotate(int n, unsigned int d){

	return (n>>d)|(n<<(INT_SIZE-d));
}

int main(){
	int n =16;
	int d = 2;
	printf("left rotation %d: ", leftRotate(n,d));
	printf("\n right rotation %d: ", rightRotate(n,d));
}
