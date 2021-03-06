//
//  MainLayer.h
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#ifndef __PaoNiu__MainLayer__
#define __PaoNiu__MainLayer__

#include <iostream>
#include "cocos2d.h"
#include "UIComm.h"

USING_NS_CC;

class MainLayer:public CCLayer{
public:
    CC_SYNTHESIZE(void*, _delegate, Delegate);
    
    bool init();
    CREATE_FUNC(MainLayer);
    void onEnter();
    void onExit();
public:
private:
    CCSize winSize;
private:
    void turnToMail();
};

#endif /* defined(__PaoNiu__MainLayer__) */
