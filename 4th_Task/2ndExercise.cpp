#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

struct DayTime
{
	unsigned int hours : 5;
	unsigned int minutes : 6;
	unsigned int seconds : 6;	 
	unsigned int number : 5;  
	unsigned int month : 4;   
	unsigned int year : 12;   
};

void Input(DayTime &dt){
	unsigned int y,mo,n,h,mi,s;
	cout << "Write year:\n";
	cin >> y;
	cout << "Write month(number):\n";
	cin >> mo;
	cout << "Write number:\n";
	cin >> n;
	cout << "Write hour:\n";
	cin >> h;
	cout << "Write minute:\n";
	cin >> mi;
	cout << "Write second:\n";
	cin >> s;
	dt.hours = h;
	dt.minutes = mi;
	dt.month = mo;
	dt.number = n;
	dt.seconds = s;
	dt.year = y;	
}

void Output(DayTime dt){
	cout << setw(2)<<setfill('0')<<dt.number<<"."<<setw(2)<<setfill('0')<<dt.month<<"."<<dt.year<<"\n";
	cout << setw(2)<<setfill('0')<<dt.hours<<":"<<setw(2)<<setfill('0')<<dt.minutes<<":"<<setw(2)<<setfill('0')<<dt.seconds<<"\n";
}

int main(){
	DayTime dt;
	Input(dt);
	Output(dt);
}
