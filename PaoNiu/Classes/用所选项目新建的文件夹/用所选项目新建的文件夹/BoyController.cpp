#include "BoyController.h"
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
BoyController* BoyController::create(BoyType type)
{
    BoyController* boy = new BoyController();
    boy->init(type);
    boy->autorelease();
    return boy;
}
bool BoyController::init(BoyType type)
{
    _type = type;
	/*
     CCLog("BoyController Start!");
     char buf[10];
     sprintf(buf, "%d", _type);
     //string b = buf;
     CCLog(buf);
     */
	CCString* animationName = CCString::createWithFormat("fish_animation_%d", _type);
	//CCLog(animationName->getCString());
    CCAnimation* boyAnimation = CCAnimationCache::sharedAnimationCache()->animationByName(animationName->getCString());
    CCAnimate* boyAnimate = CCAnimate::create(boyAnimation);
    boyAnimate->setTag(k_Action_Animate);
    _boySprite = CCSprite::create();
    this->addChild(_boySprite);
    _boySprite->runAction(CCRepeatForever::create(boyAnimate));
    return true;
}
CCRect BoyController::getCollisionArea()
{
    CCAssert(this->getParent(), "You Should Call This After Add it as a child");
    CCPoint origin = this->getParent()->convertToWorldSpace(this->getPosition());
    CCSize size = _boySprite->getContentSize();
    return CCRectMake(origin.x-size.width*0.5, origin.y-size.height*0.5, size.width, size.height);
}
void BoyController::beCaught()
{
    this->stopActionByTag(k_Action_MoveTo);
    CCDelayTime* delayTime = CCDelayTime::create(1.0);
    CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(BoyController::beCaught_CallFunc));
    CCFiniteTimeAction* seq = CCSequence::create(delayTime, callFunc, NULL);
    
    CCBlink* blink = CCBlink::create(1.0, 8);
    CCFiniteTimeAction *spawn = CCSpawn::create(blink,seq , NULL);
    this->runAction(spawn);
}
void BoyController::beCaught_CallFunc()
{
    this->getParent()->removeChild(this, false);
}
void BoyController::moveTo(CCPoint destination)
{
    CCPoint start = this->getParent()->convertToWorldSpace(this->getPosition());
    float speed = ccpDistance(destination, start) / 200;
    CCMoveTo* moveTo = CCMoveTo::create(speed ,destination);
    CCCallFunc* callfunc = CCCallFunc::create(this, callfunc_selector(BoyController::moveEnd));
    
    CCFiniteTimeAction* seq = CCSequence::create(moveTo, callfunc, NULL);
    seq->setTag(k_Action_MoveTo);
    this->runAction(seq);
}
void BoyController::reset()
{
    this->setRotation(0);
    this->setVisible(true);
}
void BoyController::moveEnd()
{
    this->getParent()->removeChild(this, false);
}
