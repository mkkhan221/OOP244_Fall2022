#include <iostream>
#include "Room.h"
using namespace std;
namespace sdds {
	// create no argument constructor 
		// use of *this , explicit call
	Room::Room() {
		init();
		cout << "calling no arg constructor" << endl;
	}
	Room::Room(double w, double h, double b) {
		cout << "calling 3 arg constructor" << endl;
		setRoom(w, h, b);
	}

	Room::Room(Room& r) {
		cout << "calling copy constructor" << endl;
		//*this = r; 
		copy(r);
	}


	Room::Room(int no) {
		cout << "calling one arg constructor" << endl;
		setRoom(no, no, no);
	}

	void Room::init() {
		width = 10;
		height = 10;
		length = 10;
	}

	void Room::setRoom(double w, double h, double b) {

		if (checkDimensions(w, h, b)) {
			setWidth(w);
			setLength(b);
			setHeight(h);

		}
		else {
			init();
		}

	}

	void Room::setWidth(double w) {
		width = w;
	}
	void Room::setHeight(double h) {
		height = h;
	}
	void Room::setLength(double b) {
		length = b;
	}
	double Room::getWidth() const {
		return width;
	}
	double Room::getHeight() const {
		return height;
	}
	double Room::getLength() const {
		return length;
	}
	bool Room::checkDimensions(double w, double h, double b) const {
		bool check = false;
		if ((w > MIN_dimension) && (h > MIN_dimension) && (b > MIN_dimension)) {
			check = true;
		}
		return check;
	}

	void Room::copy(Room& r) {

		this->setLength(r.getLength());
		this->setWidth(r.getWidth());
		this->setHeight(r.getHeight());
	}

	void Room::display()const {
		cout << "the breadth of room:" << getLength() << endl;
		cout << "the width of room:" << getWidth() << endl;
		cout << "the Height of room:" << getHeight() << endl;

	}

	double Room::calculateArea() const {
		return length * width;
	}

	Room& Room::operator --() {
		width -= 10;
		length -= 10;
		height -= 10;
		return *this; // returns current object ref
	}
	Room Room::operator --(int no) {
		Room temp = *this; // saves current object state. automatically calls copy constructor since = is not overloaded
		this->width -= 10;
		this->length -= 10;
		this->height -= 10;
		temp.display();
		return temp; // returns the new room object before current object decremented
	}

	// pre fix operator overload
	Room& Room::operator++() {
		width += 10;
		length += 10;
		height += 10;
		return *this;
	}
	// post-fx operator overloaded

	Room Room::operator++(int increment) {
		Room temp;
		temp = *this;
		cout << temp << endl;
		++(*this);
		cout << *this << endl;
		return temp; // returns copy of the current object before increment

	}
	// binary operator overloaded
	bool Room::operator<(Room r) const {
		return this->calculateArea() < r.calculateArea();

	}

	bool Room:: operator > (Room r) const {
		return this->calculateArea() > r.calculateArea();
	}

	// binary operator += overloaded
	Room& Room::operator+=(const Room& room) {
		this->setHeight(this->height + room.height);
		this->setLength(this->length + room.length);
		this->setWidth(this->width + room.width);
		return *this;
	}
	Room Room::operator+(const Room& room) {
		Room temp;
		if (room) {
			temp.width = this->width + room.width;
			temp.length = this->length + room.length;
			temp.height = this->height + room.height;
		}
		else
			temp.init();
		return temp;
		
	}
	Room::operator bool() const {
		return this->checkDimensions(this->width, this->height, this->length);
	}

	
	// friend operator using private members. To be just helper operator, use getters 
	ostream& operator<< (ostream& stream, const Room& room) {
		stream << "Room(" << room.width << "," << room.length << "," << room.height << ")";
		return stream;
	}

	std::istream& operator>>(std::istream& cinstream, Room& room) {
		cout << "Enter data: ";
		double h, l, w;
		cinstream >> l;
		room.setLength(l);
		cinstream >> w;
		room.setWidth(w);
		cinstream >> h;
		room.setHeight(h);

		return cinstream;
	}
	
	// helper 
	void display(Room* rooms, int size) {
		for (int i = 0; i < size; i++) {
			cout << rooms[i] << endl;
		}
	}


}