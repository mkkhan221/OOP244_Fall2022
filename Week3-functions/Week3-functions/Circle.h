#ifndef SDDS_CIRCLE_H
#define SDDS_CIRCLE_H

namespace sdds{
	const double PI = 3.14;
	const int max_size = 31;

 struct Circle {
	private:

		char* color=nullptr;
		double radius;
		bool isBorder;
		double area;
		void calculateArea(); // mutator or modifer
		

	public: 
		void createmem(const char*); // fro DMA for color in circle type 
		void deletemem(); // to delete DMA
		void setSafeEmpty(); // to set circle member to defaultbased on problem statement
		void setColor(const char* c); // mutator or modifer
		void getColor(char* c) const; // query
		void setRadius(double r); // mutator or modifer
		double getRadius() const; // query
		void setIsBorder(bool b = true); // defualt argument // mutator or modifer
		bool getIsBorder() const;  // query
		double getArea() ;  // query and special
		void display()const;  // query or special

		// const placed at end of the function prototype ensure that the code doesn't change state of object directly or indirectly 
		// hence getArea is query but cannot be const as it is calling calculateArea function which is modifier. 

	};

}


#endif