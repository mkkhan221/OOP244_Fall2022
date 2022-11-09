#pragma once
namespace sdds {
	// abstract class becuase it has pure virtual function.
	class Animalia
	{
		char species[31];
	public:
		Animalia();
		Animalia(Animalia& an);
		virtual void act() = 0;
		virtual void sound() = 0;// pure virtual function . it will not have implementation in the class
		virtual void move() = 0;
		void getSpecies(char*);
		void setSpecies(const char*);
		virtual ~Animalia() = default;
	};
}

