#ifdef ENABLE_TDD
//
//  SpaceShipTest.h
//
//
#ifndef __TDD_SpaceShipTest__
#define __TDD_SpaceShipTest__

// Include Header

#include "TDDBaseTest.h"

class SpaceShipSceneLayer;

// Class Declaration
class SpaceShipTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	virtual void willRunTest(const std::string &name);	// before run a test
	virtual void didRunTest(const std::string &name);	// after run a test
	
	
#pragma mark - Touch Handling
private:
	void setupTouchListener();
	
	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);
	
	
private:
	void testSample();
	void testChangeFrame();
	void testRotation();
	void testRotationByPos();
	void testSetSpeed();
private:
	SpaceShipSceneLayer *mLayer;
};

#endif

#endif
