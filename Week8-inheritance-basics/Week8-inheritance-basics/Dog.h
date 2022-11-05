#include <iostream>
#include "Animal.h"
namespace sdds {
	class Dog : public Animal
	{
		int* m_size;
	public:
		Dog();
		Dog(const char*, int);
		~Dog();
		std::ostream& display(std::ostream&) const;// will shadow animal display despite different signature
		//using Animal::display ; // to call overload in Animal
		void act();
		void move();
	};
}

