#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Coordinate
{
	double x, y;

public:
	Coordinate(double _x = 0, double _y = 0) : x(_x), y(_y) 
	{

	}
	~Coordinate() 
	{

	}

	float getDistance(const Coordinate &b) const
	{
		return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
	}
	float getDistance() const
	{
		return getDistance(Coordinate(0, 0));
	}

	void move_x(float v)
	{
		x += v;
	}

	void move_y(float v)
	{
		y += v;
	}
	void move(float v)
	{
		move_x(v);
		move_y(v);
	}
	Coordinate operator++()
	{
		return Coordinate(++x, ++y);
	}

	Coordinate operator++(int)
	{
		return Coordinate(x++, y++);
	}

	Coordinate operator--()
	{
		return Coordinate(--x, --y);
	}

	Coordinate operator--(int)
	{
		return Coordinate(x--, y--);
	}
	bool operator>(Coordinate c)
	{
		float a = getDistance();
		float b = c.getDistance();
		if(a>b) return true;
		return false;
	}

	bool operator<(Coordinate c)
	{
		if(c>*this) return true;
		return false;
	}

	bool operator==(Coordinate c)
	{
		if(c > *this || c < *this) return false;
		return true;
	}


	bool operator!=(Coordinate c)
	{
		if(c == *this) return false;
		return true;
	}

	bool operator<=(Coordinate c)
	{
		if(c < *this) return false;
		return true;
	}

	bool operator>=(Coordinate c)
	{
		if(c > *this) return false;
		return true;
	}


	void display()
	{
		cout << "(x,y) = "<< "(" << x << "," << y << ")\n";
	}
};

int main()
{
	// Coordinate a(1,2), b(1, 2);
	// Coordinate a(1,1), b(1, 2);
	Coordinate a(1,2), b(1, 1);
	if(a > b) cout<<"A greater B\n";
	if(a < b) cout<<"A less than B\n";
	if(a <= b) cout<<"A <= B\n";
	if(a >= b) cout<<"A >= B\n";
	if(a == b) cout <<"A == B\n";
	if(a != b) cout<<"A != B\n";
	
	return 0;
}