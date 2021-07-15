#include "1900411101_Task2.h"

Float::operator int() const
{
	int x = (int)value;
	return x;
}
 
void Float::display() const
{
	cout<<value<<endl;
}

Float Float::operator + (Float f1)
{
	return Float(value + f1.value);
}

Float Float:: operator - (Float f1)
{
	return Float(value - f1.value);
}

Float Float:: operator * (Float f1)
{
	return Float(value * f1.value);
}

Float Float:: operator / (Float f1)
{
	if(f1.value == 0) return Float(9.9E+37);
	return Float(value / f1.value);
}

int main(){
    Float f1(2.5),f2(1.5),f3, f0(0.0);
	// f3 = f1+f2;
	// f3 = f1-f2;
	// f3 = f2-f1;
	// f3 = f1*f2;
	// f3 = f1/f2;
	// f3 = f2/f1;
	f3 = f1/f2;

	int k = f3;
	cout<<k<<endl;
	f3.display();
}