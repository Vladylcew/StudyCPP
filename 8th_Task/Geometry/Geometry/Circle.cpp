#include "Figures.h";


void Circle::getInfo()
{
	std::cout << "Circle\n\n";
	std::cout << "Radius: r = " << r << "\n";
	std::cout << "Perimeter = " << getPerimeter() << "\n";
	std::cout << "Square = " << getSquare() << "\n\n";
}