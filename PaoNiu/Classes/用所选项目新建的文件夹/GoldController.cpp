
#include "GoldController.h"
GoldController::GoldController(void)
{
}

GoldController::~GoldController(void)
{
}
void GoldController::onExit()
{
    CCNode::onExit();
}
void GoldController::onEnter()
{
    CCNode::onEnter();
    CCSize size = CCDirector::sharedDirector()->getWinSize(); 
    this->setContentSize(size);
    bits = CCArray::createWithCapacity(5);
    //分数标题
    CCSprite *title = CCSprite::create("score.png");
    title->setPosition(ccp(60,size.height - 20));
    title->setScale(0.5);
    addChild(title);
    //数字按位设置
    for(int i = 0;i < 5;i ++){
        CCSprite * shu = CCSprite::create("shu.png");
        ui = shu->getTexture();
        shu->setScale(0.5);
        shu->setTextureRect(CCRectMake(234,0,26,31));
        shu->setPosition(ccp( 100 + i * 15,size.height - 20));
        bits->addObject(shu);
        addChild(shu);
    }
    bits->retain();
    gold = 100;
}
void GoldController::setGold(int var){
	gold = var;
}
void GoldController::subNumber(int var){
    //分数，按位设置数字
    gold -= var;
    int temp = gold % 10;
    if(temp > 0){
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(4))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31)); 
    }else{
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(4))->setTextureRect(CCRectMake(234,0,26,31)); 
    }
    temp = (gold % 100) / 10;
    if(temp > 0){
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(3))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31));  
 
    }else{
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(3))->setTextureRect(CCRectMake(234,0,26,31)); 
    }
    temp = (gold % 1000) / 100;
    if(temp > 0){
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(2))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31)); 
 
    }else{
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(2))->setTextureRect(CCRectMake(234,0,26,31));
    }
    temp = (gold % 10000) / 1000;
    if(temp > 0){
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(1))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31)); 
 
    }else{
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(1))->setTextureRect(CCRectMake(234,0,26,31)); 
    }
    temp = gold / 10000;
    if(temp > 0){
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(0))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31));  
 
    }else{
        ((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((CCSprite *)bits->objectAtIndex(0))->setTextureRect(CCRectMake(234,0,26,31));
    }
}