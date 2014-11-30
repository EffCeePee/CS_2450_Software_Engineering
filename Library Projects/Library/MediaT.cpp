#include "UnitTest++.h"
#include "Media.h"

//------------------------------------------------------------------------------
// \brief Test the default values returned by public methods of Media class.
//------------------------------------------------------------------------------
TEST(MediaDefaultsTest)
{
	Media m;

	CHECK_EQUAL(true, m.isAvailable());
	CHECK_EQUAL(false, m.isStatus(""));
	CHECK_EQUAL(true, m.isType(""));
	CHECK_EQUAL("", m.printName());
	CHECK_EQUAL("", m.printType());
	CHECK_EQUAL("available", m.printStatus());
	CHECK_EQUAL(",,available,0,\n", m.parseOutput());
}
//------------------------------------------------------------------------------
TEST(MediaTest1)
{
	Media m("Media 1", "adult", "available", 0, "");

	CHECK_EQUAL(true, m.isAvailable());
	CHECK_EQUAL(true, m.isStatus("available"));
	CHECK_EQUAL(false, m.isStatus("checkedout"));
	CHECK_EQUAL(true, m.isType("adult"));
	CHECK_EQUAL(false, m.isType("childrens"));
	CHECK_EQUAL(false, m.isType("dvd"));
	CHECK_EQUAL(false, m.isType("videotape"));
	CHECK_EQUAL("Media 1", m.printName());
	CHECK_EQUAL("adult", m.printType());
	CHECK_EQUAL("available", m.printStatus());
	CHECK_EQUAL("Media 1,adult,available,0,\n", m.parseOutput());
}
//------------------------------------------------------------------------------
TEST(MediaTest2)
{
	Media m("War of the Worlds", "childrens", "checkedout", 56, "Tommy Smith");

	CHECK_EQUAL(false, m.isAvailable());
	CHECK_EQUAL(false, m.isStatus("available"));
	CHECK_EQUAL(true, m.isStatus("checkedout"));
	CHECK_EQUAL(false, m.isType("adult"));
	CHECK_EQUAL(true, m.isType("childrens"));
	CHECK_EQUAL(false, m.isType("dvd"));
	CHECK_EQUAL(false, m.isType("videotape"));
	CHECK_EQUAL("War of the Worlds", m.printName());
	CHECK_EQUAL("childrens", m.printType());
	CHECK_EQUAL("checkedout", m.printStatus());
	CHECK_EQUAL("War of the Worlds,childrens,checkedout,56,Tommy Smith\n", m.parseOutput());
}
//------------------------------------------------------------------------------
TEST(MediaTest3)
{
	Media m("War of the Worlds", "childrens", "checkedout", 56, "Tommy Smith");

	m.assignPatron("Bobby Jones");
	CHECK_EQUAL(false, m.isStatus("available"));
	CHECK_EQUAL(true, m.isStatus("checkedout"));
	CHECK_EQUAL(false, m.isType("adult"));
	CHECK_EQUAL(true, m.isType("childrens"));
	CHECK_EQUAL(false, m.isType("dvd"));
	CHECK_EQUAL(false, m.isType("videotape"));
	CHECK_EQUAL("War of the Worlds", m.printName());
	CHECK_EQUAL("childrens", m.printType());
	CHECK_EQUAL("checkedout", m.printStatus());
	CHECK_EQUAL("War of the Worlds,childrens,checkedout,56,Bobby Jones\n", m.parseOutput());
}
//------------------------------------------------------------------------------
TEST(MediaTest4)
{
	Media m("War of the Worlds", "childrens", "checkedout", 56, "Tommy Smith");

	m.removePatron();
	CHECK_EQUAL(true, m.isStatus("available"));
	CHECK_EQUAL(false, m.isStatus("checkedout"));
	CHECK_EQUAL(false, m.isType("adult"));
	CHECK_EQUAL(true, m.isType("childrens"));
	CHECK_EQUAL(false, m.isType("dvd"));
	CHECK_EQUAL(false, m.isType("videotape"));
	CHECK_EQUAL("War of the Worlds", m.printName());
	CHECK_EQUAL("childrens", m.printType());
	CHECK_EQUAL("available", m.printStatus());
	CHECK_EQUAL("War of the Worlds,childrens,available,56,\n", m.parseOutput());
}
//------------------------------------------------------------------------------
TEST(MediaTest5)
{
	Media m("War of the Worlds", "childrens", "checkedout", 56, "Tommy Smith");

	m.updateStatus(0);
	CHECK_EQUAL(false, m.isStatus("available"));
	CHECK_EQUAL(true, m.isStatus("checkedout"));
	CHECK_EQUAL(false, m.isType("adult"));
	CHECK_EQUAL(true, m.isType("childrens"));
	CHECK_EQUAL(false, m.isType("dvd"));
	CHECK_EQUAL(false, m.isType("videotape"));
	CHECK_EQUAL("War of the Worlds", m.printName());
	CHECK_EQUAL("childrens", m.printType());
	CHECK_EQUAL("checkedout", m.printStatus());
	CHECK_EQUAL("War of the Worlds,childrens,checkedout,56,Tommy Smith\n", m.parseOutput());
}
//------------------------------------------------------------------------------
TEST(MediaTest6)
{
	Media m("Media 1", "childrens", "checkedout", 56, "Patron 1");

	m.updateStatus(56 + 6);
	CHECK_EQUAL(true, m.isStatus("checkedout"));

	m.updateStatus(56 + 7);
	CHECK_EQUAL(true, m.isStatus("checkedout"));

	m.updateStatus(56 + 8);
	CHECK_EQUAL(true, m.isStatus("overdue"));
}
//------------------------------------------------------------------------------
TEST(MediaTest7)
{
	Media m("Media 1", "adult", "checkedout", 56, "Patron 1");

	m.updateStatus(56 + 13);
	CHECK_EQUAL(true, m.isStatus("checkedout"));

	m.updateStatus(56 + 14);
	CHECK_EQUAL(true, m.isStatus("checkedout"));

	m.updateStatus(56 + 15);
	CHECK_EQUAL(true, m.isStatus("overdue"));
}
//------------------------------------------------------------------------------
TEST(MediaTest8)
{
	Media m("Media 1", "dvd", "checkedout", 56, "Patron 1");

	m.updateStatus(56 + 1);
	CHECK_EQUAL(true, m.isStatus("checkedout"));

	m.updateStatus(56 + 2);
	CHECK_EQUAL(true, m.isStatus("checkedout"));

	m.updateStatus(56 + 3);
	CHECK_EQUAL(true, m.isStatus("overdue"));
}
//------------------------------------------------------------------------------
TEST(MediaTest9)
{
	Media m("Media 1", "videotape", "checkedout", 56, "Patron 1");

	m.updateStatus(56 + 2);
	CHECK_EQUAL(true, m.isStatus("checkedout"));

	m.updateStatus(56 + 3);
	CHECK_EQUAL(true, m.isStatus("checkedout"));

	m.updateStatus(56 + 4);
	CHECK_EQUAL(true, m.isStatus("overdue"));
}
