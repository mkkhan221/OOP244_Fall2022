#include "Parrot.h"
#include <iostream>
using namespace std;
namespace sdds {
    Parrot::Parrot(const char* thename, int s) :Animal(thename) {
        if (sdds::debug) cout << "as a Parrot with " << endl;
    }
    void Parrot::act() {
        cout << "Act playful, " << name() << " the Parrot" << endl;
    }
    void Parrot::move() {
        
        cout << "Move like " << name() << " the Parrot" << endl;

    }
    void Parrot::sound() {
        Animal::sound();
        cout << "TukTuk" << endl;
    }
    Parrot::~Parrot() {
        cout << "Removing " << name() << " the Parrot" << endl;
    }
}