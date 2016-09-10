#ifdef ENABLE_TDD
//
//  FlashLightTest.m
//	TDD Framework
//
//	Reference Source:
//		http://gamemechanicexplorer.com/#lighting-1
//
#include "FlashLightTest.h"
#include "TDDHelper.h"
#include "VisibleRect.h"
#include "FlashLightScene.h"

void FlashLightTest::setUp()
{
	log("TDD Setup is called");
	
//	setMenuSize(Size(120, VisibleRect::getVisibleRect().size.height));
}


void FlashLightTest::tearDown()
{
	log("TDD tearDown is called");
}

void FlashLightTest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
}

void FlashLightTest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}


#pragma mark -
#pragma mark List of Sub Tests

void FlashLightTest::defineTests()
{
	ADD_TEST(testSprite);
	ADD_TEST(testDrawCircle);
	ADD_TEST(testMaskUsingBlend);
	ADD_TEST(testScene);
	ADD_TEST(testUpdateMaskPos);
	ADD_TEST(testAddRandomCharacter);
}

#pragma mark -
#pragma mark Sub Test Definition
void FlashLightTest::testSprite()
{
	Sprite *player = Sprite::create("game_mech/player.png");
	player->setPosition(Vec2(100, 100));
	
	addChild(player);
}

void FlashLightTest::testDrawCircle()
{
	DrawNode *drawNode = DrawNode::create();
	
	drawNode->drawSolidRect(Vec2(0, 0), VisibleRect::rightTop(), Color4F::BLACK);
	drawNode->drawSolidCircle(VisibleRect::center(), 50, 0, 50, 1, 1, Color4F::WHITE);

	addChild(drawNode);
}


void FlashLightTest::testMaskUsingBlend()
{
	Sprite *player = Sprite::create("game_mech/player.png");
	player->setScale(3);
	player->setPosition(VisibleRect::center());
	
	addChild(player);

	// kencoder: the following is the testing code while developing
	// USing Sprite
//	// blurred-circle.png
//	Sprite *mask = Sprite::create("game_mech/blurred-circle.png");
//	mask->setScale(0.5);
//	mask->setPosition(VisibleRect::center());
//	mask->setBlendFunc(BlendFunc{GL_ONE_MINUS_SRC_ALPHA, GL_SRC_COLOR});
//	addChild(mask);

//	// The Mask
//	auto stencil = DrawNode::create();
//	stencil->drawSolidRect(Vec2(0, 0), VisibleRect::rightTop(), Color4F::BLACK);
//	stencil->drawSolidCircle(VisibleRect::center(), 30, 0, 50, 1, 1, Color4F::WHITE);
//	
//	
//	auto clipper = ClippingNode::create();
//	clipper->setStencil(stencil);
//	clipper->addChild(player);
//	addChild(clipper);

	DrawNode *drawNode = DrawNode::create();
	drawNode->drawSolidRect(Vec2(0, 0), VisibleRect::rightTop(), Color4F(0.5, 0.5, 0.5, 1));
	drawNode->drawSolidCircle(VisibleRect::center(), 50, 0, 50, 1, 1, Color4F::WHITE);
	drawNode->visit();

	Size textureSize = VisibleRect::getVisibleRect().size;
	
	RenderTexture *texture = RenderTexture::create(textureSize.width, textureSize.height, Texture2D::PixelFormat::RGBA8888);
	
	texture->begin();
	drawNode->visit();
	texture->end();
	
	Rect rect = Rect(Vec2(0, 0), textureSize);
	Sprite *sprite = Sprite::createWithTexture(texture->getSprite()->getTexture());
	sprite->setFlippedY(true);
	sprite->setPosition(VisibleRect::center());
	sprite->setBlendFunc(BlendFunc{GL_ONE_MINUS_SRC_ALPHA, GL_SRC_COLOR});
	addChild(sprite);

	
}

void FlashLightTest::testScene()
{
	FlashLightSceneLayer *layer = FlashLightSceneLayer::create();
	
	addChild(layer);
	
	mLayer = layer;
}

void FlashLightTest::testUpdateMaskPos()
{
	if(mLayer == nullptr) {
		log("Run testScene first");
		return;
	}
	
	Vec2 pos = mLayer->getMaskPosition();
	pos += Vec2(10, 15);
	
	mLayer->setMaskPosition(pos);
	mLayer->updateMaskPosition();
}

void FlashLightTest::testAddRandomCharacter()
{
	//if(m)
	//void testAddRandomCharacter();
	if(mLayer == nullptr) {
		log("Run testScene first");
		return;
	}
	
	mLayer->addRandomCharacter();
}

#endif
