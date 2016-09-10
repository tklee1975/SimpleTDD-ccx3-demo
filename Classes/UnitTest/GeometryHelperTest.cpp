#ifdef ENABLE_TDD
//
//  GeometryHelperTest.m
//	TDD Framework
//
//
#include "GeometryHelperTest.h"
#include "TDDHelper.h"

void GeometryHelperTest::setUp()
{
	log("TDD Setup is called");
}


void GeometryHelperTest::tearDown()
{
	log("TDD tearDown is called");
}

void GeometryHelperTest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
}

void GeometryHelperTest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}


#pragma mark -
#pragma mark List of Sub Tests

void GeometryHelperTest::defineTests()
{
	ADD_TEST(testSample);
}

#pragma mark -
#pragma mark Sub Test Definition
void GeometryHelperTest::testSample()
{
	log("this is a sample subTest");
}


#endif
