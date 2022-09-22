#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Circle.h"
using namespace std;
using namespace sdds;

namespace sdds {

	void Circle::createmem(const char * c) {
		// if object calls this function , before we allocate DM , we should ensure that there is no previous allocation.
		if (color == nullptr) {
			if (c) {
				color = new char[strlen(c) + 1];
				strcpy(color, c);
			}
			else {
				color = new char[max_size];
				strcpy(color, "white");
			}
		}
		else {
			deletemem();
			
			color = new char[max_size];
		}
		radius = 1;
		isBorder = false;
		area = PI * radius * radius;

	}

	void Circle::deletemem() {
		if (color) {
			delete color;
			color = nullptr;
		}
	}
	void Circle::setSafeEmpty() {
		deletemem();
		radius = 0;
		isBorder = false;
		area = 0;
	}
	void Circle::setColor(const char* c) // mutator
	{
		strcpy(color,c);
		
	}
	void Circle::getColor(char* c) const //query
	{
		if (c) {
			strcpy(c, color);
		}
		else {
			c = nullptr;
		}
	}

	void Circle::setRadius(double r) // mutator
	{
		radius = r;
	}

	double Circle::getRadius() const //query
	{
		return radius;
	}
	void Circle::setIsBorder(bool b) //mutator
	{
		isBorder = b;
	}

	bool Circle::getIsBorder() const //query
	{
		return isBorder;
	}
	void Circle::calculateArea() {
		area = PI * radius * radius;
	}
	double Circle::getArea() {
		calculateArea();
		return area;
	}
	void Circle::display() const //special
	{
		cout << "The color is " << color << endl;
		cout << "The radius is " << radius << endl;
		cout << "Circle has border? " << isBorder << endl;
		cout << "The circle area is " << area << endl;
	}
}

