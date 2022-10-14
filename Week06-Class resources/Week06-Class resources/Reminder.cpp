#define _CRT_SECURE_NO_WARNINGS
#include "Reminder.h"
#include <cstring>

// deep copy vs shallow copy

namespace sdds {

	Reminder::Reminder(const char* t) {
		title = new char[(strlen(t) + 1)];
		if (t) {
			strncpy(this->title, t, (strlen(t) + 1));
			//this->title = t; //example of shallow copy, referencec copied 
		}
		else
			delete[] title;

	}
	// shallow copy causes memory leaks
/*Reminder::Reminder(Reminder& n) {
		*this = n;
	}*/

	Reminder::~Reminder() {
		deAllocSafely();
		
	}

	Reminder* Reminder::getReminder()  {
		//create temp, copy and return temp
		// or return current object 
		/*Reminder* temp = new Reminder("meeting");
		strncpy(temp->title, this->title, (strlen(this->title) + 1));
		return temp;*/
		return this;
	}
	/*Reminder& Reminder::operator= (const Reminder& n) {
		if ( n.title && this != &n) {
			deAllocSafely();
			title = new char[(strlen(n.title) + 1)];
			strncpy(this->title, n.title, (strlen(n.title) + 1));
		}
		return *this;
	}*/

	void Reminder::deAllocSafely() {
		delete[] title;
		title = nullptr;
	}
}