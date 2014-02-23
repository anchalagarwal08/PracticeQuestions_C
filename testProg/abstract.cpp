#include <iostream>
#include <stdio.h>
using namespace std;

class A{

	public:
        virtual const void fun()=0;
};
class B: public A{
	public:
	virtual const void fun()
	{
		cout<<"am in derived class";
	}
	void ret(){
		cout << "crapppp";
	}
};

int main(){

	B* a = new B();
	a.ret();
}
