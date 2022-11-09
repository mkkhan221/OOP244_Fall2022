#include <iostream>
using namespace std;
#include "Dog.h"
#include "Parrot.h"
#include "Animalia.h"
#include "Animal.h"

using namespace sdds;
// this example is to check polymorphic behavior without virtual and with virtual Animal class functions and destructor
int main() {
	sdds::debug = true;

/*	Dog p("Tom"); // by ref
	Dog* c = new Dog("Fido"); // by ptr using DMA

	// animal pointer and reference
	Animal* ap = new Dog("Blue"); // base class allows child instance 
	Animal* aptr2 = c;
	Animal& ar = p;
	
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
	cout << "------------Using Animal reference: " << endl;
	//static binding will force the varibale declaration type function to be called 
	
	ar.act();  // Animal class functions will be called through static binding which means at compile act function name will be binded with ar Animal type
	ar.move();// 
	ar.sound();
	//ar.play() //will not work as ar type is Animal though instance referred to is Dog but base cannot see Dog specialized content
	// shadowing will not occur for member functions which are overridden

	((Dog&)ar).play(); // by casting ar to Dog ref Dog specialized members can be called

	
	cout << "------------Using Animal pointer: " << endl;
	ap->act(); //Animal class act function will be called 
	ap->move();
	ap->sound();
	((Dog*)ap)->play();
	cout << "------------Using operator overload + polymorphic behaviour " << endl;
	*/
	Dog carno, heb("Fido");
	// in operator overload and overide the argument type is important. 
	//passing Dog type doesn't match with Animal op overriding so regardless of being virtual
	//compiler cannot associate op in dog with Animal ref and calls Animal op
	Animal& ar=carno;
	((Dog&)ar) = heb;// use this with Dog type ref in operator parameter. even dog is assigned
	carno = heb;
			   /*
	cout << "------------Deleting a Dog pointed by a Dog ptr" << endl;
	delete c; //since DMA , delete child object . this calls chidl destructor and parent constructor 
	cout << "------------Deleting a cDog pointed by an animal ptr" << endl;
	delete ap; // ap is Animal type with Dog object . the destructor of Animal will be called as ap cannot access specialized member of Dog
	cout << "Dog part is not deleted and is a leak!" << endl;
	cout << "------------End of main" << endl;
	*/
	return 0;
}
/*
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