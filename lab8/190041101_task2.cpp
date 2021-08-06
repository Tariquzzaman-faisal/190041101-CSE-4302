#include "task2.hpp"

int main()
{
	N28_Building n28;
	Lab lab1("MPK1", 60), lab2("MPK2", 60), lab3("MPK3", 50), lab4("MPK4", 50);
	n28.input_lab(lab1);
	n28.input_lab(lab2);
	n28.input_lab(lab3);
	n28.input_lab(lab4);

	LecturerRoom r1("Hafiz", 102, 3), r2("Shafie", 105, 3), r3("Aisha", 202, 3), r4("Rahim", 208, 3);
	n28.input_room(r1);
	n28.input_room(r2);
	n28.input_room(r3);
	n28.input_room(r4);

	cout << "Welcome to N28 Building\n";
	n28.showAllLabs();
	n28.showAllLectureRooms();
}