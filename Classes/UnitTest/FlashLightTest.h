#ifdef ENABLE_TDD
//
//  FlashLightTest.h
//
//
#ifndef __TDD_FlashLightTest__
#define __TDD_FlashLightTest__

// Include Header

#include "TDDBaseTest.h"

class FlashLightSceneLayer;

// Class Declaration
class FlashLightTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	virtual void willRunTest(const std::string &name);	// before run a test
	virtual void didRunTest(const std::string &name);	// after run a test
	
private:
	void testSprite();
	void testDrawCircle();
	void testMaskUsingBlend();
	void testScene();
	void testUpdateMaskPos();

private:
	FlashLightSceneLayer *mLayer;
	
};

#endif

#endif
