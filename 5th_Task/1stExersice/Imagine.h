#include <iostream>
#include <cmath>
using namespace std;
 

class Imagine 
{
private: 
    float real, 
        imag, 
        angle,
		radius; 
public: 
    void setNum(float Real, float Imag ) 
    {
        real   = Real; 
        imag = Imag;
		radius = sqrt(real*real + imag*imag) ;
    }
    void getNum() 
    {	
    	cout << "Choose the way of representation:\n"<<
    	"1.Normal\n"<<
    	"2.Triganometrical\n"<<
    	"3.Exponential \n";
    	int x;
    	cin>>x;
    	switch(x){
    		case 1:
    			if (imag > 0){
    				cout<<real<<"+i"<<imag;	
				}
				else if(imag < 0){
					cout<<real<<"-i"<<imag;
				}
				else{
					cout<<real;
				}
			break;
			case 2:
				if (real*real + imag*imag == 0){
					cout<<"Can't represent this number";
					break;
				}
				float CosF, TanF;
				CosF = real/radius;
				TanF = imag/real;
				if (CosF > 0){
				
					angle =  atan(TanF);
				}
				else if(CosF<0){
				
					if (atan(TanF) < 0){
						angle = M_PI - atan(TanF);
					}
					else {
						angle = atan(TanF) - M_PI;
					};
				}
				else if (real == 0){
					if (imag > 0){
						angle = M_PI / 2;
					}
					else{
						angle = (-1) * M_PI / 2;
					}
				}
				cout<< radius<<"(cos"<<angle<<"+i*sin"<<angle<<")\n";
			break;
			case 3:
				if (real*real + imag*imag == 0){
					cout<<"Can't represent this number";
					break;
				}
				float CosF, TanF;
				CosF = real/radius;
				TanF = imag/real;
				if (CosF > 0){
				
					angle =  atan(TanF);
				}
				else if(CosF<0){
				
					if (atan(TanF) < 0){
						angle = M_PI - atan(TanF);
					}
					else {
						angle = atan(TanF) - M_PI;
					};
				}
				else if (real == 0){
					if (imag > 0){
						angle = M_PI / 2;
					}
					else{
						angle = (-1) * M_PI / 2;
					}
				}
				cout<<"exp(i*"<<angle<<")\n";
			break;
		}
    };
    
    Image operator +(const Image& obj) {
        imagineryClass temp;
        temp.real = real + obj.real;
        temp.img = img + obj.img;
        return temp;
    }

    Image operator -(const Image& obj) {
        Image temp;
        temp.real = real - obj.real;
        temp.img = img - obj.img;
        return temp;
    }
    Image operator !() {
        Image temp;
        temp.real = real;
        temp.img = -img;
        return temp;
    }
    Image operator *(const Image& obj) {
        Image temp;
        temp.real = real * obj.real - img * obj.img;
        temp.img = real * obj.img + obj.real * img;
        return temp;
    }
}; 
