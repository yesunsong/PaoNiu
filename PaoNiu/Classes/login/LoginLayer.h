//
//  StartLayer.h
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-7.
//
//

#ifndef __PaoNiu__LoginLayer__
#define __PaoNiu__LoginLayer__

#include "cocos2d.h"
#include "UIComm.h"
USING_NS_CC;

class LoginLayer:public CCLayer{
public:
    bool init();
    CREATE_FUNC(LoginLayer);
    
public:
    void setDelegate(void* delegate);
private:
    CCSize winSize;
    void* _delegate;
    
private:
    void loginWechat();
    void loginQQ();
    
};
#endif /* defined(__PaoNiu__LoginLayer__) */
