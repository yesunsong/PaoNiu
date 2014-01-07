//
//  DynamicData.cpp
//  FishingJoy
//
//  Created by Ringo_D on 12-9-30.
//
//

#include "DynamicData.h"
#include "StaticData.h"
USING_NS_CC;
static DynamicData* _sharedDynamicData = NULL;
DynamicData* DynamicData::sharedDynamicData()
{
    if(_sharedDynamicData==NULL){
        _sharedDynamicData = new DynamicData();
        _sharedDynamicData->init();
    }
    return _sharedDynamicData;
}
void DynamicData::purge()
{
    CC_SAFE_RELEASE_NULL(_sharedDynamicData);
}
DynamicData::DynamicData()
{
    
}
DynamicData::~DynamicData()
{
    this->flush();
}
bool DynamicData::init()
{
    _isBeginner = CCUserDefault::sharedUserDefault()->getBoolForKey("beginner",true);
    if(_isBeginner == true){
        this->reset();
        this->flush();
        this->setIsBeginner(false);
    }else{
        _isBeginner = CCUserDefault::sharedUserDefault()->getBoolForKey("beginner");
        _soundVolume = CCUserDefault::sharedUserDefault()->getFloatForKey("sound");
		
        _musicVolume = CCUserDefault::sharedUserDefault()->getFloatForKey("music");
        _gold = CCUserDefault::sharedUserDefault()->getIntegerForKey("gold");
		_mark = CCUserDefault::sharedUserDefault()->getIntegerForKey("mark");
        CCUserDefault::sharedUserDefault()->purgeSharedUserDefault();
    }
    return true;
}
void DynamicData::reset()
{
    int gold = STATIC_DATA_INT("default_gold");
    this->setGold(gold);
    this->setIsBeginner(true);
    this->setMusicVolume(1);
    this->setSoundVolume(1);
    this->flush();
}
void DynamicData::alterGold(int delta)
{
    this->setGold(this->getGold()+delta);
}
void DynamicData::flush()
{
    CCUserDefault::sharedUserDefault()->setFloatForKey("sound", this->getSoundVolume());
    CCUserDefault::sharedUserDefault()->setBoolForKey("beginner", this->getIsBeginner());
    CCUserDefault::sharedUserDefault()->setIntegerForKey("gold", this->getGold());
    CCUserDefault::sharedUserDefault()->setFloatForKey("music", this->getMusicVolume());
    CCUserDefault::sharedUserDefault()->flush();
    CCUserDefault::sharedUserDefault()->purgeSharedUserDefault();
}
