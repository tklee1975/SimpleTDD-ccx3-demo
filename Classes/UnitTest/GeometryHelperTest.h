#ifdef ENABLE_TDD
//
//  GeometryHelperTest.h
//
//
#ifndef __TDD_GeometryHelperTest__
#define __TDD_GeometryHelperTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration
class GeometryHelperTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	virtual void willRunTest(const std::string &name);	// before run a test
	virtual void didRunTest(const std::string &name);	// after run a test
	
private:
	void testSample();
};

#endif

#endif
