#include <iostream>
using namespace std;

void print() {
	cout << endl;
}

template <typename Head, typename...Tail>
void print(Head&& head, Tail&&... tail) {
	cout <<head  << " ";
	print(tail...);
}

int main() {
	int b = 5;
	int& a = b;
	int c = -54;
	print(1, 5.4, -2 ,"f g", a);
	print(1, 5.4, -2, "f g",b, move(c));
}
