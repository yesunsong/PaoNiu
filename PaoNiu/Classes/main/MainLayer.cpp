//
//  MainLayer.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#include "MainLayer.h"
#include "MainDelegate.h"

#include "TollgateItem.h"
bool MainLayer::init(){
    if(!CCLayer::init()){
		return false;
	}
	winSize= CCDirector::sharedDirector()->getWinSize();
    
    CCLabelTTF* bodyLabel=CCLabelTTF::create("精力:0", "", 20);
    bodyLabel->setAnchorPoint(ccp(0,0.5));
    bodyLabel->setPosition(ccp(winSize.width*0.5-160, winSize.height-140));
    addChild(bodyLabel);
    
    CCMenu* menu=CCMenu::create();
    menu->setPosition(CCPointZero);
    addChild(menu);
    
    CCMenuItemLabel *mailButton=createMenuitemLabel("邮件");
    mailButton->setPosition(ccp(winSize.width*0.5+100, winSize.height-140));
    mailButton->initWithTarget(this, menu_selector(MainLayer::turnToMail));
    menu->addChild(mailButton);
        
    return true;
}

//CCAction* PapawController::netAction(){
//    CCDelayTime* delayTime = CCDelayTime::create(2.0);
//    
//    CCHide* hide = CCHide::create();
//    
//    CCFiniteTimeAction* seq = CCSequence::create(delayTime, hide, NULL);
//    
//	//this->setPosition(ccp(-100,-100));
//    return seq;
//}

void MainLayer::onEnter(){
    CCLayer::onEnter();
    
    int row;
    int column;
    TollgateItem* item;
    for (int i=0; i<9; i++) {
        row=(i%3);
        column=int(i/3);
        
        item=TollgateItem::create();
        item->setContentSize(CCSizeMake(140, 100));
        item->setTollgate(CCString::createWithFormat("关卡%d",i+1)->getCString(),(i+1)*152, (i+1));
        item->setPosition(ccp(row*200+300, winSize.height-250-column*150));
        item->setHotArea(CCRectMake(item->getPositionX()-item->getContentSize().width*item->getAnchorPoint().x,item->getPositionY()-item->getContentSize().height*item->getAnchorPoint().y,item->getContentSize().width,item->getContentSize().height));
        item->setDelegate(_delegate);
        addChild(item);
    }
}

void MainLayer::onExit(){
    CCLayer::onExit();
}
void MainLayer::turnToMail(){
    ((MainDelegate*)_delegate)->openMailPage();
}