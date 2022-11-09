#define _CRT_SECURE_NO_WARNINGS
#include "Animalia.h"
#include <iostream>
#include <cstring>
namespace sdds {
	Animalia::Animalia() {
		strcpy(species, "new");
		std::cout << "Creating the Animalia Kingdon" << std::endl;
	}
	Animalia::Animalia(Animalia& an) {
		strcpy(species, an.species);
		std::cout << "Creating the Animalia Kingdon" << std::endl;
	}
	void Animalia::getSpecies(char* s) {
		strcpy(s, species); // Assume s is validated
	}
	void Animalia::setSpecies(const char* s) {
		strcpy(species, s);
	}
}