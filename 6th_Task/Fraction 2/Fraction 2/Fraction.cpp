#include "Fraction.h"
#include<cmath>
#include<iostream>

using namespace std;

int gcd(int a, int b) {
	a = abs(a);
	return b ? gcd(b, a % b) : a;
}

Fraction::Fraction(int nom, int denom) {
	setFraction(nom, denom);
	Reduction();
}

Fraction::Fraction() {}

void Fraction::setFraction(int nom, int denom) {
	if (denom < 0) {
		nominator = -nom;
		denominator = -denom;
	}
	else if (denom == 0) {
		cout << "Error, deviding by zero";
	}
	else {
		nominator = nom;
		denominator = denom;
	};
}

void Fraction::Reduction() {
		int NOD;
		NOD = gcd(nominator, denominator);
		nominator = nominator / NOD;
		denominator = denominator / NOD;
}

float Fraction::getFraction() {
	return (nominator * 1.0) / (denominator * 1.0);
}

int Fraction::getNom() {
	Reduction();
	return nominator;
}

unsigned int Fraction::getDenom() {
	Reduction();
	return denominator;
}

Fraction Fraction ::operator+(int a) {
	Fraction temp;
	temp = Fraction(a * denominator + nominator, denominator);
	temp.Reduction();
	return temp;
}

Fraction Fraction ::operator+() {
	Fraction temp;
	temp = Fraction(nominator, denominator);
	temp.Reduction();
	return temp;
}

Fraction Fraction ::operator+(Fraction& obg) {
	Fraction temp;
	temp = Fraction(nominator * obg.denominator + obg.nominator * denominator, denominator * obg.denominator / gcd(denominator, obg.denominator));
	temp.Reduction();
	return temp;
}

Fraction Fraction ::operator+=(int a) {
	Fraction temp;
	temp = *this + a;
	temp.Reduction();	
	*this = temp;
	return temp;
}

Fraction Fraction ::operator+=(Fraction& obg) {
	Fraction temp;
	temp = *this + obg;
	temp.Reduction();
	*this = temp;
	return temp;
}

Fraction Fraction ::operator++() {
	Fraction temp;
	temp = *this + 1;
	temp.Reduction();
	*this = temp;
	return temp;
}

Fraction Fraction ::operator++(int) {
	Fraction temp;
	temp = *this + 1;
	temp.Reduction();
	*this = temp;
	return temp;
}

Fraction Fraction ::operator-(int a) {
	Fraction temp;
	temp = Fraction(-a * denominator + nominator, denominator);
	temp.Reduction();
	return temp;
}

Fraction Fraction ::operator-(Fraction& obg) {
	Fraction temp;
	temp = Fraction(nominator * obg.denominator - obg.nominator * denominator, denominator * obg.denominator / gcd(denominator, obg.denominator));
	temp.Reduction();
	return temp;
}

Fraction Fraction ::operator-() {
	Fraction temp;
	temp = Fraction(-nominator, denominator);
	temp.Reduction();
	return temp;
}

Fraction Fraction ::operator-=(int a) {
	Fraction temp;
	temp = *this - a;
	temp.Reduction();
	*this = temp;
	return temp;
}

Fraction Fraction ::operator-=(Fraction& obg) {
	Fraction temp;
	temp = *this - obg;
	temp.Reduction();
	*this = temp;
	return temp;
}

Fraction Fraction::operator--(){
	Fraction temp;
	temp = *this - 1;
	temp.Reduction();
	*this = temp;
	return temp;
}

Fraction Fraction::operator--(int) {
	Fraction temp;
	temp = *this - 1;
	temp.Reduction();
	*this = temp;
	return temp;
}

Fraction Fraction ::operator*(int a) {
	Fraction temp;
	temp = Fraction(nominator * a, denominator);
	temp.Reduction();
	return temp;
}

Fraction Fraction ::operator*(Fraction& obg) {
	Fraction temp;
	temp = Fraction(nominator * obg.nominator, denominator * obg.denominator);
	temp.Reduction();
	return temp;
}

Fraction Fraction ::operator/(int a) {
	Fraction temp;
	temp = Fraction(nominator, denominator * a);
	temp.Reduction();
	return temp;
}

Fraction Fraction ::operator/(Fraction& obg) {
	Fraction temp;
	temp = Fraction(nominator * obg.denominator, denominator * obg.nominator);
	temp.Reduction();
	return temp;
}

bool Fraction ::operator>(Fraction& obg) {
	return ((*this - obg).getNom() > 0);
}

bool Fraction ::operator>=(Fraction& obg) {
	return ((*this - obg).getNom() >= 0);
}

bool Fraction ::operator<(Fraction& obg) {
	return ((*this - obg).getNom() < 0);
}

bool Fraction ::operator<=(Fraction& obg) {
	return ((*this - obg).getNom() <= 0);
}

bool Fraction ::operator>(int obg) {
	return ((*this - obg).getNom() > 0);
}

bool Fraction ::operator>=(int obg) {
	return ((*this - obg).getNom() >= 0);
}

bool Fraction ::operator<(int obg) {
	return ((*this - obg).getNom() < 0);
}

bool Fraction ::operator<=(int obg) {
	return ((*this - obg).getNom() <= 0);
}