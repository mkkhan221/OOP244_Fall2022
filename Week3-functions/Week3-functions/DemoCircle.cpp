#include <iostream>
#include "Circle.h"
using namespace sdds;
using namespace std;

void display(sdds::Circle* cir); // global function to display content on entire circle type array
void initializeCircles(sdds::Circle* cir); // global function to initialize circle * type array with default values
void distructCircles(sdds::Circle* cir); // to free DMA from each circle in array
const int ARRAYSIZE = 10;
int main() {

	sdds::Circle cl;
	Circle* circles = new Circle[ARRAYSIZE];;
	//Circle circlesarray[];
	char color[30];
	cl.createmem("red");
	//cl.setColor("black");
	cl.getColor(color);
	cout << color << endl;
	cl.display();
	cl.setSafeEmpty();

	initializeCircles(circles);
	display(circles);
	distructCircles(circles);
	delete[] circles;
}

void display(Circle* cir) {
	for (int i = 0; i < ARRAYSIZE; i++) {
		cout << "Circle object" << i << endl;
		cir[i].display();
	}
}

void initializeCircles(Circle* cir) {
	for (int i = 0; i < ARRAYSIZE; i++) {
		cir[i].createmem("white");
	}
}
void distructCircles(Circle* cir) {
	for (int i = 0; i < ARRAYSIZE; i++) {
		cir[i].deletemem();
	}
	cout << "success" << endl;
}
