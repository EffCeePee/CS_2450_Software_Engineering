#include "UnitTest++.h"
#include "Library.h"

//------------------------------------------------------------------------------
// \brief Test Library stuff.
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
class LibraryHolder
{
public:
	LibraryHolder() {
		m_lib.inputMediaFile(".\\..\\Library\\mediaFile.txt");
		m_lib.inputPatronFile(".\\..\\Library\\patronFile.txt");
	}

	Library m_lib;
};

//------------------------------------------------------------------------------
TEST_FIXTURE(LibraryHolder, LibraryTestOutputMediaFile)
{
	std::stringstream ss;
	m_lib.outputMediaFileStream(ss);
	string actual = ss.str();
	string expected = "ABook 1,adult,available,0,null\nABook 10,adult,available,0,null\nABook 11,adult,available,0,null\nABook 12,adult,available,0,null\nABook 13,adult,available,0,null\nABook 14,adult,available,0,null\nABook 15,adult,available,0,null\nABook 16,adult,available,0,null\nABook 2,adult,available,0,null\nABook 3,adult,available,0,null\nABook 4,adult,available,0,null\nABook 5,adult,available,0,null\nABook 6,adult,available,0,null\nABook 7,adult,available,0,null\nABook 8,adult,available,0,null\nABook 9,adult,available,0,null\nCBook 1,childrens,available,0,null\nCBook 10,childrens,available,0,null\nCBook 11,childrens,available,0,null\nCBook 12,childrens,available,0,null\nCBook 2,childrens,available,0,null\nCBook 3,childrens,available,0,null\nCBook 4,childrens,available,0,null\nCBook 5,childrens,available,0,null\nCBook 6,childrens,available,0,null\nCBook 7,childrens,available,0,null\nCBook 8,childrens,available,0,null\nCBook 9,childrens,available,0,null\nDVD 1,dvd,available,0,null\nDVD 10,dvd,available,0,null\nDVD 11,dvd,available,0,null\nDVD 2,dvd,available,0,null\nDVD 3,dvd,available,0,null\nDVD 4,dvd,available,0,null\nDVD 5,dvd,available,0,null\nDVD 6,dvd,available,0,null\nDVD 7,dvd,available,0,null\nDVD 8,dvd,available,0,null\nDVD 9,dvd,available,0,null\nVideotape 1,videotape,available,0,null\nVideotape 10,videotape,available,0,null\nVideotape 11,videotape,available,0,null\nVideotape 2,videotape,available,0,null\nVideotape 3,videotape,available,0,null\nVideotape 4,videotape,available,0,null\nVideotape 5,videotape,available,0,null\nVideotape 6,videotape,available,0,null\nVideotape 7,videotape,available,0,null\nVideotape 8,videotape,available,0,null\nVideotape 9,videotape,available,0,null\n";
	CHECK_EQUAL(expected, actual);
}
//------------------------------------------------------------------------------
TEST_FIXTURE(LibraryHolder, LibraryTestOutputPatronFile)
{
	std::stringstream ss;
	m_lib.outputPatronFileStream(ss);
	string actual = ss.str();
	string expected = "Patron 1,adult,\nPatron 10,adult,\nPatron 11,adult,\nPatron 12,adult,\nPatron 13,adult,\nPatron 14,adult,\nPatron 15,adult,\nPatron 16,adult,\nPatron 17,adult,\nPatron 18,adult,\nPatron 19,adult,\nPatron 2,adult,\nPatron 20,adult,\nPatron 21,adult,\nPatron 22,adult,\nPatron 23,adult,\nPatron 24,adult,\nPatron 25,child,\nPatron 26,child,\nPatron 27,child,\nPatron 28,child,\nPatron 29,child,\nPatron 3,adult,\nPatron 30,child,\nPatron 31,child,\nPatron 32,child,\nPatron 33,child,\nPatron 34,child,\nPatron 35,child,\nPatron 36,child,\nPatron 37,child,\nPatron 38,child,\nPatron 39,child,\nPatron 4,adult,\nPatron 40,child,\nPatron 41,child,\nPatron 42,child,\nPatron 43,child,\nPatron 44,child,\nPatron 45,child,\nPatron 46,child,\nPatron 47,child,\nPatron 48,child,\nPatron 49,child,\nPatron 5,adult,\nPatron 50,child,\nPatron 51,child,\nPatron 52,child,\nPatron 6,adult,\nPatron 7,adult,\nPatron 8,adult,\nPatron 9,adult,\n";
	CHECK_EQUAL(expected, actual);
}
void checkoutMedia(string mediaName, string patronName);
//------------------------------------------------------------------------------
TEST_FIXTURE(LibraryHolder, LibraryTestCheckoutMedia)
{
	std::stringstream ss;
	m_lib.checkoutMedia("ABook 3", "Patron 5");
	m_lib.displayPatronMediaStream("Patron 5", ss);
	string actual = ss.str();
	string expected = "ABook 3\n";
	CHECK_EQUAL(expected, actual);
}
//------------------------------------------------------------------------------
TEST_FIXTURE(LibraryHolder, LibraryTestCheckinMedia)
{
	std::stringstream ss;
	m_lib.checkinMedia("DVD 1", "Patron 1");
	m_lib.displayPatronMediaStream("Patron 1", ss);
	string actual = ss.str();
	string expected = "";
	CHECK_EQUAL(expected, actual);
}
//------------------------------------------------------------------------------
TEST_FIXTURE(LibraryHolder, LibraryTestDisplayPatrons1)
{
	std::stringstream ss;
	m_lib.displayPatronsStream("", ss);
	string actual = ss.str();
	string expected = "";
	CHECK_EQUAL(expected, actual);
}
//------------------------------------------------------------------------------
TEST_FIXTURE(LibraryHolder, LibraryTestDisplayPatrons2)
{
	std::stringstream ss;
	m_lib.displayPatronsStream("all", ss);
	string actual = ss.str();
	string expected = "Patron 1\nPatron 10\nPatron 11\nPatron 12\nPatron 13\nPatron 14\nPatron 15\nPatron 16\nPatron 17\nPatron 18\nPatron 19\nPatron 2\nPatron 20\nPatron 21\nPatron 22\nPatron 23\nPatron 24\nPatron 25\nPatron 26\nPatron 27\nPatron 28\nPatron 29\nPatron 3\nPatron 30\nPatron 31\nPatron 32\nPatron 33\nPatron 34\nPatron 35\nPatron 36\nPatron 37\nPatron 38\nPatron 39\nPatron 4\nPatron 40\nPatron 41\nPatron 42\nPatron 43\nPatron 44\nPatron 45\nPatron 46\nPatron 47\nPatron 48\nPatron 49\nPatron 5\nPatron 50\nPatron 51\nPatron 52\nPatron 6\nPatron 7\nPatron 8\nPatron 9\n";
	CHECK_EQUAL(expected, actual);
}
//------------------------------------------------------------------------------
TEST_FIXTURE(LibraryHolder, LibraryTestDisplayMedia)
{
	std::stringstream ss;
	m_lib.displayMediaStream("", "", ss);
	string actual = ss.str();
	string expected = "";
	CHECK_EQUAL(expected, actual);
}
//------------------------------------------------------------------------------
TEST_FIXTURE(LibraryHolder, LibraryTestDisplayMedia2)
{
	std::stringstream ss;
	m_lib.displayMediaStream("all", "all", ss);
	string actual = ss.str();
	string expected = "(available) - ABook 1\n(available) - ABook 10\n(available) - ABook 11\n(available) - ABook 12\n(available) - ABook 13\n(available) - ABook 14\n(available) - ABook 15\n(available) - ABook 16\n(available) - ABook 2\n(available) - ABook 3\n(available) - ABook 4\n(available) - ABook 5\n(available) - ABook 6\n(available) - ABook 7\n(available) - ABook 8\n(available) - ABook 9\n(available) - CBook 1\n(available) - CBook 10\n(available) - CBook 11\n(available) - CBook 12\n(available) - CBook 2\n(available) - CBook 3\n(available) - CBook 4\n(available) - CBook 5\n(available) - CBook 6\n(available) - CBook 7\n(available) - CBook 8\n(available) - CBook 9\n(available) - DVD 1\n(available) - DVD 10\n(available) - DVD 11\n(available) - DVD 2\n(available) - DVD 3\n(available) - DVD 4\n(available) - DVD 5\n(available) - DVD 6\n(available) - DVD 7\n(available) - DVD 8\n(available) - DVD 9\n(available) - Videotape 1\n(available) - Videotape 10\n(available) - Videotape 11\n(available) - Videotape 2\n(available) - Videotape 3\n(available) - Videotape 4\n(available) - Videotape 5\n(available) - Videotape 6\n(available) - Videotape 7\n(available) - Videotape 8\n(available) - Videotape 9\n";
	CHECK_EQUAL(expected, actual);
}
//------------------------------------------------------------------------------
TEST_FIXTURE(LibraryHolder, LibraryTestDisplayPatronMedia)
{
	std::stringstream ss;
	m_lib.displayPatronMediaStream("Patron 3", ss);
	string actual = ss.str();
	string expected = "";
	CHECK_EQUAL(expected, actual);
}
//------------------------------------------------------------------------------
TEST_FIXTURE(LibraryHolder, LibraryTestDisplayPatronMedia1)
{
	//std::stringstream ss;
	//m_lib.displayPatronMediaStream("", ss);
	//string actual = ss.str();
	//string expected = "";
	//CHECK_EQUAL(expected, actual);
}
//------------------------------------------------------------------------------
TEST_FIXTURE(LibraryHolder, LibraryTestDisplayPatronMedia2)
{
	//std::stringstream ss;
	//m_lib.displayPatronMediaStream("Bob", ss);
	//string actual = ss.str();
	//string expected = "";
	//CHECK_EQUAL(expected, actual);
}
//------------------------------------------------------------------------------
TEST_FIXTURE(LibraryHolder, LibraryTestIncrementDate)
{
	CHECK_EQUAL(0, m_lib.getDate());
	m_lib.incrementDate();
	CHECK_EQUAL(1, m_lib.getDate());
}
//------------------------------------------------------------------------------
TEST_FIXTURE(LibraryHolder, LibraryTestPrintMenu)
{
	std::ostringstream ss;
	m_lib.printMenuStream(ss);
	string actual = ss.str();
	string expected =
		"\n"
		"LIBRARY\n"
		"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
		"-1-  Checkout Book\n"
		"-2-  Checkin Book\n"
		"-3-  Display Media List\n"
		"-4-  Display Patron List\n"
		"-5-  Display Patron's Media\n"
		"-6-  Increment Date\n"
		"-7-  Save and Quit\n"
		"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
		"Please enter a command: ";
	CHECK_EQUAL(expected, actual);
}
