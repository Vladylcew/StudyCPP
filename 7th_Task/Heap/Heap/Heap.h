#pragma once

#include<iostream>
using namespace std;


template<typename T>
class Heap {
private:
	T* h;
	unsigned int HeapSize, HeapCapacity;
public:
	Heap();
	Heap(const Heap<T>& a);
	Heap(unsigned int a);
	~Heap();

	void Resize(unsigned int size);
	void addElem(T n);
	void getHeap();
	void getArrHeap();
	void SortHeap(unsigned int i);
	T getMax();
};

template <typename T>
Heap<T> ::Heap()
{
    HeapSize = 0;
    HeapCapacity = 0;
    h = NULL;
}

template <typename T>
Heap<T>::Heap(const Heap<T>& a)
{
    HeapSize = a.HeapSize;
    HeapCapacity = HeapSize;
    h = NULL;
    if (HeapSize != 0)
        h = new T[HeapSize];
    else
        h = 0;
    for (int i = 0; i < HeapSize; ++i)
        h[i] = a.h[i];
}

template <typename T>
Heap<T>::~Heap()
{
    if (h)
        delete[] h;
};

template <typename T>
Heap<T>::Heap(unsigned int a)
{
    HeapSize = a;
    HeapCapacity = a;
    if (a)
        h = new T[a];
    else
        h = 0;
}

template <typename T>
void Heap<T>::Resize(unsigned int size)
{
    if (size > HeapCapacity)
    {
        int new_capacity = size;
        T* new_data = new T[new_capacity];
        for (int i = 0; i < HeapSize; ++i)
            new_data[i] = h[i];
        delete[] h;
        h = new_data;
        HeapCapacity = new_capacity;
    }
    HeapSize = size;
}

template <typename T>
void Heap<T>::addElem(T n)
{
    Resize(HeapSize + 1);
    int i, parent;
    i = HeapSize - 1;

    h[i] = n;
    parent = (i - 1) / 2;
    while (parent >= 0 && i > 0) {
        if (h[i] > h[parent]) {
            int temp = h[i];
            h[i] = h[parent];
            h[parent] = temp;
        }
        i = parent;
        parent = (i - 1) / 2;
    }
}

template <typename T>
void Heap<T>::getHeap() {
    int i = 0;
    int k = 1;
    while (i < HeapSize) {
        while ((i < k) && (i < HeapSize)) {
            cout << h[i] << " ";
            i++;
        }
        cout << endl;
        k = k * 2 + 1;
    }
}

template <typename T>
void Heap<T>::getArrHeap() {
    for (int i = 0; i < HeapSize; i++) {
        cout << h[i] << " ";
    }
    cout << endl;
}

template <typename T>
void Heap<T>::SortHeap(unsigned int i) {
    unsigned int left, right;
    unsigned int temp;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if (left < HeapSize) {
        if (h[i] < h[left]) {
            temp = h[i];
            h[i] = h[left];
            h[left] = temp;
            SortHeap(left);
        }
    }
    if (right < HeapSize) {
        if (h[i] < h[right]) {
            temp = h[i];
            h[i] = h[right];
            h[right] = temp;
            SortHeap(right);
        }
    }
}

template<typename T>
T Heap<T>::getMax() {
    T temp;
    temp = h[0];
    h[0] = h[HeapSize - 1];
    Resize(HeapSize - 1);
    SortHeap(0);
    return temp;
}