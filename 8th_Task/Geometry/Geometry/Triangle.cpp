#include "Figures.h"
#include <cmath>

bool Triangle:: check(double a, double b, double c)
{
	return (a + b > c) and (a + c > b) and (b + c > a);
}

double Triangle::getPerimeter() const
{
	double tmp = 0;
	for (int i = 0; i < 3; i++) {
		tmp += Lines[i];
	}
	return tmp;
}

double Triangle::getSquare() const
{
	double tmp,p = 0;
	p = getPerimeter()/2;
	tmp = sqrt(p * (p - Lines[0]) * (p - Lines[1]) * (p - Lines[2]));

	return tmp;
}

void Triangle::getInfo()
{
	std::cout << "Triangle\n\n";
	print(Lines);
	std::cout << "Perimeter = " << getPerimeter() << "\n";
	std::cout << "Square = " << getSquare() << "\n\n";
}

