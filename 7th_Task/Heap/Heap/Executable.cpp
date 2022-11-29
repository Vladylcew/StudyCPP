#include"Heap.h"
#include<iostream>

using namespace std;

int main() {
    Heap<char> h;
    char k;

    for (int i = 0; i < 16; i++) {
        cout << "Write down element " << i + 1 << ": ";
        cin >> k;
        h.addElem(k);
    }
    h.getHeap();
    cout << endl;
    h.getArrHeap();
    cout << endl << "Max: " << h.getMax();
    cout << endl << "New Heap: " << endl;
    h.getHeap();
    cout << endl;
    h.getArrHeap();
    cout << endl << "Max: " << h.getMax();
    cout << endl << "New Heap: " << endl;
    h.getHeap();
    cout << endl;
    h.getArrHeap();
    return 0;
}