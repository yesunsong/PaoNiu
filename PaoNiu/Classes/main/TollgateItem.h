//
//  TollgateItem.h
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-8.
//
//

#ifndef __PaoNiu__TollgateItem__
#define __PaoNiu__TollgateItem__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class TollgateItem:public CCNode,public CCTargetedTouchDelegate{
public:
    CC_SYNTHESIZE(CCRect, m_hotArea, HotArea);
    CC_SYNTHESIZE(void*, _delegate, Delegate);
    
    bool init();
    CREATE_FUNC(TollgateItem);
    
    void onEnter();
    void onExit();
    bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    
public:
    void setTollgate(const char* name,int score,int type);
private:
    CCSprite* itemBg;
    CCLabelTTF* _nameLabel;
    CCLabelTTF* _scoreLabel;
    CCLabelTTF* _medalLabel;
    
    char* tollgateName;//关卡名称
    int score;//分数
    int medalType;//勋章类型
    
private:
    void registerWithTouchDispatcher();
    
};
#endif /* defined(__PaoNiu__TollgateItem__) */
