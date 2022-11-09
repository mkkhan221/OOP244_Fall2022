#pragma once
#include "Animal.h"
namespace sdds{
class Parrot :    public Animal
{
public:
    Parrot(const char* name = "Charlie", int s = 3);
    void act();
    void move();
    void sound();
   // void play();
   // void fly();
    ~Parrot();
};
}

