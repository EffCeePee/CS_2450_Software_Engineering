#ifndef LIBRARY_H
#define LIBRARY_H

// Library Includes
#include <iosfwd> // for ostream
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <cstdio>

// User Header File Includes
#include "Patron.h"
#include "Media.h"

// Namespace Includes
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::getline;
using std::istringstream;
using std::map;
using std::vector;

// Global Constants

class Library {

public:
	// ================================================
	// Constructors and Destructor
	// ================================================
	Library();
	~Library();

	// ================================================
	// Public Methods
	// ================================================
	void inputMediaFile(string filePath);
	void inputPatronFile(string filePath);
	void outputMediaFile(string filePath);
	void outputPatronFile(string filePath);
	void checkoutMedia(string mediaName, string patronName);	
	void checkinMedia(string mediaName, string patronName);		
	void displayMedia(string type, string status);				
	void displayPatrons(string type);
	void displayPatronMedia(string patronName);
	void incrementDate();
	void printMenu();											

	// These functions are needed for testing
	void outputMediaFileStream(std::ostream& os) const;
	void outputPatronFileStream(std::ostream& os) const;
	void displayMediaStream(string type, string status, std::ostream& os) const;
	void displayPatronsStream(string type, std::ostream& os) const;
	void displayPatronMediaStream(string patronName, std::ostream& os);
	int getDate() const;
	void printMenuStream(std::ostream& os);

private:
	// ================================================
	// Private Data Members
	// ================================================
	map<string, Media*> media;
	map<string, Patron*> patrons;
	int currentDate;
	//Date* _date = new Date();
	
};

#endif // LIBRARY_H