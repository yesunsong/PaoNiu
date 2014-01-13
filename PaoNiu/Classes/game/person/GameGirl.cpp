//
//  GameGirl.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-9.
//
//

#include "GameGirl.h"

void GameGirl::createSkin(){
    srand((unsigned)time(NULL));
    int type=rand()%6;
    
    bubble=CCSprite::create(CCString::createWithFormat("Bubble%d.png",type)->getCString());
    bubble->setPosition(ccp(100, 100));
    addChild(bubble);
}

void GameGirl::setCollisionArea(cocos2d::CCRect var){
    
}

CCRect GameGirl::getCollisionArea(){
    
    return CCRectMake(0, 0, 10, 10);
}