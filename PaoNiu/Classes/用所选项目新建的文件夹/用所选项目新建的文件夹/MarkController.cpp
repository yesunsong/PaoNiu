//
//  GameMark.cpp
//  example11-1
//
//  Created by shuoquan man on 12-10-20.
//  Copyright (c) 2012�� __MyCompanyName__. All rights reserved.
//

#include "MarkController.h"
MarkController::MarkController(void)
{
}

MarkController::~MarkController(void)
{
}
void MarkController::onExit()
{
    CCNode::onExit();
}
void MarkController::onEnter()
{
    CCNode::onEnter();
    CCSize size = CCDirector::sharedDirector()->getWinSize(); 
    this->setContentSize(size);
    bits = CCArray::createWithCapacity(5);
    //��������
    CCSprite *title = CCSprite::create("score.png");
    title->setPosition(ccp(size.width/2 + 100,size.height - 20));
    title->setScale(0.5);
    addChild(title);
    //���ְ�λ����
    for(int i = 0;i < 5;i ++){
        CCSprite * shu = CCSprite::create("shu.png");
        ui = shu->getTexture();
        shu->setScale(0.5);
        shu->setTextureRect(CCRectMake(234,0,26,31));
        shu->setPosition(ccp(size.width - 15 - i * 15,size.height - 20));
        bits->addObject(shu);
        addChild(shu);
    }
    bits->retain();
    mark = 0;
}
void MarkController::addnumber(int var){
    //��������λ��������
    mark += var;
    int temp = mark % 10;
    if(temp > 0){
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(0))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31)); 
    }else{
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(0))->setTextureRect(CCRectMake(234,0,26,31)); 
    }
    temp = (mark % 100) / 10;
    if(temp > 0){
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(1))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31));  
 
    }else{
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(1))->setTextureRect(CCRectMake(234,0,26,31)); 
    }
    temp = (mark % 1000) / 100;
    if(temp > 0){
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(2))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31)); 
 
    }else{
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(2))->setTextureRect(CCRectMake(234,0,26,31));
    }
    temp = (mark % 10000) / 1000;
    if(temp > 0){
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(3))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31)); 
 
    }else{
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(3))->setTextureRect(CCRectMake(234,0,26,31)); 
    }
    temp = mark / 10000;
    if(temp > 0){
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(4))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31));  
 
    }else{
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(4))->setTextureRect(CCRectMake(234,0,26,31));
    }
}