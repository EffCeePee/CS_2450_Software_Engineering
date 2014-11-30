#include "Library.h"

#include <ostream>

#include "Date.h"

// ================================================
// Constructors and Destructor
// ================================================
Library::Library() {
	//currentDate = _date->currentDate;
	currentDate = 0;
}

Library::~Library() {
	media.clear();
	patrons.clear();
	currentDate = 0;
}

// ================================================
// Public Methods
// ===============================================
/*
 * Take the user input file name and store the values in the mediaValues map
 * name, type, status, date, patron
*/
void Library::inputMediaFile(string filePath) {
	ifstream myFile;
	myFile.open(filePath);
	if (myFile.is_open()) {
		while (myFile.good()) {
			string inputString = "";
			while (getline(myFile, inputString)) {
				vector<string> mediaValues;
				istringstream iss(inputString);
				string value = "";
				while (getline(iss, value, ',')) {
					mediaValues.push_back(value);
				} // End of media properties line
				Media* m = new Media(mediaValues[0], mediaValues[1], mediaValues[2], atoi(mediaValues[3].c_str()), mediaValues[4]);
				media[mediaValues[0]] = m;
			} // End of file lines
		} // end of good file
	} // file not open
	myFile.close(); // close the file
} // end of inputMediaFile()

/*
 * Take the user input file name and store the values in the patronValues map
 * name, type, media<string> 
*/
void Library::inputPatronFile(string filePath) {
	ifstream myFile;
	myFile.open(filePath);
	if (myFile.is_open()) {
		while (myFile.good()) {
			string inputString = "";
			while (getline(myFile, inputString)) {
				vector<string> patronValues;
				istringstream iss(inputString);
				string value = "";
				while (getline(iss, value, ',')) {
					patronValues.push_back(value);
				} // End of patron properties line
				vector<string> patronMedia;
				for (vector<string>::size_type i = 2; i < patronValues.size(); ++i) {
					if(patronValues[i] != "null") { // Ignore any null values
						patronMedia.push_back(patronValues[i]);
					}
				}
				Patron* p = new Patron(patronValues[0], patronValues[1], patronMedia);
				patrons[patronValues[0]] = p;
			} // End of file lines
		} // end of good file
	} // file not open
	myFile.close(); // close the file
} // end of inputPatronFile()

/*
 * Take the user input file name and store media objects in the file
 * name, type, status, date, patron
*/
void Library::outputMediaFile(string filePath) {
	ofstream myFile;
	myFile.open(filePath, ios::out | ios::trunc);
	if (myFile.is_open()) {
		outputMediaFileStream(myFile);
	}
	myFile.close();
}
//------------------------------------------------------------------------------
void Library::outputMediaFileStream(std::ostream& os) const {
	for (auto it = media.begin(); it != media.end(); ++it) {
		string mediaOutput = it->second->parseOutput();
		os.write(mediaOutput.c_str(), mediaOutput.size());
	}
}

/*
 * Take the user input file name and store patron objects in the file
 * name, type, media<string>
*/
void Library::outputPatronFile(string filePath) {
	ofstream myFile;
	myFile.open(filePath, ios::out | ios::trunc);
	if (myFile.is_open()) {
		outputPatronFileStream(myFile);
	}
	myFile.close();
}
//------------------------------------------------------------------------------
void Library::outputPatronFileStream(std::ostream& os) const {
	for (auto it = patrons.begin(); it != patrons.end(); ++it) {
		string patronsOutput = it->second->parseOutput();
		os.write(patronsOutput.c_str(), patronsOutput.size());
	}
}

/*
 * Verify that media is available and that patron has not reached limit
 * Set media status to true and assign patron.  Add Media to Patron
*/
void Library::checkoutMedia(string mediaName, string patronName) {
	Media* m = media[mediaName];
	Patron* p = patrons[patronName];

	if (m->isAvailable() && p->canCheckout(m->printType())) {
		m->assignPatron(patronName);
		p->assignMedia(mediaName);
	} else {
		cout << "Error: Either the media is unavailable or the patron has reached their max checkout limit." << endl;
	}
}

