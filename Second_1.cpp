#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;
    float value;
    cout << "Please choose what do you want to convert. Type one of the following numbers:" << endl;
    cout << "1. Charge in Coulomb to charge in CGSE unit of charge." << endl;
    cout << "2. Force in Newton to force in dynes." << endl;
    cout << "3. Magnetic field strength in Oersteds to Amps per meter" << endl;
    cin >> num;
    cout << "Please enter your value" << endl;
    cin >> value;
    switch (num) {
        default:
            cout << "Chose on of this numbers.";
            break;

        case 1:
            cout << value * 2997924580;
            break;
        case 2:
            cout << value * 0.00001;
            break;
        case 3:
            cout << value * 1000/(4*M_PI);
            break;

    }
}