#pragma once
#include<iostream>
#include<vector>


class Point
{
private:
	double x, y;
public:

	Point(const double a, const double b): x(a), y(b){
		std::cout << "Constructing Point.\n";
	};
	Point() {
		std::cout << "Constructing Point.\n";
	}

	virtual double getPerimeter() const = 0;
	virtual double getSquare() const = 0;
	virtual void getInfo() {
		std::cout << "Point\n";
		std::cout << "X coord: " << getX() << "\n";
		std::cout << "Y coord: " << getY() << "\n";
	};

	double getX() { return x; };
	double getY() { return y; };

};

class Polygon : public Point
{
private:
	int numOfAngles;
protected:
	std::vector<double> Lines;
	Polygon(int tmp = 3) : numOfAngles(tmp)
	{
		Lines.resize(numOfAngles);
		std::cout << "Constructing Polygon.\n";
	}
	virtual void print(std::vector<double> tmp) {
		for (int i = 0; i < tmp.size(); i++) {
			std::cout << tmp[i] << " ";
		};
		std::cout << "\n";
	}
public:
	Polygon(int tmp, const std::vector<double>& tmp1) : numOfAngles(tmp)
	{
		if (tmp < 3)
		{
			std::cout << "Error: unable to create polygon.\n";
			return;
		}
		for (int i = 0; i < numOfAngles; i++)
			Lines.push_back(tmp1[i]);
		std::cout << "Constructing Polygon.\n";
	}
};



class Triangle : public Polygon
{
private:
	bool check(double a, double b, double c);

public:
	Triangle(const std::vector<double>& tmp) : Polygon(3, tmp)
	{
		if (! check(tmp[0], tmp[1], tmp[2])) {
			std::cout << "Error: unable to create Triangle with this sides.\n";
			Lines[0] = 0;
			Lines[1] = 0;
			Lines[2] = 0;
			return ;
		}
		std::cout << "Creating Triangle.\n";
	}
	Triangle(double a, double b, double c) : Polygon(3)
	{
		if (! check(a,b,c)) {
			std::cout << "Error: unable to create Triangle with this sides.\n";
			Lines[0] = 0;
			Lines[1] = 0;
			Lines[2] = 0;
			return;
		}
		std::cout << "Creating Triangle.\n";
		Lines[0] = a;
		Lines[1] = b;
		Lines[2] = c;
	}
	virtual double getPerimeter() const override final;
	virtual double getSquare() const override final;
	virtual void getInfo() override final;
};

class Rectangle : public Polygon
{
private:
	double a, b;


public:
	Rectangle(const std::vector<double>& tmp) :Polygon(4)
	{
		std::cout << "Creating Rectangle.\n";
		a = tmp[0];
		b = tmp[1];

		Lines[0] = tmp[0];
		Lines[1] = tmp[1];
		Lines[2] = tmp[0];
		Lines[3] = tmp[1];
	};
	Rectangle(double x, double y) :Polygon(4)
	{
		std::cout << "Creating Rectangle.\n";
		a = x;
		b = y;

		Lines[0] = a;
		Lines[1] = b;
		Lines[2] = a;
		Lines[3] = b;
	};
	virtual double getPerimeter() const override;
	virtual double getSquare() const override;
	virtual void getInfo() override;

	double getDiagonal() const;
};

class Square : public Rectangle
{
private:
	double a;
public:
	Square(double x):Rectangle(x,x){
		a = x;
		std::cout << "Creating Square";
	}
	virtual double getPerimeter() const override final;
	virtual double getSquare() const override final;
	virtual void getInfo()  override final;
};

class Elipse : public Point
{
private:
	double a, b;
public:
	Elipse(const std::vector<double>& tmp)
	{
		std::cout << "Creating Elipse.\n";
		a = tmp[0];
		b = tmp[1];
	};
	Elipse(double x, double y)
	{
		std::cout << "Creating Elipse.\n";
		a = x;
		b = y;
	};
	virtual double getPerimeter() const override;
	virtual double getSquare() const override;
	virtual void getInfo()  override;
};

class Circle : public Elipse
{
private:
	double r;
public:
	Circle(double a) :Elipse(a, a)
	{
		std::cout << "Creating Circle.\n";
		r = a;
	}
	virtual void getInfo()  override final;
};