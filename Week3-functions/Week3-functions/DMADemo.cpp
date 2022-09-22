/*
#include <cstdio>
#include <iostream>
#include <string>

void flushKeys();

using namespace std;

int main() {
	int no=10;
	int a(2); // static memory ,reserved in stack
	int* b = new int(no);
	cout << a << *b << endl;
	delete  b;
	//cout <<*b << endl; // segmentation fault as memory against b is deleted
	b = nullptr; //to not have seg fault at run time

	char* name = new char[31];
	cin >> name; // is space termination point in char?
	cout << name << endl;
	//cin.ignore();
	flushKeys(); // clear the cin buffer , what does cin.clear();?
	cin.getline(name,30);// gets string including spaces , sixe to be provided
	cout << name << endl;
	char* temp = new char[100];
	strcpy(temp, name);
	delete[] name; // deallocate DM and null the pointer and then reallcate Dm
	name = nullptr;
	name = temp;
	temp = nullptr;
	//flushKeys(); cin is tied with a buffer being used so no buffer no flush
	//cin.getline(name, 99);// gets string including spaces , sixe to be provided
	//cout << name << endl;
	return 0;
}
void flushKeys() {
	while (cin.get() != '\n');
}*/