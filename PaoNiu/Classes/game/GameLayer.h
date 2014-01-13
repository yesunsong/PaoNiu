//
//  GameLayer.h
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#ifndef __PaoNiu__GameLayer__
#define __PaoNiu__GameLayer__

#include <iostream>
#include "cocos2d.h"
#include "UIComm.h"

USING_NS_CC;

class GameLayer:public CCLayer{
public:
    CC_SYNTHESIZE(void*, _delegate, Delegate);
    
    bool init();
    CREATE_FUNC(GameLayer);
public:
    
private:
    CCSize winSize;
private:
};

#endif /* defined(__PaoNiu__GameLayer__) */
