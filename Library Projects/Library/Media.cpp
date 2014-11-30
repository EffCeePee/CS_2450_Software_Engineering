#include "Media.h"

// ================================================
// Constructors and Destructor
// ================================================
Media::Media() {
	name = "";
	type = "";
	status = "available";
	checkedOutDate = 0;
	patron = "";
}

Media::Media(string _name, string _type, string _status, int _date, string _patron) {
	name = _name;
	type = _type;
	status = _status;
	checkedOutDate = _date;
	patron = _patron;
}

Media::~Media() {
	name = "";
	type = "";
	status = "";
	checkedOutDate = 0;
	patron = "";
}

// ================================================
// Public Methods
// ================================================
/*
 * Verify that the media is not already checked out
*/
bool Media::isAvailable() {
	if (status == "available") {
		return true;
	} else {
		return false;
	}
}

/*
 * Check whether the book is overdue
*/
bool Media::isStatus(string _status) {
	if (_status == status) {
		return true;
	} else {
		return false;
	}
}

/*
 * Get the type of media
*/
bool Media::isType(string _type) {
	if (_type == type) {
		return true;
	} else {
		return false;
	}
}

/*
 * Change the media status to "checkedout" and assign the patron
*/
void Media::assignPatron(string patronName) {
	status = "checkedout";
	patron = patronName;
}

/*
 * Change the media status to "available" and remove the assigned patron
*/
void Media::removePatron() {
	status = "available";
	patron = "";
}

/*
 * If media is checked out, verify that it has not gone past due
*/
void Media::updateStatus(int currentDate) {
	if (status == "checkedout") {
		if (type == "adult") {
			if (currentDate > (checkedOutDate + ADULT_LOAN)) {
				status = "overdue";
			}
		} else if (type == "childrens") {
			if (currentDate > (checkedOutDate + CHILDRENS_LOAN)) {
				status = "overdue";
			}
		} else if (type == "dvd") {
			if (currentDate > (checkedOutDate + DVD_LOAN)) {
				status = "overdue";
			}
		} else if (type == "videotape") {
			if (currentDate > (checkedOutDate + VIDEOTAPE_LOAN)) {
				status = "overdue";
			}
		}
	}
}

/*
 * Return the name of media
*/
string Media::printName() {
	return name;
}

/*
 * Return the type of media
*/
string Media::printType() {
	return type;
}

/*
* Return the type of media
*/
string Media::printStatus() {
	return status;
}

/*
 * Combine all the data members into a comma-delimited string and output to file
*/
string Media::parseOutput() {
	string date = "";
	ostringstream intConvert;
	intConvert << checkedOutDate;
	date = intConvert.str();

	return name + ',' + type + ',' + status + ',' + date + ',' + patron + '\n';
}