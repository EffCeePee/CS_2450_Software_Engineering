/*		CS 2450 - 002
 *		Group Members: Colton, Michael, Karl, Scott
 *		Project Manager: Colton
 *		Tester: Michael
 *		Designers/Coders: Karl/Scott
 *		Project: Library
 *		Project URL: http://webermatters.com/cs2450/library/trunk/Library/
*/

// Library Includes
#include <cassert>

// User Header File Includes
#include "Library.h"
#include "UnitTest++.h"

// Namespace Includes

static std::vector<std::string> fg_files;

//------------------------------------------------------------------------------
/// \brief  Handle any command line arguments (only "-test" for now).
/// \return true if continuing on, false if we need to quit
//------------------------------------------------------------------------------
bool handleCommandLineArguments(int argc, char* argv[]) {
	bool doTests = false;

	for (int i = 1; i < argc; ++i) {
		std::string s = argv[i];
		if (s == "-test") {
			doTests = true;
		} else {
			fg_files.push_back(s);
		}
	}

	if (doTests) {
		UnitTest::RunAllTests();
		return false;
	}
	return true;
}
//------------------------------------------------------------------------------
bool isInteger(const std::string & s) {
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}
//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {

	bool goOn = handleCommandLineArguments(argc, argv);
	if (!goOn) {
		return 0;
	}

	Library* L = new Library();
	string userInput = "";
	string mediaPath = "";
	string patronPath = "";
	int command = 0;

	if (fg_files.empty()) {
		cout << "Please enter the file path to the Media File: ";
		getline(cin, mediaPath);
		L->inputMediaFile(mediaPath);
		cout << "Please enter the file path to the Patron File: ";
		getline(cin, patronPath);
		L->inputPatronFile(patronPath);
	}
	else {
		L->inputMediaFile(fg_files.at(0));
		L->inputPatronFile(fg_files.at(1));
	}

	// Int to string vectors
	std::vector<std::string> mediaType = { "all", "adult", "childrens", "dvd", "videotape" };
	std::vector<std::string> mediaStatus = { "all", "available", "checkedout", "overdue" };
	std::vector<std::string> patronType = { "all", "adult", "child" };
	char* p = nullptr;

	do {
		string mediaName = "";
		string patronName = "";
		string type = "";
		string status = "";

		L->printMenu();
		getline(cin, userInput);
		command = atoi(userInput.c_str());
		switch(command) {
			case 1:
				cout << "Please enter media name: ";
				getline(cin, mediaName);
				cout << "\nPlease enter patron name: ";
				getline(cin, patronName);
				L->checkoutMedia(mediaName, patronName);
				break;
			case 2:
				cout << "Please enter media name: ";
				getline(cin, mediaName);
				cout << "\nPlease enter patron name: ";
				getline(cin, patronName);
				L->checkinMedia(mediaName, patronName);
				break;
			case 3:
				cout << "Please enter media type: all(1), adult(2), childrens(3), dvd(4), videotape(5): ";
				getline(cin, type);
				if (isInteger(type)) type = mediaType[strtol(type.c_str(), &p, 10) - 1];
				cout << "\nPlease enter media status: all(1), available(2), checkedout(3), overdue(4): ";
				getline(cin, status);
				if (isInteger(status)) status = mediaStatus[strtol(status.c_str(), &p, 10) - 1];
				L->displayMedia(type, status);
				break;
			case 4:
				cout << "Please enter patron type: all(1), adult(2), child(3) ";
				getline(cin, type);
				if (isInteger(type)) type = patronType[strtol(type.c_str(), &p, 10) - 1];
				L->displayPatrons(type);
				break;
			case 5:
				cout << "Please enter the Patron's name: ";
				getline(cin, patronName);
				L->displayPatronMedia(patronName);
				break;
			case 6:
				L->incrementDate();
				break;
			case 7:
				L->outputMediaFile(mediaPath);
				L->outputPatronFile(patronPath);
				break;
			default:
				cout << "That is an invalid entry.  Please try again." << endl;
				break;
		}
	} while(command != 7);

	system("PAUSE");
	return 0;
}
