#include<bits/stdc++.h>
using namespace std;

class Employee
{
	protected:
	string name, dob, id, ssn, doj;
	int basic, travel, family, housing;
	public:
	Employee()
	{

	}
	virtual void getter() = 0;
	virtual void setter() = 0;

};

class Manager : public Employee
{
	public:
	void setter(){
		cout<<"Name: ";
		cin >> name;
		//others
		cout<<"Basic: ";
		cin >> basic;
		cout<<"Travel :";
		cin >> travel;
		cout<<"Family: ";
		cin >> family;
		cout<<"Housing: ";
		cin >> housing;
	}
	void getter()
	{
		cout<<"Eat my shit Manager "<<name<<"\n";
	}
};
class Intern : public Employee
{
	void setter(){
		cout<<"Name: ";
		cin >> name;
		//others
		cout<<"Basic: ";
		cin >> basic;
		cout<<"Travel :";
		cin >> travel;
	}
	void getter()
	{
		cout<<"Eat my shit Intern "<<name<<"\n";
	}
};
class Worker : public Employee
{
	void setter(){
		cout<<"Name: ";
		cin >> name;
		//others
		cout<<"Basic: ";
		cin >> basic;
		cout<<"Family: ";
		cin >> family;
		cout<<"Housing: ";
		cin >> housing;
	}
	void getter()
	{
		cout<<"Eat my shit Worker "<<name<<"\n";
	}
};

int main()
{
	Employee *E;
	E = new Worker();
	E->setter();
	E->getter();
	E = new Manager();
	E->setter();
	E->getter();
	E = new Intern();
	E->getter();
	E->setter();
}