#include <iostream>
#include <vector>

using namespace std;

void PrintSipacity(vector<int>& e) {
	bool f = 0;
	for (int i = 0; i < 1e5; i++) {
		e.push_back(1);
		if (e.size() == e.capacity()) {
			cout << "Size:" << e.size() << ", Capacity: " << e.capacity() << endl;
			f = 1;
		}
		else if (f) {
			cout << "Size:" << e.size() << ", Capacity: " << e.capacity() << endl;
			f = 0;
		};
	};
}

void PrintSipacity1(vector<int>& e) {
	bool f = 0;
	while(true) {
		e.push_back(1);
		if (e.size() == e.capacity()) {
			cout << "Size:" << e.size() << ", Capacity: " << e.capacity() << endl;
			f = 1;
		}
		else if (f) {
			cout << "Size:" << e.size() << ", Capacity: " << e.capacity() << endl;
			f = 0;
		};
	};
}

int main() {
	vector<int> a;
	PrintSipacity(a);

	vector<int> b;
	b.reserve(100);
	cout << b.capacity()<<endl;
	b.push_back(1);
	cout << b.capacity() << endl;
	PrintSipacity(b);

	cout << "------------------------------------";
	vector<int> c;
	c.reserve(1e8);

	PrintSipacity1(c);
	// Если немного подождать пока заполнится вся Оперативка компьютера, то можно увидеть, что прога выкидывает исключение std::bad_alloc по адресу памяти ...
}
