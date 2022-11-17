#include <iostream>
using namespace std;
#include "Dog.h"
namespace sdds {
    Dog::Dog(const char* thename, int s) :Animal(thename), size(s) {
       
     
        if (sdds::debug) cout  <<" with" << size << " height" << endl;
    }
    Dog::Dog(Dog& d) :Animal(d), size(d.size) {
        
        cout << "Dog copy construcotr called" <<endl;
        if (sdds::debug) cout << " with" << size << " height" << endl;
    }
    void Dog::act() {
        cout << "Act playful, " << name() << " the Dog" << endl;
    }
    void Dog::move() {
        cout << "Move like " << name() << " the Dog" << endl;
    }
    void Dog::sound() {
        Animal::sound();
        cout << "Wuff!" << endl;
    }
   
    void Dog::play() {
        cout << name() << " the Dog is playing!" << endl;
    }
   //if you remove this comment , and check the output 
   /*
    Dog& Dog::operator=(Animal& d) {
        name(d.name());
        // note change in other version. size is dog member, animal directly cannot access
        //and hence typecast required
        size = ((Dog&)d).size;
        cout << "Dog operator in action" << endl;
        return *this;
    }
    */
    
    // try passing dog type argument . Passing by Reference
   /*  Notice that the argument to operator=() is passed by reference.It is not absolutely necessary
        to do this, but it’s usually a good idea so as to avoid calling copy constructor to create anonymous object for slef copying
      .If such objects are large, the copies can waste a lot of  memory.Values passed by reference don’t generate copies, and thus help to conserve memory
      same with return type*/
    Dog& Dog::operator=(Dog& d) {
       // name(d.name());
        size = d.size; // note change from other version 
       (Animal&)*this = d; 
       // The assignment operator is unique among operators in that it is not inherited. If you overload
      // the assignment operator in a base class, you can’t use this same function in any derived classes. hence you call it 

        cout << "Dog operator in action" << endl;
        return *this;
    }
    
   
    Dog::~Dog() {
        if (sdds::debug) cout << "Removing " << name() << " the Dog" << endl;
    }

}