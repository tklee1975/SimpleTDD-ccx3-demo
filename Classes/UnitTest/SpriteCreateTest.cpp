#ifdef ENABLE_TDD
//
//  SpriteCreateTest.m
//	TDD Framework
//
//
#include "SpriteCreateTest.h"
#include "TDDHelper.h"
#include "VisibleRect.h"

void SpriteCreateTest::setUp()
{
	log("TDD Setup is called");
}


void SpriteCreateTest::tearDown()
{
	log("TDD tearDown is called");
}

void SpriteCreateTest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
	clearChildren();
}

void SpriteCreateTest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}


#pragma mark -
#pragma mark List of Sub Tests

void SpriteCreateTest::defineTests()
{
	ADD_TEST(createByFile);
	ADD_TEST(createByFrame);
	ADD_TEST(createByTexture);
}

#pragma mark -
#pragma mark Sub Test Definition
void SpriteCreateTest::createByFile()
{
	Sprite *sprite = Sprite::create("image/simpleTDD-icon.png");
	sprite->setScale(0.3);
	sprite->setPosition(VisibleRect::center());
	
	addChild(sprite);
}

void SpriteCreateTest::createByFrame()
{
	// Load the spritesheet first
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("spritesheet/game.plist");
	
	// planeBlue1.png
	Sprite *sprite = Sprite::createWithSpriteFrameName("planeRed1.png");
	sprite->setPosition(VisibleRect::center());
	
	addChild(sprite);
}

void SpriteCreateTest::createByTexture()
{
	// TODO
	
//	// Load the spritesheet first
//	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("spritesheet/game.plist");
//	
//	// planeBlue1.png
//	Sprite *sprite = Sprite::createWithSpriteFrameName("planeRed1.png");
//	sprite->setPosition(VisibleRect::center());
//	
//	addChild(sprite);
}

#endif
