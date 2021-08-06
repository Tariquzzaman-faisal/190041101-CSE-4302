#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Lab
{
	string labName;
	int capacity;

public:
	Lab(string name = "", int c = 0) : labName(name), capacity(c)
	{
	}
	~Lab()
	{
	}
	string getLabName()
	{
		return labName;
	}
	int getCapacity()
	{
		return capacity;
	}
	void setLabName(string str)
	{
		labName = str;
	}
	void setCapacity(int c)
	{
		capacity = c;
	}
	void show()
	{
		cout << labName << " " << capacity << " capacity" << endl;
	}
};

class LecturerRoom
{
	string roomName;
	int roomNo, capacity;

public:
	LecturerRoom(string name = "", int no = 0, int c = 0) : roomName(name), roomNo(no), capacity(c)
	{
	}
	~LecturerRoom()
	{
	}
	string getRoomName()
	{
		return roomName;
	}
	int getRoomNo()
	{
		return roomNo;
	}
	int getCapacity()
	{
		return capacity;
	}
	void setRoomName(string s)
	{
		roomName = s;
	}
	void setRoomNo(int n)
	{
		roomNo = n;
	}
	void setCapacity(int c)
	{
		capacity = c;
	}
	void show()
	{
		cout << roomName << " " << roomNo << " " << capacity << " capacity\n";
	}
};
class N28_Building
{
private:
	vector<Lab *> labs;
	vector<LecturerRoom *> lecture_rooms;

public:
	N28_Building() {}

	~N28_Building() {}

	void input_lab(Lab &lab)
	{
		labs.push_back(&lab);
	}

	void input_room(LecturerRoom &room)
	{
		lecture_rooms.push_back(&room);
	}

	void showAllLabs()
	{
		cout << "Show all Labs:\n";
		for (auto it : labs)
		{
			cout << "Lab " << it->getLabName() << " " << it->getCapacity() << " Capacity" << endl;
		}
	}

	void showAllLectureRooms()
	{
		cout << "Show all lecturers room: \n";
		for (auto it : lecture_rooms)
		{
			cout << it->getRoomName() << " " << it->getRoomNo() << " " << it->getCapacity() << " Capacity" << endl;
		}
	}
};
