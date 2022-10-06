#include <iostream>

using namespace std;


int* mergeSort(int *Up, int *Down, int Left, int Right)
{
    if (Left == Right)
    {
        Down[Left] = Up[Left];
        return Down;
    }

    int Middle = Left + (Right - Left) / 2;

    int *LeftArr = mergeSort(Up, Down, Left, Middle);
    int *RightArr = mergeSort(Up, Down, Middle + 1, Right);

    int *ArrFin = LeftArr == Up ? Down : Up;

    int LeftCursor = Left, RightCursor = Middle + 1;
    for (int i = Left; i <= Right; i++)
    {
        if (LeftCursor <= Middle && RightCursor <= Right)
        {
            if (LeftArr[LeftCursor] < RightArr[RightCursor])
            {
                ArrFin[i] = LeftArr[LeftCursor];
                LeftCursor++;
            }
            else
            {
                ArrFin[i] = RightArr[RightCursor];
                RightCursor++;
            }
        }
        else if (LeftCursor <= Middle)
        {
            ArrFin[i] = LeftArr[LeftCursor];
            LeftCursor++;
        }
        else
        {
            ArrFin[i] = RightArr[RightCursor];
            RightCursor++;
        }
    }
    return ArrFin;
}

int main(){
    int n;
    cout << "Enter number of elements in array:"<< "\n";
    cin >> n;
    cout << "Enter elements of array:"<< "\n";
    int arr [n];
    int buff [n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        buff[i]=0;
    };

    int *arr1;
    arr1 = mergeSort(arr,buff,0,n-1);

    cout << "Sorted array: "<< endl;
    for (int i = 0; i < n; i++){
        cout << arr1[i]<< " ";
    };
}