#include <iostream>
#include "Student.h"
using namespace std;
using namespace sdds;
int main() {
	int i{ 1 };
	Student std{ 100 };
	cout << "This is OOP244 class" << endl;
	getID(std);
	display(std);
	cout << "Enter an integer: ";
	cin >> sdds::i;
	cout << endl;
	cout << "The integer is: " << sdds::i << endl;
	return 0;
}