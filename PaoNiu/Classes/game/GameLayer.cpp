//
//  GameLayer.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#include "GameLayer.h"
#include "GameBoy.h"
#include "GameGirl.h"

bool GameLayer::init(){
    if(!CCLayer::init()){
		return false;
	}
    winSize=CCDirector::sharedDirector()->getWinSize();
    
    //倒计时
    CCLabelBMFont* lfTime = CCLabelBMFont::create("0123456789", "bitmapFontTest4.fnt");
	this->addChild(lfTime);
	lfTime->setPosition(ccp(winSize.width/2,winSize.height-20));
    
    //网
    CCTextureCache::sharedTextureCache()->addImage("fishingjoy_resource.png");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("fishingjoy_resource.plist");
    
    CCSprite* _papawSprite = CCSprite::createWithSpriteFrameName("fishing_net.png");
	_papawSprite->setPosition(ccp(100,100));
    this->addChild(_papawSprite);
    
    GameBoy* boy=GameBoy::create();
    addChild(boy);
    return true;
}