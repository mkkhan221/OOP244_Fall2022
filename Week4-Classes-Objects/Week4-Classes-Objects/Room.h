#ifndef SDDS_ROOM_H
#define SDDS_ROOM_H

namespace sdds {
	class Room
	{
		// DO WE NEED TO PUT PRIVATE EXPLICITLY ?
		double *width;
		double *length;
		double *height;
	//	int roomnumber;

		// DO WE NEED TO PUT PUBLIC EXPLICITLY?
	public:
		// no arg constructor 
		Room();
		Room(double, double, double);
		Room(Room&);

		~Room(); // destructor
		// initializer/setsafeempty function
		
		void init(double, double,double); 

		// freemem/deallocate function
		void deallocate();
		
		// create set (mutator) and query functions
		void setWidth(double);
		void setHeight(double);
		void setLength(double);
		void setRoom(double, double, double);	
		
		double getWidth() const;
		double getHeight() const;
		double getLength() const;
		Room* getRoom();
		void display() const;

		
	};

}
#endif

