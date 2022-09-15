#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include "Student.h"


using namespace stud;
using namespace std;

const int MAX_LENGTH = 31;

int main() {

	Student stdList[MAX_LENGTH] = { 0 };
	Student *std=new Student;
	set(std);
	cout << "name: "<<std->name<<" ID "<<std->enrollment_id<<endl;
	// case 1
//	Student* anotherstd;
//	anotherstd = std;
	
//	delete anotherstd;
//	cout << std->enrollment_id; // garbage

	//case 2

	Student* secondstd = new Student();
	set(secondstd, "Mavrick", 500);
	std = secondstd;

	cout << std->enrollment_id<<endl;
	cout << std->name << endl;


	// the below code is to open file , read records in Studnt type array 
	/*char stdname[31] = "Moona";
	fptr = fopen("stdlist.csv", "r");
	int i = 0;
	if (fptr) {
		i = loadStudentList(stdList);
		cout << i << "records read " << endl;
		fclose(fptr);
		cout << "The Student Name is " << stdList[1].name << endl;
		cout << "The Student ID is " << stdList[1].enrollment_id << endl;

		}
		*/
	/*
	// input from user using function overload 

	if (readStudent(secondstd, cin)) {
		cout <<"success"<<endl;
	}
		*/
return 0;
}