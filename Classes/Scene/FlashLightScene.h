//
//  FlashLightScene.hpp
//  SimpleTDDDemo
//
//  Created by Ken Lee on 7/9/2016.
//
//

#ifndef FlashLightScene_hpp
#define FlashLightScene_hpp

#include <stdio.h>

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include <time.h>

// Namespace stuff
USING_NS_CC_EXT;
USING_NS_CC;
using namespace cocos2d::ui;

class FlashLightSceneLayer : public LayerColor {
public:
	// returns a Scene that contains the HelloWorld as the only child
	static Scene *createScene();
	
	CREATE_FUNC(FlashLightSceneLayer);
	CC_SYNTHESIZE(Vec2, mMaskPosition, MaskPosition);
	
	//
	FlashLightSceneLayer();
	
	virtual bool init();
	
	virtual void onEnter();
	
	void updateMaskPosition();		// update the mask visually
protected:
	void setupCharacters();
	void setupMask();
	Texture2D *getMaskTexture();
	

protected:
	Sprite *mMaskSprite;
	
	
};


#endif /* FlashLightScene_hpp */
