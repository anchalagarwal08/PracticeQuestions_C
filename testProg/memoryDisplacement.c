#include <stdio.h>

int main(void){
	char a;
	char b;
	a = 'X';
	b = 'Y';
	printf("Displacement %d\n:" , (int)&b - (int)&a);
}
