#include <iostream>
using namespace std;
#include "Dog.h"
namespace sdds {
    Dog::Dog(const char* thename, int s) :Animal(thename), size(s) {
       char species[31]{0};
     //  setSpecies("Dog"); // remove comments when add Animalia to hierarchy by extending Animal class
      //  getSpecies(species);
        if (sdds::debug) cout << "as a "<< species <<" with" << size << " height" << endl;
    }
    Dog::Dog(Dog& d) :Animal(d) {

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
   /* void Dog::sound(int a) {

    }*/
    void Dog::play() {
        cout << name() << " the Dog is playing!" << endl;
    }
  /*
    Dog& Dog::operator=(Animal& d) {
        name(d.name());
     // note change in otehr version. size is dog member, animal directly cannot access
     //and hence typecast required
        size = ((Dog&)d).size; 
        cout << "Dog operator in action" << endl;
        return *this;
    }
    */
    // try passing dog type argument 
    Dog& Dog::operator=(Dog& d) {
       // name(d.name());
        size = d.size; // note change from other version 
       (Animal&)*this = d;
        cout << "Dog operator in action" << endl;
        return *this;
    }
   
    Dog::~Dog() {
        if (sdds::debug) cout << "Removing " << name() << " the Dog" << endl;
    }

}