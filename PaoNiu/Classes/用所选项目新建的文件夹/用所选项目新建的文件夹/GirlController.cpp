#include "GirlController.h"
//#include "GameScene.h"
//#include "StaticData.h"
USING_NS_CC;


#include <iostream> 
#include <string> 
using namespace std;

enum{
    k_Action_Animate = 0,
    k_Action_MoveTo
};
GirlController* GirlController::create(GirlType type)
{
    GirlController* girl = new GirlController();
    girl->init(type);
    girl->autorelease();
    return girl;
}
bool GirlController::init(GirlType type)
{
    _type = type;
	/*
	CCLog("GirlController Start!");
	char buf[10]; 
	sprintf(buf, "%d", _type); 
	//string b = buf;
	CCLog(buf);
    */
	CCString* animationName = CCString::createWithFormat("fish_animation", _type);//_%d
	//CCLog(animationName->getCString());
    CCAnimation* girlAnimation = CCAnimationCache::sharedAnimationCache()->animationByName(animationName->getCString());
    CCAnimate* girlAnimate = CCAnimate::create(girlAnimation);
    girlAnimate->setTag(k_Action_Animate);
    _girlSprite = CCSprite::create();
    this->addChild(_girlSprite);
    _girlSprite->runAction(CCRepeatForever::create(girlAnimate));
    return true;
}

CCRect GirlController::getCollisionArea()
{
    CCAssert(this->getParent(), "You Should Call This After Add it as a child");
    CCPoint origin = this->getParent()->convertToWorldSpace(this->getPosition());
    CCSize size = _girlSprite->getContentSize();
    return CCRectMake(origin.x-size.width*0.5, origin.y-size.height*0.5, size.width, size.height);
}

void GirlController::beCaught()
{
    this->stopActionByTag(k_Action_MoveTo);
    CCDelayTime* delayTime = CCDelayTime::create(1.0);
    CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(GirlController::beCaught_CallFunc));
    CCFiniteTimeAction* seq = CCSequence::create(delayTime, callFunc, NULL);
    
    CCBlink* blink = CCBlink::create(1.0, 8);
    CCFiniteTimeAction *spawn = CCSpawn::create(blink,seq , NULL);
    this->runAction(spawn);
}

void GirlController::beCaught_CallFunc()
{
    this->getParent()->removeChild(this, false);
}

void GirlController::moveTo(CCPoint destination)
{
    CCPoint start = this->getParent()->convertToWorldSpace(this->getPosition());
    float speed = ccpDistance(destination, start) / 200;
    CCMoveTo* moveTo = CCMoveTo::create(speed ,destination);
    CCCallFunc* callfunc = CCCallFunc::create(this, callfunc_selector(GirlController::moveEnd));
    
    CCFiniteTimeAction* seq = CCSequence::create(moveTo, callfunc, NULL);
    seq->setTag(k_Action_MoveTo);
    this->runAction(seq);
}

void GirlController::reset()
{
    this->setRotation(0);
    this->setVisible(true);
}

void GirlController::moveEnd()
{
    this->getParent()->removeChild(this, false);
}
