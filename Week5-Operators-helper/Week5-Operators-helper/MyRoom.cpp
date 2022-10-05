#include <iostream>
//#include "Building.h"
#include "Room.h"
//#include "Common.h"

using namespace std;
using namespace sdds;
const int MAX_ROOM = 10;
int main() {
	Room myRoom, yourRoom{ 11,12,13 }; 
	Room roomforrent(yourRoom);  //copy constructor
	Room room2;
	
	room2= (Room)3; // type cast calls constructor one arg.
	room2.display();
	
	++yourRoom; // increment 10 to each data member
	yourRoom.display();
	
	myRoom = yourRoom--; // post fix decrement
	
	cout << yourRoom << endl;
	
	myRoom.display();// you can call << operator 
	// check + operator
	Room room3;
	room3= myRoom + yourRoom; // 

	cout << room3;

	// checking < and > operators
	myRoom.setRoom(212, 212, 212);
	yourRoom.setRoom(22, 22, 22);
	
	if (myRoom > yourRoom) {
		// calling << overloaded operator when argument is Room
		cout <<myRoom<< " is bigger than " <<yourRoom<< endl;
	}
	else if (myRoom < yourRoom)
		cout << "not true" << endl;
	
// check bool typecast
	if (room2) {
		cout << "My Room is as per standard dimensions" << endl;
	}
	else {
		cout << "My Room is no per standard dimensions" << endl;
	}
	
	
	//  checking << and >> operator
	Room r2;
	cin >> r2;
	cout << r2;
	return 0;
}
