//
//  StartLayer.h
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-7.
//
//

#ifndef __PaoNiu__tStartLayer__
#define __PaoNiu__StartLayer__

#include "cocos2d.h"
//#include <<#header#>>
USING_NS_CC;

class StartLayer:public CCLayer{
public:
    bool init();
    CREATE_FUNC(StartLayer);
private:
    CCSize winSize;
};
#endif /* defined(__PaoNiu__StartLayer__) */
