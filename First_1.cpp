#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    string name;
    int price;
    string  back;
    int maxTemp;
    cout << "Product's name: "<< endl;
    cin >> name;
    cout << "Product's price Is cash: "<< endl;
    cin >> price;
    cout << "Is cash-back available for this product ? (true/false): "<<endl;
    cin >> back;
    cout << "Maximum storing temperature: " << endl;
    cin >> maxTemp;

    string maxTempStr = to_string(maxTemp);
    if (maxTemp > 0) {
        maxTempStr = "+" + maxTempStr;
    }

    stringstream priceHex;
    priceHex << hex << price;
    string priceStr(priceHex.str());
    transform(priceStr.begin(), priceStr.end(), priceStr.begin(), ::toupper);
    string zeros = "";
    for (int i = 0; i < 8 - priceStr.length(); i++){
        zeros += "0";}
    priceStr = zeros + priceStr;

    cout << name << "\n";
    cout << "Price:" << setfill('.') << setw(20) << priceStr << endl;
    cout << "Has cash-back:" << setfill('.') << setw(12) << back << endl;
    cout << "Max temperature:" << setfill('.') << setw(10)<< maxTempStr << endl;
}