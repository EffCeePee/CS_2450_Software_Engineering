#ifndef MEDIA_H
#define MEDIA_H

// Library Includes
#include <string>
#include <sstream>

// User Header File Includes
#include "Date.h"

// Namespace Includes
using std::string;
using std::ostringstream;

class Media {
public:
	// ================================================
	// Constructors and Destructor
	// ================================================
	Media();
	Media(string _name, string _type, string _status, int _date, string _patron);
	~Media();

	// ================================================
	// Public Methods
	// ================================================
	bool isAvailable();
	bool isStatus(string _status);
	bool isType(string _type);
	void assignPatron(string PatronName);
	void removePatron();
	void updateStatus(int currentDate);
	string printName();
	string printType();
	string printStatus();
	string parseOutput();

private:
	// ================================================
	// Private Data Members
	// ================================================
	string name;
	string type; // "adult", "childrens", "dvd", "videotape"
	string status; // "available", "checkedout", "overdue"
	int checkedOutDate;
	string patron;

	// ================================================
	// Private Constants
	// ================================================
	const int ADULT_LOAN = 14;
	const int CHILDRENS_LOAN = 7;
	const int DVD_LOAN = 2;
	const int VIDEOTAPE_LOAN = 3;
};


#endif // MEDIA_H