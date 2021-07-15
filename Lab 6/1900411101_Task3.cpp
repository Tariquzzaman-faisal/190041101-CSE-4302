#include "1900411101_Task3.h"

char* ZooAnimal::getnameofAnimal()
{
	return nameofAnimal;
}

int ZooAnimal::getbirthYear() const
{
	return birthYear;
}
int ZooAnimal::getcageNumber() const
{
	return cageNumber;
}

float ZooAnimal::getWeight() const
{
	return weight;
}
int ZooAnimal::getheight() const
{
	return height;
}

void ZooAnimal::setName(const char *name)
{
	strcpy(nameofAnimal, name);
}
void ZooAnimal::setBYear(int byear)
{
	birthYear = byear;
}
void ZooAnimal::setCageNumber(int x)
{
	cageNumber = x;
}
void ZooAnimal::setWeight(int x)
{
	weight = x;
}
void ZooAnimal::setHeight(int x)
{
	height = x;
}

int ZooAnimal::getAge()
{
	return 2021 - birthYear;
}

void ZooAnimal::getInformation()
{
	printf("Name: %s", nameofAnimal);
	cout << " Birth Year: " << birthYear << " Cage Number:" << cageNumber << " Weight: " << weight << " Height: " << height << endl;
}

//lab 6
bool ZooAnimal::operator==(int data)
{
	return ((int)weight == data);
}

void ZooAnimal::operator--(int dec)
{
	if (dec == 0)
		dec = 1;
	height -= dec;
}

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