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
    
    int row;
    int column;
    for (int i=0; i<9; i++) {
        row=int(i/3);
        column=(i%3);
        std::cout<<"row:"<<row<<",column:"<<column<<std::endl;
        
        TollgateItem* item=TollgateItem::create();
        item->setContentSize(CCSizeMake(200, 200));
        item->setTollgate(CCString::createWithFormat("关卡%d",i+1)->getCString(),(i+1)*152, (i+1));
        item->setPosition(ccp(row*200+300, winSize.height-250-column*150));
        addChild(item);
    }
    return true;
}

void MainLayer::setDelegate(void* delegate){
    _delegate=delegate;
}

void MainLayer::turnToMail(){
    ((MainDelegate*)_delegate)->openMailPage();
}