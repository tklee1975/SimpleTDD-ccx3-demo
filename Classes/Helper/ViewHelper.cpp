//
//  ViewHelper.cpp
//
//  Created by Ken Lee on 30/5/15.
//
//

#include "ViewHelper.h"

// For cocos 2d
using namespace cocos2d;

// For cocos studio
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"


using namespace cocos2d::ui;

void ViewHelper::adjustPanelSize(Node *uiPanel, const Size &newSize, const std::vector<std::string> &adjustList)
{
	if(uiPanel == nullptr) {
		return;
	}
	
	float diffY = uiPanel->getContentSize().height - newSize.height;
	for(int i=0; i<adjustList.size(); i++) {
		std::string nodeName = adjustList[i];
		
		Node *node = uiPanel->getChildByName(nodeName);
		if(node != nullptr) {
			Vec2 pos = node->getPosition();
			pos.y -= diffY;
			node->setPosition(pos);
		}
	}
	
}



void ViewHelper::setWidgetSwallowTouches(Node *node, bool needSwallow)
{
	Widget *widget = dynamic_cast<Widget *>(node);
	if(widget == nullptr) {
		return;
	}
	
	widget->setSwallowTouches(needSwallow);
}


void ViewHelper::showFadeAlert(Node *parent, const std::string &msg, int y,
							   int fontSize,
							   const Color4B &color)
{
	auto size = Director::getInstance()->getWinSize();
	Vec2 pos = Vec2(size.width/2, y);

	showFadeAlert(parent, msg, pos, fontSize, color);
}


void ViewHelper::showFadeAlert(Node *parent, const std::string &msg, Vec2 pos,
							   int fontSize,
							   const Color4B &color)
{
	TTFConfig ttfConfig("Caviar_Dreams_Bold.ttf", fontSize * 2);
	
	auto size = Director::getInstance()->getWinSize();
	auto label = Label::createWithTTF(ttfConfig, msg.c_str(), TextHAlignment::CENTER, size.width);
	label->setPosition(pos);
	label->setTextColor(color);
	label->setScale(0.5f);
	parent->addChild(label);

	DelayTime *delay = DelayTime::create(1);
	FadeOut *fadeOut = FadeOut::create(0.5);
	RemoveSelf *remove = RemoveSelf::create();
	
	Sequence *sequence = Sequence::create(delay, fadeOut, remove, nullptr);
	
	label->runAction(sequence);
}

Label *ViewHelper::createLabel(const std::string &msg, int fontSize,
							   const Color4B &color)
{
	TTFConfig ttfConfig("Caviar_Dreams_Bold.ttf", fontSize * 2);
	
	auto label = Label::createWithTTF(ttfConfig, msg.c_str(),
									  TextHAlignment::CENTER, 0);
	label->setTextColor(color);
	label->setScale(0.5f);
	
	return label;
}


MenuItem *ViewHelper::createMenuItemWithFont(const char *name, const char *font,
											const ccMenuCallback& callback)
{
	float fontSize = 20;
	Label *label = Label::createWithSystemFont(name, font, fontSize);
	label->setTextColor(Color4B::WHITE);
	
	return MenuItemLabel::create(label, callback);
}


Menu *ViewHelper::createMenu(Point pos, const char *name, const ccMenuCallback& callback)
{
	
	auto menuItem = createMenuItemWithFont(name, "arial", callback);
	Menu *menu = Menu::create(menuItem, NULL);
	menu->setPosition(pos);
	
	return menu;
}

Node *ViewHelper::createRedSpot(Node *parent, const Vec2 &pos)
{
	int size = 2;
	//int size = 30;
	LayerColor *dot = LayerColor::create(Color4B::RED, size, size);
	
	Vec2 finalPos = Vec2(pos.x - size/2, pos.y - size/2);
	dot->setPosition(finalPos);
	
	if(parent) {
		parent->addChild(dot);
	}
	
	return dot;
}


void ViewHelper::addBackButtonListener(Node *owner, ui::Button *button, BackHandleType backType)
{
	if(button == nullptr) {
		return;
	}
	
	//set lisenter for back button
	button->addTouchEventListener([owner, backType](Ref *sender, Widget::TouchEventType type) {
		switch(type){
			case ui::Widget::TouchEventType::ENDED: {
				if(backType == BackHandleType::PopScene) {
					Director::getInstance()->popScene();
					
				} else if(backType == BackHandleType::RemoveFromParent) {
					if(owner) {
						owner->removeFromParent();
					}
				} else {
					log("addBackButtonListener: unknown handleType");
				}
				
			}
		}
	});
}

ui::Button *ViewHelper::createButton(const std::string &name, const int fontSize,
									 const Color3B &textColor)
{
	cocos2d::ui::Button *button = cocos2d::ui::Button::create();
	button->setTitleText(name);
	button->setTitleFontSize(fontSize);
	button->setTitleColor(textColor);
	
	return button;
}

ClippingNode * ViewHelper::createMaskLayer(const Color4B &bgColor, const std::string &maskSpriteName, const Vec2 &maskPosition)
{
	// Mask Layer
	LayerColor *maskLayer = LayerColor::create(bgColor);	// Own by maskNode
	
	
	// Mask Sprite
	Sprite *mask = Sprite::create(maskSpriteName);			// Own by stencil
	mask->setPosition(maskPosition);
	
	// Create stencil
	Node *stencil = Node::create();		// Own by maskNode
	stencil->addChild(mask);
	
	
	// The mask (clipping node)
	ClippingNode *maskNode = ClippingNode::create();
	maskNode->setInverted(true);
	maskNode->setAlphaThreshold(0);
	maskNode->setStencil(stencil);
	maskNode->addChild(maskLayer);
	
	return maskNode;
}

Node *ViewHelper::createAnimationNode(const std::string &csbName,
									  const std::string &animationName,
									  bool isRepeat, bool removeSelf,
                                      const std::function<void()> &endCallback)
{
	Node *csbNode = CSLoader::createNode(csbName);
	if(csbNode == nullptr) {
		log("addCsbEffectByName. cannot create the node: %s", csbName.c_str());
		return nullptr;
	}
	
	// Setting the animation
	cocostudio::timeline::ActionTimeline *timeline = CSLoader::createTimeline(csbName);
	if(timeline == nullptr) {
		log("addCsbAnimeByName:. cannot create the timeLine: %s", csbName.c_str());
		return nullptr;
	}
	
	csbNode->runAction(timeline);
	csbNode->setUserObject(timeline);
	
	timeline->play(animationName, isRepeat);
	
	
	if(isRepeat == false && removeSelf) {
		timeline->setAnimationEndCallFunc(animationName, [&,csbNode,endCallback]() {
			csbNode->removeFromParent();
            if(endCallback){
                endCallback();
            }
		});
	}
	
	return csbNode;
}