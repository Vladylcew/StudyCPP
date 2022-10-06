#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements in array:"<< "\n";
    cin >> n;
    cout << "Enter elements of array:"<< "\n";
    int* arr;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    };
    cout << "Choose type of sorting:" << "\n" << "1) Ascending" << "\n" << "2) Descending" << "\n";
    int c;
    cin >> c;
    switch(c){
        case 1:
            sort(arr, arr+n, [](int a,int b){return a < b;});
            break;
        case 2:
            sort(arr, arr+n, [](int a,int b){return a > b;});
            break;
    }

    for (int i =0; i<n; i++)
    {
        cout << arr[i] << ' ';
    }
}
