#ifndef DATE_H
#define DATE_H

// Library Includes
#include <string>

// Namespace Includes
using std::string;

class Date {
public:
	// ================================================
	// Constructors and Destructor
	// ================================================
	Date();
	~Date();

	// ================================================
	// Public Methods
	// ================================================
	int incrementDate();

	// ================================================
	// Public Data Members
	// ================================================
	int currentDate;
};


#endif // DATE_H