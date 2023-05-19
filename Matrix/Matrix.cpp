#include <iostream>
#pragma once
#include <cassert>
#include <iomanip>
using namespace std;

template <typename T>
class MyAll {
    public:
    T** operator()(size_t H, size_t W)
    {
        T** b;
        b = new T * [H];
        for (size_t i = 0; i < H; ++i) {
            b[i] = new T[W];
        }
        return b;
    }


};


template< typename T, size_t HeightCap, size_t WidthCap, class Alloc = MyAll<T>>
class Matrix {
    public:
        T** a;

    Matrix()
    {
        a = Alloc()(HeightCap, WidthCap);
        for (size_t i = 0; i < HeightCap; ++i) {
            for (size_t j = 0; j < WidthCap; ++j) {
                a[i][j] = 0;
            }
        }
    }

    Matrix<T, HeightCap, WidthCap, Alloc>(const Matrix<T, HeightCap, WidthCap, Alloc>& tmp)
    {
        a = Alloc()(HeightCap, WidthCap);
        for (int i = 0; i < HeightCap; ++i) {
            for (int j = 0; j < WidthCap; ++j) {
                a[i][j] = move(tmp.a[i][j]);
            }
        }
    }

    ~Matrix()
        {
            for (size_t i = 0; i < HeightCap; ++i) {
                delete[] a[i];
            }
            delete[] a;
        }





    T* operator[](size_t x) {
        return a[x];
    }




    void print()
    {
        for (size_t i = 0; i < HeightCap; ++i) {
            for (size_t j = 0; j < WidthCap; ++j) {
                cout << setw(5) << a[i][j];
            }
            cout << endl;
        }
    }


    


    Matrix<T, HeightCap, WidthCap, Alloc>& operator=(const Matrix<T, HeightCap, WidthCap, Alloc>& tmp)
    {
        if (this == &tmp) {
            return *this;
        }

        a = Alloc()(HeightCap, WidthCap);

        for (int i = 0; i < HeightCap; ++i) {
            for (int j = 0; j < WidthCap; ++j) {
                a[i][j] = tmp.a[i][j];
            }
        }
        return *this;
    }

    Matrix<T, HeightCap, WidthCap, Alloc> operator+(const Matrix<T, HeightCap, WidthCap, Alloc>& tmp)
    {
        Matrix<T, HeightCap, WidthCap> result;
        for (int i = 0; i < HeightCap; ++i) {
            for (int j = 0; j < WidthCap; ++j) {
                result.a[i][j] = a[i][j] + tmp.a[i][j];
            }
        }
        return result;
    }

    Matrix<T, HeightCap, WidthCap, Alloc> operator-(const Matrix<T, HeightCap, WidthCap, Alloc>& tmp)
    {
        Matrix<T, HeightCap, WidthCap> result;
        for (int i = 0; i < HeightCap; ++i) {
            for (int j = 0; j < WidthCap; ++j) {
                result.a[i][j] = a[i][j] - tmp.a[i][j];
            }
        }
        return result;
    }




    template<size_t WidthCapN>
    Matrix<T, HeightCap, WidthCap, Alloc> operator*(const Matrix<T, WidthCap, WidthCapN, Alloc>& m)
    {
        Matrix<T, HeightCap, WidthCapN, Alloc> result;
        for (int i = 0; i < HeightCap; ++i) {
            for (int j = 0; j < WidthCapN; ++j) {
                for (int k = 0; k < WidthCapN; ++k) {
                    result.a[i][j] += (a[i][k] * m.a[k][j]);
                }
            }
        }
        return result;
    }
};


