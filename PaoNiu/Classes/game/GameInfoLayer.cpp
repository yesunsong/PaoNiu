//
//  GameInfoLayer.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#include "GameInfoLayer.h"

bool GameInfoLayer::init(){
    if (!CCLayer::init()) {
        return false;
    }
    winSize=CCDirector::sharedDirector()->getWinSize();
    
    CCLabelTTF* paoLabel=CCLabelTTF::create("泡数:10", "", 20);
    paoLabel->setAnchorPoint(ccp(0,0.5));
    paoLabel->setPosition(ccp(winSize.width*0.5-160, winSize.height-10));
    addChild(paoLabel);
    
    CCSprite *scoreLabel = CCSprite::create("score.png");
    scoreLabel->setAnchorPoint(ccp(0,0.5));
    scoreLabel->setPosition(ccp(winSize.width*0.5+160, winSize.height-10));
    scoreLabel->setScale(0.5);
    addChild(scoreLabel);
    
    CCLabelBMFont* scoreFont=CCLabelBMFont::create("0123456789", "scoreFnt.fnt");
    scoreFont->setPosition(ccp(scoreLabel->getPositionX()+scoreLabel->getContentSize().width,winSize.height-10));
    scoreFont->setScale(0.5);
    addChild(scoreFont);
    
    CCLabelTTF* storeLabel=CCLabelTTF::create("商店", "", 20);
    storeLabel->setAnchorPoint(ccp(0,0.5));
    storeLabel->setPosition(ccp(winSize.width*0.5-160, winSize.height-30));
    addChild(storeLabel);
    
    CCLabelTTF* propsLabel=CCLabelTTF::create("道具", "", 20);
    propsLabel->setAnchorPoint(ccp(0,0.5));
    propsLabel->setPosition(ccp(winSize.width*0.5+160, winSize.height-30));
    addChild(propsLabel);
    
  
    return true;
}