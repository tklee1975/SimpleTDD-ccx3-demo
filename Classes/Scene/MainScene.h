//
//  MainScene.hpp
//  SimpleTDDDemo
//
//  Created by Ken Lee on 6/9/2016.
//
//

#ifndef MainScene_hpp
#define MainScene_hpp

#include <stdio.h>

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include <time.h>

// Namespace stuff
USING_NS_CC_EXT;
USING_NS_CC;
using namespace cocos2d::ui;

class MainSceneLayer : public Layer {
public:
	// returns a Scene that contains the HelloWorld as the only child
	static Scene *createScene();
	
	CREATE_FUNC(MainSceneLayer);
	
	//
	MainSceneLayer();
	
	virtual bool init();
	
	virtual void onEnter();
	
protected:
	void setupUI(const std::string &csbName);
	
};

#endif /* MainScene_hpp */
