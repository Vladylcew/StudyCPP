#include <iostream>
#pragma once
#include <cassert>
#include <iomanip>
using namespace std;


template< typename T, size_t HeightCap, size_t WidthCap>
class Matrix {
    public:

        T **a;

    Matrix()
    {
        Resize(HeightCap,WidthCap);
        for (size_t i = 0; i < HeightCap; ++i) {
            for (size_t j = 0; j < WidthCap; ++j) {
                a[i][j] = 0;
            }
        }
    }

    Matrix<T, HeightCap, WidthCap>(const Matrix<T, HeightCap, WidthCap>& tmp)
    {
        Resize(HeightCap, WidthCap);
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


    


    Matrix<T, HeightCap, WidthCap>& operator=(const Matrix<T, HeightCap, WidthCap>& tmp)
    {
        if (this == &tmp) {
            return *this;
        }

        Resize(HeightCap, WidthCap);

        for (int i = 0; i < HeightCap; ++i) {
            for (int j = 0; j < WidthCap; ++j) {
                a[i][j] = tmp.a[i][j];
            }
        }
        return *this;
    }

    Matrix<T, HeightCap, WidthCap> operator+(const Matrix<T, HeightCap, WidthCap>& tmp)
    {
        Matrix<T, HeightCap, WidthCap> result;
        for (int i = 0; i < HeightCap; ++i) {
            for (int j = 0; j < WidthCap; ++j) {
                result.a[i][j] = a[i][j] + tmp.a[i][j];
            }
        }
        return result;
    }

    Matrix<T, HeightCap, WidthCap> operator-(const Matrix<T, HeightCap, WidthCap>& tmp)
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
    Matrix<T, HeightCap, WidthCap> operator*(const Matrix<T, WidthCap, WidthCapN>& m)
    {
        Matrix<T, HeightCap, WidthCapN> result;
        for (int i = 0; i < HeightCap; ++i) {
            for (int j = 0; j < WidthCapN; ++j) {
                for (int k = 0; k < WidthCapN; ++k) {
                    result.a[i][j] += (a[i][k] * m.a[k][j]);
                }
            }
        }
        return result;
    }


    void Resize(size_t H,size_t W)
    {
        a = new T*[H];
        for (size_t i = 0; i < H; ++i) {
            a[i] = new T[W];
        }
    }
};


