#include "GameLayer.h"
//#include "StaticData.h"
USING_NS_CC;
bool GameLayer::init()
{
    if(CCLayer::init()){
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
}
void GameLayer::papawShow(CCPoint target)
{
	_papaw->showAt(target);

}
bool GameLayer::shootTo(CCPoint target)
{
    return true;//_papaw->shootTo(target);
}