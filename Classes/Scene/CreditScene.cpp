//
//  CreditScene.cpp
//  SimpleTDDDemo
//
//  Created by Ken Lee on 11/9/2016.
//
//

#include "CreditScene.h"


#include "VisibleRect.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "ViewHelper.h"

using namespace cocostudio::timeline;


Scene *CreditSceneLayer::createScene()
{
	// 'scene' is an autorelease object
	Scene *scene = Scene::create();
	
	// 'layer' is an autorelease object
	CreditSceneLayer *layer = CreditSceneLayer::create();
	scene->addChild(layer);
	
	
	// return the scene
	return scene;
	
}

CreditSceneLayer::CreditSceneLayer()
{
	
}

bool CreditSceneLayer::init()
{
	if(Layer::init() == false) {
		return false;
	}
	
	setupUI("CreditScene.csb");
	
	return true;
}


void CreditSceneLayer::setupUI(const std::string &csbName)
{
	// Create the node
	Node *rootNode = CSLoader::createNode(csbName);
	addChild(rootNode);
	FIX_UI_LAYOUT(rootNode);
	
	Button *button;
	button = (Button *) rootNode->getChildByName("topPanel")->getChildByName("backButton");
	button->addClickEventListener([&](Ref *) {
		Director::getInstance()->popScene();
	});

}


void CreditSceneLayer::onEnter()
{
	Layer::onEnter();
	
	Director::getInstance()->setDisplayStats(false);
}