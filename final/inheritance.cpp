#include<bits/stdc++.h>
using namespace std;

class baseClass
{
	private:
	int x = 1;
	protected:
	int y = 2;
	public:
	int z = 3;
};

class derived : private baseClass
{
	public:
	void get(){
		cout<<y<<endl;
	}
};

int main(){
	derived p;
	p.get();
	p.z = 4;
}