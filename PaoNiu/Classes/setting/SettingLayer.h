//
//  SettingLayer.h
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#ifndef __PaoNiu__SettingLayer__
#define __PaoNiu__SettingLayer__

#include <iostream>
#include <iostream>
#include "cocos2d.h"
#include "UIComm.h"

USING_NS_CC;

class SettingLayer:public CCLayer{
public:
    bool init();
    CREATE_FUNC(SettingLayer);
public:
    void setDelegate(void* delegate);
private:
    CCSize winSize;
    void* _delegate;
private:
    void backToMain();
    void sendFeedback();
};
#endif /* defined(__PaoNiu__SettingLayer__) */
