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
    bool init();
    CREATE_FUNC(MainLayer);
public:
    void setDelegate(void* delegate);
private:
    CCSize winSize;
    void* _delegate;
private:
    void turnToMail();
};

#endif /* defined(__PaoNiu__MainLayer__) */
