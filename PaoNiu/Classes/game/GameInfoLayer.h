//
//  GameInfoLayer.h
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#ifndef __PaoNiu__GameInfoLayer__
#define __PaoNiu__GameInfoLayer__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class GameInfoLayer:public CCLayer{
public:
    CC_SYNTHESIZE(void*, _delegate, Delegate);
    bool init();
    CREATE_FUNC(GameInfoLayer);
private:
    CCSize winSize;
};
#endif /* defined(__PaoNiu__GameInfoLayer__) */
