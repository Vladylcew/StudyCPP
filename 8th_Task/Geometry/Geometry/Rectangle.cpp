#include"Figures.h"

double Rectangle::getPerimeter() const
{
	double tmp = 0;
	tmp = (a + b) * 2;

	return tmp;
}

double Rectangle::getSquare() const
{
	double tmp = 0;
	tmp = a * b;

	return tmp;
}

void Rectangle::getInfo()
{
	std::cout << "Rectangle\n\n";
	print(Lines);
	std::cout << "Diagonal = " << getDiagonal() << "\n";
	std::cout << "Perimeter = " << getPerimeter() << "\n";
	std::cout << "Square = " << getSquare() << "\n\n";
}

double Rectangle::getDiagonal() const
{
	return sqrt(a*a + b*b);
}