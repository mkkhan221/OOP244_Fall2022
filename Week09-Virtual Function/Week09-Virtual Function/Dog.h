#pragma once
#include "Animal.h"
namespace sdds {
    class Dog : public Animal {
        int size;
        
    public:
        Dog(const char* name = "Charlie",int s = 3);
        Dog(Dog&);
        void act();
        void move();
        void sound();
        void play();
        // to make operator overide Animal, type needs to be Animal in argument
        // by having Dog& in parameter, it will be consider Dog own function and not overide
        //Dog& operator=(Animal& d);
        Dog& operator=(Dog& d);// try with this and without typecast 
        ~Dog();
    };
}

