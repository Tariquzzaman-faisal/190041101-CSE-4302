#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

class ZooAnimal
{
private:
	char nameofAnimal[40];
	int birthYear;
	int cageNumber;
	float weight;
	int height;

public:
	ZooAnimal(int b = 2021, int c = 0, float w = 0.0, int h = 0) : birthYear(b), cageNumber(c), weight(w), height(h)
	{
		strcpy(nameofAnimal, "");
	}

	char *getnameofAnimal();

	int getbirthYear() const;
	int getcageNumber() const;

	float getWeight() const;
	int getheight() const;

	void setName(const char *name);
	void setBYear(int byear = 2021);
	void setCageNumber(int x);
	void setWeight(int x);
	void setHeight(int x);

	int getAge();

	void getInformation();

	//lab 6
	bool operator==(int data);

	void operator--(int dec);

	~ZooAnimal() {}
};