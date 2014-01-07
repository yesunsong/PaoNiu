#ifndef _GameAboutScene_h
#define _GameAboutScene_h
#include "cocos2d.h"
using namespace cocos2d;
class GameAbout : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    
    virtual void onEnter();
    
    virtual void onExit();
    
    static cocos2d::CCScene* scene();
    
    void menuBackCallback(CCObject* pSender);
    
    void menuEnter();
    
    CREATE_FUNC(GameAbout);
};


#endif