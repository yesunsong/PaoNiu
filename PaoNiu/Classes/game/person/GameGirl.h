//
//  GameGirl.h
//  PaoNiu
//
//  Created by 叶孙松 on 14-1-9.
//
//

#ifndef __PaoNiu__GameGirl__
#define __PaoNiu__GameGirl__

#include <iostream>
#include "GamePerson.h"
#include "cocos2d.h"
USING_NS_CC;

class GameGirl:public GamePerson{
public:
    CREATE_FUNC(GameGirl);
private:
    virtual void createSkin();
    void setCollisionArea(CCRect var);
    CCRect getCollisionArea();
private:
    CCSprite* bubble;
};
#endif /* defined(__PaoNiu__GameGirl__) */
