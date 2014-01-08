//
//  TollgateItem.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#include "TollgateItem.h"

bool TollgateItem::init(){
    if (!CCNode::init()) {
        return false;
    }
    _nameLabel=CCLabelTTF::create("关卡名称:关卡", "", 20);
    _nameLabel->setPosition(ccp(0, 40));
    _scoreLabel=CCLabelTTF::create("勋章:勋章1", "", 20);
    _scoreLabel->setPosition(ccp(0, 20));
    _medalLabel=CCLabelTTF::create("分数:1000", "", 20);
    _medalLabel->setPosition(ccp(0, 0));
    addChild(_nameLabel);
    addChild(_scoreLabel);
    addChild(_medalLabel);
    
    return true;
}

void TollgateItem::setTollgate(const char* name,int score,int type){
    _nameLabel->setString(CCString::createWithFormat("关卡名称:%s",name)->getCString());
    _scoreLabel->setString(CCString::createWithFormat("分数:%d",score)->getCString());
    _medalLabel->setString(CCString::createWithFormat("勋章:%d",type)->getCString());
}