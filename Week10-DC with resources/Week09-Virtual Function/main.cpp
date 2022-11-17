#include <iostream>
using namespace std;
#include "Dog.h"
#include "Parrot.h"
#include "Animalia.h"
#include "Animal.h"
#include "ServiceDog.h"

using namespace sdds;
// this example is to check polymorphic behavior without virtual and with virtual Animal class functions and destructor
int main() {
	sdds::debug = true;
	//Animalia* animaliaptr[3] = {new Dog("Sumo")};
	
	Dog p("Tom"); // by ref
	Dog* c = new Dog("Fido"); // by ptr using DMA

	// animal pointer and reference
	Animal* ap = new Dog("Blue"); // base class allows child instance 
	Animal* aptr2 = c; // simple ref assignment
	Animal& ar = p; // simple ref assignment
	//Animal a;
	cout << "------------Using Dog ref: " << endl;
	p.act(); //  dog class act function will be called . it will shadow Animal class act function
	p.move();
	p.sound();
	p.play();  // dog specific function , there is no shadowing involved 
	cout << "------------Using Dog pointer: " << endl;
	c->act(); //  dog class act function will be called . 
	c->move();
	c->sound();
	c->play();  // dog specific function , there is no shadowing involved 
	cout <<endl << "------------Using Animal reference: " << endl;
	// dynamic binding
	ar.move();
	ar.act();
	ar.sound();
	//ar.play() //will not work as ar type is Animal though instance referred to is Dog but base cannot see Dog specialized content
	// shadowing will not occur for member functions which are overridden

	((Dog&)ar).play(); // by casting ar to Dog ref Dog specialized members can be called

	
	cout <<endl << "------------Using Animal pointer: " << endl;
	ap->act(); 
	ap->move();
	ap->sound();
	((Dog*)ap)->play();

	cout <<endl<< "------------Using operator overload + polymorphic behaviour " << endl;
	
	Dog carno, heb("Fido");
	
	//The compiler distinguishes the call to the base class operator from a call to the derived class operator by the type of the left operand. 
	// comment operator part from dog class and observe result. you will find close enough operator available is of animal
	Animal& ar1=carno; //simple ref iinitializing Animal ref type variable to object aaddress. don't confuse with assignment 
	// ar1 now refer to an object and dog = operator will be called to deep copy
	((Dog&)ar1) = heb;// use this with Dog type ref in operator parameter. Dog operator called
	
	carno = heb; // dog operator is called
	
	Dog pet;
	ServiceDog sd;
	pet = sd; // Dog operator will be called as left side operand is Dog and tright side is type of dog 
	
	pet.move();
	((ServiceDog&)pet).skillset();// type cast to ServiceDog can then access ServiceDog members
			  
	cout << "------------Deleting a Dog pointed by a Dog ptr" << endl;
	delete c; //since DMA , delete child object . this calls chidl destructor and parent constructor 
	cout << "------------Deleting a cDog pointed by an animal ptr" << endl;
	delete ap; // ap is Animal type with Dog object . the destructor of Animal will be called as ap cannot access specialized member of Dog
	cout << "Dog part is not deleted and is a leak!" << endl;
	cout << "------------End of main" << endl;
	

	
	return 0;
}
/*
* // uncomment and run this portion 
using namespace sdds;
int main() {
	sdds::debug = true;

	// Array of abstract class pointers having chilc class objects
	Animalia* ptr[3] = { new Dog("Fido"),new Parrot("Charlie"), new Parrot("JoJo")};

	for (int i = 0; i < 3; i++) {
		ptr[i]->move();
		ptr[i]->act();
		ptr[i]->sound();
	}
	for (int i = 0; i < 3; delete ptr[i++]);

	// Working with Animalia abstract class ref and ptr
	Dog p("Tom");
	Dog* c = new Dog("Fido");

	//Animalia anim; // cannot initiate abstract class since one of the method is pure virtual or abstract
	Animalia* aniptr= new Dog("Zen",5);
	Animalia& aniref=p;
	
	aniptr->move();
	aniptr->sound();


	
	delete aniptr;
	
	aniptr = new Parrot("Charlie");
	aniptr->move();
	aniptr->sound();

	//delete c;
	delete aniptr;
	
	return 0;
}
*/