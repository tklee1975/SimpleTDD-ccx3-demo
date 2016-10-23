#ifdef ENABLE_TDD
//
//  SpaceShipTest.m
//	TDD Framework
//
//
#include "SpaceShipTest.h"
#include "TDDHelper.h"
#include "SpaceShipScene.h"
#include "VisibleRect.h"

void SpaceShipTest::setUp()
{
	log("TDD Setup is called");
	mLayer = nullptr;
	
	setupTouchListener();
	
	testSample();
	setMenuVisible(false);
}



void SpaceShipTest::tearDown()
{
	log("TDD tearDown is called");
}

void SpaceShipTest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
}

void SpaceShipTest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}



#pragma mark - Touch Handling

void SpaceShipTest::setupTouchListener()
{
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(SpaceShipTest::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(SpaceShipTest::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(SpaceShipTest::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(SpaceShipTest::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

bool SpaceShipTest::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	if(mLayer) {
		mLayer->setShipRotationByTouchLocation(touch->getLocation());
	}
	return true;
}

void SpaceShipTest::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
	// Vec2 currentPos = touch->getLocation();
	
}

void SpaceShipTest::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
	//    GameWorld::instance()->activateFeverMode();
	
}

void SpaceShipTest::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event)
{
}


#pragma mark -
#pragma mark List of Sub Tests

void SpaceShipTest::defineTests()
{
	ADD_TEST(testSample);
	ADD_TEST(testChangeFrame);
	ADD_TEST(testRotation);
	ADD_TEST(testRotationByPos);
	ADD_TEST(testSetSpeed);
}

#pragma mark -
#pragma mark Sub Test Definition
void SpaceShipTest::testSample()
{
	
	auto layer = SpaceShipSceneLayer::create();
	addChild(layer);
	
	mLayer = layer;
}

void SpaceShipTest::testChangeFrame()
{
	static int frame = 0;
	
	if(mLayer) {
		mLayer->setShipFrame(frame);
	}
	
	
	frame = (frame + 1) % 2;
}

void SpaceShipTest::testRotation()
{
	static int rotation = 0;
	
	if(mLayer) {
		log("Setting ship rotation=%d", rotation);
		mLayer->setShipRotation(rotation);
	}
	
	rotation += 10;
}


void SpaceShipTest::testRotationByPos()
{
	static int index = 0;
	const int numPos = 4;
	
	Vec2 touchPos[numPos] = {
		Vec2::ZERO,
		VisibleRect::leftTop(),
		VisibleRect::rightTop(),
		VisibleRect::rightBottom(),
	};
	
	if(mLayer) {
		mLayer->setShipRotationByTouchLocation(touchPos[index]);
	}

	
	index = (index + 1) % numPos;
}


void SpaceShipTest::testSetSpeed()
{
	if(! mLayer) {
		return;
	}
	
	mLayer->setSpeed(30);
}

#endif
