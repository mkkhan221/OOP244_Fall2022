#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring> // c++ string lib


#include "Student.h"
using namespace std;

namespace stud {
	FILE* fptr = nullptr;

	void setName(Student* std, const char* name) {
		strcpy(std->name, name);
	}

	void setEnrollmentId(Student* std, int id) {
		std->enrollment_id = id;
	}

	int loadStudentList(Student* Sptr) {
		int i = 0;
		while (readStudent(&Sptr[i])) {
			i++;
		}
		return i;
	}
	int readStudent(Student* St) {
		return fscanf(fptr, "%30[^, ],%d", &St->name, &St->enrollment_id) == 2;
	}

	int readStudent(Student *St, std::istream& in) {
		int flag = 0;
		if (St) {
			cout << "enter name ";
			in >> St->name;
			cout << "enter id";
			in >> St->enrollment_id;
			flag = 1;
		}
		return flag;
	}

	void set(Student* std, const char* name, int id) {
		setName(std, name);
		setEnrollmentId(std, id);

	}
}