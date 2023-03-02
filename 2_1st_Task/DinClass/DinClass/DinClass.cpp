#include <iostream>
#include <vector>
#include <chrono>

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


class MemoryBlock1
{
public:

    explicit MemoryBlock1(size_t length)
        : _length(length)
        , _data(new int[length])
    {
        vec.resize(length);

    }

    ~MemoryBlock1()
    {

        if (_data != nullptr)
        {
            delete[] _data;
        }
    }

    MemoryBlock1(const MemoryBlock1& other)
        : _length(other._length)
        , _data(new int[other._length])
    {
        vec = other.vec;

        std::copy(other._data, other._data + _length, _data);
    }

    MemoryBlock1& operator=(const MemoryBlock1& other)
    {

        if (this != &other)
        {
            delete[] _data;

            _length = other._length;
            _data = new int[_length];
            std::copy(other._data, other._data + _length, _data);

            vec = other.vec;
        }
        return *this;
    }

    size_t Length() const
    {
        return _length;
    }

    size_t _length; 
    int* _data; 
    vector<int> vec;
};

class MemoryBlock2
{
public:

     MemoryBlock2(size_t length)
        : _length(length)
        , _data(new int[length])
    {
        vec.resize(length);

    }

    ~MemoryBlock2()
    {

        if (_data != nullptr)
        {
            delete[] _data;
        }
    }


    MemoryBlock2(MemoryBlock2&& other) noexcept
        : _data(nullptr)
        , _length(0)
    {
        _data = other._data;
        _length = other._length;
        vec = other.vec;

        other.vec.clear();
        other._data = nullptr;
        other._length = 0;
    }

    MemoryBlock2& operator=(MemoryBlock2&& other) noexcept
    {
        if (this != &other)
        {
            delete[] _data;

            _data = other._data;
            _length = other._length;
            vec = other.vec;

            other.vec.clear();
            other._data = nullptr;
            other._length = 0;
        }
        return *this;
    }


    size_t Length() const
    {
        return _length;
    }

    size_t _length; 
    int* _data;
    vector<int> vec;
};


int main() {
    MemoryBlock1 A(3e7);

    for (int i = 0; i < A._length; i++) {
        A._data[i] = rand();
    }

    MemoryBlock1 B(1e7);

    MemoryBlock2 C(3e7);
    for (int i = 0; i < C._length; i++) {
        C._data[i] = rand();
    }
    MemoryBlock2 D(1e7);

    {

        LogDuration ld("Copy construction");
        MemoryBlock1 E(A);
    }
     {
        LogDuration ld("Move construction");
        MemoryBlock2 F(move(C));
    }
    {
        LogDuration ld("Copy Assignment");
        A = B;
    }
    {
        LogDuration ld("Move Assignment");
        C = move(D);
    }
};