//
//  LoadLayer.h
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#ifndef __PaoNiu__LoadLayer__
#define __PaoNiu__LoadLayer__

#include "cocos2d.h"
USING_NS_CC;

class LoadLayer:public CCLayer{
public:
    bool init();
    CREATE_FUNC(LoadLayer);
    
public:
    void setDelegate(void* delegate);
private:
    CCSize winSize;
    void* _delegate;
    
private:
    void loadFinish();
    
};

#endif /* defined(__PaoNiu__LoadLayer__) */
