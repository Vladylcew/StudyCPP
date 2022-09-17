#include<iostream>
#include<cmath>
using namespace std;
int main(){
    cout<<"Enter numbers of elements: "<<endl;
    int lenght;
    cin>>lenght;
    double arr[lenght];
    cout<<"Enter elements of sorted array: "<<endl;
    for(int i=0;i<lenght;i++){
        cin>>arr[i];
    };
    cout<<"Enter searching value: "<<endl;
    int value;
    cin>>value;

    int left = 0,right = lenght-1;
    bool flag = true;
    while(left<=right){
        int mid = ceil((left+right)/2);
        int midValue = arr[mid];

        if (midValue < value){
            left = mid+1;
        }
        else if(midValue < value){
            right = mid-1;
        }
        else{
            cout<<"Value is found, index is: "<<mid+1;
            flag = false;
            break;
        }
    }
    if(flag){
        cout<<"Value is not found";
    };
}