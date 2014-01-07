//
//  StartScene.cpp
//  FishingJoy
//
//  Created by Ringo_D on 12-9-8.
//
//

#include "StartScene.h"
#include "GameScene.h"
#include "PersonalAudioEngine.h"
#include "StaticData.h"
#include "GirlController.h"
#include "DynamicData.h"
USING_NS_CC;
using namespace CocosDenshion;
CCScene* StartScene::scene()
{
    CCScene* scene = CCScene::create();
    StartScene* layer = StartScene::create();
    scene->addChild(layer);
    return scene;
}
bool StartScene::init()
{
    if(!CCLayer::init())
	{
		return false;
	}
	
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        
    CCSprite* background = CCSprite::create(STATIC_DATA_STRING("background"));
    background->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.5));
    this->addChild(background);
        
    CCSprite* title = CCSprite::create(STATIC_DATA_STRING("title"));
    title->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.7));
    this->addChild(title);

    if(CCDirector::sharedDirector()->getTotalFrames()<10)
	{
		CCTextureCache::sharedTextureCache()->addImageAsync(STATIC_DATA_STRING("fishingjoy_texture"), this, callfuncO_selector(StartScene::loading));
            
        CCSprite* progressBg = CCSprite::create(STATIC_DATA_STRING("progress_bg"));
        _progressFg = CCLabelTTF::create("0/100", "Thonburi", 16);
        _progressFg->setColor(ccc3(0, 0, 0));
            
        _progressBar = ProgressBar::create(this, CCSprite::create(STATIC_DATA_STRING("progress_bar")));
        _progressBar->setBackground(progressBg);
        _progressBar->setForeground(_progressFg);
        _progressBar->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.5));
        _progressBar->setSpeed(100.0);
        this->addChild(_progressBar);

        this->audioAndUserDataInit();
	}
	else
	{
		this->initializationCompleted();
    }

    return true;
   
}
void StartScene::audioAndUserDataInit()
{
    DynamicData::sharedDynamicData();
    PersonalAudioEngine::sharedEngine();
}
void StartScene::loading(CCObject* pObj)
{
    _progressBar->progressTo(100.0);
}
void StartScene::transition(CCObject* pSender)
{
    CCScene* scene = CCTransitionFadeDown::create(1.0f, GameScene::create());
    CCDirector::sharedDirector()->replaceScene(scene);
}
void StartScene::cacheInit()
{
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("fishingjoy_resource.plist");
    
    int frameCount = STATIC_DATA_INT("fish_frame_count");
    for (int type = k_Girl_Type_Red; type < k_Girl_Type_Count; type++) 
	{
        CCArray* spriteFrames = CCArray::createWithCapacity(frameCount);
        for(int i = 0;i < frameCount;i++)
		{
            CCString* filename = CCString::createWithFormat(STATIC_DATA_STRING("fish_frame_name_format"),type,i);
            CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(filename->getCString());
            spriteFrames->addObject(spriteFrame);
        }
        CCAnimation* girlAnimation = CCAnimation::createWithSpriteFrames(spriteFrames);
        girlAnimation->setDelayPerUnit(STATIC_DATA_FLOAT("fish_frame_delay"));
        CCString* animationName = CCString::createWithFormat(STATIC_DATA_STRING("fish_animation"), type);
        CCAnimationCache::sharedAnimationCache()->addAnimation(girlAnimation, animationName->getCString());
    }
}
void StartScene::initializationCompleted()
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCMenuItemSprite* start = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("start_normal")), CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("start_selected")), this, menu_selector(StartScene::transition));
    CCMenu* menu = CCMenu::create(start, NULL);
    menu->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.4));
    
    this->removeChild(_progressBar, true);
    this->addChild(menu);
    PersonalAudioEngine::sharedEngine()->playBackgroundMusic(STATIC_DATA_STRING("bg_music"));
}
void StartScene::loadingFinished()
{
    this->cacheInit();
    this->initializationCompleted();
}
void StartScene::progressPercentageSetter(float percentage)
{
    CCString* str = CCString::createWithFormat("%d/100",(int)percentage);
    _progressFg->setString(str->getCString());
}