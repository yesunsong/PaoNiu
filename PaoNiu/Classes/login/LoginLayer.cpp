//
//  StartScene.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-7.
//
//

#include "LoginLayer.h"

#include "LoginScene.h"

bool LoginLayer::init(){
    if(!CCLayer::init()){
		return false;
	}
	winSize= CCDirector::sharedDirector()->getWinSize();
    
    CCSprite* background = CCSprite::create("background.png");
    background->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.5));
    this->addChild(background);
    
    CCSprite* title = CCSprite::create("title.png");
    title->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.7));
    this->addChild(title);
    
    CCMenu *menu=CCMenu::create();
    menu->setPosition(CCPointZero);
    menu->alignItemsVertically();
    addChild(menu);
    
    CCMenuItem *weixinLogin=createMenuitemLabel("与微信好友玩");
    weixinLogin->setPosition(ccp(winSize.width*0.5,winSize.height*0.5));
    weixinLogin->initWithTarget(this, menu_selector(LoginLayer::loginWechat));
    menu->addChild(weixinLogin);
    
    CCMenuItem *qqLogin=createMenuitemLabel("与QQ好友玩");
    qqLogin->setPosition(ccp(winSize.width*0.5,winSize.height*0.5-weixinLogin->getContentSize().height));
        qqLogin->initWithTarget(this, menu_selector(LoginLayer::loginQQ));
    menu->addChild(qqLogin);
    
    return true;
}

void LoginLayer::setDelegate(void* delegate){
    _delegate=delegate;
}

void LoginLayer::loginWechat(){
    ((LoginDelegate *)_delegate)->loginWeChat();
}

void LoginLayer::loginQQ(){
    ((LoginDelegate* )_delegate)->loginQQ();
}