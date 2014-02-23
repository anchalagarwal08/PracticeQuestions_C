#include "stdio.h"
#include "iostream"
using namespace std;

class Area
{
	public:
	int length;
	int width;
	
	virtual int area(){
		return (length*width);
	}
};

class Perim: public Area
{
	public:
	virtual int area(){
		return (2*(length+width));
	}
};
int main(){
	Perim a1;
	Area a2;
//	Area a2 = new Area;
	a1.length = 10;
	a1.width = 20;
	a2.length = 2;
	a2.width = 4;
	cout<< a1.area() << endl;
	cout << a2.area() << endl;
}
