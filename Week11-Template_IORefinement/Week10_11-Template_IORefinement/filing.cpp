//The following program is saved in a file called filing.cpp
//What is the exact output :
/*
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	int n = 10;
	fstream  f("filing.cpp", ios::in);
	char str[2000] = "Nothing";  
	f.getline(str, 1000, '*'); // 4 what add * here
	cout << str << endl;
	f >> n;
	cout << n << endl;
	f >> str; 
	cout << str;
	cout << endl; 
	return 0;
}
*/

