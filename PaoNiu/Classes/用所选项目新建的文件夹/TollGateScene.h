#ifndef __TOLLGATE_SCENE_H__
#define __TOLLGATE_SCENE_H__

#include "cocos2d.h"
#include "TollGateModel.h"

using namespace cocos2d;

class TollGate : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
	CCArray *tollgateDatas;

    // implement the "static node()" method manually
    CREATE_FUNC(TollGate);
};

#endif // __HELLOWORLD_SCENE_H__
