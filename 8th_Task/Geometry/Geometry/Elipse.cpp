#include "Figures.h"
#include <cmath>
#define M_PI 3.14159265358979323846

double Elipse::getPerimeter() const
{
	return 4 * ((M_PI*(a)*b) + pow((a - b),2))/(a+b);
}

double Elipse::getSquare() const
{
	return M_PI * a * b;
}

void Elipse::getInfo()
{
	std::cout << "Elipse\n\n";
	std::cout << "Semiaxes: a = " << a << ", b = " << b << "\n";
	std::cout << "Perimeter = " << getPerimeter() << "\n";
	std::cout << "Square = " << getSquare() << "\n\n";
}