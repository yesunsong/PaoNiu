//
//  StartScene.h
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-7.
//
//

#ifndef __PaoNiu__StartScene__
#define __PaoNiu__StartScene__

#include "cocos2d.h"
#include "LoginDelegate.h"

USING_NS_CC;

class LoginScene:public CCScene{
public:
    bool init();
    CREATE_FUNC(LoginScene);
private:
    CCSize winSize;
};
#endif /* defined(__PaoNiu__StartScene__) */
