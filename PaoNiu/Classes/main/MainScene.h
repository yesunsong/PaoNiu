//
//  MainScene.h
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#ifndef __PaoNiu__MainScene__
#define __PaoNiu__MainScene__

#include <iostream>

#include "cocos2d.h"
#include "LoginDelegate.h"

USING_NS_CC;

class MainScene:public CCScene{
public:
    bool init();
    CREATE_FUNC(MainScene);
private:
    CCSize winSize;
};
#endif /* defined(__PaoNiu__MainScene__) */
