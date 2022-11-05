#pragma once
#include "Animal.h"
namespace sdds {
    class Cat :
        public Animal
         {
        using Animal::Animal; // this means Cat doesn't have its own constructor adn will use base one
    };
}

