#include "GameLayer.h"
#include "StaticData.h"
USING_NS_CC;
bool GameLayer::init()
{
    if(CCLayer::init()){
		/*
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        _weapon = Weapon::create();
        _weapon->setPosition(winSize.width*0.5, _weapon->getCannon()->getCurCannonSprite()->getContentSize().height*0.26);
        this->addChild(_weapon);
        
        _subItem = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("button_sub")), CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("button_sub")), this, menu_selector(GameLayer::switchCannon));
        _addItem = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("button_add")), CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("button_add")), this, menu_selector(GameLayer::switchCannon));
        CCMenu* menu = CCMenu::create(_subItem, _addItem, NULL);
        menu->alignItemsHorizontallyWithPadding(_weapon->getCannon()->getCurCannonSprite()->getContentSize().width+10);
        menu->setPosition(CCPointMake(winSize.width*0.5, _subItem->getContentSize().height*0.5));
        this->addChild(menu);
		*/
		_papaw = PapawController::create((PapawType)0);
		_papaw->setPosition(ccp(-100,-100));
		_papaw->setVisible(false);
		//_papaw->showAt(ccp(100,100));
		this->addChild(_papaw);
        return true;
    }
    return false;
}
void GameLayer::switchPapaw(CCObject* sender)
{
    //CannonType type = _weapon->getCannon()->getType();
   // if(sender == _addItem){
    //    type = (CannonType)((int)type+1);
   // }else if(sender == _subItem){
   //     type = (CannonType)((int)type-1);
   // }
   // _weapon->getCannon()->setType(type);
}
void GameLayer::papawShow(CCPoint target)
{
    /*
	char x[10];
	char y[10];
	sprintf(x, "%.0f",target.x);
	sprintf(y, "%.0f",target.y);
	CCLog(x);
	CCLog(y);
	*/

	//_papaw = PapawController::create((PapawType)0);
	//_papaw->setPosition(ccp(-100,-100));
	//_papaw->setVisible(false);
		//_papaw->showAt(ccp(100,100));
	//this->addChild(_papaw);

	_papaw->showAt(target);

}
bool GameLayer::shootTo(CCPoint target)
{
    return true;//_papaw->shootTo(target);
}