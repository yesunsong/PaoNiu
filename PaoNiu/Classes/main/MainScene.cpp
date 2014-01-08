//
//  MainScene.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#include "MainScene.h"

#include "MainDelegate.h"

#include "MainLayer.h"
#include "MenuLayer.h"

bool MainScene::init(){
    if (!CCScene::init()) {
        return false;
    }
    winSize=CCDirector::sharedDirector()->getWinSize();
    
    MainDelegate* delegate=new MainDelegate();
    
    CCSprite* background = CCSprite::create("bg.png");
    background->setPosition(ccp(winSize.width*0.5, winSize.height*0.5));
    this->addChild(background);
    
    MenuLayer* menuLayer=MenuLayer::create();
    menuLayer->setDelegate(delegate);
    addChild(menuLayer);
    
    MainLayer* mainLayer=MainLayer::create();
    mainLayer->setDelegate(delegate);
    addChild(mainLayer);
    
    return true;
}