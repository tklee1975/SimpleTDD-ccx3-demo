//
//  FireworkView.hpp
//  SimpleTDDDemo
//
//  Created by Ken Lee on 26/12/2016.
//
//

#ifndef FireworkView_hpp
#define FireworkView_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocos2d;
using namespace cocos2d::ui;

class FireworkView : public Layout
{
public:
	CREATE_FUNC(FireworkView);
	
	FireworkView();
	
	virtual bool init();
	
	void setupCsb(const std::string &csbFile);
	
	void activateEmitter(int index);
	
	
#pragma mark - Firework scheduling
public:
	void startFirework();
	void stopFirework();
	void update(float delta);
	int getEmitterCount();
	
private:
	void updateCounter();
	
private:
	int mCounter;
	float mCooldown;

	
private:
	Vector<ParticleSystemQuad *> mEmitterList;
};


#endif /* FireworkView_hpp */
