#include <iostream>
 
using namespace std;

 
class Price 
{
private:
	double sum;
	static int percent;
public:
    Price(double sum)
    {
        this->sum = sum;
    }
    static int getPercent()
    {
        return percent;
    }
    static void setPercent(int r)
    {
        percent = r;
    }
    double getIncome()
    {
        return sum - sum * percent / 100;
    }
};
int Price::percent = 8;
int main()
{
    Price item1(20000);
    Price item2(50000);
    Price::setPercent(5);
cout << "Percent: " << Price::getPercent() << endl;
cout << "Percent: " << item1.getPercent() << " Final price: " << item1.getIncome() << endl;
cout << "Percent: " << item2.getPercent() << " Final price: " << item2.getIncome() << endl;
	Price::setPercent(20);
cout << "Percent: " << Price::getPercent() << endl;
cout << "Percent: " << item1.getPercent() << " Final price: " << item1.getIncome() << endl;
cout << "Percent: " << item2.getPercent() << " Final price: " << item2.getIncome() << endl;
    return 0;
}
