//
//  GameScene.h
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#ifndef __PaoNiu__GameScene__
#define __PaoNiu__GameScene__

#include <iostream>
#include "cocos2d.h"
#include "LoginDelegate.h"

USING_NS_CC;

class GameScene:public CCScene{
public:
    bool init();
    CREATE_FUNC(GameScene);
private:
    CCSize winSize;
};

#endif /* defined(__PaoNiu__GameScene__) */
