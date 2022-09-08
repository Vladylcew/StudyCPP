#include <iostream>

using std::cin, std::cout;

int main(){
    int x,y;
    cin >> x >> y;
    y = x + y;
    x = y - x;
    y = y - x;
    cout << x << " " << y;
}
