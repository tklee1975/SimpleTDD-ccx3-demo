#ifdef ENABLE_TDD
//
//  FireworkViewTest.h
//
//
#ifndef __TDD_FireworkViewTest__
#define __TDD_FireworkViewTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration
class FireworkViewTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	virtual void willRunTest(const std::string &name);	// before run a test
	virtual void didRunTest(const std::string &name);	// after run a test
	
private:
	void testCreate();
};

#endif

#endif
