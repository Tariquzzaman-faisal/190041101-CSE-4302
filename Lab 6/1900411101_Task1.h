#include <iostream>
#include<math.h>
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

	float getDistance(const Coordinate &b) const;
	float getDistance() const;

	void move_x(float v);

	void move_y(float v);
	void move(float v);
	Coordinate operator++();

	Coordinate operator++(int);

	Coordinate operator--();
	Coordinate operator--(int);
	bool operator>(Coordinate c);

	bool operator<(Coordinate c);
	bool operator==(Coordinate c);


	bool operator!=(Coordinate c);

	bool operator<=(Coordinate c);

	bool operator>=(Coordinate c);


	void display();
};
