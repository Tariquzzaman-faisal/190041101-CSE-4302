#include<iostream>

using namespace std;

/*Virtual Example*/
class Animal
{
	public:
	virtual void identity(){
		cout<<"I am an animal\n";
	}
	void sleep(){
		cout<<"Sleeping\n";
	}
};

class Dog : public Animal
{
	public:
	void identity(){
		cout<<"I am a dog\n";
	}
};

class Cat : public Animal
{
	public:
	//Virtual function not overridden, will not be valid for pure virtual functions
};
void virtual_function_test();


class colorPen
{
	public:
	virtual void color() = 0; //a color pen must have a specific colo
	void signature(){
		cout<<"Md. Tariquzzaman\n";
	}
};

class matador : public colorPen
{
	public:
	void color(){
		cout<<"Blue\n";
	}
};

class linc : public colorPen
{
	public:
	//no pure virtual function's overriding given
};
void pure_virtual_function_test();


int main(){
	virtual_function_test();
	pure_virtual_function_test();
	return 0;
}

void virtual_function_test(){
	Animal a;// Calls base class methods
	Dog b;
	Cat c;
	a.identity();
	a.sleep();
	b.identity();
	b.sleep();
	c.identity();
	c.sleep();

	Animal *p;
	p = &b; // Calls derived class methods
	p->identity();
	p->sleep();
}

void pure_virtual_function_test(){
	//colorPen a; // not valid as it contains a pure virtual function which is not defined in the base class
	colorPen *a; //valid because its a pointer, it doesnt need to have the definition 
	matador b;
	//linc c; // not valid as pure virtual function has not been overridden
	b.color();
	b.signature();

	a = &b;
	a->color();
	a->signature();
}