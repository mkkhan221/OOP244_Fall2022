#ifndef SDDS_ROOM_H
#define SDDS_ROOM_H
#include <ostream>
#include <istream>
namespace sdds {
	
	const double MIN_dimension = 10;
	class Room
	{
		// does private modifier required?
		double  width, height, length;
		bool checkDimensions(double, double, double) const;
	public:
		// safe empty state
		// create no argument constructor 
		Room(); 
		
		// create argument constructor 
		Room(double w, double h, double b);
		
		//create constructor with room reference using &
		Room(Room& r);
		
		// Type casting constructor and overloaded operator 
		explicit Room(int no);

		void init(); // for safe empty , called anywhere 
			
		// create set and get functions
		void setWidth(double);
		void setHeight(double);
		void setLength(double);
		void setRoom(double, double, double);	// create setRoom to return room ref
		

		double getWidth() const;
		double getHeight() const;
		double getLength() const;
		double calculateArea() const;
		// copy function to copy argument room type data to current object
		void copy(Room&);
		void display() const;
		
		
		//Room(double no);
		
		Room& operator--();
		Room operator--(int);
		Room& operator++();
		Room operator++(int);
		bool operator<(Room r) const; 
		bool operator>(Room r) const;
		Room& operator+=(const Room& room);
		Room operator+(const Room& room);
		operator bool() const; // could be helper as well if need to return
		
		// [] operator can be overloaded if the data member is array of custom type e.g Building has Room type array
		// [] can be overloaded in Building class to return Room type ref at index. 
		
		// use of friend to allow helper function to use class members
		friend std::ostream& operator <<(std::ostream& stream, const Room& room);
		friend void display(Room*, int);

	};

	std::istream& operator>>(std::istream& cinstream,  Room& room);
	
	// << can be helper withput friend. toa check comment above << function which is friend
	//std::ostream& operator <<(std::ostream& stream, const Room& room);
}
#endif

