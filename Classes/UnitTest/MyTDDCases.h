//
//  MyTDDCases.h
//  Cocos2dxTDDLib
//
//	This header should be included by TDDCases.h only
//  Created by Ken Lee on 25/5/14.
//
//


// Add the Header here!
#include "TDD2SampleTest.h"
#include "CocosGUITest.h"
#include "SpriteCreateTest.h"
#include "SpriteTest.h"
#include "MainSceneTest.h"
#include "FlashLightTest.h"
#include "SpaceShipTest.h"
#include "FireworkViewTest.h"

//#include#
// NOTE!!! The above line is used to generate new unit test, must not be removed.

// Define
TDD_CASES
{
	TEST(SpriteTest),
	TEST(FireworkViewTest),
	TEST(SpaceShipTest),
	TEST(SpriteCreateTest),
	TEST(CocosGUITest),
	TEST(TDD2SampleTest),
	TEST(MainSceneTest),
	TEST(FlashLightTest),
	
	
//#testcase#
// NOTE!!! The above line is used to generate new unit test, must not be removed.
};


