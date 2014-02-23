#include <stdio.h>
#include <iostream>
using namespace std;

int main(){

	int var =20;
	int *ip;
	
	ip = &var;
	cout<<"the address stored in ip is:"<< ip << endl;
	
	cout<<"value stored in ip is";
	cout<< *ip << endl;
	return 0;
}
