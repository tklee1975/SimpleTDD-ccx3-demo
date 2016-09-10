//
//  SpaceShipScene.cpp
//  SimpleTDDDemo
//
//  Created by Ken Lee on 8/9/2016.
//
//

#include "SpaceShipScene.h"

#include "VisibleRect.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "SimpleTDD.h"
#include "ViewHelper.h"
#include "GeometryHelper.h"


using namespace cocostudio::timeline;

const Color4B kBgColor = Color4B(0x44, 0x88, 0xcc, 0xff);				//  0x4488cc;


Scene *SpaceShipSceneLayer::createScene()
{
	// 'scene' is an autorelease object
	Scene *scene = Scene::create();
	
	// 'layer' is an autorelease object
	auto layer = SpaceShipSceneLayer::create();
	scene->addChild(layer);
	
	
	// return the scene
	return scene;
	
}

SpaceShipSceneLayer::SpaceShipSceneLayer()
: mShipSprite(nullptr)
, mCurrentAccel(0)
, mAcceleration(50)
, mDeceleration(-50)
, mSpeed(0)
, mMaxSpeed(100)
, mActive(false)
{
	
}

bool SpaceShipSceneLayer::init()
{
	Size contentSize = VisibleRect::getVisibleRect().size;
	if(LayerColor::initWithColor(kBgColor, contentSize.width, contentSize.height) == false) {
		return false;
	}
	
	setupCharacter();
	setupGUI();
	
	
	setupTouchListener();
	
	return true;
}


void SpaceShipSceneLayer::setupGUI()
{
	Button *button = Button::create();
	button->setTitleText("back");
	button->setTitleFontSize(15);
	button->setPosition(Vec2(300, 50));
	button->addClickEventListener([&](Ref *) {
		Director::getInstance()->popScene();
	});
	
	addChild(button);
}

void SpaceShipSceneLayer::setupCharacter()
{
	Texture2D *texture = Director::getInstance()->getTextureCache()->addImage("game_mech/ship.png");
	
	float grid = texture->getContentSizeInPixels().width;
	
	// define the frames
	mSpriteFrames.clear();
	for(int i=0; i<3; i++) {
		SpriteFrame *frame = SpriteFrame::createWithTexture(texture, Rect(0, i * grid, grid, grid));
		mSpriteFrames.pushBack(frame);
	}

	Sprite *sprite = Sprite::create();
	sprite->setPosition(VisibleRect::center());
	addChild(sprite);
	
	mShipSprite = sprite;
	
	
	// Set the frame
	setShipFrame(0);
}


void SpaceShipSceneLayer::onEnter()
{
	Layer::onEnter();
	
	Director::getInstance()->setDisplayStats(true);
	
	scheduleUpdate();
}

void SpaceShipSceneLayer::onExit()
{
	unscheduleUpdate();
	
	Layer::onExit();
}


#pragma mark - Touch Handling

void SpaceShipSceneLayer::setupTouchListener()
{
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(SpaceShipSceneLayer::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(SpaceShipSceneLayer::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(SpaceShipSceneLayer::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(SpaceShipSceneLayer::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

bool SpaceShipSceneLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	setActive(true);
	
	Vec2 currentPos = touch->getLocation();
	setShipRotationByTouchLocation(currentPos);
	
	return true;
}

void SpaceShipSceneLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
	Vec2 currentPos = touch->getLocation();
	setShipRotationByTouchLocation(currentPos);
}

void SpaceShipSceneLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
	setActive(false);
}

void SpaceShipSceneLayer::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event)
{
	setActive(false);
}


void SpaceShipSceneLayer::setShipFrame(int frame)
{
	if(mShipSprite) {
		mShipSprite->setSpriteFrame(mSpriteFrames.at(frame));
	}
}

void SpaceShipSceneLayer::setShipRotation(float rotation)
{
	if(mShipSprite) {
		mShipSprite->setRotation(rotation);
	}
}


void SpaceShipSceneLayer::setShipRotationByTouchLocation(const Vec2 &pos)
{
	if(! mShipSprite) {
		return;
	}
	
	int rotation = (int) GeometryHelper::findAngleDegree(mShipSprite->getPosition(), pos);
	setShipRotation((360 -rotation) % 360);
	
	
}

void SpaceShipSceneLayer::update(float delta)
{

	updateSpeed(delta);
	updatePosition(delta);
}

void SpaceShipSceneLayer::updateSpeed(float delta)
{
	float newSpeed = mSpeed + delta * (float) mCurrentAccel;
	if(newSpeed > mMaxSpeed) {
		newSpeed = mMaxSpeed;
	}else if(newSpeed < 0) {
		newSpeed = 0;
	}
	
	mSpeed = newSpeed;
	// log("newSpeed=%f", mSpeed);
}

void SpaceShipSceneLayer::updatePosition(float delta)
{
	if(! mShipSprite) {
		return;
	}
	
	float angleRadian = CC_DEGREES_TO_RADIANS(mShipSprite->getRotation());
	Vec2 speedVec = GeometryHelper::resolveVec2(mSpeed, angleRadian);
	speedVec.y *= -1;	// fix anti clockwise issue
	
	Vec2 pos = mShipSprite->getPosition() + speedVec * delta;
	
	mShipSprite->setPosition(pos);
}


void SpaceShipSceneLayer::setActive(bool flag)
{
	mActive = flag;
	
	if(mActive) {
		setShipFrame(1);
		setCurrentAccel(mAcceleration);
	} else {
		setShipFrame(0);
		setCurrentAccel(mDeceleration);
	}
}