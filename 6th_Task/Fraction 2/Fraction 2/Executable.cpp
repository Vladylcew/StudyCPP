#include<iostream>
using namespace std;

#include"Fraction.h"



int main() {
	Fraction a(-21, 14);
	Fraction b(1, 3);
	cout << "a = " << a.getNom() << "/" << a.getDenom() << " = " << a.getFraction()<<endl;

	cout << "b = " << b.getNom() << "/" << b.getDenom()<<endl;

	Fraction c;
	c = a + b;
	cout <<  "c = a + b = " << c.getNom() << "/" << c.getDenom() << " = " << c.getFraction() << endl;
	
	Fraction d;
	d = a + 5;
	cout << "d = a + 5 = " << d.getNom() << "/" << d.getDenom() << " = " << d.getFraction() << endl;

	Fraction e;
	e = a - b;
	cout << "e = a - b = " << e.getNom() << "/" << e.getDenom() << " = " << e.getFraction() << endl;

	Fraction f;
	f = a - 8;
	cout << "f = a - 8 = " << f.getNom() << "/" << f.getDenom() << " = " << f.getFraction() << endl;

	Fraction g;
	g = -a;

	cout << "g = -a = " << g.getNom() << "/" << g.getDenom() << " = " << g.getFraction() << endl;

	g = +a;

	cout << "g = +a = " << g.getNom() << "/" << g.getDenom() << " = " << g.getFraction() << endl;

	Fraction h;
	h = a / 3;

	cout << "h = a / 3 = " << h.getNom() << "/" << h.getDenom() << " = " << h.getFraction() << endl;

	h = a / b;

	cout << "h = a / b = " << h.getNom() << "/" << h.getDenom() << " = " << h.getFraction() << endl;

	bool i;
	Fraction j(-3, 2);
	i = a <= j;
	
	cout << "i = a <= - 3/2 = " << i << endl;

	i = a < -2;

	cout << "i = a < - 2 = " << i << endl;

	a += 4;
	cout << "a+= 4\n" << "a = " << a.getFraction() << endl;

	a += b;
	cout << "a+= b\n" << "a = " << a.getFraction() << endl;

	a++;

	cout << "a++ \n" << "a = " << a.getFraction() << endl;

	++a;

	cout << "++a \n" << "a = " << a.getFraction() << endl;

	a--;

	cout << "a-- \n" << "a = " << a.getFraction() << endl;

	--a;

	cout << "--a \n" << "a = " << a.getFraction() << endl;
	return 0;
}