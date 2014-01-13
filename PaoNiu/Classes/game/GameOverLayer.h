//
//  GameOverLayer.h
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#ifndef __PaoNiu__GameOverLayer__
#define __PaoNiu__GameOverLayer__

#include <iostream>
#include "cocos2d.h"
#include "UIComm.h"

USING_NS_CC;
class GameOverLayer:public CCLayer{
public:
    CC_SYNTHESIZE(void*, _delegate, Delegate);
    
    bool init();
    CREATE_FUNC(GameOverLayer);
public:
    
private:
    CCSize winSize;
private:
};

#endif /* defined(__PaoNiu__GameOverLayer__) */
