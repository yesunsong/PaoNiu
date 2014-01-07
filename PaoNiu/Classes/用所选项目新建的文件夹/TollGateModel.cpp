#include "TollGateModel.h"
//#include "GameScene.h"
TollGateModel::TollGateModel(void)
{
}

TollGateModel::~TollGateModel(void)
{
}
void TollGateModel::onEnter()
{
    CCNode::onEnter();
    this->setContentSize(CCSizeMake(99,111));
    mainbody = CCSprite::create("DrDog1.png");
    //初始化动画
    CCAnimation* animation = CCAnimation::create();
    animation->addSpriteFrameWithFileName("DrDog1.png");
    animation->addSpriteFrameWithFileName("DrDog2.png");
    animation->setDelayPerUnit(0.1f);
    animation->setRestoreOriginalFrame(true);
    mainbody->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
    addChild(mainbody);
    boom = CCSprite::create("Boom1.png");
    addChild(boom);
    boom->setVisible(false);
    islife = true;
}
void TollGateModel::setdie(){
    islife = false;
    mainbody->setVisible(false);
    boom->setVisible(true);
    this->stopAllActions();
    //爆炸动画
    CCAnimation* boomAnimation = CCAnimation::create();
    boomAnimation->addSpriteFrameWithFileName("Boom1.png");
    boomAnimation->addSpriteFrameWithFileName("Boom2.png");
    boomAnimation->addSpriteFrameWithFileName("Boom3.png");
    boomAnimation->addSpriteFrameWithFileName("Boom4.png");
    boomAnimation->addSpriteFrameWithFileName("Boom5.png");
    boomAnimation->setDelayPerUnit(0.1f);
    boomAnimation->setRestoreOriginalFrame(true);
    //boom->runAction(CCSequence::create(CCAnimate::create(boomAnimation),CCCallFuncN::create(this, callfuncN_selector(TollGateModel::restart)),NULL));
}
void TollGateModel::releasebullet(){
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCPoint pos = this->getPosition();
    if(pos.y > 20 && pos.y < size.height && islife){
       //GameMain *p = (GameMain *) this->getParent();
       //p->releaseenemyBullet(pos.x,pos.y - 30);
    }
}
void TollGateModel::onExit()
{
    CCNode::onExit();
}
void TollGateModel::setType(short var){
    type = var;
}
void TollGateModel::restart(){
    mainbody->setVisible(true);
    boom->setVisible(false);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    this->setPosition(ccp(size.width/4 * type,size.height + 50));
    islife = true;
    mainbody->setVisible(true);
    boom->setVisible(false);
    //this->movestart();
}
