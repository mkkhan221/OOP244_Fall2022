#include <iostream>
#include "Student.h"

namespace sdds {

	void getID(Student &s) {
		std::cout << "Enter ID:";
		std::cin >> s.id;
	
	}

	void display(Student s) {
		std::cout << "the Student ID is :" << s.id << std::endl;

	}
}