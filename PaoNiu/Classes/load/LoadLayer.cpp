//
//  LoadLayer.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#include "LoadLayer.h"
#include "LoadDelegate.h"

bool LoadLayer::init(){
    if(!CCLayer::init()){
		return false;
	}
	winSize= CCDirector::sharedDirector()->getWinSize();
    
    CCLabelTTF *logo=CCLabelTTF::create("LOGO", "", 33);
    logo->setPosition(ccp(winSize.width*0.5, winSize.height*0.5));
    addChild(logo);
    
    CCLabelTTF *loading=CCLabelTTF::create("加载动画和资源.....", "", 26);
    loading->setPosition(ccp(winSize.width*0.5, winSize.height*0.5-50));
    addChild(loading);
    
    this->scheduleOnce(schedule_selector(LoadLayer::loadFinish), 1);
    return true;
}

void LoadLayer::setDelegate(void* delegate){
    _delegate=delegate;
}

void LoadLayer::loadFinish(){
    ((LoadDelegate*)_delegate)->loadFinsh();
}