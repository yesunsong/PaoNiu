

#include "TouchController.h"
#include "GameScene.h"
USING_NS_CC;
bool TouchController::init()
{
    this->setTouchEnabled(true);
    return true;
}
GameScene* TouchController::getGameScene()
{
    return (GameScene*)this->getParent();
}
bool TouchController::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    this->getGameScene()->setIsPapaw(true);
	if(this->getGameScene()->hasGold())
	{
		this->getGameScene()->papawShowAt(this->locationFromTouch(touch));
	}
    return true;
}
void TouchController::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
    this->getGameScene()->papawShowAt(this->locationFromTouch(touch));
}
void TouchController::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    this->getGameScene()->setIsPapaw(false);
	this->getGameScene()->papawShowAt(this->locationFromTouch(touch));
}
void TouchController::setTouchEnabled(bool flag)
{
    if (m_bTouchEnabled != flag){
        m_bTouchEnabled = flag;
        if(flag){
            CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        }else{
            CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
        }
    }
}
CCPoint TouchController::locationFromTouch(CCTouch* touch)
{
    //把点从UI坐标系转到GL坐标系
    return CCDirector::sharedDirector()->convertToGL(touch->getLocationInView());
}