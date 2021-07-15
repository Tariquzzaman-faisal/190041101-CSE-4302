#include <iostream>

using namespace std;

class Float{
private:
	float value;
public:
	Float(float value = 0.0): value(value){}
	~Float(){} 
	void display() const;
	Float operator + (Float f1);
	Float operator - (Float f1);
	Float operator * (Float f1);
	Float operator / (Float f1);
	operator int() const;
};