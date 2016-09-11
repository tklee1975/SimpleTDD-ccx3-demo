#ifdef ENABLE_TDD
//
//  SpriteTest.m
//	TDD Framework
//
//
#include "SpriteTest.h"
#include "TDDHelper.h"
#include "VisibleRect.h"
#include "TDDHelper.h"

void SpriteTest::setUp()
{
	log("TDD Setup is called");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("spritesheet/game.plist");
}


void SpriteTest::tearDown()
{
	log("TDD tearDown is called");
}

void SpriteTest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
	clearChildren();
}

void SpriteTest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}


#pragma mark -
#pragma mark List of Sub Tests

void SpriteTest::defineTests()
{
	ADD_TEST(testColor);
	ADD_TEST(testSkew);
	ADD_TEST(testFrameAnimation);
	ADD_TEST(testSequenceAnimation);
}

#pragma mark -
#pragma mark Sub Test Definition
void SpriteTest::testColor()
{
	log("this is a sample subTest");
	
	Color3B colorList[3] = {
		Color3B::WHITE,
		Color3B::BLUE,
		Color3B::BLACK,
	};

	Vec2 pos = Vec2(VisibleRect::center().x, 100);
	
	for(int i=0; i<3; i++) {
		Color3B color = colorList[i];
		
		Sprite *sprite = Sprite::createWithSpriteFrameName("planeRed1.png");
		sprite->setPosition(pos);
		sprite->setColor(color);
		
		addChild(sprite);

		pos.y += 100;
	}
}


void SpriteTest::testSkew()
{
	log("this is a sample subTest");
	
	
	// SkewX
	Vec2 pos = Vec2(VisibleRect::center().x - 80, 50);
	
	for(int i=0; i<100; i+=20) {
		
		Sprite *sprite = Sprite::createWithSpriteFrameName("planeYellow1.png");
		sprite->setScale(0.4);
		sprite->setPosition(pos);
		sprite->setSkewX(i);
		TDDHelper::addAnchorPoint(sprite);
		
		addChild(sprite);
		
		pos.y += 50;
	}
	
	pos = Vec2(VisibleRect::center().x + 80, 50);
	
	for(int i=0; i<100; i+=20) {
		
		Sprite *sprite = Sprite::createWithSpriteFrameName("planeYellow1.png");
		sprite->setScale(0.4);
		sprite->setPosition(pos);
		sprite->setSkewY(i);
		TDDHelper::addAnchorPoint(sprite);
		
		addChild(sprite);
		
		pos.y += 50;
	}

}

// The test is inspired by the cocos2d-x/SpriteTest.cpp/SpriteAnimationSplit
void SpriteTest::testFrameAnimation()
{
	// define the frames
	auto frame0 = SpriteFrameCache::getInstance()->getSpriteFrameByName("planeYellow1.png");
	auto frame1 = SpriteFrameCache::getInstance()->getSpriteFrameByName("planeYellow2.png");
	
	// define the sprite
	auto sprite = Sprite::createWithSpriteFrame(frame0);
	sprite->setPosition(VisibleRect::center());
	addChild(sprite);
	
	// make the animation
	Vector<SpriteFrame*> animFrames(2);
	animFrames.pushBack(frame0);
	animFrames.pushBack(frame1);
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.2f);
	auto animate = Animate::create(animation);

	
	sprite->runAction(RepeatForever::create(animate));
}


void SpriteTest::testSequenceAnimation()
{
	auto texture = Director::getInstance()->getTextureCache()->addImage("spritesheet/character.png");
	
	// define the frames
	float frameW = 64; float frameH = 64;
	int numFrame = 9;
	Vector<SpriteFrame *> frameList;
	for(int i=0; i<numFrame; i++) {
		auto frame = SpriteFrame::createWithTexture(texture, Rect(frameW*i, frameH*10, frameW, frameH));
		frameList.pushBack(frame);
	}
	
	// define the sprite
	auto sprite = Sprite::createWithSpriteFrame(frameList.at(0));
	sprite->setPosition(VisibleRect::center());
	addChild(sprite);
	
	// make the animation
//	Vector<SpriteFrame*> animFrames(numFrame);
//	animFrames.pushBack(frame0);
//	animFrames.pushBack(frame1);
	auto animation = Animation::createWithSpriteFrames(frameList, 0.1f);
	auto animate = Animate::create(animation);
	
	
	sprite->runAction(RepeatForever::create(animate));
}

#endif
