//
//  MainScene.cpp
//  SimpleTDDDemo
//
//  Created by Ken Lee on 6/9/2016.
//
//

#include "MainScene.h"

#include "VisibleRect.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "SimpleTDD.h"
#include "ViewHelper.h"

using namespace cocostudio::timeline;


Scene *MainSceneLayer::createScene()
{
	// 'scene' is an autorelease object
	Scene *scene = Scene::create();
	
	// 'layer' is an autorelease object
	MainSceneLayer *layer = MainSceneLayer::create();
	scene->addChild(layer);
	
	
	// return the scene
	return scene;
	
}

MainSceneLayer::MainSceneLayer()
{
	
}

bool MainSceneLayer::init()
{
	if(Layer::init() == false) {
		return false;
	}
	
	setupUI("MainScene.csb");
	
	return true;
}


void MainSceneLayer::setupUI(const std::string &csbName)
{
	// Create the node
	Node *rootNode = CSLoader::createNode(csbName);
	addChild(rootNode);
	FIX_UI_LAYOUT(rootNode);
	
	Node *mainPanel = (Node *) rootNode->getChildByName("mainPanel");
//	
//	
	Button *button;
 
	button = (Button *) mainPanel->getChildByName("mechanic1Button");
	button->addClickEventListener([&](Ref *) {
		//TDDManager();
		SimpleTDD::gotoTest("FlashLightTest");
	});
//
//	
//	button = (Button *) mainPanel->getChildByName("gameDataButton");
//	button->addClickEventListener([&](Ref *) {
//		gotoGameData();
//	});
//	
//	// Adding the test button
//	TDDHelper::addTestButton(this, Vec2(100, 80));
//
	Vec2 pos = VisibleRect::bottom() + Vec2(0, 50);
	SimpleTDD::setup(this, pos);
}


void MainSceneLayer::onEnter()
{
	Layer::onEnter();
	
	Director::getInstance()->setDisplayStats(false);
}