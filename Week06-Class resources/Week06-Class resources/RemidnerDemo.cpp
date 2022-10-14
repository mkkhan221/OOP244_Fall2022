#include <string>
#include <iostream>
#include "Reminder.h"
using namespace std;
using namespace sdds;

int main() {
	/*
	char n[] = "Moona";
	//char* n1, *n2;
	

	*/
	// shallow copy is disasterous
	const char* n = "birthday";
	const char* n1= "meeting";
	Reminder r1(n);
	Reminder r2(n1); // calls copy which will call = 
	r1 = r2;
	r2 = "alert";// call overloaded = called. if no operator compiler will call copy constructor 
	//r2 = r1.getReminder();
	cout << r1.title; 
	
	// use debugger and add watch to r1 and r2 to check shallow assignment 
	//when there is no copy constructor and = operator 
	// the run time error generates as compiler calles destructor for both r1 and r2 and 
	// no memory when tries deleting r1.
	// delete comments from copy constructor and operator= function in Reminder.h and .cpp file 
	//to see deep copy work.
}