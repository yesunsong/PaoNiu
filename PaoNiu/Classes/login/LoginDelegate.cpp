//
//  StartDelegate.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#include "LoginDelegate.h"

#include "cocos2d.h"
USING_NS_CC;

#include "LoadScene.h"


void LoginDelegate::loginQQ(){
    CCLOG("login QQ");
    CCDirector::sharedDirector()->replaceScene(LoadScene::create());
}

void LoginDelegate::loginWeChat(){
    CCLOG("login WeChat");
    CCDirector::sharedDirector()->replaceScene(LoadScene::create());
}