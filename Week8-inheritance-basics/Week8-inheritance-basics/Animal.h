#ifndef SDDS_QUERY_H
#define SDDS_QUERY_H
#include <iostream>

namespace sdds {

	class Animal
	{
	protected:
		
		char* m_name;

	public:
		Animal();
		Animal(const char* name);
		Animal(const Animal&);
		~Animal();
		void setSafeEmpty();
		const char* getName() const;
		void set(const char*);
		
		std::istream& read(std::istream&);
		void act();
		void move();

		Animal& operator=(Animal&);
		void display() const;
	
	};
	extern bool debug;
	std::ostream& operator << (std::ostream& os, Animal&); // helper operator of animal
}
#endif

