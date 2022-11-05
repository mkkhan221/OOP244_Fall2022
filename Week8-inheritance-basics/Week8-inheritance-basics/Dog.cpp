#include "Dog.h"
using namespace std;
namespace sdds {
	Dog::Dog(): Animal("Dog") // call Animal constructor explicitly. not calling will call no arg constructor
	{
		m_size = new int();
		*m_size = 2;
		cout << "Dog: " << *m_size << endl;
		
			
	}
	Dog::Dog(const char* name, int size): Animal(name) // explicit call to one arg constructor 
		//base constructors are always called before child but you can explicitly call overload constructor
	{
		m_size = new int();
		*m_size = size;
		cout << "Dog: " << *m_size << endl;
	}
	Dog::~Dog() {
		delete m_size;
		cout << "Dog Deallocated" << endl;
	}
	ostream& Dog::display(ostream& out) const {
		Animal::display();
		out << "size" << *m_size<<endl;
		return out;
	}
	void Dog::act() {
		
		cout << "Dog jumped " << endl;
	}
}