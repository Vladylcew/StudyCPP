#include<iostream>
#include<vector>

using namespace std;

int main(){
    int length;
    cout<<"Enter number of elements: "<<endl;
    cin>>length;
    cout<<"Enter array: "<<endl;
    vector <int> SuitableName(length);
    for(int i = 0; i<length;i++){
        cin>>SuitableName[i];
    };

    for (int j = 2; j < length; j++){
        int key = SuitableName[j];
        int i = j - 1;
        while ( i >= 0 && SuitableName[i] > key){
            swap(SuitableName[i+1],SuitableName[i]);
        i--;
        };
            SuitableName[i + 1] = key;
    };
    cout<<"Sorted array: "<<endl;
    for(int i = 0; i<length;i++){
        cout<<SuitableName[i]<<" ";
    };
}