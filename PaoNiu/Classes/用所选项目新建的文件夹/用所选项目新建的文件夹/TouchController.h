

#ifndef _TouchController_h_
#define _TouchController_h_
#include "cocos2d.h"

class GameScene;

class TouchController : public cocos2d::CCLayer
{
public:
    CREATE_FUNC(TouchController);
    bool init();
    bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    
    //�������رմ����Ľӿ�
    void setTouchEnabled(bool flag);
protected:
    GameScene* getGameScene();
    cocos2d::CCPoint locationFromTouch(cocos2d::CCTouch *touch);

};

#endif /* defined(__FishingJoy__TouchController__) */
