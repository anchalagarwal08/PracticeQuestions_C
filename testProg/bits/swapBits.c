#include <stdio.h>
int swapBits(unsigned int);
int main(){

unsigned int num = 23;
printf("%u\n", swapBits(num));
}

int swapBits(unsigned int num){

unsigned int even = num & 0xAAAAAAAA;
unsigned int odd = num & 0x55555555;

even>>=1;
odd<<=1;
return (odd|even);
}


