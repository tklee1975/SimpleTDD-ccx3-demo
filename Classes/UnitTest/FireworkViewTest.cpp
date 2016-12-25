#ifdef ENABLE_TDD
//
//  FireworkViewTest.m
//	TDD Framework
//
//
#include "FireworkViewTest.h"
#include "TDDHelper.h"
#include "FireworkView.h"

void FireworkViewTest::setUp()
{
	log("TDD Setup is called");
	setBackgroundColor(Color3B::BLACK);
}


void FireworkViewTest::tearDown()
{
	log("TDD tearDown is called");
}

void FireworkViewTest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
}

void FireworkViewTest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}


#pragma mark -
#pragma mark List of Sub Tests

void FireworkViewTest::defineTests()
{
	ADD_TEST(testCreate);
}

#pragma mark -
#pragma mark Sub Test Definition
void FireworkViewTest::testCreate()
{
	FireworkView *view = FireworkView::create();
	view->setAnchorPoint(Vec2(0.5, 0.5f));
	view->setPosition(Vec2(250, 160));
	
	addChild(view);
	
}


#endif
