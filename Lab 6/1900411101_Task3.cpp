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

	char *getnameofAnimal()
	{
		return nameofAnimal;
	}

	int getbirthYear() const
	{
		return birthYear;
	}
	int getcageNumber() const
	{
		return cageNumber;
	}

	float getWeight() const
	{
		return weight;
	}
	int getheight() const
	{
		return height;
	}

	void setName(const char *name)
	{
		strcpy(nameofAnimal, name);
	}
	void setBYear(int byear = 2021)
	{
		birthYear = byear;
	}
	void setCageNumber(int x)
	{
		cageNumber = x;
	}
	void setWeight(int x)
	{
		weight = x;
	}
	void setHeight(int x)
	{
		height = x;
	}

	int getAge()
	{
		return 2021 - birthYear;
	}

	void getInformation()
	{
		printf("Name: %s", nameofAnimal);
		cout << " Birth Year: " << birthYear << " Cage Number:" << cageNumber << " Weight: " << weight << " Height: " << height << endl;
	}

	//lab 6
	bool operator==(int data)
	{
		return ((int)weight == data);
	}

	void operator--(int dec)
	{
		if (dec == 0)
			dec = 1;
		height -= dec;
	}

	~ZooAnimal() {}
};

int main()
{

	ZooAnimal bird;
	bird.setName("Parrot");
	bird.setHeight(10);
	bird.setWeight(1.3);
	bird.setBYear(2018);
	bird.setCageNumber(4);
	bird.getInformation();
	cout << "Age: " << bird.getAge() << endl;

	if (bird == 2)
		cout << "bird weight == 2\n";
	if (bird == 1)
		cout << "bird weight == 1\n";
	int x = 2;
	bird.operator--(x);
	bird.getInformation();
	bird--;
	bird.getInformation();
	return 0;
}