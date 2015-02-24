#ifdef ENABLE_TDD
//
//  Example1Test.h
//
//
#ifndef __TDD_Example1Test__
#define __TDD_Example1Test__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class Example1Test : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void subTest(Ref *sender);
	void testSpriteRotate(Ref *sender);
}; 

#endif

#endif
