#ifdef ENABLE_TDD
//
//  SpriteTest.h
//
//
#ifndef __TDD_SpriteTest__
#define __TDD_SpriteTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration
class SpriteTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	virtual void willRunTest(const std::string &name);	// before run a test
	virtual void didRunTest(const std::string &name);	// after run a test
	
private:
	void testColor();
	void testSkew();
	void testFrameAnimation();
	void testSequenceAnimation();
};

#endif

#endif
