//
//  StartScene.cpp
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-7.
//
//

#include "StartLayer.h"
//#include "StaticData.h"

bool StartLayer::init(){
    if(!CCLayer::init()){
		return false;
	}
    
	winSize= CCDirector::sharedDirector()->getWinSize();
    
    CCSprite* background = CCSprite::create("background.png");
    background->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.5));
    this->addChild(background);
    
    CCSprite* title = CCSprite::create("title.png");
    title->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.7));
    this->addChild(title);
    
//    if(CCDirector::sharedDirector()->getTotalFrames()<10){
//		CCTextureCache::sharedTextureCache()->addImageAsync(STATIC_DATA_STRING("fishingjoy_texture"), this, callfuncO_selector(StartScene::loading));
//        
//        CCSprite* progressBg = CCSprite::create(STATIC_DATA_STRING("progress_bg"));
//        _progressFg = CCLabelTTF::create("0/100", "Thonburi", 16);
//        _progressFg->setColor(ccc3(0, 0, 0));
//        
//        _progressBar = ProgressBar::create(this, CCSprite::create(STATIC_DATA_STRING("progress_bar")));
//        _progressBar->setBackground(progressBg);
//        _progressBar->setForeground(_progressFg);
//        _progressBar->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.5));
//        _progressBar->setSpeed(100.0);
//        this->addChild(_progressBar);
//        
//        this->audioAndUserDataInit();
//	}else{
//		this->initializationCompleted();
//    }
    
    cccontrol
    
    
    CCMenuItemSprite* start = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("start_normal.png"), CCSprite::createWithSpriteFrameName("start_selected.png"), this, NULL);
    CCMenu* menu = CCMenu::create(start, NULL);
    menu->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.4));
    
//    this->removeChild(_progressBar, true);
    this->addChild(menu);
//    PersonalAudioEngine::sharedEngine()->playBackgroundMusic(STATIC_DATA_STRING("bg_music"));
    
    return true;
}