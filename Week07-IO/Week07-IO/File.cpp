#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include "File.h"

using namespace std;
namespace sdds {
	
	File::File() {
		name = new char[MAX_NAME_LEN+1];
		fileID = 0;
		size = 0;
	}
	// removed one ar constructor and provided defaults
	File::File(const char* n, int fid, int s) {
		name = nullptr;
		if (n != nullptr) {
			name = new char[strlen(n) + 1]{};
			strcpy(name, n);
		}
		else {
			name = new char[] {"noname.txt"};
		}
		fileID = fid;
		size = s;
		//display(cout);
	}
	File::File(const File& fi) {
		name = nullptr;
		set(fi.name, fi.fileID, size);
	}
	File::~File() {
		dealloc();
	}
	void File::dealloc() {
		delete[] name;
		name = nullptr;
		
	}
	void File::setSafeState() {
		dealloc();
		fileID = 0;
		size = 0;
	}

	bool File::setName(const char* n) {
		bool check = false;
		dealloc();
		if (n != nullptr) {
			name = new char[strlen(n) + 1]{};
			strcpy(name, n);
			check = true;
		}
		else {
			setSafeState();
		}
		return check;
	}
	bool File::setFileID(int fid) {
		
		fileID = fid;
		return true;
	}
	bool File::setSize(int s) {
		bool check = false;
		if (s >= 0 && s <= maxfilesize) {
			size = s;
			check = true;
		}
		else {
			setSafeState();
		}
		return check;
	}
	bool File::set(const char* n, int fid, int s) {
		bool check = false;
		if (setName(n) && setFileID(fid) && setSize(s)) {
			check = true;
		}
		return check;
	}
	bool File::set(const File& fi) {
		bool check = false;
		if (set(fi.name, fi.fileID, fi.size)) {
			check = true;
		}
		return check;
	}

	char* File::getFileName()const {
		char* tempname=nullptr;
		if (name && name[0]!='\0') {
			tempname = new char[strlen(name) + 1];
			strcpy(tempname, name);
		}
		return tempname;
	}
	int File::getFileID()const {
		
		return fileID;
	}
	int File::getSize()const {
		return size;
	}

	bool File::isEmpty() const {
		return size == 0;
	}
	File::operator bool() const {
		return !isEmpty();
	}
	std::ostream& File::display(std::ostream& out) const {
		out << "File name is: " << name << endl;
		out << "File id is: " << fileID << endl;
		out << "File size is: " << size << endl;
		return out;

	}
	int read(const char* filename, File flist[], int size) {
		ifstream f(filename);
		int i = 0;
		if (!f.is_open()) {
			cerr << "File cannot be opened" << endl;
		}
		else {

			while (!f.eof() && i < size) {

				f >> (flist[i]);
				i++;

			}
		}
		f.close();
		return i;
	}
	// print all the data in file array to file
	void print(File flist[], const char* filename, int arraysize)
	{
		ofstream outfile(filename, ios::app); // open file in append mode
		//char* name = new char[30]{};
		//char* fileid = new char[10]{ };

		if (!outfile.is_open()) {
			cerr << "File cannot be opened" << endl;
		}
		else {
			for (int i = 0; i < arraysize; i++) {

				outfile << flist[i];
				//flist[i].getFileName(name);
				//flist[i].getFileID(fileid);

				//outfile << name << "," << fileid << "," << flist[i].getSize()<<endl;
				//name = strSet(name, '\0'); // to clear the array 
				//fileid = strSet(fileid, '\0'); // to clear the array
			}
		}
		outfile.close();

	}
	ofstream& operator<<(std::ofstream& out, File& f) {
		int fid = 0;
		char* name=nullptr;
		if (!out.is_open()) {
			cerr << "File cannot be opened" << endl;
		}
		else {
			fid=f.getFileID();
			name=f.getFileName();
			cout << "Writing to the file" << endl;
			out << name << "," << fid << "," << f.getSize() << endl;
		}

		delete[] name;
		return out;
	}

	std::ifstream& operator>>(ifstream& in, File& f) {

		char fname[MAX_NAME_LEN+1];
		int fileid=0;
		string name = "";
		string fid = "";
		int size = 0;
		if (!in.is_open()) {
			cerr << "File cannot be opened" << endl;
		}
		else {
			cout << "Reading from the file" << endl;
			while (in.peek() != '\n')  // to read single record
			{
				getline(in, name, ','); // get text in string type. string type used as std::getline() offers parsing of string using delimeter

				in >> fileid;
				in >> size;

				strcpy(fname, name.c_str()); // c_str() is string object function which returns pointer to char array. this is to get char array for set functions
				

				f.setName(fname);
				f.setFileID(fileid);
				f.setSize(size);
			}
		}

		in.ignore(); // ignore newline
		return in;

	}
}