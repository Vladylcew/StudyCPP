#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRС {
private:
    int Capacity;
    size_t Size = 0;

    list<int> Priority;
    unordered_map<int, int> Cont;

public:


    LRС(int cap = 10):
    Capacity(cap)
    {};

    ~LRС() {
        Cont.clear();
        Priority.clear();
        Size = 0;
        Capacity = 0;
    };


    int get(int i) {
        int el = Cont[i];
        if (el) {
            Priority.remove(i);
            Priority.push_back(i);
        }
        return el;
        //Работает за О(1), т.к. в контейнерах методы работают по той же асимптотике
    };

    void put(int i, int value) {
        if (Cont[i])
            Priority.remove(i);
        else if (Size < Capacity) {
            ++Size;
        }
        else {
            Cont.erase(Priority.front());
            Priority.pop_front();
            Priority.push_back(i);
        }
        Priority.push_back(i);
        Cont[i] = value;
        //Аналогично с get()
    };
    void pop(int i) {
        Cont.erase(i);
        Priority.remove(i);
        --Size;
    }
};


int main()
{
    LRС a(4);
    a.put(1, 43);
    a.put(2, 342);
    a.put(5, 345);
    a.put(9, -34);

    cout << a.get(1) << "\n";
    cout << a.get(2) << "\n";
    cout << a.get(5) << "\n";
    cout << a.get(9) << "\n";
    cout << endl;

    a.put(13, 28);
    cout << a.get(13) << "\n";
    cout << a.get(1) << "\n" << endl;


    a.put(2, 16);
    a.put(95, 7);
    cout << a.get(2) << "\n";
    cout << a.get(5) << "\n" << endl;
    
    cout << a.get(25) << "\n" << endl;
  
    a.put(100, 18);
    cout << a.get(98) << endl;


}