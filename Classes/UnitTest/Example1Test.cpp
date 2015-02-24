#ifdef ENABLE_TDD
//
//  Example1Test.m
//	TDD Framework 
//
//
#include "Example1Test.h"
#include "TDDHelper.h"

void Example1Test::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void Example1Test::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void Example1Test::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(Example1Test::subTest);
	SUBTEST(Example1Test::testSpriteRotate);
}

#pragma mark -
#pragma mark Sub Test Definition
void Example1Test::subTest(Ref *sender)
{
	log("this is a sample subTest");
}

void Example1Test::testSpriteRotate(Ref *sender)
{
	log("testSpriteRotate");
	
	int rotate[3] = {45, 180, 260};
	Vec2 pos = Vec2(80, 100);

	for(int i=0; i<3; i++) {
		Sprite *sprite = Sprite::create("HelloWorld.png");
		sprite->setPosition(pos);
		sprite->setRotation(rotate[i]);
		sprite->setScale(0.5);
		addChild(sprite);
		
		pos.y += 100;
	}
}


#endif
