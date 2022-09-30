#include "Room.h"
#include <iostream>

using namespace std;

namespace sdds {

	Room::Room(): Room(100, 100, 100) // call another constructor valid in c++14 onwards
	{	

	}
	// another way of initializing datamembers is to use : after constructor header 
	// Room::Room(double width=100, double height=100, double length=100): datamember(value), ...
	Room::Room(double width=100, double height=100, double length=100) {
		this->width = new double;
		this->length = new double;
		this->height = new double;
		init(width, height, length);
		cout << "3 Arg Constructor: Successfull" << endl;
	}
	// copy constructor . more later
	Room::Room(Room& room) {
		this->width = new double;
		length = new double;
		height = new double;
		this->init(*room.width, *room.height, *room.length);
	}
	Room::~Room() {
		delete width;
		delete length;
		delete height;
		cout << "Destructor: successfull" << endl;
	}
	void Room::init(double width, double height, double length) {
		*(*this).width = width;
		*(*this).height = height;
		*(*this).length = length;
		
	}
		
	void Room::setRoom(double w, double h, double b) {

		//if (checkDimensions(w, h, b)) {
			setWidth(w);
			setLength(b);
			setHeight(h);

		//}
	//	else {
	//		init();
	//	}

	}

	void Room::setWidth(double w) {
		*width = w;
	}
	void Room::setHeight(double h) {
		*height = h;
	}
	void Room::setLength(double b) {
		*length = b;
	}
	double Room::getWidth() const {
		return *width;
	}
	double Room::getHeight() const {
		return *height;
	}
	double Room::getLength() const {
		return *length;
	}
	Room* Room::getRoom() {
		
		return this;
	}
	
	void Room::display()const {
		cout << "the breadth of room:" << getLength() << endl;
		cout << "the width of room:" << getWidth() << endl;
		cout << "the Height of room:" << getHeight() << endl;


	}

}