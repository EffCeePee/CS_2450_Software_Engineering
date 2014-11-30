#include "UnitTest++.h"
#include "Patron.h"

//------------------------------------------------------------------------------
// \brief Test the default values returned by public methods of Patron class.
//------------------------------------------------------------------------------
TEST(PatronDefaultsTest)
{
	Patron p;

	CHECK_EQUAL(false, p.canCheckout(""));
	CHECK_EQUAL(true, p.isType(""));
	CHECK_EQUAL("", p.printName());
	vector<string> media = p.printMedia();
	CHECK_ARRAY_EQUAL(vector<string>(), media, media.size());
}
//------------------------------------------------------------------------------
TEST(PatronTestAdult)
{
	Patron p("Patron 4", "adult", std::vector<string>());

	CHECK_EQUAL(true, p.canCheckout("adult"));
	CHECK_EQUAL(true, p.canCheckout("childrens"));
	CHECK_EQUAL(true, p.isType("adult"));
	CHECK_EQUAL(false, p.isType("child"));
	CHECK_EQUAL("Patron 4", p.printName());
	vector<string> media = p.printMedia();
	CHECK_ARRAY_EQUAL(vector<string>(), media, media.size());
}
//------------------------------------------------------------------------------
TEST(PatronTestChild)
{
	Patron p("Patron 38", "child", std::vector<string>());

	CHECK_EQUAL(false, p.canCheckout("adult"));
	CHECK_EQUAL(true, p.canCheckout("childrens"));
	CHECK_EQUAL(false, p.isType("adult"));
	CHECK_EQUAL(true, p.isType("child"));
	CHECK_EQUAL("Patron 38", p.printName());
	vector<string> media = p.printMedia();
	CHECK_ARRAY_EQUAL(vector<string>(), media, media.size());
}
//------------------------------------------------------------------------------
TEST(PatronTestPrintMedia)
{
	std::vector<string> mediaIn = { "Book 1", "Book 2" };
	Patron p("Patron 4", "adult", mediaIn);

	vector<string> mediaOut = p.printMedia();
	CHECK_ARRAY_EQUAL(mediaIn, mediaOut, mediaIn.size());
}
//------------------------------------------------------------------------------
TEST(PatronTestAssignMedia)
{
	std::vector<string> mediaIn = { "Book 1", "Book 2" };
	Patron p("Patron 38", "child", mediaIn);

	p.assignMedia("Book 3");
	vector<string> expected = { "Book 1", "Book 2", "Book 3" };
	vector<string> mediaOut = p.printMedia();
	CHECK_ARRAY_EQUAL(expected, mediaOut, mediaOut.size());
}
//------------------------------------------------------------------------------
TEST(PatronTestRemoveMedia)
{
	std::vector<string> mediaIn = { "Book 1", "Book 2" };
	Patron p("Patron 38", "child", mediaIn);

	p.removeMedia("Book 1");
	vector<string> expected = { "Book 2" };
	vector<string> mediaOut = p.printMedia();
	CHECK_ARRAY_EQUAL(expected, mediaOut, mediaOut.size());
}
//------------------------------------------------------------------------------
TEST(PatronTestRemoveMedia2)
{
	std::vector<string> mediaIn = { "Book 1", "Book 2" };
	Patron p("Patron 38", "child", mediaIn);

	p.removeMedia("Book 77");
	vector<string> expected = { "Book 1", "Book 2" };
	vector<string> mediaOut = p.printMedia();
	CHECK_ARRAY_EQUAL(expected, mediaOut, mediaOut.size());
}
//------------------------------------------------------------------------------
TEST(PatronTestParseOutput)
{
	std::vector<string> mediaIn = { "Book 1", "Book 2" };
	Patron p("Patron 38", "child", mediaIn);

	vector<string> mediaOut = p.printMedia();
	CHECK_ARRAY_EQUAL(mediaIn, mediaOut, mediaOut.size());

	string expected = "Patron 38,child,Book 1,Book 2\n";
	string actual = p.parseOutput();
	CHECK_EQUAL(expected, actual);
}
//------------------------------------------------------------------------------
/// \brief Adults can checkout 6 items
TEST(PatronTestLimits)
{
	std::vector<string> mediaIn = { "Book 1", "Book 2", "Book 3", "Book 4", "Book 5", "Book 6"};
	Patron p("Patron 38", "adult", mediaIn);

	CHECK_EQUAL(false, p.canCheckout("adult"));
}
//------------------------------------------------------------------------------
/// \brief Adults can checkout 6 items
TEST(PatronTestLimits2)
{
	std::vector<string> mediaIn = { "Book 1", "Book 2", "Book 3", "Book 4", "Book 5"};
	Patron p("Patron 38", "adult", mediaIn);

	CHECK_EQUAL(true, p.canCheckout("adult"));
}
//------------------------------------------------------------------------------
/// \brief Children can checkout 3 items
TEST(PatronTestLimits3)
{
	std::vector<string> mediaIn = { "Book 1", "Book 2", "Book 3" };
	Patron p("Patron 38", "child", mediaIn);

	CHECK_EQUAL(false, p.canCheckout("childrens"));
}
//------------------------------------------------------------------------------
/// \brief Children can checkout 3 items
TEST(PatronTestLimits4)
{
	std::vector<string> mediaIn = { "Book 1", "Book 2"};
	Patron p("Patron 38", "child", mediaIn);

	CHECK_EQUAL(true, p.canCheckout("childrens"));
}