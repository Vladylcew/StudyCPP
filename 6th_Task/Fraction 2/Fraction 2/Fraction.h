#pragma once;


int gcd(int a, int b);

class Fraction {
private:
	int nominator;
	unsigned int denominator;

public:
	explicit Fraction(int nom, int denom);
	Fraction();

	void setFraction(int nom, int denom);
	void Reduction();
	float getFraction();
	int getNom();
	unsigned int getDenom();

	Fraction operator+(int a);
	Fraction operator+(Fraction& obg);
	Fraction operator+();

	Fraction operator+=(int a);
	Fraction operator+=(Fraction& obg);

	Fraction operator++();
	Fraction operator++(int);

	Fraction operator-(int a);
	Fraction operator-(Fraction& obg);
	Fraction operator-();

	Fraction operator-=(int a);
	Fraction operator-=(Fraction& obg);

	Fraction operator--();
	Fraction operator--(int);

	Fraction operator*(int a);
	Fraction operator*(Fraction& obg);

	Fraction operator/(int a);
	Fraction operator/(Fraction& obg);

	bool operator>(Fraction& obg);
	bool operator>=(Fraction& obg);

	bool operator<(Fraction& obg);
	bool operator<=(Fraction& obg);

	bool operator>(int obg);
	bool operator>=(int obg);

	bool operator<(int obg);
	bool operator<=(int obg);
};