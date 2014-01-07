//
//  PapawController.cpp
//  FishingJoy
//
//  Created by Ringo_D on 12-9-18.
//
//

#include "PapawController.h"
#include "StaticData.h"
USING_NS_CC;

PapawController* PapawController::create(PapawType type)
{
    PapawController* papaw = new PapawController();
    papaw->init(type);
    papaw->autorelease();
    return papaw;
}

bool PapawController::init(PapawType type)
{
    _papawSprite = CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("fishing_net"));
	//_papawSprite->setPosition(ccp(-100,-100));
    this->addChild(_papawSprite);
    return true;
}
void PapawController::showAt(CCPoint pos)
{
    this->setPosition(pos);
    this->setScale(1.0f);
    this->setVisible(true);
    this->stopAllActions();
    this->runAction(this->netAction());
}
CCAction* PapawController::netAction()
{
    CCDelayTime* delayTime = CCDelayTime::create(2.0);
    
    CCHide* hide = CCHide::create();
    
    CCFiniteTimeAction* seq = CCSequence::create(delayTime, hide, NULL);

	//this->setPosition(ccp(-100,-100));
    return seq;
}
CCRect PapawController::getCollisionArea()
{
    CCPoint origin = this->getParent()->convertToWorldSpace(this->getPosition());
    CCSize defaultSize = _papawSprite->getContentSize();
    float scale = this->getScale();
    CCSize size = CCSizeMake(defaultSize.width*scale, defaultSize.height*scale);
    return CCRectMake(origin.x-size.width*0.5, origin.y-size.height*0.5, size.width, size.height);
}