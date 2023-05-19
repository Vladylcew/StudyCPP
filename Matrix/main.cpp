#include <iostream>
#include "matrix.cpp"

using namespace std;


template<typename T, size_t HeightCap, size_t WidthCap, class Alloc = MyAll<T>>
Matrix<T, WidthCap, HeightCap, Alloc> Transpose(Matrix<T, HeightCap, WidthCap, Alloc>&& tmp)
{
    Matrix<T, WidthCap, HeightCap, Alloc> result;
    for (int i = 0; i < HeightCap; ++i) {
        for (int j = 0; j < WidthCap; ++j) {
            result.a[j][i] = tmp.a[i][j];
        }
    }
    return result;
}

int main() {
    Matrix<int, 2, 3> a;
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;

    Matrix<int, 2, 2> b;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            b[i][j] = j-i;
        }
    }

    Matrix <int, 2, 2> c;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            c[i][j] = i + j;
        }
    }




    cout << "Matrix a \n";
    a.print();
    cout << "Matrix b \n";
    b.print();
    cout << "Matrix c \n";
    c.print();
    Matrix<int, 2, 2> d;


    d = b + c;
    cout << "Matrix b + c \n";
    d.print();

    d = b * c;
    cout << "Matrix b * c \n";
    d.print();

    cout << "Matrix a Transposed \n";
    Transpose(move(a)).print();


    /*d = a + b; выдает ошибку в compile tiem */



    return 0;
}