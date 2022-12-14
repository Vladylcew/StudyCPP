#include"Figures.h"
using namespace std;


int main() {
	vector<double> a = { 3,4,1 };
	Triangle T(a);
	T.getInfo();
	Triangle Y(3, 4, 5);
	Y.getInfo();

	Rectangle A(3, 4);
	A.getInfo();

	Circle C(1);
	C.getInfo();

	Elipse E(2, 4);
	E.getInfo();

}