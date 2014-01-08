//
//  LoadScene.h
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#ifndef __PaoNiu__LoadScene__
#define __PaoNiu__LoadScene__

#include "cocos2d.h"
#include "LoadDelegate.h"


USING_NS_CC;

class LoadScene:public CCScene{
public:
    bool init();
    CREATE_FUNC(LoadScene);
private:
    CCSize winSize;
};

#endif /* defined(__PaoNiu__LoadScene__) */
