//
//  GamePerson.h
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-9.
//
//

#ifndef __PaoNiu__GamePerson__
#define __PaoNiu__GamePerson__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class GamePerson:public CCNode,public CCTouchDelegate{
public:
    CC_PROPERTY(CCRect, _collsionArea, CollisionArea);
    
    GamePerson();
    virtual ~GamePerson();
    bool init();
    CREATE_FUNC(GamePerson);
private:
    CCSize winSize;
protected:
    CCSprite *skin;
    float fallSpeed;
protected:
   virtual void createSkin();
};
#endif /* defined(__PaoNiu__GamePerson__) */
