//
//  SettingScene.h
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#ifndef __PaoNiu__SettingScene__
#define __PaoNiu__SettingScene__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class SettingScene:public CCScene{
public:
    bool init();
    CREATE_FUNC(SettingScene);
private:
    CCSize winSize;
};
#endif /* defined(__PaoNiu__SettingScene__) */
