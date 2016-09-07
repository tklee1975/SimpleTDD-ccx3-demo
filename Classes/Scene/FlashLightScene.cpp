//
//  FlashLightScene.cpp
//  SimpleTDDDemo
//
//  Created by Ken Lee on 7/9/2016.
//
//

#include "FlashLightScene.h"

#include "VisibleRect.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "SimpleTDD.h"
#include "ViewHelper.h"

using namespace cocostudio::timeline;

const Color4B kBgColor = Color4B(0x44, 0x88, 0xcc, 0xff);				//  0x4488cc;


Scene *FlashLightSceneLayer::createScene()
{
	// 'scene' is an autorelease object
	Scene *scene = Scene::create();
	
	// 'layer' is an autorelease object
	auto layer = FlashLightSceneLayer::create();
	scene->addChild(layer);
	
	
	// return the scene
	return scene;
	
}

FlashLightSceneLayer::FlashLightSceneLayer()
: mMaskSprite(nullptr)
{
	
}

bool FlashLightSceneLayer::init()
{
	Size contentSize = VisibleRect::getVisibleRect().size;
	if(LayerColor::initWithColor(kBgColor, contentSize.width, contentSize.height) == false) {
		return false;
	}
	
	mMaskPosition = VisibleRect::center();
	
	setupCharacters();
	setupMask();
	
	setupTouchListener();
	
	return true;
}


void FlashLightSceneLayer::setupCharacters()
{
	Sprite *player = Sprite::create("game_mech/player.png");
	player->setPosition(VisibleRect::center());
	
	addChild(player);
}

// note: the following code is based on the sample code in FlashLighText.testMaskUsingBlend
void FlashLightSceneLayer::setupMask()
{

	
	// Create the sprite for Blend
	Sprite *sprite = Sprite::createWithTexture(getMaskTexture());
	sprite->setFlippedY(true);
	sprite->setPosition(VisibleRect::center());
	sprite->setBlendFunc(BlendFunc{GL_ONE_MINUS_SRC_ALPHA, GL_SRC_COLOR});	// it similar to MULTIPLY blend
	addChild(sprite);
	
	mMaskSprite = sprite;
	
	// Update the sprite content
	updateMaskPosition();
}

Texture2D *FlashLightSceneLayer::getMaskTexture()
{
	DrawNode *drawNode = DrawNode::create();
	drawNode->drawSolidRect(Vec2(0, 0), VisibleRect::rightTop(), Color4F(0.5, 0.5, 0.5, 1));	// shadow area
	drawNode->drawSolidCircle(mMaskPosition, 50, 0, 50, 1, 1, Color4F::WHITE);					// light area
	
	Size textureSize = getContentSize();
	
	RenderTexture *texture = RenderTexture::create(textureSize.width, textureSize.height, Texture2D::PixelFormat::RGBA8888);
	
	texture->begin();
	drawNode->visit();
	texture->end();	// New texture created!!!
	
	
	return texture->getSprite()->getTexture();
}

void FlashLightSceneLayer::updateMaskPosition()		// update the mask visuall
{
	if(mMaskSprite == nullptr) {
		return;
	}
	
	// Create the mask texture using DrawNode
	mMaskSprite->setTexture(getMaskTexture());

	mMaskSprite->setBlendFunc(BlendFunc{GL_ONE_MINUS_SRC_ALPHA, GL_SRC_COLOR});
}


void FlashLightSceneLayer::onEnter()
{
	Layer::onEnter();
	
	Director::getInstance()->setDisplayStats(true);
}



#pragma mark - Touch Handling

void FlashLightSceneLayer::setupTouchListener()
{
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(FlashLightSceneLayer::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(FlashLightSceneLayer::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(FlashLightSceneLayer::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(FlashLightSceneLayer::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

bool FlashLightSceneLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	return true;
}

void FlashLightSceneLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
	Vec2 currentPos = touch->getLocation();
	
	// Make some offset	// for the big finger
	currentPos.y += 40;

	setMaskPosition(currentPos);
	
	updateMaskPosition();
}

void FlashLightSceneLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
	//    GameWorld::instance()->activateFeverMode();
	
}

void FlashLightSceneLayer::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event)
{
}

