//
//  FireworkView.cpp
//  SimpleTDDDemo
//
//  Created by Ken Lee on 26/12/2016.
//
//

#include "FireworkView.h"
#include "cocostudio/CocoStudio.h"

const float kCooldown = 0.3f;

using namespace cocos2d::ui;


FireworkView::FireworkView()
: mCooldown(0)
, mCounter(0)
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
	
	
	// Clean up first
	mEmitterList.clear();
	
	// Define the EmitterList and
	// By default
	int numFirework = 10;
	
	
	for(int i=1; i<=numFirework; i++) {
		std::string nodeName = StringUtils::format("firework%d", i);
		
		ParticleSystemQuad *particle = rootNode->getChildByName<ParticleSystemQuad *>(nodeName);
		if(particle != nullptr) {
			mEmitterList.pushBack(particle);
		}
	}
	
	// Prevent all emitter being activated
	for(ParticleSystemQuad *particle : mEmitterList) {
		particle->stopSystem();
	}
}

void FireworkView::activateEmitter(int index)
{
	if(index < 0 || index >= mEmitterList.size()) {
		log("FireworkLayer::activateEmitter: out of bound. index=%d", index);
		return;
	}
	
	ParticleSystemQuad *particle = mEmitterList.at(index);
	particle->resetSystem();
}


#pragma mark - Firework scheduling
void FireworkView::startFirework()
{
	scheduleUpdate();
}

void FireworkView::stopFirework()
{
	unscheduleUpdate();
	
	// Prevent all emitter being activated
	for(ParticleSystemQuad *particle : mEmitterList) {
		particle->stopSystem();
	}
}

void FireworkView::update(float delta)
{
	mCooldown -= delta;
	
	if(mCooldown > 0) {	// Not yet activate
		return;
	}
	
	mCooldown = 0.1f * RandomHelper::random_int(5, 12);	// random interval
	activateEmitter(mCounter);
	updateCounter();
}

int FireworkView::getEmitterCount()
{
	return (int) mEmitterList.size();
}

void FireworkView::updateCounter()
{
	mCounter = (mCounter + 1) % getEmitterCount();
}
