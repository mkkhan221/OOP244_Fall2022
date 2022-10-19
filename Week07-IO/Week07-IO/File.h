#ifndef SDDS_FILE_H__
#define SDDS_FILE_H__
#include <iostream>

namespace sdds {
	const int maxfilesize = 100;
	const int MAX_NAME_LEN = 30;
	class File
	{
		char* name;
		int fileID;
		int size;
	public:
		// the trios
		File();

		File(const char*, int fid = 0, int s = 0);
		File(const File&); // copy constructor

		// destructor
		~File();
		// setters

		bool setName(const char*);
		bool setFileID(int);
		bool setSize(int);
		bool set(const char*, int, int);
		bool set(const File&);

		//safe state
		void dealloc();
		void setSafeState();

		//operator overload
		File& operator=(const File&);// deep copy

		// User input
		std::istream& read(int, std::istream&); // input int 
		std::istream& read(char*, std::istream&); // input name or id 


		//queries
		std::ostream& display(std::ostream&) const;
		char* getFileName()const;
		int getFileID()const;
		int getSize()const;

		bool isEmpty()const; // if size 0 return T
		bool operator==(const File&);
		bool operator!=(const File&);
		operator bool()const; // return T if not empty


	};
	//read file type records from file system
	int read(const char*, File[], int);
	void print(File[], const char* filename, int); // print array of file type data to file
	std::istream& operator>>(const std::istream&, File&);
	std::ofstream& operator<<(std::ofstream&, File&);
	std::ostream& operator<<(const std::ostream&, File&);
	std::ifstream& operator>>(std::ifstream&, File&);
}

#endif