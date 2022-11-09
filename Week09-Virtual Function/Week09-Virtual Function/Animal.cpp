#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Animal.h"
//#include "Animalia.h"
#include<cstring>

namespace sdds {
    bool debug = false;
    Animal::Animal(const char* thename) {
       name(thename);
       
        if (debug) cout << "Creating " << name() << " the Animal of "  << endl;
    }
    Animal::Animal(Animal& a)//: Animalia(a)
    {
        name(a.name());
        if (debug) cout << "Creating " << name() << " the Animal of " << endl;
    }

  /*  //for abstract class Animalia
    Animal::Animal(const char* thename) {
        char species[] = "German Sheperd";
        name(thename);
        setSpecies(species);

        if (debug) cout << "Creating " << name() << " the Animal of " << species << " species" << endl;
    }
    */
    const char* Animal::name()const {
        return m_name;
    }
    void Animal::name(const char* value) {
        strcpy(m_name, value); //assume value validated for right length for copy
    }
    void Animal::act() {
        cout << "Act like " << name() << " the animal" << endl;
    }
    void Animal::move() {
        cout << "Move like " << name() << " the  animal" << endl;
    }
    void Animal::sound() {
        cout << "Sound like " << name() << " the  animal" << endl;
    }
    Animal& Animal::operator=(Animal& a) {
        name(a.m_name);
        cout << "Animal operator in action" << endl;
        return *this;
    }
   
    Animal::~Animal() {
        if (debug) cout << "Removing " << m_name << " the animal" << endl;
    }
}