//
//  ViewHelper.h
//  RPSGame
//
//	A Helper class that help to do somethings on the View
//
//  Created by Ken Lee on 30/5/15.
//
//

#ifndef __RPSGame__ViewHelper__
#define __RPSGame__ViewHelper__

#include <stdio.h>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

USING_NS_CC_EXT;
USING_NS_CC;

// Cocos Studio
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
using namespace cocostudio::timeline;


#define kDEFAULT_COLOR Color4B(0x31, 0xd8, 0xd4, 0xff)

// 
#define kMaskSpriteTag	10000

#define FIX_UI_LAYOUT(__uiPanel__) \
__uiPanel__->setContentSize(getContentSize()); \
cocos2d::ui::Helper::doLayout(__uiPanel__);


#define RESIZE_UI_LAYOUT(__uiPanel__, __size__) \
__uiPanel__->setContentSize(__size__); \
cocos2d::ui::Helper::doLayout(__uiPanel__);


class ViewHelper
{
public:
	enum BackHandleType {
		PopScene,
		RemoveFromParent,
	};
public:
	static void setWidgetSwallowTouches(Node *node, bool needSwallow);
	static void showFadeAlert(Node *parent, const std::string &msg, int y,
							  int fontSize = 15,
							  const Color4B &color = Color4B(0x31, 0xd8, 0xd4, 0xff)
							  );
	
	static Node *createRedSpot(Node *parent, const Vec2 &pos);
	
	static void showFadeAlert(Node *parent, const std::string &msg, Vec2 pos,
							   int fontSize = 15,
							   const Color4B &color = kDEFAULT_COLOR);
	
	static void adjustPanelSize(Node *uiPanel, const Size &newSize, const std::vector<std::string> &adjustList);
	
	static MenuItem *createMenuItemWithFont(const char *name, const char *font,
												 const ccMenuCallback& callback);
	static Menu *createMenu(Point pos, const char *name, const ccMenuCallback& callback);
	
	static Label *createLabel(const std::string &msg, int fontSize = 15,
							  const Color4B &color = kDEFAULT_COLOR);
	
	// Owner is the master node contain the button and its parent
	static void addBackButtonListener(Node *owner, ui::Button *button, BackHandleType backType);
	
	static ui::Button *createButton(const std::string &name, const int fontSize,
									const Color3B &textColor = Color3B::WHITE);

	
	static ClippingNode *createMaskLayer(const Color4B &bgColor,
						const std::string &maskSpriteName, const Vec2 &maskPosition);
	
	static Node *createAnimationNode(const std::string &csbName, const std::string &animationName,
                                     bool isRepeat, bool removeSelf, const std::function<void()> &endCallback = NULL);
};

#endif /* defined(__RPSGame__ViewHelper__) */
