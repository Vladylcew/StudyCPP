
#include <iostream>

template<typename RT, typename ... Types>
RT Size1(RT firstArg, Types... args)
{
    if constexpr (sizeof...(args) > 0)
    {
        return Size1(firstArg) + Size1(args...);
    }
    else
    {
        return sizeof(firstArg);
    }
}

template<typename T, typename... Types>
void print_second_realization(T first_argument, Types... arguments) {
    std::cout << first_argument << ' ';
    if constexpr (sizeof...(arguments) > 0) {
        print_second_realization(arguments...);
    }
}

template<typename ... Types>
auto Size2(Types... args)
{
    return (... + sizeof(args));
}

int main()
{
    int a = 1, b = 2, c = 5;
    int size_in_bytes_1, size_in_bytes_2;

    size_in_bytes_1 = Size1<int, int, int>(a, b, c);
    size_in_bytes_2 = Size2<int, int, int>(a, b, c);

    std::cout << "First method:  " << size_in_bytes_1 << " bytes." << '\n';
    std::cout << "Second method: " << size_in_bytes_2 << " bytes." << '\n';

    return 0;
}
