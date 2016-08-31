#ifdef ENABLE_TDD
//
//  CocosGUITest.m
//	TDD Framework
//
//
#include "CocosGUITest.h"
#include "TDDHelper.h"

#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

using namespace cocos2d::ui;

void CocosGUITest::setUp()
{
	log("TDD Setup is called");
}


void CocosGUITest::tearDown()
{
	log("TDD tearDown is called");
}

void CocosGUITest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
}

void CocosGUITest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}


#pragma mark -
#pragma mark List of Sub Tests

void CocosGUITest::defineTests()
{
	ADD_TEST(testGUI);
}

#pragma mark -
#pragma mark Sub Test Definition
void CocosGUITest::testGUI()
{
	Node *rootNode = CSLoader::createNode("gui/GUITest.csb");
	addChild(rootNode);
}


#endif