/*
* Set media status to false and patron to "".  Remove Media from Patron
*/
void Library::checkinMedia(string mediaName, string patronName) {
	Media* m = media[mediaName];
	Patron* p = patrons[patronName];

	m->removePatron();
	p->removeMedia(mediaName);
}

/*
 * Take the user input and display the appropriate data
 * Type and status will be determined
*/
void Library::displayMedia(string type, string status) {
	std::ostringstream ss;
	displayMediaStream(type, status, ss);
	cout << ss.str();
}
//------------------------------------------------------------------------------
/// \brief Get the list of patrons as a stream.
/// \param type: Choices are "all", "adult", "childrens", "dvd", "videotape"
/// \param status: Choices are "all", "available", "checkedout", "overdue"
//------------------------------------------------------------------------------
void Library::displayMediaStream(string type, string status, std::ostream& os) const
{
	if (type != "all") {
		if (status != "all") {
			for (auto it = media.begin(); it != media.end(); ++it) {
				if (it->second->isType(type) && it->second->isStatus(status)) {
					os << "(" << it->second->printStatus() << ") - " << it->second->printName() << endl;
				}
			}
		}
		else {
			for (auto it = media.begin(); it != media.end(); ++it) {
				if (it->second->isType(type)) {
					os << "(" << it->second->printStatus() << ") - " << it->second->printName() << endl;
				}
			}
		}
	}
	else {
		if (status != "all") {
			for (auto it = media.begin(); it != media.end(); ++it) {
				if (it->second->isStatus(status)) {
					os << "(" << it->second->printStatus() << ") - " << it->second->printName() << endl;
				}
			}
		}
		else {
			for (auto it = media.begin(); it != media.end(); ++it) {
				os << "(" << it->second->printStatus() << ") - " << it->second->printName() << endl;
			}
		}
	}
}
/*
* Take the user input and display the appropriate data
* Type will be determined
*/
void Library::displayPatrons(string type) {
	std::ostringstream ss;
	displayPatronsStream(type, ss);
	cout << ss.str();
}
//------------------------------------------------------------------------------
/// \brief Get the list of patrons as a stream.
/// \param type: Choices are "all", "adult", "child".
//------------------------------------------------------------------------------
void Library::displayPatronsStream(string type, std::ostream& os) const
{
	if (type != "all") {
		for (auto it = patrons.begin(); it != patrons.end(); ++it) {
			if (it->second->isType(type)) {
				os << it->second->printName() << endl;
			}
		}
	}
	else {
		for (auto it = patrons.begin(); it != patrons.end(); ++it) {
			os << it->second->printName() << endl;
		}
	}
}

/*
 * Take the patron Name and display all media associated with them
*/
void Library::displayPatronMedia(string patronName) {
	std::ostringstream ss;
	displayPatronMediaStream(patronName, ss);
	cout << ss.str();
}
//------------------------------------------------------------------------------
void Library::displayPatronMediaStream(string patronName, std::ostream& os) {
	Patron* p = patrons[patronName];

	vector<string> patronMedia = p->printMedia();
	for (int i = 0; i < patronMedia.size(); ++i) {
		os << patronMedia[i] << endl;
	}
}

/*
 * Increment the date
*/
void Library::incrementDate() {
	//currentDate = _date->incrementDate();
	++currentDate;
	for (auto it = media.begin(); it != media.end(); ++it) {
		it->second->updateStatus(currentDate);
	}
}
//------------------------------------------------------------------------------
int Library::getDate() const {
	return currentDate;
}

/*
 * Print the menu
*/
void Library::printMenu() {
	std::ostringstream ss;
	printMenuStream(ss);
	cout << ss.str();
}
//------------------------------------------------------------------------------
void Library::printMenuStream(std::ostream& os) {
	os << "\nLIBRARY" << endl;
	os << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	os << "-1-  Checkout Book" << endl;
	os << "-2-  Checkin Book" << endl;
	os << "-3-  Display Media List" << endl;
	os << "-4-  Display Patron List" << endl;
	os << "-5-  Display Patron's Media" << endl;
	os << "-6-  Increment Date" << endl;
	os << "-7-  Save and Quit" << endl;
	os << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	os << "Please enter a command: ";
}