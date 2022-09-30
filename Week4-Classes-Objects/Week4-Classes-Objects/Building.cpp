#include "Building.h"
#include <iostream>
#include "Room.h"
using namespace std;
namespace sdds {
	Building::Building() {
		firstfloorrooms = new Room[MAX_NUMBER];
		occupiedcount = 0;
	}
	Building::~Building() {
		delete[] firstfloorrooms;
	}

	void Building::display() const {
		for (int i = 0; i < MAX_NUMBER; i++) {
			firstfloorrooms[i].display();
		}
		cout << "Rooms Occupied: " << occupiedcount << endl;
		cout << "Rooms vacant: " << MAX_NUMBER - occupiedcount << endl;

	}
	Room* Building::rentRoom() {
		Room* temproom;
		if (occupiedcount < MAX_NUMBER) {
			temproom = &firstfloorrooms[occupiedcount];
			occupiedcount += 1;
		}
		else
			temproom = nullptr;
		return temproom;
	}


}

using namespace sdds;

int main() 
	{
	
	Room r1(400,400,400);
	Room rooms[4]{ {100,200,300},{100,200,300},{100,200,300},{100,200,300} };
	
	Room* anothersetrooms = new Room[4]();
	Room r2(r1.getWidth(), r1.getHeight(), r1.getLength());
	Room r3(r1);
	//Room* r2 = &r1;
	r1.display();
		for (int i = 0; i < 4; i++) {
			rooms[i].display();
		}
		delete [] anothersetrooms;

		Building b1;
		b1.display();
		Room* rentroom = b1.rentRoom();
		if (rentroom == nullptr)
			cout << "Room not available" << endl;
		else
			cout << "Room rented" << endl;
		b1.display();
	} 