#include<iostream>
#include<tuple>

using namespace std;

template <typename T>
void printElem(const T& x) {
    std::cout << x << ',';
};

template <typename TupleT, std::size_t... Is>
void printTupleManual(const TupleT& tp, std::index_sequence<Is...>) {
    (printElem(std::get<Is>(tp)), ...);
}

template <typename TupleT, size_t TupSize = tuple_size_v<TupleT>>
void printTuple(const TupleT& tp) {
    printTupleManual(tp, std::make_index_sequence<TupSize>{});
}


int main() {
    std::tuple<int, char, float> a{ 6, 'v', 4.3 };
    printTuple(a);
}