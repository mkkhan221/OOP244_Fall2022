#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Pair.h"
#include "Displayer.h"
using namespace std;
namespace sdds {
	
		template<class type> // template <typename type>
		type Add(type operand1,  type operand2) {
			return (operand1 + operand2);
		}
		
	// AddChar Add(AddChar operant1, AddChar operand2)
	//int Add(int operand1, int operand2)
		// double Add(doube operand1, double operand2)
		class AddChar {
		public:
			char* str;
		
			void setStr(const char* s) {
				str = new char[strlen(s) + 1];
				strcpy(str,s);
			}

			AddChar& operator+(AddChar& st)
			{
				char* temp = new char[strlen(this->str) + strlen(st.str) + 1];
				 
				strcpy(temp, this->str);
				strcat(temp, st.str);
				temp[strlen(temp)] = '\0';
				delete str;
				setStr(temp);
				delete[] temp;
				return *this;
			}
		};
}

using namespace sdds;
/*
int main() {
	int num1 = 3, num2=4;
	cout << "The Sum is: " << Add<int>(num1, num2) << endl;
	double no1 = 2.2, no2 = 2.2;
	cout << " The Sum is: " << Add<double>(no1, no2) << endl;
	AddChar one, two;
	one.setStr("Moona");
	two.setStr("Kanwal");
	AddChar cat;
	cat=Add(one,two);
	cout << "The Sum is: " << cat.str << endl;
	
	cout << " The Sum is: " << Add<double>(no1, no2) << endl;
	//cout<<one.Add(one, two);
	//cout << "The Sum is: " << Add("", "") << endl;

}*/

/*
//demo for displayer
int main() {
	Displayer<int> D, E = 300;
	Displayer<double> A, B = 300.1234;
	cout << D << endl;
	cout << E << endl;
	cout << "Value: ";
	cin >> D;
	cout << "The value is: " << D << endl;
	cout << A << endl << B << endl;
	cout << "double value: ";
	cin >> A;
	cout << A << endl;

	return 0;
}
*/