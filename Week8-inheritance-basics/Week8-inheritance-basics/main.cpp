#include <iostream>
using namespace std;
#include "Dog.h"
#include "Cat.h"

#include "Animal.h"

using namespace sdds;
// this example is to check polymorphic behavior without virtual and with virtual Animal class functions and destructor
int main() {
	sdds::debug = true;

		
	//	Dog* c = new Dog("Fido", 4); // by ptr using DMA
		Animal a;
		
		// animal object call 
		cout << "Animal Object" << endl;
		
		a.act();
		cout << a << endl; // helper call
		cout << "____________________" << endl;
		cout << "Animal reference" << endl;
		// Animal reference call
		Animal& anim = a;
		anim.act();
		cout << anim << endl;
		cout << "____________________" << endl;
		cout << "Animal DMA" << endl;
		Animal* animptr = new Animal("pet animal");
		// Animal DMA call
		animptr->act();
		cout << *animptr << endl;
		cout << "____________________" << endl;
		
		cout << "Dog static object" << endl;
		Dog p; 
		//Dog call
		p.act();
		p.display(cout);
		cout << p << endl; // p accepted but excutes animal display 
		cout << "____________________" << endl;

		cout << "Cat static object" << endl;
		Cat c("Cat"), cat; // will use animal constructors 
		c.act();
		c.display();
		cout << "____________________" << endl;
		cat.act();
		cat.display();
		cout << "____________________" << endl;
		return 0;
	}