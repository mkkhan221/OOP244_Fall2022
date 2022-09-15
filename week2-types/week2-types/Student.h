#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
#include <cstdio>
#include <iostream>
// using namespace is wrong on .h file

namespace stud {
	const int MAX_STD = (100);
	
	struct Student {
		char name[30];
		int enrollment_id;

	};

	void setName(Student* std, const char* name);
	void setEnrollmentId(Student* std, int id);
	int loadStudentList(Student* Sptr);
	int readStudent(Student* St);
	int readStudent(Student *St, std::istream& in);
	void set(Student* std, const char* name = "Joe", int id = 000);

	extern std::FILE* fptr;
}

#endif