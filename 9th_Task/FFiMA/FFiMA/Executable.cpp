#include<iostream>
#include"FFiMA.h"
using namespace std;


int main() {
	FIFO<char,string> C;
	C.push('x');
	C.push('y');
	C.push('z');
	char a, b, c;
	a = C.get();
	b = C.get();
	c = C.get();
	cout << a << "\n" << b<<"\n"<<c<<"\n";
	

	FIFO<int,vector<int>> A;
	A.push(1);
	A.push(5);
	A.push(4);

	cout << A.get() << " ";
	cout << A.get() << " ";
	cout << A.get();


}