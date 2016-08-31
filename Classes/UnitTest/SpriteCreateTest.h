#ifdef ENABLE_TDD
//
//  SpriteCreateTest.h
//
//
#ifndef __TDD_SpriteCreateTest__
#define __TDD_SpriteCreateTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration
class SpriteCreateTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	virtual void willRunTest(const std::string &name);	// before run a test
	virtual void didRunTest(const std::string &name);	// after run a test
	
private:
	void createByFile();
	void createByFrame();
	void createByTexture();
};

#endif

#endif
