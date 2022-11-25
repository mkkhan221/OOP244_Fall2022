#ifndef SDDS_ROOM_H
#define SDDS_ROOM_H
namespace sdds {
	const double MIN_dimension = 10;
	class Room
	{
		// does private modifier required?
		double  width, height, breadth;
		bool checkDimensions(double, double, double);
	public:
		Room(); // safe empty state
		// create no argument constructor 
			// create argument constructor 
		Room(double w, double h, double b);
		//create constructor with room reference using &
		Room(Room& r);
		void init(); // for safe empty , called anywhere 

		// create set and get functions
		void setWidth(double);
		void setHeight(double);
		void setBreadth(double);
		void setRoom(double, double, double);	// create setRoom to return room ref

		double getWidth() const;
		double getHeight() const;
		double getBreadth() const;
		void copy(Room&);
		//double calculateArea();
		void display() const;
		Room operator+(Room);
		//void deallocate();
		// create safe empty and deallocate function to be called in constructor though better way would be to call argument constructor 
		//~Room(); // deconstructor
		// create calculateArea 
		// create display
	};
}
#endif
/*
struct Room{


};
*/