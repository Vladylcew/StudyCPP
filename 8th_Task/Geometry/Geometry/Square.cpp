#include "Figures.h"

double Square::getPerimeter() const
{
	return 4 * a;
}

double Square::getSquare() const
{
	return a*a;
}

void Square::getInfo()
{
	std::cout << "Sqare\n\n";
	print(Lines);
	std::cout << "Perimeter = " << getPerimeter() << "\n";
	std::cout << "Square = " << getSquare() << "\n\n";
}