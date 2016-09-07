#ifdef ENABLE_TDD
//
//  MainSceneTest.m
//	TDD Framework
//
//
#include "MainSceneTest.h"
#include "TDDHelper.h"
#include "MainScene.h"

void MainSceneTest::setUp()
{
	log("TDD Setup is called");
}


void MainSceneTest::tearDown()
{
	log("TDD tearDown is called");
}

void MainSceneTest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
}

void MainSceneTest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}


#pragma mark -
#pragma mark List of Sub Tests

void MainSceneTest::defineTests()
{
	ADD_TEST(testSceneLayer);
}

#pragma mark -
#pragma mark Sub Test Definition
void MainSceneTest::testSceneLayer()
{
	log("this is a sample subTest");
	MainSceneLayer *layer = MainSceneLayer::create();
	
	
	addChild(layer);
	
	hideMenu();
}


#endif
