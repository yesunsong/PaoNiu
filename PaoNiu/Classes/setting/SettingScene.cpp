//
//  SettingScene.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#include "SettingScene.h"
#include "SettingLayer.h"
#include "SettingDelegate.h"

bool SettingScene::init(){
    if (!CCScene::init()) {
        return false;
    }
    winSize=CCDirector::sharedDirector()->getWinSize();
    
    SettingDelegate* delegate=new SettingDelegate();
    
    CCSprite* background = CCSprite::create("bg.png");
    background->setPosition(ccp(winSize.width*0.5, winSize.height*0.5));
    this->addChild(background);
    
    SettingLayer* settingLayer=SettingLayer::create();
    settingLayer->setDelegate(delegate);
    addChild(settingLayer);
    
    return true;
}