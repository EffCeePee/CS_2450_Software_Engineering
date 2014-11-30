#ifndef PATRON_H
#define PATRON_H

// Library Includes
#include <string>
#include <vector>
#include <algorithm>

// User Header File Includes
#include "Media.h"

// Namespace Includes
using std::string;
using std::vector;
using std::find;

class Patron {
public:
	// ================================================
	// Constructors and Destructor
	// ================================================
	Patron();
	Patron(string, string, vector<string>);
	~Patron();

	// ================================================
	// Public Methods
	// ================================================
	bool canCheckout(string mediaType);
	bool isType(string _type);
	void assignMedia(string mediaName);
	void removeMedia(string mediaName);
	string printName() const;
	vector<string> printMedia() const;
	string parseOutput();

private:
	// ================================================
	// Private Data Members
	// ================================================
	string name;
	string type;          // "adult" or "child"
	int allowedMedia;     // ADULT_LIMIT or CHILD_LIMIT
	vector<string> media; // vector of checked out media

	// ================================================
	// Private Constants
	// ================================================
	const int ADULT_LIMIT = 6;
	const int CHILD_LIMIT = 3;
};


#endif // PATRON_H