#include "1900411101_Task1.h"

float Coordinate::getDistance(const Coordinate &b) const
{
	return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
}
float Coordinate::getDistance() const
{
	return getDistance(Coordinate(0, 0));
}

void Coordinate::move_x(float v)
{
	x += v;
}

void Coordinate::move_y(float v)
{
	y += v;
}
void Coordinate::move(float v)
{
	move_x(v);
	move_y(v);
}
Coordinate Coordinate::operator++()
{
	return Coordinate(++x, ++y);
}

Coordinate Coordinate::operator++(int)
{
	return Coordinate(x++, y++);
}

Coordinate Coordinate::operator--()
{
	return Coordinate(--x, --y);
}

Coordinate Coordinate::operator--(int)
{
	return Coordinate(x--, y--);
}
bool Coordinate::operator>(Coordinate c)
{
	float a = getDistance();
	float b = c.getDistance();
	if(a>b) return true;
	return false;
}

bool Coordinate::operator<(Coordinate c)
{
	if(c>*this) return true;
	return false;
}

bool Coordinate::operator==(Coordinate c)
{
	if(c > *this || c < *this) return false;
	return true;
}


bool Coordinate::operator!=(Coordinate c)
{
	if(c == *this) return false;
	return true;
}

bool Coordinate::operator<=(Coordinate c)
{
	if(c < *this) return false;
	return true;
}

bool Coordinate::operator>=(Coordinate c)
{
	if(c > *this) return false;
	return true;
}


void Coordinate::display()
{
	cout << "(x,y) = "<< "(" << x << "," << y << ")\n";
}

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