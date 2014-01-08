//
//  MenuLayer.h
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#ifndef __PaoNiu__MenuLayer__
#define __PaoNiu__MenuLayer__

#include "cocos2d.h"
USING_NS_CC;

class MenuLayer:public CCLayer{
public:
    bool init();
    CREATE_FUNC(MenuLayer);
    
public:
    void setDelegate(void* delegate);
private:
    CCSize winSize;
    void* _delegate;
    
private:
    void trunToHelp();
    void trunToStore();
    void turnToProp();
    void trunToSetting();
};

#endif /* defined(__PaoNiu__MenuLayer__) */
