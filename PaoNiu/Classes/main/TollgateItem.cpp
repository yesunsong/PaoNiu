//
//  TollgateItem.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#include "TollgateItem.h"
#include "MainDelegate.h"

bool TollgateItem::init(){
    if (!CCNode::init()) {
        return false;
    }
    itemBg=CCSprite::create("itemBg.png");
    itemBg->setScaleX(0.7);
    itemBg->setScaleY(0.5);
    itemBg->setAnchorPoint(CCPointZero);
    itemBg->setPosition(CCPointZero);
    addChild(itemBg);
    
    _nameLabel=CCLabelTTF::create("关卡名称:关卡", "", 20);
    _nameLabel->setAnchorPoint(CCPointZero);
    _nameLabel->setPosition(ccp(0, 40));
    
    _medalLabel =CCLabelTTF::create("勋章:勋章1", "", 20);
        _medalLabel->setAnchorPoint(CCPointZero);
    _medalLabel->setPosition(ccp(0, 20));
    
    _scoreLabel=CCLabelTTF::create("分数:1000", "", 20);
        _scoreLabel->setAnchorPoint(CCPointZero);
    _scoreLabel->setPosition(ccp(0, 0));
    addChild(_nameLabel);
    addChild(_scoreLabel);
    addChild(_medalLabel);
    
    return true;
}

void TollgateItem::onEnter(){
    registerWithTouchDispatcher();
}

void TollgateItem::onExit(){
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

void TollgateItem::registerWithTouchDispatcher(){
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
}

bool TollgateItem::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    return true;
}

void TollgateItem::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    CCPoint location=this->getParent()->convertTouchToNodeSpace(pTouch);
    if (m_hotArea.containsPoint(location)) {
        CCLog("ccTouchEnded");
        CCAssert(_delegate!=NULL,"_delegate must not be NULL");
        ((MainDelegate*)_delegate)->turnToMainGame();
    }
}

void TollgateItem::setTollgate(const char* name,int score,int type){
    _nameLabel->setString(CCString::createWithFormat("关卡名称:%s",name)->getCString());
    _scoreLabel->setString(CCString::createWithFormat("分数:%d",score)->getCString());
    _medalLabel->setString(CCString::createWithFormat("勋章:%d",type)->getCString());
}