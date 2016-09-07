#ifdef ENABLE_TDD
//
//  MainSceneTest.h
//
//
#ifndef __TDD_MainSceneTest__
#define __TDD_MainSceneTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration
class MainSceneTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	virtual void willRunTest(const std::string &name);	// before run a test
	virtual void didRunTest(const std::string &name);	// after run a test
	
private:
	void testSceneLayer();
};

#endif

#endif
