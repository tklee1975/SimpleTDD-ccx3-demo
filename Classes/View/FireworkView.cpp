//
//  FireworkView.cpp
//  SimpleTDDDemo
//
//  Created by Ken Lee on 26/12/2016.
//
//

#include "FireworkView.h"
#include "cocostudio/CocoStudio.h"


using namespace cocos2d::ui;


FireworkView::FireworkView()
{
	
}

bool FireworkView::init()
{
	if(Layout::init() == false) {
		return false;
	}
	
	std::string csb = "gui/FireworkView.csb";
	setupCsb(csb);
	
	
	return true;
}


void FireworkView::setupCsb(const std::string &csbName)
{
	Node *rootNode = CSLoader::createNode(csbName);
	addChild(rootNode);
	
	setContentSize(rootNode->getContentSize());		// update the layout size based on the CSB size
	
	
}

