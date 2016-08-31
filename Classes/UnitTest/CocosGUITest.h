#ifdef ENABLE_TDD
//
//  CocosGUITest.h
//
//
#ifndef __TDD_CocosGUITest__
#define __TDD_CocosGUITest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration
class CocosGUITest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	virtual void willRunTest(const std::string &name);	// before run a test
	virtual void didRunTest(const std::string &name);	// after run a test
	
private:
	void testGUI();
};

#endif

#endif
