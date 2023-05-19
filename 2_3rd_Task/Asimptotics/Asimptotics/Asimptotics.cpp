#include <chrono>
#include <iostream>
#include <set>
#include <vector>
#include<algorithm>

using namespace std;

class LogDuration {
public:
    LogDuration(string id)
        : id_(move(id)) {
    }

    ~LogDuration() {
        const auto end_time = chrono::steady_clock::now();
        const auto dur = end_time - start_time_;
        cout << id_ << ": ";
        cout << "operation time"
            << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count()
            << " ms" << std::endl;
    }

private:
    const std::string id_;
    const std::chrono::steady_clock::time_point start_time_ = std::chrono::steady_clock::now();
};

template <typename T>
void MySort(T a, size_t aSize) {
    sort(a, a + aSize);
}


void MySort(vector<int> a){
    sort(a.begin(),a.end());
}


int main() {
    int N = 0;
    vector<int> a;
    N = 1e7;
    for (int i = 0; i < N; i++) {
        a.push_back(rand());
    };
    const size_t l = a.size();
    vector<int> b;
    int* arr;

    {
        LogDuration ld("Vector sort");
        for (int i = 0; i < a.size(); i++) {
            b.push_back(a[i]);
        };
        MySort(b);
    }
    set<int> c;
    {
        LogDuration ld("Set insert");
        for (int i = 0; i < a.size(); i++) {
            c.insert(a[i]);
        };
    }

    {
        LogDuration ld("Array sort");
        for (int i = 0; i < a.size(); i++) {
            arr[i] = a[i];
        };
        MySort(arr, a.size());
    }


}