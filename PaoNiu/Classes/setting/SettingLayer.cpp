//
//  SettingLayer.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#include "SettingLayer.h"
#include "SettingDelegate.h"
#include "UIComm.h"

bool SettingLayer::init(){
    if(!CCLayer::init()){
		return false;
	}
    winSize=CCDirector::sharedDirector()->getWinSize();
    
    CCLabelTTF* title=CCLabelTTF::create("系统设置", "", 40);
    title->setAnchorPoint(ccp(.5, 1));
    title->setPosition(ccp(winSize.width*0.5, winSize.height));
    addChild(title);
    
    CCLabelTTF* music=CCLabelTTF::create("音乐", "", 20);
    music->setAnchorPoint(ccp(0, 0.5));
    music->setPosition(ccp(winSize.width*0.5-200, winSize.height-100));
    addChild(music);
    
    CCLabelTTF* sound=CCLabelTTF::create("音效", "", 20);
    sound->setAnchorPoint(ccp(0, 0.5));
    sound->setPosition(ccp(winSize.width*0.5-200, winSize.height-150));
    addChild(sound);
    
    CCLabelTTF* version=CCLabelTTF::create("版本:v 1.0.0", "", 20);
    version->setAnchorPoint(ccp(0, 0.5));
    version->setPosition(ccp(winSize.width*0.5-200, winSize.height-200));
    addChild(version);
    
//    CCEditBox *feedbackMsg=createEditBox("", CCSizeMake(200, 250), "", 20, ccc3(250, 0, 0), 250, "请在此输入：）", kEditBoxInputModeAny, kEditBoxInputFlagSensitive, kKeyboardReturnTypeDefault);
//    addChild(feedbackMsg);
    
    
    CCMenu* menu=CCMenu::create();
    menu->setPosition(CCPointZero);
    addChild(menu);
    
    CCMenuItemLabel* backButton=createMenuitemLabel("返回");
    backButton->setPosition(ccp(winSize.width*0.5-200,winSize.height-500));
    backButton->initWithTarget(this, menu_selector(SettingLayer::backToMain));
    menu->addChild(backButton);
    
    CCMenuItemLabel* feedbackButton=createMenuitemLabel("反馈");
        feedbackButton->setPosition(ccp(winSize.width*0.5+200,winSize.height-500));
        feedbackButton->initWithTarget(this, menu_selector(SettingLayer::sendFeedback));
    menu->addChild(feedbackButton);
    
    return true;
}

void SettingLayer::setDelegate(void* delegate){
    _delegate=delegate;
}

void SettingLayer::backToMain(){
    ((SettingDelegate*)_delegate)->backToMain();
}


void SettingLayer::sendFeedback(){
    ((SettingDelegate*)_delegate)->sendFeedback();
}
