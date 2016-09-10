//
//  SpaceShipScene.hpp
//  SimpleTDDDemo
//
//	Features:
//		- move the ship by touch the screen
//			(touch down to accelerate the ship)	-> active mode
//			(touch up to stop acceleration)
//		- the ship will warp around the bound
//
//	Requirement:
//		- When Active:
//			- acceleration to defined value
//			- the flame is shown
//		- When InActive:
//			- become deccelerate
//			- the flame is not shown
//		- When update
//			- change the velocity based on the current acceleration
//			- change the position based on the velocity
//
//
//
//	Work Breakdown:
//		- Show the Ship
//			- toggle between frame0: no flame  frame1: with flame
//		- Change ship direction, speed and acceleration
//
//
//
//  Created by Ken Lee on 8/9/2016.
//
//

#ifndef SpaceShipScene_hpp
#define SpaceShipScene_hpp

#include <stdio.h>

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include <time.h>

// Namespace stuff
USING_NS_CC_EXT;
USING_NS_CC;
using namespace cocos2d::ui;

class SpaceShipSceneLayer : public LayerColor {
public:
	// returns a Scene that contains the HelloWorld as the only child
	static Scene *createScene();
	
	CREATE_FUNC(SpaceShipSceneLayer);
	
	CC_SYNTHESIZE(int, mAcceleration, Acceleration);
	CC_SYNTHESIZE(int, mDeceleration, Deceleration);
	CC_SYNTHESIZE(float, mMaxSpeed, MaxSpeed);
	CC_SYNTHESIZE(int, mCurrentAccel, CurrentAccel);
	CC_SYNTHESIZE(float, mSpeed, Speed);		// current Speed
	
	//
	SpaceShipSceneLayer();
	
	virtual bool init();
	
	virtual void onEnter();
	virtual void onExit();
	
	void setShipFrame(int frame);
	
	void setShipRotation(float rotation);
	void setShipRotationByTouchLocation(const Vec2 &pos);
	
	void setActive(bool flag);
	
protected:
	void setupCharacter();
	void setupGUI();
	
	
	virtual void update(float delta);
	virtual void updateSpeed(float delta);
	virtual void updatePosition(float delta);
	
#pragma mark - Touch Handling
private:
	void setupTouchListener();
	
	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);
	
	
protected:
	Sprite *mShipSprite;
	Vector<SpriteFrame *> mSpriteFrames;

	bool mEnable;
	bool mActive;
	
};



#endif /* SpaceShipScene_hpp */
