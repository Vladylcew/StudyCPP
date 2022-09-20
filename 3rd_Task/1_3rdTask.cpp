#include<iostream>

using namespace std;
//1е неопределенность с float и double при конвертации числа
void f1(float i);
void f1(double i);

//2е неопределенность при конвертации числа в char и unsigned char
void f2(char i);
void f2(unsigned char i);

//3е неопределенность при использовании функций с элементами по умолчанию
void f3(int i,int j = 0);
void f3(int i);


int main(){
    f1(4);
    f2('33');
    f3(5);
}