#define _CRT_SECURE_NO_WARNINGS
#include "Animal.h"
#include <iostream>

using namespace std;
namespace sdds {
	bool debug = false;
	Animal::Animal()
	{ 
		set("Animal");
		if (debug) {
			cout << "Creating " << m_name << " the Animal" << endl;
			
		}
	}

	Animal::Animal(const char* name) {
		set(name);
		if (debug) {
			cout << "Creating " << m_name << " the Animal" << endl;
			
		}
	}

	void Animal::setSafeEmpty() {
		delete[] m_name;
		m_name = nullptr;
	}
	void Animal::set(const char* name) {
		if (!m_name)
		{
			if (name) {
				m_name = new char[strlen(name) + 1];
				strcpy(m_name, name);
			}
		}
		else
			setSafeEmpty();
	}

	const char* Animal::getName()const {
		char* name = nullptr;
		if (m_name) {
			name = new char[strlen(m_name) + 1];
			strcpy(name, m_name);

		}
		return name;
	}
	Animal::Animal(const Animal& a)
	{
		set(a.getName());
		if (debug) {
			
			cout << "Creating " << m_name << " the Animal" << endl;
			
		}
	}

	Animal:: ~Animal() {
		setSafeEmpty();
		cout << "Animal deallocated" << endl;
	}
	
	void Animal::act() {
		cout << "Animal:" <<m_name <<"can act" << endl;
	}

	void Animal::display() const {
		cout << "Animal " << m_name << endl;
		
	}

	std::ostream& operator << (std::ostream& os, Animal& a) {
		a.display();
		return os;
	}
}