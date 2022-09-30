#ifndef SDDS_BUILDING_H
#define SDDS_BUILDING_H

#include "Room.h"

namespace sdds {
	const int MAX_NUMBER = 3;
	class Building
	{
		Room* firstfloorrooms;
		int occupiedcount;

	public:
		Building();
		~Building();
		void display() const;
		Room* rentRoom();
		void vacateRoom();
	};
}
#endif

