//
//  MenuLayer.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#include "MenuLayer.h"
#include "UIComm.h"
#include "MainDelegate.h"

bool MenuLayer::init(){
    if(!CCLayer::init()){
		return false;
	}
	winSize= CCDirector::sharedDirector()->getWinSize();
    
    CCMenu* menu=CCMenu::create();
    menu->setPosition(CCPointZero);
    addChild(menu);
    
    CCMenuItemLabel *helpButton=createMenuitemLabel("帮助");
    helpButton->setPosition(ccp(winSize.width*0.5-100, winSize.height-57));
    helpButton->initWithTarget(this, menu_selector(MenuLayer::trunToHelp));
    menu->addChild(helpButton);
    
    CCMenuItemLabel *storeButton=createMenuitemLabel("商店");
    storeButton->setPosition(ccp(winSize.width*0.5-50, winSize.height-57));
        storeButton->initWithTarget(this, menu_selector(MenuLayer::trunToStore));
    menu->addChild(storeButton);
    
    CCMenuItemLabel *propButton=createMenuitemLabel("道具");
    propButton->setPosition(ccp(winSize.width*0.5, winSize.height-57));
    propButton->initWithTarget(this, menu_selector(MenuLayer::turnToProp));
    menu->addChild(propButton);
    
    CCMenuItemLabel *settingButton=createMenuitemLabel("设置");
    settingButton->setPosition(ccp(winSize.width*0.5+50, winSize.height-57));
    settingButton->initWithTarget(this, menu_selector(MenuLayer::trunToSetting));
    menu->addChild(settingButton);
    
    return true;
}

void MenuLayer::setDelegate(void* delegate){
    _delegate=delegate;
}

void MenuLayer::trunToHelp(){
    ((MainDelegate*)_delegate)->openHelpPage();
}
void MenuLayer::trunToStore(){
    ((MainDelegate*)_delegate)->openStorePage();
}
void MenuLayer::turnToProp(){
    ((MainDelegate*)_delegate)->openHPropPage();
}
void MenuLayer::trunToSetting(){
    ((MainDelegate*)_delegate)->openSettingPage();
}



